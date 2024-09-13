#!/usr/bin/env python3
# encoding=utf-8

# =========================================================================
# @brief    transmit File
# Copyright CompanyNameMagicTag 2023-2023. All rights reserved.
# =========================================================================

import os
import config


class Trans(object):

    def __init__(self, socket_handle):
        self.socket_handle = socket_handle


    def send(self, file_path):
        file_size = os.path.getsize(file_path)
        print("Tx file length. file_size: %d" % file_size)

        str_file_size = '%08X' % file_size
        self.socket_handle.send(str_file_size.encode())

        data = self.socket_handle.recv(1024)
        if (data.decode() != config.trans_ack):
            print("Tx failure: Wait ACK failure.")
            return 0

        send_size = 0
        with open(file_path, "rb") as file:
            while True:
                if (file_size == send_size):
                    print("Tx success!")
                    return 1

                try:
                    if (file_size - send_size) >= 1024:
                        file_data = file.read(1024)
                    else:
                        file_data = file.read(file_size - send_size)
                except Exception as e:
                    print("Tx abnormal: ", e)

                if 0 == len(file_data):
                    print("File read error: length = 0")
                    break

                send_size += len(file_data)
                self.socket_handle.send(file_data)

        return 0


    def recv(self, file_path):
        data = self.socket_handle.recv(8).decode()
        self.socket_handle.send(config.trans_ack.encode())
        print("Rx file len:", data)

        file_size = int(data, 16)
        recv_size = 0

        with open(file_path, "wb") as file:
            while True:
                if (file_size == recv_size):
                    print("Rx success!")
                    return 1

                try:
                    if (file_size - recv_size) >= 1024:
                        file_data = self.socket_handle.recv(1024)
                    else:
                        file_data = self.socket_handle.recv(file_size - recv_size)
                except Exception as e:
                    print("Rx abnormal: ", e)

                if (len(file_data) == 0):
                    print("File read error: length = 0")
                    break

                recv_size += len(file_data)
                file.write(file_data)

        return 0
