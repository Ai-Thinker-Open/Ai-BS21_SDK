#ifndef __DEMO_H_
#define __DEMO_H_
#include "common_def.h"
#include "soc_osal.h"
#include "app_init.h"
#include "pinctrl.h"
#include "hal_gpio.h"
#include "osal_addr.h"
#include "osal_debug.h"
#include "cmsis_os2.h"
#include "securec.h"
#include "errcode.h"
#include "uart.h"
#include "bts_def.h"
#include "bts_gatt_stru.h"
#include "bts_gatt_server.h"
#include "bts_le_gap.h"
#include "bts_gatt_server.h"
#include "bts_le_gap.h"
#include "gpio.h"
#include "pinctrl.h"
#include "adc.h"
#include "adc_porting.h"
#include "common_def.h"
#include "soc_osal.h"
#include "app_init.h"
#include "chip_io.h" 
#include "securec.h"
#include "osal_debug.h"
#include "gadget/f_hid.h"
#include "keyscan.h"
#include "keyscan_porting.h"
#ifdef __DEMO_C_
    #define DEMO_EXT
#else
    #define DEMO_EXT extern
#endif

#endif
