#!/usr/bin/env python3
# encoding=utf-8
# ============================================================================
# @brief    packet files
# ============================================================================

import os
import sys
import importlib

sys.path.append(os.path.dirname(os.path.realpath(__file__)))
sys.dont_write_bytecode = True

g_bs2x_chip_list = ["bs20", "bs21", "bs21a", "bs21e", "bs22", "bs26"]

def main():
    arg_ls = sys.argv
    build_soc = sys.argv[1]
    build_target = sys.argv[2]
    build_extr_defines = " ".join(sys.argv[3].split(","))
    sector_cfg = sys.argv[4]

    if build_soc in g_bs2x_chip_list:
        load_fmt = "chip_packet.bs2x.packet"
    else:
        load_fmt = "chip_packet.%s.packet" %build_soc
    load_mod = importlib.import_module(load_fmt)

    lost_file = load_mod.is_packing_files_exist(build_soc, build_target)
    if lost_file:
        lost = ";".join(lost_file)
        print(f"cannot find {lost}")
        exit(-1)
    if build_soc in ["ws63"]:
        load_mod.make_all_in_one_packet(build_target, build_extr_defines)
    elif build_soc in g_bs2x_chip_list:
        load_mod.make_all_in_one_packet(build_soc, build_target, sector_cfg)
    else:
        load_mod.make_all_in_one_packet(build_target)

if __name__ == "__main__":
    main()
