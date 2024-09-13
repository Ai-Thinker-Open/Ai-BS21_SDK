
	.osal_xip :
	{
	    . = ALIGN(8);
	    *libosal.a:*.o* (.text.oal_int_create .text.oal_int_delete \
	                     .text.osal_event_init  .text.osal_event_destroy \
	                     .text.osal_irq_request  .text.osal_irq_free  .text.osal_irq_set_priority \
	                     .text.osal_msg_queue_create .text.osal_msg_queue_delete \
	                     .text.osal_mutex_init .text.osal_mutex_destroy \
	                     .text.osal_sem_init .text.osal_sem_binary_sem_init .text.osal_sem_destroy \
	                     .text.osal_kthread_create .text.osal_kthread_destroy \
	                     .text.osal_timer_init .text.osal_timer_destroy)
	    . = ALIGN(8);
	} > FLASH_PROGRAM

	.drv_xip :
	{
	    . = ALIGN(8);
	    *i2c*.a:*.o*(.text.uapi_i2c_master_init .text.hal_i2c_*_master_init .text.hal_i2c_*_regs_init .text.hal_i2c_*_init_comp_param .text.i2c_port_register_irq \
	                  .text.uapi_i2c_deinit .text.hal_i2c_*_deinit)
	    *spi*.a:*.o* (.text.uapi_spi_init .text.hal_spi_regs_init .text.hal_spi_*_init .text.uapi_spi_deinit .text.hal_spi_v151_deinit)
	    *libpm_porting.a:*.o* (.text.ulp_rtc_init)
	    *libpm_sleep_porting.a:*.o* (.text.pm_wakeup_rtc_init .text.pm_port_sleep_config_int)
	    *libpm_dev.a:*.o* (.text.uapi_pm_register_dev_ops)
	    *libpm_sleep.a:*.o* (.text.uapi_pm_register_sleep_funcs)
	    *libpm_fsm.a:*.o* (.text.uapi_pm_register_fsm_handler)
	    *libpm_veto.a:*.o* (.text.uapi_pm_veto_init)
	    *libdfx_log.a:log.*.o* (.text.log_init .text.get_log_sn_number)
	    . = ALIGN(8);
	} > FLASH_PROGRAM

	.liteos_xip :
	{
	    . = ALIGN(8);
	    *libc.a:*.o* (.text.atoi .text.strtox .text.strtoull  .text.__shlim  .text.__shgetc .text.__uflow .text.__toread  .text.__errno_location)
	    *libc.a:*intscan* (.text .text* .rodata .rodata* .srodata .srodata*)
	    /* *libsegger.a:*.o*(.text .text* .rodata .rodata* .srodata .srodata*) */
	    *libgcc.a:*.o*(.rodata .rodata* .srodata .srodata*)
	    *libbase.a:*.o* (.text.LOS_EventInit .text.LOS_EventDestroy \
	                     .text.OsHwiInit .text.OsHwiDel* .text.LOS_HwiCreate .text.LOS_HwiDelete .text.LOS_HwiSetPriority \
	                     .text.OsMuxInit .text.LOS_MuxCreate .text.LOS_MuxDelete \
	                     .text.OsQueueInit .text.LOS_QueueCreate .text.LOS_QueueDelete \
	                     .text.OsSemInit .text.OsSemCreate .text.LOS_SemCreate .text.LOS_BinarySemCreate .text.LOS_SemDelete \
	                     .text.OsSwtmrInit .text.LOS_SwtmrStart .text.OsSwtmrStartTimer .text.OsSwtmrStart .text.LOS_SwtmrStop .text.LOS_SwtmrCreate .text.OsSwtmrDelete .text.LOS_SwtmrDelete \
	                     .text.OsTaskInit .text.OsPriQueueInit .text.OsTaskStackFree .text.LOS_TaskResRecycle \
	                     .text.OsTaskMonInit \
	                     .text.LOS_TaskCreate* .text.OsIdleTaskCreate .text.OsTaskDelete .text.LOS_TaskDelete \
	                     .text.LOS_TaskSuspend .text.LOS_TaskResume .text.LOS_TaskInfoGet .text.LOS_TaskPriSet \
	                     .text.OsTickInit \
	                     .text.OsMemSystemInit  .text.LOS_MemInit  .text.LOS_MemPoolInit .text.OsHeapInit  \
	                     .text.LOS_MemInfoGet .text.OsHeapStatisticsGet)
	     *libinterrupt.a:*.o* (.text.HalIrqVersion .rodata.HalIrqVersion.* .text.HalIrqInit .rodata.g_plicOps* .text.HalIrqSetPrio)
	     *libriscv.a:*.o* ( .text.ArchExcInit  .text.ArchSetExcHook  .text.ArchSetNMIHook \
	                        .text.OsExcInfoDisplay .rodata.OsExcInfoDisplay.* .rodata.g_xRegsMap .text.ArchTaskExit .text.ArchTaskStackInit)
	    . = ALIGN(8);
	} > FLASH_PROGRAM