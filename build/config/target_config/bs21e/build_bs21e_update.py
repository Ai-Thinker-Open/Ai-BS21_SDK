#!/usr/bin/env python3
# encoding=utf-8
# ============================================================================
# @brief    Build Update Pkg File
# Copyright CompanyNameMagicTag 2023-2023. All rights reserved.
# ============================================================================

import os
import sys
import hashlib
import struct
import shutil

file_dir = os.path.dirname(os.path.realpath(__file__))
g_root = os.path.realpath(os.path.join(file_dir, "..", "..", "..", ".."))
sys.path.append(os.path.join(g_root, 'build', 'script'))
from build_upg_pkg import get_parameters, begin, lzma_compress_bin, fill_lzma_head

class config:
    def __init__(self, info):
        self.app_name        = "fota"
        self.upg_format_path = info.fota_format_path
        self.base            = info.fota_cfg
        self.user_firmware_version = info.user_firmware_version
        self.temp_dir        = info.temp_dir
        self.new_images      = get_new_image(info)
        self.old_images      = ""
        self.output_dir      = info.upg_output
        self.type            = 0

class upg_base_info:
    def __init__(self, target, option):
        self.root_path = g_root
        self.option = option
        # 升级包结构配置文件
        self.fota_format_path = os.path.join(self.root_path, "build", "config", "target_config", "bs21e", "fota")
        # 产品升级配置文件
        if "extern_flash" in target or "peripheral" in target and "slp" not in target:
            self.fota_cfg = os.path.join(self.root_path, "build", "config", "target_config", "bs21e", "fota", "extern_flash", "fota.cfg")
        else:
            self.fota_cfg = os.path.join(self.root_path, "build", "config", "target_config", "bs21e", "fota", "1M_flash", "fota.cfg")
        # 用户配置固件版本
        self.user_firmware_version = self.get_user_defined_firmware_version(target)
        # 产品镜像输出路径
        self.output = os.path.join(self.root_path, "output", "bs21e")
        # 产品升级镜像包输出路径
        self.upg_output = os.path.join(self.output, "acore", target)
        # 产品升级制作临时文件输出路径
        self.temp_dir = os.path.join(self.upg_output, "temp_dir")
        self.interim_path = os.path.join(self.root_path, "interim_binary", "bs21e")

        # 产品镜像路径
        self.flashboot_bin = os.path.join(self.root_path, "interim_binary", "bs21e", "bin", "boot_bin", "flashboot_sign_a.bin")
        self.app_bin = os.path.join(self.output, "acore", target, "application_sign.bin")
        self.nv_bin = os.path.join(self.root_path, "interim_binary", "bs21e", "bin", "bs21e_all_nv.bin")
        self.slp_path = os.path.join(self.root_path, "interim_binary", "bs21e", "bin", "slp", target, "file_array_ota")
        self.slp_bin = os.path.join(self.root_path, "interim_binary", "bs21e", "bin", "slp", target, "file_array_ota", "slp.bin")

    def get_user_defined_firmware_version(self, target):
        target = target.replace('-', "_")
        mconfig_file_path = os.path.join(self.root_path, 'build', 'config', 'target_config', "bs21e", 'menuconfig', "acore", f"{target}.config")
        if not os.path.exists(mconfig_file_path):
            return None
        with open(mconfig_file_path, 'r') as file:
            for line in file:
                line = line.strip()
                # 跳过注释行和空行
                if not line or line.startswith('#'):
                    continue
                if '=' in line:
                    key, value = line.split('=', 1)
                    if key == 'CONFIG_USER_FIRMWARE_VERSION':
                        return value.replace('"', "")
        return None

def get_new_image(info):
    image_list = []
    for pkg_bin in info.option:
        if pkg_bin == "flashboot":
            image_list.append("=".join([info.flashboot_bin, "flashboot"]))
        elif pkg_bin == "application":
            image_list.append("=".join([info.app_bin, "application"]))
        elif pkg_bin == "slp":
            image_list.append("=".join([info.slp_bin, "slp"]))
        elif pkg_bin == "nv":
            image_list.append("=".join([info.nv_bin, "nv"]))
    new_image = "|".join(image_list)
    return new_image

def merge_fwpkg(info):
    # 读取两个fwpkg文件
    fota_path = os.path.join(info.upg_output, "fota.fwpkg")
    slp_path = os.path.join(info.slp_path, "slp.lzma")
    output_path = os.path.join(info.upg_output, "fota_all.fwpkg")
    with open(fota_path, 'rb') as f1, open(slp_path, 'rb') as f2:
        fota_data = f1.read()
        slp_data = f2.read()

    slp_lzma_offset = 0x50000
    # 合并形成fota_slp.fwpkg
    with open(output_path, 'wb') as out:
        size = slp_lzma_offset + 0xa0 + os.path.getsize(slp_path)
        if size % 16:
            size = size // 16 * 16 + 16
        out.write(b'\xff' * size)

        out.seek(0, 0)
        out.write(fota_data)
        header_magic = struct.pack("i", 0x464F5451)
        image_id = struct.pack("i", 0x4B0F2D2F)
        image_size = struct.pack("i", os.path.getsize(slp_path))
        image_offset = struct.pack("i", (slp_lzma_offset + 0xa0))
        image_flag = struct.pack("i", 0x5b)
        lzma_flag = struct.pack("i", 0x3c7896e1)
        sha = hashlib.sha256(slp_data)
        new_image_size = struct.pack("i", os.path.getsize(info.slp_bin))

        out.seek(slp_lzma_offset, 0)
        out.write(header_magic)
        out.write(image_id)
        out.write(image_offset)
        out.write(image_size)
        out.write(sha.digest())
        out.seek(slp_lzma_offset + 0x54, 0)
        out.write(new_image_size)
        out.seek(slp_lzma_offset + 0x60, 0)
        out.write(lzma_flag)
        out.seek(slp_lzma_offset + 0x9C, 0)
        out.write(image_flag)

        out.seek(slp_lzma_offset + 0xA0, 0)
        out.write(slp_data)
        out.close

def fota_add_slp(info):
    image_bin_file = os.path.join(info.slp_path, "slp.bin")
    if not os.path.exists(image_bin_file):
        return
    upg_lzma_file = os.path.join(info.slp_path, "slp.lzma")
    lzma_tool = os.path.join(g_root, "tools", "bin", "lzma_tool", 'lzma_tool')
    # slp镜像压缩
    print("fota add slp...")
    lzma_compress_bin('"%s"' % image_bin_file, '"%s"' % upg_lzma_file, lzma_tool)
    fill_lzma_head(upg_lzma_file, info.slp_path, 'slp')
    # 合并升级包与slp镜像压缩包
    merge_fwpkg(info)
    shutil.copy(image_bin_file, os.path.join(info.upg_output, "fota_slp.fwpkg"))

if __name__ == '__main__':
    # config.py中对应target的'upg_pkg'选项用于配置需要升级的镜像
    # 需要升级slp时，'upg_pkg'选项可选择'slp'或者'slp_lzma'，分别对应两种分区方案
    # 'slp': slp镜像和其他镜像一样，有独立的分区
    # 'slp_lzma': slp镜像分区与fota分区复用
    arg_ls = sys.argv
    target = sys.argv[1]
    option = sys.argv[2].split(';')
    info = upg_base_info(target, option)
    conf = config(info)
    begin(conf)
    if 'slp_lzma' in option:
        fota_add_slp(info)
