/**
 * Copyright (c) @CompanyNameMagicTag 2022-2024. All rights reserved. \n
 *
 * Description: Application core main function for standard \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-07-27, Create file. \n
 */
#include "main_init.h"
#include "chip_io.h"

/*
 *  芯片初始化入口。
 *  芯片初始化信息请参考：drivers/chips/bs2x/main_init/main_init.c main_init函数。
 *  软件线程初始化请参考：drivers/chips/bs2x/main_init/app_os_init.c app_os_init函数。
 */

void main(const void *startup_details_table)
{
    UNUSED(startup_details_table);
    main_init();
}
