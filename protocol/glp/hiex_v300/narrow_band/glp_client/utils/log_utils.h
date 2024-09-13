/*
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved.
 */
#ifndef LOG_UTILS_H
#define LOG_UTILS_H

#include <stdint.h>

#if (CHIP_BS21 || CHIP_BS21E)
#include "log_oam_logger.h"
#include "log_def.h"
#include "soc_diag_log.h"
#endif

#ifdef SIMULATOR
#include <stdio.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define UNUSED(var) do { (void)(var); } while (0)

#ifndef SIMULATOR

#if TARGET_CHIP_BS25
#define PRINT_NONE    LOG_LEVEL_NONE
#define PRINT_ERROR    LOG_LEVEL_ERROR
#define PRINT_WARNING    LOG_LEVEL_WARNING
#define PRINT_NORMAL    LOG_LEVEL_INFO
#endif

typedef enum {
    ERR_LEVEL = 1,
    WNG_LEVEL,
    INFO_LEVEL,
    DBG_LEVEL
} LogLevel;

/*
 * IMPORT:
 * this two Global variable can't be used external
 * just used by log macro defined here.
 */
extern LogLevel g_logLevel;

#define GLP_ERR_LOG0(fmt)                                          \
    do {                                                           \
        if (g_logLevel >= ERR_LEVEL) {                             \
            oml_glp_log_print0(LOG_LEVEL_ERROR, fmt); \
        }                                                          \
    } while (0)

#define GLP_ERR_LOG1(fmt, p1)                                          \
    do {                                                               \
        if (g_logLevel >= ERR_LEVEL) {                                 \
            oml_glp_log_print1(LOG_LEVEL_ERROR, fmt, p1); \
        }                                                              \
    } while (0)

#define GLP_ERR_LOG2(fmt, p1, p2)                                          \
    do {                                                                   \
        if (g_logLevel >= ERR_LEVEL) {                                     \
            oml_glp_log_print2(LOG_LEVEL_ERROR, fmt, p1, p2); \
        }                                                                  \
    } while (0)

#define GLP_ERR_LOG3(fmt, p1, p2, p3)                                          \
    do {                                                                       \
        if (g_logLevel >= ERR_LEVEL) {                                         \
            oml_glp_log_print3(LOG_LEVEL_ERROR, fmt, p1, p2, p3); \
        }                                                                      \
    } while (0)

#define GLP_ERR_LOG4(fmt, p1, p2, p3, p4)                                          \
    do {                                                                           \
        if (g_logLevel >= ERR_LEVEL) {                                             \
            oml_glp_log_print4(LOG_LEVEL_ERROR, fmt, p1, p2, p3, p4); \
        }                                                                          \
    } while (0)

#define GLP_ERR_LOG12(fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12)                                       \
    do {                                                                                                            \
        if (g_logLevel >= ERR_LEVEL) {                                                                              \
            oml_glp_log_print_alter(LOG_LEVEL_ERROR, fmt, 12, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, \
                p11, p12);                                                                                          \
        }                                                                                                           \
    } while (0)

#define GLP_WARNING_LOG0(fmt)                                        \
    do {                                                             \
        if (g_logLevel >= WNG_LEVEL) {                               \
            oml_glp_log_print0(LOG_LEVEL_WARNING, fmt); \
        }                                                            \
    } while (0)


#define GLP_WARNING_LOG1(fmt, p1)                                        \
    do {                                                                 \
        if (g_logLevel >= WNG_LEVEL) {                                   \
            oml_glp_log_print1(LOG_LEVEL_WARNING, fmt, p1); \
        }                                                                \
    } while (0)

#define GLP_WARNING_LOG2(fmt, p1, p2)                                        \
    do {                                                                     \
        if (g_logLevel >= WNG_LEVEL) {                                       \
            oml_glp_log_print2(LOG_LEVEL_WARNING, fmt, p1, p2); \
        }                                                                    \
    } while (0)


#define GLP_WARNING_LOG3(fmt, p1, p2, p3)                                        \
    do {                                                                         \
        if (g_logLevel >= WNG_LEVEL) {                                           \
            oml_glp_log_print3(LOG_LEVEL_WARNING, fmt, p1, p2, p3); \
        }                                                                        \
    } while (0)

