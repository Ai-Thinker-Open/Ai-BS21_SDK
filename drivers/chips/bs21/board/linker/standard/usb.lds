
SECTIONS
{
    .usb_ramtext :
    {
        /* usb code */
        . = ALIGN(8);
        *(.text.ArchAtomicInc* .text.fhid_send_data* .text.dwc_otg_core_ep_complete* .text.LOS_AtomicInc* .text.LOS_SpinUnlockRestore* .text.LOS_IntLock* .text.LOS_SpinUnlockRestore* .text.LOS_SpinLockSave* .text.udc_interrupt* .text.ArchAtomicDec* .text.LOS_SpinLockSave* .text.usb_dma_cache_flush* .text.endpoint_arg_set* .text.LOS_AtomicDec* .text.hid_release_lock* .text.LOS_IntRestore* .text.check_and_add_hid_operations_count* .text.handle_normal_endpoint* .text.fhid_input_req_complete* .text.hid_write_data* .text.usbd_ep_queue* .text.dwc_otg_common_irq* .text.dwc_otg_ep_start_transfer* .text.hid_acquire_lock* .text.hid_submit_data* .text.dwc_otg_irq* .text.sub_hid_operations_count* .text.dwc_otg_pcd_irq* .text.dwc_otg_ep_req_start* .text.ArchWrite32* .text.ArchRead32* .text.usb_dma_cache_invalid* .text.DWC_MODIFY_REG32* .text.DWC_WRITE_REG32* .text.DWC_READ_REG32* .text.dwc_otg_epn_start_transfer* .text.handle_in_endpoint_intr*)
        *(.text.mouse_sensor_cb* .text.dongle_cb* .text.mouse_cb* .text.paw3395_get_xy* .text.mouse_spi_burst_read*)
        . = ALIGN(32);
    }  > ITCM AT > FLASH_PROGRAM
}