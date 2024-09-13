#!/usr/bin/env python3
# coding: utf-8

# =========================================================================
# @brief    signing service for melody
# Copyright CompanyNameMagicTag 2023-2023. All rights reserved.
# =========================================================================

import sys
import socket
import os
sys.path.append(os.path.join(os.path.dirname(os.path.realpath(__file__))))
import config
import trans

BUF_SIZE = 1024


class Properties:
    def get_properties(self, filename):
        properties = {}
        with open(filename, "r") as f:
            for line in f:
                cmd = line.split("#")[0]
                if "=" not in cmd:
                    continue

                key, value = cmd.strip(" ").split("=")
                key = key.strip(" ")
                value = value.strip(" ")
                value = value.strip("\n")
                value = value.strip("\r")
                value = value.strip(" ")

                if (len(value) == 0):
                    continue

                properties[key] = value

        return properties


def usage():
    print("\nsign_tool_melody - Version 0.9.0 (debug)  2023.06.15\n")
    print("sign_tool_melody.py [type] [cfg_file]")
    print("  [type]         0: Sign images")
    print("  [cfg_file]     Config file, config item format \"key = value\", \"#\" for comments.\n")
    print("For example:")
    print("  .\sign_tool_melody.py 0 acpu.cfg\n")
    return


def sign_client(argv):
    sign_type = int(argv[1], 10)
    if sign_type != 0:
        print("Not support!")
        return

    src_flag = 1
    p = Properties()
    properties = p.get_properties(argv[2])
    if properties["ImageId"] in ["0xFFFFFFFF"]:
        src_flag = 0
        if properties["Type"] not in ["0", "1", "2"]:
            print("Not support!")
            return
        if properties["Type"] in ["2"]:
            if "SrcFile" not in properties:
                print("SrcFile error.")
                return
            src_flag = 1
    else:
        if "SrcFile" not in properties:
            print("SrcFile error.")
            return

    if "DstFile" not in properties:
        print("DstFile error.")
        return

    tcp_client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)   # 创建socket
    tcp_client_socket.connect((config.server_name, config.server_port))     # 连接IP地址和端口
    tcp_client_socket.send(config.connect_cmd.encode())

    ack = tcp_client_socket.recv(BUF_SIZE)
    if (ack.decode() != config.trans_ack):
        print("Rx failure.")
        tcp_client_socket.close()
        return

    trans_handle = trans.Trans(tcp_client_socket)

    # 发送配置文件
    if (trans_handle.send(argv[2]) != 1):
        print("Tx cfg file failure.")
        tcp_client_socket.close()
        return

    # 发送源文件
    if src_flag == 1:
        src_file = properties["SrcFile"].replace('"','').replace("'",'')
        if (trans_handle.send(src_file) != 1):
            print("Tx src file failure.")
            tcp_client_socket.close()
            return

    # 接收签名结果文件
    dst_file = properties["DstFile"].replace('"','').replace("'",'')
    if (trans_handle.recv(dst_file) != 1):
        print("Rx dst file failure.")
        tcp_client_socket.close()
        return

    tcp_client_socket.close()
    print("Success!")
    return


if __name__ == '__main__':
    """
    Command Format: sign_tool_melody.py [type] [cfg_file]
    """

    if (len(sys.argv) != 3):
        usage()
    else:
        sign_client(sys.argv)
