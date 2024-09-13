/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: cmd delete file struct
 * This file should be changed only infrequently and with great care.
 */
#ifndef TRANSMIT_CMD_DEL_FILE_ST_H
#define TRANSMIT_CMD_DEL_FILE_ST_H

#include <stdint.h>

typedef struct {
    uint16_t dir_len;   /* strlen(name)+1 */
    uint8_t rev;        /* 保留字段 */
    uint8_t file_type;  /* 类型：文件为0 文件夹为1 */
    uint8_t name[0];    /* 文件名，要带结束符 */
} diag_del_cmd_t;

typedef struct {
    uint32_t ret_value;
} diag_del_ind_t;

#endif /* TRANSMIT_CMD_DEL_FILE_ST_H */
