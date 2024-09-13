/*
 * Copyright (c) CompanyNameMagicTag 2023-2023. All rights reserved.
 * Description: USB HID Mouse driver.
 * Author:  CompanyNameTag
 * Create:  2023-03-29
 */
#ifndef USBD_HID_MOUSE_H
#define USBD_HID_MOUSE_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Registe dynamic report descriptor.
 * @param report_desc Reporter description.
 * @param lenth Length of reporter description.
 * @return True if success, otherwise false.
 */
bool usb_hid_mouse_register_report_desc(uint8_t *report_desc, uint16_t lenth);

#endif