/******************************************************************************
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: runtime adapter \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-04-10, Create file. \n
 ******************************************************************************/

#ifndef __RUNTIME_MONITOR_H
#define __RUNTIME_MONITOR_H

#include "los_typedef.h"

/* define the system status check interval  */
#define STATUS_CHECK_INTERVAL           5000        /* 5s */
#define STATUS_CHECK_MAX_FAIL_COUNT     6           /* 30s */

#define SET_SYS_READY       1
#define SET_SYS_SLEEP       0

typedef enum tagSysStatus {
    SYS_START_ERR = -1,
    SYS_OS_READY = 0,
    SYS_INIT = 1,
    SYS_FPGA_DOWNLOAD,
    SYS_READY,
    SYS_STANDBY,
    SYS_SLEEP,
    SYS_POWERDOWN,
}SYS_STATUS;

typedef enum tagMonitorTask {
#if (CORE == APPS)
    MON_TASK_BEGIN = 0,

    /* APP TASKS BEGIN */
    MON_TASK_RPC = MON_TASK_BEGIN,          /* rpc_main */
    MON_TASK_AGING,                         /* aging_test_task */
    MON_TASK_APP,                           /* app_task */
    MON_TASK_BASIC_SENSOR,                  /* basic_sensor_task */
    MON_TASK_COMMU,                         /* commu_task */
    MON_TASK_DEVICE_MISC,                   /* device_misc_task */
    MON_TASK_FORWARD,                       /* forward_task */
    MON_TASK_FILE_RTAN,                     /* file_tran_task */
    MON_TASK_OTA,                           /* protocol_task */
    MON_TASK_GESTURE,                       /* gesture_task */
    MON_TASK_MAINTENANCE,                   /* maintenance_task */
    MON_TASK_MANUFACTURE,                   /* manufacture_task */
    MON_TASK_POWER,                         /* power_task */
    MON_TASK_SYS,                           /* sys_task */
    MON_TASK_UX,                            /* ux_task */
    MON_TASK_WEAR,                          /* wear_task */
    MON_TASK_BT_DEVICE,                     /* bt_task */
    MON_TASK_AUDIO,                         /* audio_thread_task */
    MON_TASK_SENSOR_DATA,                   /* sensors_data_task */

    MON_TASK_BTC,
    MON_TASK_BTH_INIT,
    MON_TASK_BTH_RPC,
    MON_TASK_BTH_GDK,
    MON_TASK_BTH_SDK,
    MON_TASK_BTH_MSG,

#if (APP_BTN_TASK_MONITOR_ENABLE == YES)
    MON_TASK_BUTTON,                        /* button_task */
#endif
    MON_TASK_LOG,
    /* APP TASKS END */
    MON_TASK_END,
#else
    MON_TASK_BEGIN = 0,
    MON_TASK_BT_DEMO = MON_TASK_BEGIN,
    MON_TASK_RPC,
    MON_TASK_BTC,
    MON_TASK_BTH_INIT,
    MON_TASK_BTH_RPC,
    MON_TASK_BTH_GDK,
    MON_TASK_BTH_SDK,
    MON_TASK_BTH_MSG,
#if (BTH_WITH_SMART_WEAR == YES)
    MON_TASK_BTV_BT_TRAN,
    MON_TASK_BTV_A2DP_SERVICE,
#endif
    MON_TASK_END,
#endif
}MONITOR_TASK_ID_E;

VOID runtime_monitor_init(VOID);
VOID osTskMonBegin(UINT32 uwMailID);
VOID osTskMonEnd(UINT32 uwMailID);
void statuscheck_timer_callback(void);
void SysProcCallback(void);
void RuntimeMonitorTimerStop(void);
void RuntimeMonitorTimerStart(void);

#endif