#define GLP_WARNING_LOG4(fmt, p1, p2, p3, p4)                                        \
    do {                                                                             \
        if (g_logLevel >= WNG_LEVEL) {                                               \
            oml_glp_log_print4(LOG_LEVEL_WARNING, fmt, p1, p2, p3, p4); \
        }                                                                            \
    } while (0)

#define GLP_INFO_LOG0(fmt)                                          \
    do {                                                            \
        if (g_logLevel >= INFO_LEVEL) {                             \
            oml_glp_log_print0(LOG_LEVEL_INFO, fmt); \
        }                                                           \
    } while (0)


#define GLP_INFO_LOG1(fmt, p1)                                          \
    do {                                                                \
        if (g_logLevel >= INFO_LEVEL) {                                 \
            oml_glp_log_print1(LOG_LEVEL_INFO, fmt, p1); \
        }                                                               \
    } while (0)

#define GLP_INFO_LOG2(fmt, p1, p2)                                          \
    do {                                                                    \
        if (g_logLevel >= INFO_LEVEL) {                                     \
            oml_glp_log_print2(LOG_LEVEL_INFO, fmt, p1, p2); \
        }                                                                   \
    } while (0)

#define GLP_INFO_LOG3(fmt, p1, p2, p3)                                          \
    do {                                                                        \
        if (g_logLevel >= INFO_LEVEL) {                                         \
            oml_glp_log_print3(LOG_LEVEL_INFO, fmt, p1, p2, p3); \
        }                                                                       \
    } while (0)

#define GLP_INFO_LOG4(fmt, p1, p2, p3, p4)                                          \
    do {                                                                            \
        if (g_logLevel >= INFO_LEVEL) {                                             \
            oml_glp_log_print4(LOG_LEVEL_INFO, fmt, p1, p2, p3, p4); \
        }                                                                           \
    } while (0)

#define GLP_INFO_LOG5(fmt, p1, p2, p3, p4, p5)                                                  \
    do {                                                                                        \
        if (g_logLevel >= INFO_LEVEL) {                                                         \
            oml_glp_log_print_alter(LOG_LEVEL_INFO, fmt, 5, p1, p2, p3, p4, p5); \
        }                                                                                       \
    } while (0)

#define GLP_INFO_LOG6(fmt, p1, p2, p3, p4, p5, p6)                                                  \
    do {                                                                                            \
        if (g_logLevel >= INFO_LEVEL) {                                                             \
            oml_glp_log_print_alter(LOG_LEVEL_INFO, fmt, 6, p1, p2, p3, p4, p5, p6); \
        }                                                                                           \
    } while (0)

#define GLP_INFO_LOG7(fmt, p1, p2, p3, p4, p5, p6, p7)                                                  \
    do {                                                                                                \
        if (g_logLevel >= INFO_LEVEL) {                                                                 \
            oml_glp_log_print_alter(LOG_LEVEL_INFO, fmt, 7, p1, p2, p3, p4, p5, p6, p7); \
        }                                                                                               \
    } while (0)

#define GLP_INFO_LOG8(fmt, p1, p2, p3, p4, p5, p6, p7, p8)                                                  \
    do {                                                                                                    \
        if (g_logLevel >= INFO_LEVEL) {                                                                     \
            oml_glp_log_print_alter(LOG_LEVEL_INFO, fmt, 8, p1, p2, p3, p4, p5, p6, p7, p8); \
        }                                                                                                   \
    } while (0)

#define GLP_INFO_LOG9(fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9)                                                  \
    do {                                                                                                        \
        if (g_logLevel >= INFO_LEVEL) {                                                                         \
            oml_glp_log_print_alter(LOG_LEVEL_INFO, fmt, 9, p1, p2, p3, p4, p5, p6, p7, p8, p9); \
        }                                                                                                       \
    } while (0)

#define GLP_INFO_LOG11(fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)                                            \
    do {                                                                                                             \
        if (g_logLevel >= INFO_LEVEL) {                                                                              \
            oml_glp_log_print_alter(LOG_LEVEL_INFO, fmt, 11, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, \
                p11);                                                                                                \
        }                                                                                                            \
    } while (0)

