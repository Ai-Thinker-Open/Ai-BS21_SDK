/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: dump by name struct
 * This file should be changed only infrequently and with great care.
 */
#ifndef __ZDIAG_CMD_DUMP_BY_NAME_ST_H__
#define __ZDIAG_CMD_DUMP_BY_NAME_ST_H__

#include <stdint.h>

typedef struct {
    uint32_t offset;
    uint32_t size; /* ext_dump_id  */
} diag_dump_item_t;

typedef struct {
    uint32_t len;                 /* strlen(path+file)+1 */
    char name[128];          /* 固定128 */
    uint32_t cnt;                 /* item个数 */
    diag_dump_item_t item[0]; /*  */
} diag_dump_by_name_cmd_t;

typedef struct {
    uint32_t ret;
    uint32_t offset;     /* 偏移 */
    uint32_t size;       /* 大小 */
    uint8_t data[0]; /* 内容 */
} diag_dump_by_name_ind_t;

#endif
