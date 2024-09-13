#!/usr/bin/env python3
# encoding=utf-8
# ============================================================================
# @brief    Build ATE Pkg File
# Copyright CompanyNameMagicTag 2023-2023. All rights reserved.
# ============================================================================

import os
import sys
import struct

file_dir = os.path.dirname(os.path.realpath(__file__))
g_root = os.path.realpath(os.path.join(file_dir, "..", "..", "..", "..", ".."))

def merge_bins(ate_bin, partition_bin, output, size):
    # 读取两个bin文件
    with open(ate_bin, 'rb') as f1, open(partition_bin, 'rb') as f2:
        data_sign = f1.read(0x300)
        f1.seek(0x300, 0)
        data_info = f1.read()
        data_part = f2.read()

    # 创建一个长度为FW大小的bin文件
    with open(output, 'wb') as out:
        out.write(b'\x00' * size * 1024)
        # 将ate bin放在bin文件的起始位置
        out.seek(0, 0)
        out.write(data_info)
        # 将partition bin放在bin文件的末尾偏移0x1000的位置
        out.seek(-0x1000, 2)
        out.write(data_part)
        # 将ate bin的签名放在bin文件的末尾偏移0x1300的位置
        out.seek(-0x1300, 2)
        out.write(data_sign)

def create_hex_file(_bin, _hex):
    with open(str(_bin), "rb") as binfile, open(
                str(_hex), "wb") as hexfile:
        while True:
            bindata = binfile.read(4)
            if not bindata:
                break
            if len(bindata) != 4:
                bindata = bindata + b'\x00' * (4 - len(bindata))
            longdata, = struct.unpack("<L", bindata)
            hexstr = '{:x}'.format(longdata)  # dec to hex number str
            hexstr = '%s\r\n' % '{:0>8}'.format(hexstr).upper()
            hexfile.write(str.encode(hexstr))

def main():
    app_bin_path = os.path.join(g_root, "output", "bs21", "acore", "ate-application-bs21", "ate_sign.bin")
    patition_bin_path = os.path.join(g_root, "interim_binary", "bs21", "bin", "partition", "ate-application-bs21", "partition.bin")
    output_bin_path = os.path.join(g_root, "output", "bs21", "acore", "ate-application-bs21", "ate_pkg.bin")
    output_hex_path = os.path.join(g_root, "output", "bs21", "acore", "ate-application-bs21", "ate_pkg.hex")
    itcm_size = 32

    merge_bins(app_bin_path, patition_bin_path, output_bin_path, itcm_size)
    create_hex_file(output_bin_path, output_hex_path)

if __name__ == '__main__':
    main()
