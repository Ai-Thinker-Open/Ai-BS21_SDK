usage: sec_tool.py [-h] --gid GID [--iter ITER] --salt SALT --plaintext
                   PLAINTEXT --iv IV

options:
  -h, --help            show this help message and exit
  --gid GID             eFuse中的GID, 64位的十六进制字符串, 例: "0102030405060708090A0B0C0D0E0F101112131415161718191A1B1C1D1E1F20"
  --iter ITER           密钥派生迭代次数, 默认1024次.
  --salt SALT           密钥派生用的盐值, 32位的十六进制串, 安全随机数, 例: "5AB7CD2BA2B3CCFD98C7DFE0BB365F0D"
  --plaintext PLAINTEXT 待加密的明文字符串, 要求传入十六进制串, 长度32位对齐.
  --iv IV               加密用的初始向量, 32位的十六进制串, 安全随机数, 例: "5AB7CD2BA2B3CCFD98C7DFE0BB365F0D"
