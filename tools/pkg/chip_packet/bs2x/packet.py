#!/usr/bin/env python3
# encoding=utf-8
# ============================================================================
# @brief    packet files
# ============================================================================

import os
import sys
import json
import re

PY_PATH = os.path.dirname(os.path.realpath(__file__))
sys.path.append(PY_PATH)
PKG_DIR = os.path.dirname(PY_PATH)
PKG_DIR = os.path.dirname(PKG_DIR)

from packet_create import create_sha_file
from packet_create import packet_bin

TOOLS_DIR = os.path.dirname(PKG_DIR)
SDK_DIR = os.path.dirname(TOOLS_DIR)
sys.path.append(os.path.join(SDK_DIR, "build", "script"))

sector_cfg_type = {
    'flashboot': '0x00',
    'flashboot_bak': '0x01',
    'app': '0x23',
    'nv': '0x25',
    'slp': '0x27'
}

def search_sector_info(region, sector_config_list, sector_cfg):
    index = sector_cfg_type[region]
    for info in sector_config_list:
        if info[0] == index:
            region_addr = "0x%x" % (int(info[1], 16) + 0x90100000)
            region_len = info[2]
            return f"|{region_addr}|{region_len}|", int(region_len, 16)
    print(f'error: {region} not found in {sector_cfg}, index is {index}!')
    sys.exit(-1)

def pkg_error_log(path, image_size, sector_size):
    print("packet error: image size overflow.")
    print(f"image path: {path}.")
    print(f"image size: {hex(image_size)} > max pkg size: {hex(sector_size)}.")
    sys.exit(-1)

