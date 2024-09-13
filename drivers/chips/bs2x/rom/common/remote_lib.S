        .option norelax
        .option norvc
        .global rl_driver_deinit

rl_driver_deinit:
        /* set driver data section */
        la      t0, __driver_data_begin__
        la      t1, __driver_data_load__
        la      t2, __driver_data_size__
        beq     t2, x0, end_set_driver_data_loop
set_driver_data_loop:
        lw      t3, (t1)
        sw      t3, (t0)
        addi    t0, t0, 4
        addi    t1, t1, 4
        addi    t2, t2, -4
        blt     x0, t2, set_driver_data_loop
end_set_driver_data_loop:
        /* clear driver bss section */
        la      t0, __driver_bss_begin__
        la      t1, __driver_bss_end__
        beq     t0, t1, end_clear_driver_bss_loop
        li      t2, 0x00000000
clear_driver_bss_loop:
        sw      t2, (t0)
        addi    t0, t0, 4
        blt     t0, t1, clear_driver_bss_loop
end_clear_driver_bss_loop:
        ret


