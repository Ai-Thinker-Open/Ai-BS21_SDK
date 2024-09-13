/*
 * Copyright (c) @CompanyNameMagicTag. 2021-2022. All rights reserved.
 * Description: Common part of the OSAL kernel osal_test.c
 */
#ifndef OSAL_TEST_H
#define OSAL_TEST_H

#include "soc_osal.h"
#include "securec.h"
#include "string.h"

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#define TIME_MS_10   10
#define TIME_MS_20   20
#define TIME_MS_30   30
#define TIME_MS_50   50
#define TIME_MS_100  100
#define TIME_MS_150  150
#define TIME_MS_200  200
#define TIME_MS_300  300
#define TIME_MS_500  500
#define TIME_MS_1000  1000
#define MIN_STACK_SIZE 1024

#define osal_test_log(fmt, ...) osal_printk("[OSAL TEST: %s:%d]:" fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__)

#define osal_test_fail_log(fmt, ...) \
    osal_printk("\033[0;31m[OSAL TEST: %s:%d]:" fmt "\033[0m", __FUNCTION__, __LINE__, ##__VA_ARGS__)

#define expect_eq(a, b)                                            \
if ((a) != (b)) {                                                 \
    OSAL_TEST_FAIL_LOG("FAILED! actually:0x%x, expect:0x%x\n", a, b);  \
}

#define expect_neq(a, b)                                           \
if ((a) == (b)) {                                                 \
    OSAL_TEST_FAIL_LOG("FAILED! actually:0x%x, expect:0x%x\n", a, b);  \
}

#define expect_streq(_str1, _str2, _cnt)                         \
if (memcmp((_str1), (_str2), (_cnt)) != 0) {                     \
    OSAL_TEST_FAIL_LOG("FAILED! str1:%s, str2:%s.\n", _str1, _str2);  \
}

void osal_test(void);

#endif