# bs21
def make_all_in_one_packet(pkg_soc, pack_style_str, sector_cfg):
    # ate never pkg.
    if "ate" in pack_style_str:
        return

    if sector_cfg:
        sector_cfg_path = os.path.join(SDK_DIR, "build", "config", "target_config", pkg_soc, "flash_sector_config")
        sector_cfg_json = os.path.join(sector_cfg_path, sector_cfg + ".json")
        if not os.path.exists(sector_cfg_json):
            print("packet error: sector config %s not found in %s." % (sector_cfg, sector_cfg_path))
            exit(-1)
        with open(sector_cfg_json, 'r') as f:
            sector = json.load(f)
        sector_config_list = sector['Partition_Tbl']['param_info']
        info = {}
        for key, value in sector_cfg_type.items():
            info[key] = search_sector_info(key, sector_config_list, sector_cfg)

        # get pkg dir.
        interim_binary_dir = os.path.join(SDK_DIR, "interim_binary", pkg_soc, "bin")
        if pack_style_str.startswith("pack"):
            bin_dir = os.path.join(SDK_DIR, "output", "package", pkg_soc, pack_style_str)
            partition_dir = bin_dir
            boot_dir = bin_dir
            application_dir = bin_dir
            nv_dir =  bin_dir
            glp_dir =  bin_dir
            output_dir = bin_dir
        else:
            partition_dir = os.path.join(interim_binary_dir, "partition", pack_style_str)
            boot_dir = os.path.join(interim_binary_dir, "boot_bin")
            application_dir = os.path.join(SDK_DIR, "output", pkg_soc, "acore", pack_style_str)
            nv_dir =  os.path.join(interim_binary_dir, "nv", pack_style_str)
            glp_dir =   os.path.join(interim_binary_dir, "slp", pack_style_str, "file_array_ota")
            output_dir = os.path.join(SDK_DIR, "output", pkg_soc, "fwpkg", pack_style_str)

        # fwpkg output dir
        bs2x_fwpkg = os.path.join(output_dir, "%s_all_in_one.fwpkg" %pkg_soc)
        bs2x_flashboot_only_fwpkg = os.path.join(output_dir, "%s_flashboot_only.fwpkg" %pkg_soc)
        bs2x_loadapp_only_fwpkg = os.path.join(output_dir, "%s_loadapp_only.fwpkg" %pkg_soc)
        bs2x_nv_fwpkg = os.path.join(output_dir, "%s_nv_only.fwpkg" %pkg_soc)
        bs2x_ide_fwpkg = os.path.join(SDK_DIR, "tools", "pkg", "fwpkg", pkg_soc, "%s_all.fwpkg" %pkg_soc)
        bs2x_efuse_fwpkg = os.path.join(output_dir, "%s_efuse.fwpkg" %pkg_soc)

        # bin pkg dir
        partition = os.path.join(partition_dir, "partition.bin")
        loadboot = os.path.join(boot_dir, "loaderboot_sign.bin")
        flashboot = os.path.join(boot_dir, "flashboot_sign_a.bin")
        flashboot_bak = os.path.join(boot_dir, "flashboot_sign_b.bin")
        app = os.path.join(application_dir, "application_sign.bin")
        nv = os.path.join(nv_dir, "%s_all_nv.bin" %pkg_soc)
        slp = os.path.join(glp_dir, "slp.bin")
        efuse = os.path.join(interim_binary_dir, "boot_bin" , "efuse_cfg.bin")

        # pkg bin addr
        loadboot_bx = loadboot + "|0x0|0x0|0"
        partition_bx = partition + "|0x90100000|0x1000|1"

        if os.path.isfile(efuse):
            efuse_bx = efuse + "|0x0|0x0|3"

        # get flashboot info.
        if os.path.getsize(flashboot) < info["flashboot"][1]:
            flashboot_bx = flashboot + info["flashboot"][0] + "1"
        else:
            pkg_error_log(flashboot, os.path.getsize(flashboot), info["flashboot"][1])
        # get flashboot bak info.
        if info["flashboot_bak"][1] == 0: # don't pkg flashbootb.
            flashboot_bak_bx = None
        elif os.path.getsize(flashboot_bak) < info["flashboot_bak"][1]:
            flashboot_bak_bx = flashboot_bak + info["flashboot_bak"][0] + "1"
        else:
            pkg_error_log(flashboot_bak, os.path.getsize(flashboot_bak), info["flashboot_bak"][1])
        # get app info.
        if os.path.getsize(app) < info["app"][1]:
            app_bx = app + info["app"][0] + "1"
        else:
            pkg_error_log(app, os.path.getsize(app), info["app"][1])
        # get nv info.
        if os.path.getsize(nv) < info["nv"][1]:
            nv_bx = nv + info["nv"][0] + "1"
        else:
            pkg_error_log(nv, os.path.getsize(nv), info["nv"][1])
        # get slp info.
        if os.path.isfile(slp):
            if info["slp"][1] == 0:
                print("no need to pack slp.")
            elif os.path.getsize(slp) < info["slp"][1]:
                slp_bx = slp + info["slp"][0] + "1"
            else:
                pkg_error_log(slp, os.path.getsize(slp), info["slp"][1])
    else:
        print("packet error: no sector config.")
        exit(-1)

    try:
        # pack all in one fwpkg.
        packet_post_agvs = list()
        packet_post_agvs.append(loadboot_bx)
        packet_post_agvs.append(partition_bx)
        packet_post_agvs.append(flashboot_bx)
        if flashboot_bak_bx is not None:
            packet_post_agvs.append(flashboot_bak_bx)
        packet_post_agvs.append(app_bx)
        packet_post_agvs.append(nv_bx)
        if os.path.isfile(slp) and info["slp"][1] > 0:
            packet_post_agvs.append(slp_bx)
        packet_bin(bs2x_fwpkg, packet_post_agvs)
        packet_bin(bs2x_ide_fwpkg, packet_post_agvs)

        # pack flashboot only fwpkg.
        packet_post_agvs = list()
        packet_post_agvs.append(loadboot_bx)
        packet_post_agvs.append(flashboot_bx)
        if flashboot_bak_bx is not None:
            packet_post_agvs.append(flashboot_bak_bx)
        packet_bin(bs2x_flashboot_only_fwpkg, packet_post_agvs)

        # pack application only fwpkg.
        packet_post_agvs = list()
        packet_post_agvs.append(loadboot_bx)
        packet_post_agvs.append(app_bx)
        packet_bin(bs2x_loadapp_only_fwpkg, packet_post_agvs)

        # pack nv only fwpkg.
        packet_post_agvs = list()
        packet_post_agvs.append(loadboot_bx)
        packet_post_agvs.append(nv_bx)
        packet_bin(bs2x_nv_fwpkg, packet_post_agvs)

        # pack efuse only fwpkg.
        if os.path.isfile(efuse):
            packet_post_agvs = list()
            packet_post_agvs.append(loadboot_bx)
            packet_post_agvs.append(efuse_bx)
            packet_bin(bs2x_efuse_fwpkg, packet_post_agvs)

    except Exception as e:
        print(e)
        exit(-1)


def is_packing_files_exist(soc, pack_style_str):
    """
    判断打包文件是否存在
    :return:
    """
    packing_files = get_packing_files(soc, pack_style_str)
    lost_files = list()
    for f_path in packing_files:
        if not os.path.isfile(f_path):
            lost_files.append(f_path)
    return lost_files

def get_packing_files(soc, pack_style_str):
    """
    直接添加需要打包的文件路径
    :return:
    """

    packing_files = list()
    if pack_style_str.startswith("pack"):
        bin_dir = os.path.join(SDK_DIR, "output", "package", soc, pack_style_str)
        if pack_style_str.endswith("ate"):
            ate_path = os.path.join(bin_dir, "ate.bin")
            packing_files.append(ate_path)
        else:
            application_path = os.path.join(bin_dir, "application.bin")
            packing_files.append(application_path)
    else:
        bin_dir = os.path.join(SDK_DIR, "output", soc, "acore", pack_style_str)
        if pack_style_str.startswith("ate"):
            ate_path = os.path.join(bin_dir, "ate.bin")
            packing_files.append(ate_path)
        else:
            application_path = os.path.join(bin_dir, "application.bin")
            packing_files.append(application_path)
    return packing_files
