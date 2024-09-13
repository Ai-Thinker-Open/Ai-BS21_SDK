#!/usr/bin/env python3
# coding: utf-8
# Copyright (c) CompanyNameMagicTag. 2023-2023. All rights reserved.

import argparse
import sys
import re
import hmac
from Crypto.Cipher import AES


def get_parameters(argv):

    parser = argparse.ArgumentParser()

    parser.add_argument('--gid', type=str, required=True,
        help='eFuse中的GID, 64位十六进制字符串, 例: \"0102030405060708090A0B0C0D0E0F101112131415161718191A1B1C1D1E1F20\"')
    parser.add_argument('--iter', type=int, default=1024,
        help='密钥派生迭代次数ITER, 默认1024次，取值范围[1000, 65535]')
    parser.add_argument('--salt', type=str, required=True,
        help='密钥派生用的盐值SALT, 32位十六进制串, 安全随机数, 例: \"5AB7CD2BA2B3CCFD98C7DFE0BB365F0D\"')
    parser.add_argument('--plaintext', type=str, required=True,
        help='待加密的明文字符串, 要求传入十六进制串, 长度32位对齐，不超过8092字符')
    parser.add_argument('--iv', type=str, required=True,
        help='加密用的初始向量IV, 32位十六进制串, 安全随机数, 例: \"5AB7CD2BA2B3CCFD98C7DFE0BB365F0D\"')

    args = parser.parse_args(argv)
    return args


def is_hexadecimal(string):
    pattern = re.compile(r'^[0-9a-fA-F]*$')
    return bool(pattern.match(string))


def check_parameters(args):
    if len(args.gid) != 64:
        raise Exception('GID长度应该为64位')
    if len(args.salt) != 32:
        raise Exception('盐值长度应该为32位')
    if len(args.iv) != 32:
        raise Exception('IV长度应该为32位')

    text_len = len(args.plaintext)
    if (text_len % 32) != 0:
        raise Exception('明文字符串长度应该为32的整数倍')
    if text_len > 8192:
        raise Exception('明文字符串长度不能超过8192字符')

    if is_hexadecimal(args.gid) == False:
        raise Exception('GID应该为十六进制字符串')
    if is_hexadecimal(args.salt) == False:
        raise Exception('盐值应该为十六进制字符串')
    if is_hexadecimal(args.iv) == False:
        raise Exception('IV应该为十六进制字符串')
    if is_hexadecimal(args.plaintext) == False:
        raise Exception('明文字符串应该为十六进制字符串')
    if args.iter < 1000 or args.iter > 65535:
        raise Exception('迭代次数取值范围[1000, 65535]')
    pass


def key_deriv(gid, salt, iter=1024):
    deriv_param = salt
    ki = gid
    ko = '00' * 32

    for i in range(1, iter + 1):
        m = "{}{}{}{}00".format(ko, hex(i)[2:].zfill(8), deriv_param, hex(iter)[2:].zfill(4))
        ko = hmac.new(bytes.fromhex(ki), bytes.fromhex(m), 'sha256').hexdigest()

    return ko[-32:]


if __name__ == '__main__':
    args = get_parameters(sys.argv[1:])

    try:
        check_parameters(args)
    except Exception as e:
        print('[ERROR] {}'.format(e))
        exit()

    aes_key = key_deriv(args.gid, args.salt, args.iter)
    aes_obj = AES.new(bytes.fromhex(aes_key), AES.MODE_CBC, bytes.fromhex(args.iv))

    ciphertext = aes_obj.encrypt(bytes.fromhex(args.plaintext))
    print('[cipher text]: {}'.format(bytes.hex(ciphertext).upper()))