#define GLP_INFO_LOG12(fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12)                                       \
    do {                                                                                                             \
        if (g_logLevel >= INFO_LEVEL) {                                                                              \
            oml_glp_log_print_alter(LOG_LEVEL_INFO, fmt, 12, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, \
                p11, p12);                                                                                           \
        }                                                                                                            \
    } while (0)


#define GLP_DBG_LOG0(fmt)                                           \
    do {                                                            \
        if (g_logLevel >= DBG_LEVEL) {                              \
            oml_glp_log_print0(LOG_LEVEL_DBG, fmt); \
        }                                                           \
    } while (0)

#define GLP_DBG_LOG1(fmt, p1)                                           \
    do {                                                                \
        if (g_logLevel >= DBG_LEVEL) {                                  \
            oml_glp_log_print1(LOG_LEVEL_DBG, fmt, p1); \
        }                                                               \
    } while (0)

#define GLP_DBG_LOG2(fmt, p1, p2)                                           \
    do {                                                                    \
        if (g_logLevel >= DBG_LEVEL) {                                      \
            oml_glp_log_print2(LOG_LEVEL_DBG, fmt, p1, p2); \
        }                                                                   \
    } while (0)

#define GLP_DBG_LOG3(fmt, p1, p2, p3)                                           \
    do {                                                                        \
        if (g_logLevel >= DBG_LEVEL) {                                          \
            oml_glp_log_print3(LOG_LEVEL_DBG, fmt, p1, p2, p3); \
        }                                                                       \
    } while (0)

#define GLP_DBG_LOG4(fmt, p1, p2, p3, p4)                                           \
    do {                                                                            \
        if (g_logLevel >= DBG_LEVEL) {                                              \
            oml_glp_log_print4(LOG_LEVEL_DBG, fmt, p1, p2, p3, p4); \
        }                                                                           \
    } while (0)

#define GLP_DBG_LOG5(fmt, p1, p2, p3, p4, p5)                                                  \
    do {                                                                                            \
        if (g_logLevel >= DBG_LEVEL) {                                                             \
            oml_glp_log_print_alter(LOG_LEVEL_DBG, fmt, 5, p1, p2, p3, p4, p5); \
        }                                                                                           \
    } while (0)

#define GLP_DBG_LOG6(fmt, p1, p2, p3, p4, p5, p6)                                                  \
    do {                                                                                            \
        if (g_logLevel >= DBG_LEVEL) {                                                             \
            oml_glp_log_print_alter(LOG_LEVEL_DBG, fmt, 6, p1, p2, p3, p4, p5, p6); \
        }                                                                                           \
    } while (0)

#define GLP_DBG_LOG7(fmt, p1, p2, p3, p4, p5, p6, p7)                                                  \
    do {                                                                                            \
        if (g_logLevel >= DBG_LEVEL) {                                                             \
            oml_glp_log_print_alter(LOG_LEVEL_DBG, fmt, 7, p1, p2, p3, p4, p5, p6, p7); \
        }                                                                                           \
    } while (0)

#define GLP_DBG_LOG8(fmt, p1, p2, p3, p4, p5, p6, p7, p8)                                        \
    do {                                                                                                             \
        if (g_logLevel >= DBG_LEVEL) {                                                                               \
            oml_glp_log_print_alter(LOG_LEVEL_DBG, fmt, 8, p1, p2, p3, p4, p5, p6, p7, p8); \
        }                                                                                                            \
    } while (0)

#define GLP_DBG_LOG9(fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9)                                        \
    do {                                                                                                             \
        if (g_logLevel >= DBG_LEVEL) {                                                                               \
            oml_glp_log_print_alter(LOG_LEVEL_DBG, fmt, 9, p1, p2, p3, p4, p5, p6, p7, p8, p9); \
        }                                                                                                            \
    } while (0)

#define GLP_DBG_LOG11(fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)                                        \
    do {                                                                                                             \
        if (g_logLevel >= DBG_LEVEL) {                                                                               \
            oml_glp_log_print_alter(LOG_LEVEL_DBG, fmt, 11, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, \
                p11);                                                                                           \
        }                                                                                                            \
    } while (0)

#define GLP_DBG_LOG12(fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12)                                        \
    do {                                                                                                             \
        if (g_logLevel >= DBG_LEVEL) {                                                                               \
            oml_glp_log_print_alter(LOG_LEVEL_DBG, fmt, 12, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, \
                p11, p12);                                                                                           \
        }                                                                                                            \
    } while (0)

