/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Flash boot dfu header \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2024-03-12, Create file. \n
 */
#ifndef USB_DFU_H
#define USB_DFU_H

#include "stdint.h"

int usb_dfu_init(void);
void usb_dfu_wait_ugrade_done_and_reset(uint32_t timeout_ms);
bool usb_dfu_is_upgrade_fail(void);
#endif
