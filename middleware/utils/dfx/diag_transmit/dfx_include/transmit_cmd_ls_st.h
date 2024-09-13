/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: cmd ls struct
 * This file should be changed only infrequently and with great care.
 */
#ifndef TRANSMIT_CMD_LS_ST_H
#define TRANSMIT_CMD_LS_ST_H

#include <stdint.h>

typedef struct {
    uint32_t dir_len;    /* strlen(path) + 1 */
    uint8_t path[0];     /* 路径名称，要带结束符 */
} diag_ls_cmd_t;

typedef struct {
    uint16_t idx;           /* 序号:是否丢失 */
    uint8_t  path_len;      /* strlen(file_name)+1 */
    uint8_t  file_type;     /* 类型：文件为0 文件夹为1 */
    uint32_t file_size;     /* 文件大小 */
    uint8_t file_name[0];   /* 文件名 */
} diag_ls_ind_t;

#endif /* TRANSMIT_CMD_LS_ST_H */