#else

#define GLP_WARNING_LOG0(fmt) printf(fmt "\r\n")
#define GLP_WARNING_LOG1(fmt, p1) printf(fmt "\r\n", p1)
#define GLP_WARNING_LOG2(fmt, p1, p2) printf(fmt "\r\n", p1, p2)

#define GLP_ERR_LOG0(fmt) printf(fmt "\r\n")
#define GLP_ERR_LOG1(fmt, p1) printf(fmt "\r\n", p1)
#define GLP_ERR_LOG2(fmt, p1, p2) printf(fmt "\r\n", p1, p2)
#define GLP_ERR_LOG3(fmt, p1, p2, p3) printf(fmt "\r\n", p1, p2, p3)
#define GLP_ERR_LOG4(fmt, p1, p2, p3, p4) printf(fmt "\r\n", p1, p2, p3, p4)
#define GLP_ERR_LOG12(fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12) \
    printf(fmt "\r\n", p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12)

#define GLP_INFO_LOG0(fmt) printf(fmt "\r\n")
#define GLP_INFO_LOG1(fmt, p1) printf(fmt "\r\n", p1)
#define GLP_INFO_LOG2(fmt, p1, p2) printf(fmt "\r\n", p1, p2)
#define GLP_INFO_LOG3(fmt, p1, p2, p3) printf(fmt "\r\n", p1, p2, p3)
#define GLP_INFO_LOG4(fmt, p1, p2, p3, p4) printf(fmt "\r\n", p1, p2, p3, p4)
#define GLP_INFO_LOG5(fmt, p1, p2, p3, p4, p5) printf(fmt "\r\n", p1, p2, p3, p4, p5)
#define GLP_INFO_LOG6(fmt, p1, p2, p3, p4, p5, p6) printf(fmt "\r\n", p1, p2, p3, p4, p5, p6)
#define GLP_INFO_LOG7(fmt, p1, p2, p3, p4, p5, p6, p7) printf(fmt "\r\n", p1, p2, p3, p4, p5, p6, p7)
#define GLP_INFO_LOG8(fmt, p1, p2, p3, p4, p5, p6, p7, p8) printf(fmt "\r\n", p1, p2, p3, p4, p5, p6, p7, p8)
#define GLP_INFO_LOG9(fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9) printf(fmt "\r\n", p1, p2, p3, p4, p5, p6, p7, p8, p9)
#define GLP_INFO_LOG11(fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11) \
    printf(fmt "\r\n", p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)
#define GLP_INFO_LOG12(fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12) \
    printf(fmt "\r\n", p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12)

#define GLP_DBG_LOG0(fmt) printf(fmt "\r\n")
#define GLP_DBG_LOG1(fmt, p1) printf(fmt "\r\n", p1)
#define GLP_DBG_LOG2(fmt, p1, p2) printf(fmt "\r\n", p1, p2)
#define GLP_DBG_LOG3(fmt, p1, p2, p3) printf(fmt "\r\n", p1, p2, p3)
#define GLP_DBG_LOG4(fmt, p1, p2, p3, p4) printf(fmt "\r\n", p1, p2, p3, p4)
#define GLP_DBG_LOG5(fmt, p1, p2, p3, p4, p5) printf(fmt "\r\n", p1, p2, p3, p4, p5)
#define GLP_DBG_LOG6(fmt, p1, p2, p3, p4, p5, p6) printf(fmt "\r\n", p1, p2, p3, p4, p5, p6)
#define GLP_DBG_LOG7(fmt, p1, p2, p3, p4, p5, p6, p7) printf(fmt "\r\n", p1, p2, p3, p4, p5, p6, p7)
#define GLP_DBG_LOG8(fmt, p1, p2, p3, p4, p5, p6, p7, p8) printf(fmt "\r\n", p1, p2, p3, p4, p5, p6, p7, p8)
#define GLP_DBG_LOG9(fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9) printf(fmt "\r\n", p1, p2, p3, p4, p5, p6, p7, p8, p9)
#define GLP_DBG_LOG11(fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11) \
    printf(fmt "\r\n", p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)
#define GLP_DBG_LOG12(fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12) \
    printf(fmt "\r\n", p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12)

#endif

#ifdef __cplusplus
}
#endif

#endif
