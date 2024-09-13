/*
 * Copyright (c) CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: USB HID Class.
 * Author:  CompanyNameTag
 * Create:  2021-08-19
 */
#ifndef USBD_HID_H
#define USBD_HID_H

#include <stdint.h>
#include <stdbool.h>

bool usb_hid_send_report(uint8_t *data, uint16_t length, uint8_t interface_index);

#endif