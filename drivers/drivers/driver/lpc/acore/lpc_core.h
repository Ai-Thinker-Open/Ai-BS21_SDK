/*
 * Copyright (c) @CompanyNameMagicTag 2018-2020. All rights reserved.
 * Description:  LPC CORE SPECIFIC HEADER
 * Author: @CompanyNameTag
 * Create:  2018-10-15
 */

#ifndef NON_OS_LPC_CORE_H
#define NON_OS_LPC_CORE_H

#include "lpc.h"

/** @addtogroup connectivity_drivers_non_os_lpc
  * @{
  */
/** Low Power Sleep Id */
typedef enum {
    LPC_ID_A2B,     /* !< APP communicate witch BCPU */
    LPC_ID_A2D,     /* !< APP communicate witch DCPU */
    LPC_ID_PLT,     /* !< PLT */
    LPC_ID_RESERVE, /* !< RESERVE */
    LPC_ID_MAX,     /* !< MAX */
} lpc_sleep_id_e;

typedef struct {
    uint16_t lpc_sleep_vetos;
    uint32_t lr_pointer;
} lpc_veto_type;

/** Low Power Sleep Configurations State */
typedef enum {
    LPC_CONFIGURATION_DEEP_SLEEP,  /* !< Standard configuration for Deep Sleep */
    LPC_CONFIGURATION_LIGHT_SLEEP, /* !< Standard configuration for Light Sleep */
    LPC_CONFIGURATION_WORK,        /* !< Standard configuration for Working On */
    LPC_CONFIGUEATION_VAD,
    LPC_CONFIGUEATION_MAD,
    LPC_CONFIGURATION_MAX,         /* !< Standard configuration for States Max */
} lpc_work_states_e;

typedef void (*lpc_fsm_callback_handler)(void);

/**
 * @brief  Add a callback to the handler array. Called whenever the registered FSM handler.
 * @param  id The ID register handler.
 * @param  state The state on callback handler.
 * @param  handler The handler.
 */
void lpc_fsm_callback_register_handler(lpc_sleep_id_e id, lpc_work_states_e state, lpc_fsm_callback_handler handler);

/**
 * @brief  The callback handler that on the id and config.
 * @param  id The ID register handler.
 * @param  config The config about sleep config.
 */
void lpc_work_state_callback(lpc_sleep_id_e id, lpc_work_states_e config);

/**
  * @brief  Add a veto for the sleep function.
  * If any sleep veto has been added (and not removed) the sleep functions
  * will not try to go to sleep and they will just return.
  * To remove a sleep veto the lpc_remove_sleep_veto() must be used.
  * @note   The limit of sleep vetos is UINT16_MAX, any aditional veto is ignored.
  */
void lpc_sys_sleep_veto(lpc_sleep_id_e sys_id);

/**
 * @brief  Remove a veto for the sleep function previously added using lpc_sys_sleep_veto().
 * @note   The atempt to remove vetos if there is none will be ignored.
 */
void lpc_sys_remove_sleep_veto(lpc_sleep_id_e sys_id);

/**
 * @brief  Gets the current value of the LPC sleep count veto on sys_id.
 * @return The current value of the LPC sleep count veto
 */
uint16_t lpc_get_id_sleep_veto(lpc_sleep_id_e sys_id);

/**
 * @brief  Gets the latest lr attached to the veto on sys_id.
 * @return The latest lr attached to the veto
 */
uint32_t lpc_get_id_sleep_lr(lpc_sleep_id_e sys_id);

/**
 * @brief  Gets the current value of the LPC sleep count veto.
 * @return The current value of the LPC sleep count veto
 */
uint32_t lpc_get_sleep_veto(void);

/**
  * @brief  Add a veto for mcpu i2c, prevent m7 to enter sleep and power off i2c clock.
  * If any sleep veto has been added (and not removed) the sleep functions
  * will not try to go to sleep and they will just return.
  * To remove a sleep veto the lpc_mcpu_i2c_remove_sleep_veto() must be used.
  * @note   The limit of sleep vetos is UINT32_MAX, any aditional veto is ignored.
  */
void lpc_mcpu_i2c_sleep_veto(void);

/**
 * @brief  Remove a veto for the sleep function previously added using lpc_mcpu_i2c_sleep_veto().
 * @note   The atempt to remove vetos if there is none will be ignored.
 */
void lpc_mcpu_i2c_remove_sleep_veto(void);

/**
 * @brief  Gets the current value of the mcpu i2c sleep count veto.
 * @return The current value of the mcpu i2c sleep count veto.
 */
uint32_t lpc_get_mcpu_i2c_sleep_veto(void);

/**
  * @brief  Add a veto for mcpu mprep, prevent m7 to enter sleep and power off mcpu mprep clock.
  * If any sleep veto has been added (and not removed) the sleep functions
  * will not try to go to sleep and they will just return.
  * To remove a sleep veto the lpc_mcpu_mprep_remove_sleep_veto() must be used.
  * @note   The limit of sleep vetos is UINT32_MAX, any aditional veto is ignored.
  */
void lpc_mcpu_mprep_sleep_veto(void);

/**
 * @brief  Remove a veto for the sleep function previously added using lpc_mcpu_mprep_remove_sleep_veto().
 * @note   The atempt to remove vetos if there is none will be ignored.
 */
void lpc_mcpu_mprep_remove_sleep_veto(void);

/**
 * @brief  Gets the current value of the mcpu mprep sleep count veto.
 * @return The current value of the mcpu mprep sleep count veto
 */
uint32_t lpc_get_mcpu_mprep_sleep_veto(void);

/**
 * @brief  Trigger security core Perform specific actions after waking up from sleep
 * @note   Interrupts will have been disabled before this function is called
 */
void lpc_wakeup_trigger(void);

/**
 * @brief  Set the default and common configuration
 */
void lpc_core_init_configuration(void);

/**
 * @brief  Gets the current value of the mcpu sleep veto information.
 */
volatile lpc_veto_type *lpc_get_sys_sleep_veto(void);

/**
  * @}
  */
#endif
