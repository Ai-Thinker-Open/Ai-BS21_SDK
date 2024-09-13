#!/usr/bin/env python3
# coding: utf-8
# Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.


class Properties:

    def __init__(self, filename):
        self.filename = filename
        pass


    def get_properties(self):
        properties = {}
        with open(self.filename, 'r') as f:
            for line in f:
                cmd = line.split('#')[0]
                if '=' not in cmd:
                    continue

                key, value = cmd.strip(' ').split('=')
                key = key.strip(' ')
                value = value.strip(' ')
                value = value.strip('\n')
                value = value.strip('\r')
                value = value.strip(' ')

                if (len(value) == 0):
                    continue

                properties[key] = value

        return properties


    def set_properties(self, properties):
        with open(self.filename, 'r') as cfg_file:
            lines = cfg_file.readlines()

        replace_lines = ''
        for line in lines:
            command = line.split('#')[0]
            if '=' not in command:
                replace_lines += line
                continue

            key, value = command.strip(' ').split('=')
            key = key.strip(' ')
            value = value.strip(' ')
            value = value.strip('\n')
            value = value.strip('\r')
            value = value.strip(' ')

            if (len(value) == 0):
                replace_lines += line
                continue

            if key in properties:
                if '#' in line:
                    comment = line.split('#')[1]
                    comment = comment.strip('\n')
                    comment = comment.strip('\r')
                    line = '{}={}    #{}\n'.format(key, properties[key], comment)
                else:
                    line = '{}={}\n'.format(key, properties[key])
            replace_lines += line

        with open(self.filename, 'w') as cfg_file:
            cfg_file.write(replace_lines)

