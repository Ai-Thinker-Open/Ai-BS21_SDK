/*
 * Copyright (c) @CompanyNameMagicTag 2018-2020. All rights reserved.
 * Description:  LPC HEADER
 * Author: @CompanyNameTag
 * Create:  2018-10-15
 */
#ifndef NON_OS_LPC_H
#define NON_OS_LPC_H

#include "std_def.h"

/** @defgroup connectivity_drivers_non_os_lpc LPC
  * @ingroup  connectivity_drivers_non_os
  * @{
  */
/**
 * @brief  System sleep mode.
 */
typedef enum {
    LPC_SLEEP_MODE_LIGHT,  /*!< System light sleep mode. */
    LPC_SLEEP_MODE_DEEP,   /*!< System deep sleep mode. */
} lpc_sleep_mode_e;

/**
 * @brief  Initialises the Low Power controller
 */
void lpc_init(void);

/**
 * @brief  Add a veto for the sleep function.
 * If any sleep veto has been added (and not removed) the sleep functions
 * will not try to go to sleep and they will just return.
 * To remove a sleep veto the lpc_remove_sleep_veto() must be used.
 * @note   The limit of sleep vetos is UINT16_MAX, any aditional veto is ignored.
 */
void lpc_add_sleep_veto(void);

/**
 * @brief  Remove a veto for the sleep function previously added using lpc_add_sleep_veto().
 * @note   The atempt to remove vetos if there is none will be ignored.
 */
void lpc_remove_sleep_veto(void);

/**
 * @brief  Add a veto for the deep sleep function.
 * If any deep sleep veto has been added (and not removed) the sleep functions
 * will try to go to light sleep in stead of deep
 * sleep.
 * To remove a sleep veto the lpc_remove_deep_sleep_veto() must be used.
 * @note   The limit of sleep deep vetos is UINT16_MAX, any aditional veto is ignored.
 */
void lpc_add_deep_sleep_veto(void);

/**
 * @brief  Remove a deep sleep veto previously added using lpc_add_deep_sleep_veto().
 * @note   The atempt to remove vetos if there is none will be ignored.
 */
void lpc_remove_deep_sleep_veto(void);

/**
 * @brief  Deinitialise the Low Power Controller.
 */
void lpc_deinit(void);

/**
 * @brief  Adds a timer to be used for waking us up from sleep.
 * @param  period_in_ms The time to keep sleeping.
 */
void lpc_start_wakeup_timer(uint32_t period_in_ms);

/**
 * @brief  Enter Wait for interrupt state by wfi.
 */
void lpc_enter_wfi(void);

/**
 * @brief  Set the system sleep mode which can be light or deep.
 * @param  mode The mode of sleep.
 */
void lpc_set_sleep_mode(lpc_sleep_mode_e mode);

/**
  * @}
  */
#endif
