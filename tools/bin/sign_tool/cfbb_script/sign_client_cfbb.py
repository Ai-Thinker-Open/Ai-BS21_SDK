#!/usr/bin/env python3
# coding: utf-8
# Copyright (c) Hisilicon Technologies Co., Ltd. 2023-2023. All rights reserved.

import argparse
import sys
import socket
import config
from properties import Properties
from trans      import Trans


def get_parameters(argv):

    parser = argparse.ArgumentParser()

    parser.add_argument('--project', type=str, required=True, help='Project name, eg. Hi2120, Hi3881, Melody, etc.')
    parser.add_argument('--config',  type=str, required=True, help='Config file')

    args = parser.parse_args(argv)
    return args


def sign_client_process(project_name, config_file, socket_handle):

    p = Properties(config_file)
    properties = p.get_properties()

    if 'DstFile' not in properties:
        raise Exception('Not found \'DstFile\' in config file.')

    # 发送连接请求
    socket_handle.send(project_name.encode('utf-8'))
    ack = socket_handle.recv(config.seg_size)
    if ack != config.trans_ack:
        raise Exception('Not support project.')

    trans_handle = Trans(socket_handle)

    # 发送配置文件
    if trans_handle.send(config_file) != 1:
        raise Exception('Send config file failed.')

    # 发送源文件
    if 'SrcFile' in properties:
        if trans_handle.send(properties['SrcFile']) != 1:
            raise Exception('Send SrcFile file failed.')

    # 接收结果文件
    if trans_handle.recv(properties['DstFile']) != 1:
        raise Exception('Send DstFile file failed.')

    pass


def sign_client(project_name, config_file):

    # 创建socket
    tcp_client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # 连接ip和port
    tcp_client_socket.connect((config.server_name, config.server_port))

    try:
        sign_client_process(project_name=project_name, config_file=config_file, socket_handle=tcp_client_socket)
    finally:
        tcp_client_socket.close()
    pass


if __name__ == '__main__':
    args = get_parameters(sys.argv[1:])

    try:
        sign_client(project_name=args.project, config_file=args.config)
    except Exception as e:
        print('[ERROR] {}'.format(e))
    else:
        print('Success')
