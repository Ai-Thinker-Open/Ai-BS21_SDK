/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * Description: zdiag ind producer
 * This file should be changed only infrequently and with great care.
 */
#ifndef DIAG_IND_SRC_H
#define DIAG_IND_SRC_H

#include "errcode.h"
#include "diag_common.h"
#include "diag.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

typedef struct {
    uint8_t *packet;
    uint16_t packet_size;
} diag_report_sys_msg_packet;

typedef struct {
    uint8_t **packet;
    uint16_t *packet_size;
    uint8_t pkt_cnt;
} diag_report_packet;

typedef struct {
    uint32_t sn;        /* SN序列号 */
    uint8_t level;      /* 日志级别，参见soc_diag_log.h */
    bool sn_enable;     /* SN序列号是否由外部指定。true -- 指定为sn值; flase -- 由函数内部设置序列号 */
    bool sync;          /* 日志是否同步输出。true -- 直接输出至UART， false -- 发送至DFX线程处理 */
} diag_msg_attr_t;

errcode_t uapi_diag_report_packet_direct(uint16_t cmd_id, diag_option_t *option, const uint8_t *packet,
    uint16_t packet_size);

errcode_t uapi_diag_report_sys_msg_common(uint32_t module_id, uint32_t msg_id, const uint8_t *packet,
    uint16_t packet_size, diag_msg_attr_t *msg_attr);

errcode_t uapi_zdiag_report_sys_msg_instance(uint32_t module_id, uint32_t msg_id, const uint8_t *packet,
    uint16_t packet_size, uint8_t level);

errcode_t uapi_zdiag_report_sys_msg_instance_sn(uint32_t module_id, uint32_t msg_id,
    diag_report_sys_msg_packet *report_sys_msg_packet, uint8_t level, uint32_t sn);

errcode_t uapi_diag_report_sys_msg_to_buffer(uint32_t module_id, uint32_t msg_id, const uint8_t *packet,
    uint16_t packet_size, uint8_t level);

errcode_t uapi_diag_report_sys_msg_from_buffer(uint8_t *buf, uint16_t buf_size, bool proc_async);

#if (defined CONFIG_DFX_SUPPORT_CUSTOM_LOG) && (CONFIG_DFX_SUPPORT_CUSTOM_LOG == DFX_YES)
errcode_t uapi_zdiag_report_sys_msg_custom(uint32_t msg_id, uint32_t src_mod, uint32_t dst_mod,
    diag_report_sys_msg_packet *report_sys_msg_packet, uint8_t level);
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* DIAG_IND_SRC_H */
