/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: At bt header \n
 * Author: @CompanyNameTag \n
 */

#ifndef AT_PORTING_H
#define AT_PORTING_H

#include "at.h"

/**
 * @brief  At switch to testsuite.
 * @param [in] None.
 */
at_ret_t uapi_at_sw_testsuite(void);

/**
 * @brief  Testsuite switch to At.
 * @param [in] None.
 */
int uapi_testsuite_sw_at(int argc, char **argv);

/**
 * @brief  At init.
 * @param [in] None.
 */
void uapi_at_cmd_init(void);

/**
 * @brief  Set At task Task Tcb id.
 * @param [in] at_task_id at task id.
 * @param [in] testsuite_task_id testsuite task id.
 */
void uapi_set_at_task(uint32_t *at_task_id);

/**
 * @brief  Register plt cmd table.
 * @param [in] cmd_tbl cmd table.
 * @param [in] cmd_num cmd num.
 */
uint32_t uapi_at_plt_register_cmd(const at_cmd_entry_t *cmd_tbl, uint16_t cmd_num);

/**
 * @brief  Register bt cmd table.
 * @param [in] cmd_tbl cmd table.
 * @param [in] cmd_num cmd num.
 */
uint32_t uapi_at_bt_register_cmd(const at_cmd_entry_t *cmd_tbl, uint16_t cmd_num);

/**
 * @brief  Get plt cmd table.
 * @param None
 */
const at_cmd_entry_t* uapi_get_plt_at_table(void);

/**
 * @brief  Get plt cmd table size.
 * @param None
 */
uint32_t uapi_get_plt_table_size(void);

/**
 * @brief  Get bt cmd table.
 * @param None
 */
const at_cmd_entry_t *uapi_get_bt_at_table(void);

/**
 * @brief  Get bt cmd table size.
 * @param None
 */
uint32_t uapi_get_bt_table_size(void);
#endif
