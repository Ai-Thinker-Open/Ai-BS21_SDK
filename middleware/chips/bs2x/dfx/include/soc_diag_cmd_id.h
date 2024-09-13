/*
 * Copyright (c) @CompanyNameMagicTag 2020-2022. All rights reserved.
 * Description: DIAG - cmd id.
 */

#ifndef SOC_DIAG_CMD_ID_H
#define SOC_DIAG_CMD_ID_H

#define DIAG_MAINTENANCE_MODULE_ID      0x05

#define diag_cmd_id_comb(cmd_id)        (DIAG_MAINTENANCE_MODULE_ID << 8 | (cmd_id))

/* initialization and system related DIAG commands [0x00, 0x08] */
#define DIAG_CMD_HOST_CONNECT           diag_cmd_id_comb(0x00)
#define DIAG_CMD_HOST_DISCONNECT        diag_cmd_id_comb(0x01)
#define DIAG_CMD_CONNECT_RANDOM         diag_cmd_id_comb(0x02)
#define DIAG_CMD_CONNECT_M_CHECK        diag_cmd_id_comb(0x03)
#define DIAG_CMD_PWD_CHANGE             diag_cmd_id_comb(0x04)
#define DIAG_CMD_HEART_BEAT             diag_cmd_id_comb(0x05)
#define DIAG_CMD_REMOTE_TEST            diag_cmd_id_comb(0x06)
#define DIAG_CMD_SIMULATE_AT            diag_cmd_id_comb(0x07)
#define DIAG_CMD_MOCKED_SHELL           diag_cmd_id_comb(0x08)

/* os info cmd [0x09, 0x0C] */
#define DIAG_CMD_GET_CPUP               diag_cmd_id_comb(0x09)
#define DIAG_CMD_GET_MEM_INFO           diag_cmd_id_comb(0x0A)
#define DIAG_CMD_GET_RESOURCE_INFO      diag_cmd_id_comb(0x0B)
#define DIAG_CMD_GET_TASK_INFO          diag_cmd_id_comb(0x0C)

/* memory Operations cmd [0x0D, 0x12] */
#define DIAG_CMD_MEM_MEM32              diag_cmd_id_comb(0x0D)
#define DIAG_CMD_MEM_MEM16              diag_cmd_id_comb(0x0E)
#define DIAG_CMD_MEM_MEM8               diag_cmd_id_comb(0x0F)
#define DIAG_CMD_MEM_W1                 diag_cmd_id_comb(0x10)
#define DIAG_CMD_MEM_W2                 diag_cmd_id_comb(0x11)
#define DIAG_CMD_MEM_W4                 diag_cmd_id_comb(0x12)

/* DFX cmd 1 [0x13, 0x23] */
#define DIAG_CMD_ID_LAST_DUMP           diag_cmd_id_comb(0x13)
#define DIAG_CMD_ID_LAST_DUMP_FINISH    diag_cmd_id_comb(0x14)
#define DIAG_CMD_ID_LAST_WORD           diag_cmd_id_comb(0x15)
#define DIAG_CMD_DUMP_SYSERR            diag_cmd_id_comb(0x16)
#define DIAG_CMD_DUMP_SYSERR_MAX        diag_cmd_id_comb(0x17)
#define DIAG_CMD_ID_LAST_DUMP_START     diag_cmd_id_comb(0x18)
#define DIAG_CMD_ID_LAST_DUMP_END       diag_cmd_id_comb(0x19)

#define DIAG_CMD_TRACE_START            diag_cmd_id_comb(0x20)
#define DIAG_CMD_TRACE_STOP             diag_cmd_id_comb(0x21)
#define DIAG_CMD_GET_TIME               diag_cmd_id_comb(0x22)
#define DIAG_CMD_SET_TIME               diag_cmd_id_comb(0x23)

/* PQUI cmd [0x24, 0x2F] */
#define DIAG_CMD_AUDIO_HAID_REQ         diag_cmd_id_comb(0x24)
#define DIAG_CMD_AUDIO_SWS_EFFECT_REQ   diag_cmd_id_comb(0x25)
#define DIAG_CMD_AUDIO_SEE_EFFECT_REQ   diag_cmd_id_comb(0x26)

