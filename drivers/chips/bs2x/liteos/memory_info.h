/*
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved.
 * Description:  LiteOs Heap and Stack info
 * Author: @CompanyNameTag
 * Create: 2022-09-27
 */
#ifndef MEMORY_INFO_H
#define MEMORY_INFO_H

#define MEMORY_INFO_CRTL_REG 0x52000010
#define MEMORY_INFO_CLOSE 0x5a

void print_os_task_id_and_name(void);

/**
 * @brief  Print LiteOs stack info.
*/
void print_stack_waterline_riscv(void);

/**
 * @brief  Print LiteOs heap info.
*/
void print_heap_statistics_riscv(void);

void print_os_sys_task_heap(uint8_t taskid);

void print_os_all_sys_task_heap(void);

void print_os_dfx_info(void);
/**
 * @}
 */
#endif