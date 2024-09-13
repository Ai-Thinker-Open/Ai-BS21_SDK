/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: file operation
 * This file should be changed only infrequently and with great care.
 */
#ifndef __DFX_FILE_OPERATION_H__
#define __DFX_FILE_OPERATION_H__

#include "errcode.h"
#include "stdbool.h"
#include "dfx_feature_config.h"
#include "common_def.h"

typedef struct {
    bool is_dir;
    const char *name;
    uint32_t file_size;
} dfx_file_ls_node_info_t;

typedef void (*dfx_file_report_node_hook)(dfx_file_ls_node_info_t *info, uintptr_t usr_data);
#if CONFIG_DFX_SUPPORT_FILE_SYSTEM == DFX_YES
errcode_t dfx_file_ls(const char *ls_path, dfx_file_report_node_hook handler, uintptr_t usr_data);
errcode_t dfx_file_delete(const char *path);
int32_t dfx_file_mkdir(const char *path);
errcode_t dfx_file_rmdir(const char *path);
int32_t dfx_file_write(const char *path, unsigned offset, const uint8_t *buf, uint32_t size);
int32_t dfx_file_read(const char *path, uint32_t offset, uint8_t *buf, uint32_t size);
int32_t dfx_file_open_for_read(const char *path);
int32_t dfx_file_read_fd(int32_t fd, uint32_t offset, uint8_t *buf, uint32_t size, bool burst);
int32_t dfx_file_open_for_write(const char *path);
int32_t dfx_file_open_for_rewrite(const char *path);
int32_t dfx_file_write_fd(int fd, unsigned offset, const uint8_t *buf, uint32_t size);
void dfx_file_fsync(int32_t fd);
void dfx_file_close(int32_t fd);

#else
static inline errcode_t dfx_file_ls(const char *ls_path, dfx_file_report_node_hook handler,
    uintptr_t usr_data)
{
    unused(ls_path);
    unused(handler);
    unused(usr_data);
    return ERRCODE_NOT_SUPPORT;
}

static inline errcode_t dfx_file_delete(const char *path)
{
    unused(path);
    return ERRCODE_NOT_SUPPORT;
}

static inline int32_t dfx_file_write(const char *path, unsigned offset, const uint8_t *buf, uint32_t size)
{
    unused(path);
    unused(offset);
    unused(buf);
    unused(size);

    return ERRCODE_NOT_SUPPORT;
}
static inline int32_t dfx_file_read(const char *path, uint32_t offset, uint8_t *buf, uint32_t size)
{
    unused(path);
    unused(offset);
    unused(buf);
    unused(size);

    return ERRCODE_NOT_SUPPORT;
}
static inline int32_t dfx_file_open_for_read(const char *path)
{
    unused(path);
    return ERRCODE_NOT_SUPPORT;
}

static inline int32_t dfx_file_open_for_write(const char *path)
{
    unused(path);
    return ERRCODE_NOT_SUPPORT;
}

static inline int32_t dfx_file_open_for_rewrite(const char *path)
{
    unused(path);
    return ERRCODE_NOT_SUPPORT;
}

static inline int32_t dfx_file_mkdir(const char *path)
{
    unused(path);
    return ERRCODE_NOT_SUPPORT;
}

static inline errcode_t dfx_file_rmdir(const char *path)
{
    unused(path);
    return ERRCODE_NOT_SUPPORT;
}

static inline int32_t dfx_file_read_fd(int32_t fd, uint32_t offset, uint8_t *buf, uint32_t size, bool burst)
{
    unused(fd);
    unused(offset);
    unused(buf);
    unused(size);
    unused(burst);
    return ERRCODE_NOT_SUPPORT;
}

static inline int32_t dfx_file_write_fd(int fd, unsigned offset, const uint8_t *buf, uint32_t size)
{
    unused(fd);
    unused(offset);
    unused(buf);
    unused(size);
    return ERRCODE_NOT_SUPPORT;
}

static inline void dfx_file_fsync(int32_t fd)
{
    unused(fd);
    return;
}

static inline void dfx_file_close(int32_t fd)
{
    unused(fd);
    return;
}

#endif /* CONFIG_DFX_SUPPORT_FILE_SYSTEM == DFX_YES */
#endif /* __TRANSMIT_FILE_OPERATION_H__ */