/* NV read and write commands [0x30, 0x33] */
#define DIAG_CMD_NV_RD                  diag_cmd_id_comb(0x30)
#define DIAG_CMD_NV_WR                  diag_cmd_id_comb(0x31)
#define DIAG_CMD_NV_RD_WITH_ATTR        diag_cmd_id_comb(0x32)
#define DIAG_CMD_NV_WR_WITH_ATTR        diag_cmd_id_comb(0x33)

/* sample related cmd [0x34, 0x3F] */
#define DIAG_CMD_ID_AUDIO_SAMPLE        diag_cmd_id_comb(0x38)
#define DIAG_CMD_ID_SAMPLE              diag_cmd_id_comb(0x39)
#define DIAG_CMD_ID_BGLE_SAMPLE         diag_cmd_id_comb(0x3A)
#define DIAG_CMD_ID_WLAN_SAMPLE         diag_cmd_id_comb(0x3B)
#define DIAG_CMD_ID_SOC_SAMPLE          diag_cmd_id_comb(0x3C)
#define DIAG_CMD_ID_SAMPLE_DATA         diag_cmd_id_comb(0x3D)
#define DIAG_CMD_ID_SAMPLE_FINISH       diag_cmd_id_comb(0x3E)
#define DIAG_CMD_ID_PHY_SAMPLE          diag_cmd_id_comb(0x3F)

/* DFX cmd 2 [0x40, 0x4F] */
#define DIAG_CMD_SIMULATE_AT_IND        diag_cmd_id_comb(0x40)
#define DIAG_CMD_MOCKED_SHELL_IND       diag_cmd_id_comb(0x41)
#define DIAG_CMD_CHANGE_UART_CONFIG     diag_cmd_id_comb(0x42)
#define DIAG_CMD_GET_UART_CONFIG        diag_cmd_id_comb(0x43)
#define DIAG_CMD_MOCKED_SHELL_ENABLE    diag_cmd_id_comb(0x44)
#define DIAG_CMD_SET_OFFLINE_LOG        diag_cmd_id_comb(0x45)
#define DIAG_CMD_GET_INIT_INFO          diag_cmd_id_comb(0x46)

/* audio cmd [0x4a, 0x55] */
#define DIAG_CMD_AUDIO_PROC_AI          diag_cmd_id_comb(0x4a)
#define DIAG_CMD_AUDIO_PROC_SEA         diag_cmd_id_comb(0x4b)
#define DIAG_CMD_AUDIO_PROC_ADEC        diag_cmd_id_comb(0x4c)
#define DIAG_CMD_AUDIO_PROC_AENC        diag_cmd_id_comb(0x4d)
#define DIAG_CMD_AUDIO_PROC_AO          diag_cmd_id_comb(0x4e)
#define DIAG_CMD_AUDIO_PROC_AB          diag_cmd_id_comb(0x4f)
#define DIAG_CMD_AUDIO_PROC_SYS         diag_cmd_id_comb(0x50)
#define DIAG_CMD_AUDIO_DUMP             diag_cmd_id_comb(0x51)
#define DIAG_CMD_AUDIO_PROBE            diag_cmd_id_comb(0x52)

/* DFX cmd 3 [0x56, 0x5F] */
#define DIAG_CMD_ID_DIAG_DFX_REQ        diag_cmd_id_comb(0x56)
#define DIAG_CMD_ID_DIAG_DFX_START      diag_cmd_id_comb(0x57)
#define DIAG_CMD_ID_DIAG_DFX_END        diag_cmd_id_comb(0x5E)
#define DIAG_CMD_ID_DBG_STAT_QUERY      diag_cmd_id_comb(0x5F)

