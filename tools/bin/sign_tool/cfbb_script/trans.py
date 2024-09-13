#!/usr/bin/env python3
# encoding=utf-8
# Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2021. All rights reserved.

import os
import config


class Trans(object):

    def __init__(self, socket_handle):
        self.socket_handle = socket_handle
        pass

    def send(self, file_path):
        file_size = os.path.getsize(file_path)
        print('[Tx  ] Send file: {}'.format(file_path))
        print('[Tx  ] File length: {}'.format(file_size))

        file_size_str = '{:08X}'.format(file_size)
        self.socket_handle.send(file_size_str.encode())

        data = self.socket_handle.recv(config.seg_size)
        if (data != config.trans_ack):
            print('[Tx  ] Failure: Wait ACK failure.')
            return 0

        send_size = 0
        with open(file_path, 'rb') as fin:
            while True:
                if file_size == send_size:
                    print('[Tx  ] Success!')
                    return 1

                try:
                    if (file_size - send_size) >= config.seg_size:
                        file_data = fin.read(config.seg_size)
                    else:
                        file_data = fin.read(file_size - send_size)
                except Exception as e:
                    print('[Tx  ] Abnormal: {}'.format(e))

                if len(file_data) == 0:
                    print('[Tx  ] File read error: length = 0')
                    return 0

                send_size += len(file_data)
                self.socket_handle.send(file_data)

        return 0


    def recv(self, file_path):
        data = self.socket_handle.recv(8).decode()
        file_size = int(data, 16)
        self.socket_handle.send(config.trans_ack)
        print('[  Rx] Recv file: {}'.format(file_path))
        print('[  Rx] File length: {}'.format(file_size))

        recv_size = 0

        with open(file_path, 'wb') as fout:
            while True:
                if file_size == recv_size:
                    print('[  Rx] Success!')
                    return 1

                try:
                    if (file_size - recv_size) >= config.seg_size:
                        file_data = self.socket_handle.recv(config.seg_size)
                    else:
                        file_data = self.socket_handle.recv(file_size - recv_size)
                except Exception as e:
                    print('[  Rx] Abnormal: {}'.format(e))

                if (len(file_data) == 0):
                    print('[  Rx] File recv error: length = 0')
                    break

                recv_size += len(file_data)
                fout.write(file_data)

        return 0

