/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description:  product config
 * Author: @CompanyNameTag
 * Create: 2021-06-16
 */
#ifndef PRODUCT_H
#define PRODUCT_H

#ifndef YES
#define YES (1)
#endif

#ifndef NO
#define NO (0)
#endif

#if (defined BS21_PRODUCT_NONE)
#define APPLICATION_VERSION_STRING "BS2X 1.0.12"
#include "product_none.h"
#endif

#if (defined BS21_PRODUCT_EVB)
#define APPLICATION_VERSION_STRING "BS2X 1.0.12"
#include "product_evb_standard.h"
#endif

#if (defined PRODUCT_TAG)
#define APPLICATION_VERSION_STRING "BS2X 1.0.12"
#include "product_tag.h"
#endif

#if (defined BS21_PRODUCT_HID)
#define APPLICATION_VERSION_STRING "BS2X 1.0.12"
#include "product_hid_common.h"
#if (defined VERSION_DEBUG)
#include "product_hid_debug.h"
#elif (defined VERSION_FACTORY)
#include "product_hid_factory.h"
#elif (defined VERSION_STANDARD)
#include "product_hid_standard.h"
#else
#include "product_hid_end_user.h"
#endif
#endif

#define TWS_EAR_WEAR_NOTICE_SUPP            NO
#define TWS_A2DP_TX_PWR_REDUCE_SUPP         NO
#define TWS_PAGE_TX_PWR_REDUCE_SUPP         NO
#define BT_EXIST                            NO
#define APP_EXIST                           YES
#define DSP_EXIST                           NO
#define DUAL_DSP_EXIST                      NO
#define GNSS_EXIST                          NO
#define SECURITY_EXIST                      NO
#define WIFI_EXIST                          NO
#define UWB_EXIST                           NO
#define NFC_EXIST                           NO
#define CORE_NUMS                           1
#define IPC_SHARE_NUMS                      0
#define OTP_SET_CLK_PERIOD                  NO
#define SHA512_EXIST                        YES
#define SM4_EXIST                           YES
#define SHA_LAST_PACKAGE_IS_BIG_ENDIAN      YES
#define OTP_FIRST_REGION_BITS               1024
#define OTP_SECOND_REGION_BITS              0
#define USE_PMU_WDT                         YES
#define SFC_FLASH_EXIST                     YES
#define SPI_FLASH_EXIST                     YES
#endif