/* MSG config [0x60, 0x69] */
#define DIAG_CMD_MSG_CFG_SET_SYS        diag_cmd_id_comb(0x60)
#define DIAG_CMD_MSG_CFG_SET_DEV        diag_cmd_id_comb(0x61)
#define DIAG_CMD_MSG_CFG_SET_USR        diag_cmd_id_comb(0x62)
#define DIAG_CMD_MSG_CFG_SET_AIR        diag_cmd_id_comb(0x63)
#define DIAG_CMD_MSG_CFG_SET_LEVEL      diag_cmd_id_comb(0x64)

/* NV cmd 2 [0x6A, 0x6F] */
#define DIAG_CMD_NV_GET_STORE_STATUS    diag_cmd_id_comb(0x6A)
#define DIAG_CMD_NV_BACKUP_ALL_KEYS     diag_cmd_id_comb(0x6B)
#define DIAG_CMD_NV_RESTORE_ALL_KEYS    diag_cmd_id_comb(0x6C)
#define DIAG_CMD_NV_GET_PAGE_USAGE      diag_cmd_id_comb(0x6D)
#define DIAG_CMD_NV_SET_RESTORE_FLAG    diag_cmd_id_comb(0x6E)

/* DFX cmd 4 [0x70, 0x7F] */
#define DIAG_CMD_UPDATE_PREPARE         diag_cmd_id_comb(0x70)
#define DIAG_CMD_UPDATE_REQUEST         diag_cmd_id_comb(0x71)
#define DIAG_CMD_UPDATE_START           diag_cmd_id_comb(0x72)
#define DIAG_CMD_UPDATE_GET_SIZE        diag_cmd_id_comb(0x74)
#define DIAG_CMD_LOG_FILE_CFG           diag_cmd_id_comb(0x76)
#define DIAG_CMD_LOG_FILE_CTRL          diag_cmd_id_comb(0x77)
#define DIAG_CMD_LOG_FILE_WRITE         diag_cmd_id_comb(0x78)

/* BT */
#define DIAG_CMD_ID_BT_DFT              diag_cmd_id_comb(0x80)

/* Charger */
#define DIAG_CMD_DEV_INIT               diag_cmd_id_comb(0x82)
#define DIAG_CMD_IOCTL_INIT             diag_cmd_id_comb(0x83)
#define DIAG_CMD_GET_SYS_STATUS         diag_cmd_id_comb(0x84)
#define DIAG_CMD_GET_PARAMETER          diag_cmd_id_comb(0x85)
#define DIAG_CMD_SET_PARAMETER          diag_cmd_id_comb(0x86)
#define DIAG_CMD_GET_ID                 diag_cmd_id_comb(0x87)
#define DIAG_CMD_GET_NAME               diag_cmd_id_comb(0x88)
#define DIAG_CMD_ENTER_SHIPMODE         diag_cmd_id_comb(0x89)

/* BTH DFX [0x90,0x9F] */
#define DIAG_CMD_ID_BT_DBG_POS          diag_cmd_id_comb(0x90)

/* report log cmd [0xF0, 0xFF] */
#define DIAG_CMD_MSG_RPT_SYS_EXTEND_LOG diag_cmd_id_comb(0xF9)
#define DIAG_CMD_MSG_RPT_LAYER          diag_cmd_id_comb(0xFA)
#define DIAG_CMD_MSG_RPT_USR            diag_cmd_id_comb(0xFB)
#define DIAG_CMD_MSG_RPT_AIR            diag_cmd_id_comb(0xFC)
#define DIAG_CMD_MSG_RPT_SYS_NORMAL_LOG diag_cmd_id_comb(0xFD)
#define DIAG_CMD_MSG_RPT_SYS_FULLY_LOG  diag_cmd_id_comb(0xFE)
#define DIAG_CMD_MSG_RPT_SYS_MINI_LOG   diag_cmd_id_comb(0xFF)

#define DIAG_CMD_MAX                    0x100

#ifdef USE_ZDIAG
#define DIAG_CMD_ID_TRANSMIT_REQUEST 0x03
#define DIAG_CMD_ID_TRANSMIT_REPLY   0x04
#define DIAG_CMD_ID_TRANSMIT_START   0x05
#define DIAG_CMD_ID_STATE_NOTIFY     0x06
#endif
#endif /* SOC_DIAG_CMD_ID_H */
