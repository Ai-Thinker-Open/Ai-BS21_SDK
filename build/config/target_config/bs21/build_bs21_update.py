#!/usr/bin/env python3
# encoding=utf-8
# ============================================================================
# @brief    Build Update Pkg File
# Copyright CompanyNameMagicTag 2023-2023. All rights reserved.
# ============================================================================

import os
import sys

file_dir = os.path.dirname(os.path.realpath(__file__))
g_root = os.path.realpath(os.path.join(file_dir, "..", "..", "..", ".."))
sys.path.append(os.path.join(g_root, 'build', 'script'))
from build_upg_pkg import get_parameters, begin, lzma_compress_bin

class config:
    def __init__(self, info):
        self.app_name        = "fota"
        self.upg_format_path = info.fota_format_path
        self.base            = info.fota_cfg
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
        self.fota_format_path = os.path.join(self.root_path, "build", "config", "target_config", "bs21", "fota")
        # 产品升级配置文件
        if "extern_flash" in target or "peripheral" in target:
            self.fota_cfg = os.path.join(self.root_path, "build", "config", "target_config", "bs21", "fota", "extern_flash", "fota.cfg")
        else:
            self.fota_cfg = os.path.join(self.root_path, "build", "config", "target_config", "bs21", "fota", "1M_flash", "fota.cfg")
        # 产品镜像输出路径
        self.output = os.path.join(self.root_path, "output", "bs21")
        # 产品升级镜像包输出路径
        self.upg_output = os.path.join(self.output, "acore", target)
        # 产品升级制作临时文件输出路径
        self.temp_dir = os.path.join(self.upg_output, "temp_dir")
        self.interim_path = os.path.join(self.root_path, "interim_binary", "bs21")

        # 产品镜像路径
        self.flashboot_bin = os.path.join(self.root_path, "interim_binary", "bs21", "bin", "boot_bin", "flashboot_sign_a.bin")
        self.app_bin = os.path.join(self.output, "acore", target, "application_sign.bin")
        self.nv_bin = os.path.join(self.root_path, "interim_binary", "bs21", "bin", "bs21_all_nv.bin")

def get_new_image(info):
    image_list = []
    for pkg_bin in info.option:
        if pkg_bin == "flashboot":
            image_list.append("=".join([info.flashboot_bin, "flashboot"]))
        elif pkg_bin == "application":
            image_list.append("=".join([info.app_bin, "application"]))
        elif pkg_bin == "nv":
            image_list.append("=".join([info.nv_bin, "nv"]))
    new_image = "|".join(image_list)
    return new_image

if __name__ == '__main__':
    arg_ls = sys.argv
    target = sys.argv[1]
    option = sys.argv[2].split(';')
    info = upg_base_info(target, option)
    conf = config(info)
    begin(conf)
