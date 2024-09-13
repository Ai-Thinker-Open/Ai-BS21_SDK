#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
#===============================================================================

/**
 * @brief  This is the code that gets called when the processor first
 *          starts execution following a reset event. Only the absolutely
 *          necessary set is performed, after which the application
 *          supplied main() routine is called.
 * @param  None
 * @retval : None
*/
        .extern TrapVector
        .section .text.entry
        .global _start
        .option norvc
_start:
        j Reset_Handler

Reset_Handler:
        la      t0, TrapVector
        csrw    mtvec, t0
        csrwi   mstatus, 0
        csrwi   mie, 0

        .option push
        .option norelax
        /* initialize global pointer */
        la      gp, _gp_
        .option pop

        # initialize stack pointer
        la      sp, __stack_top__

#ifdef STACK_DEBUG
        /* init stack */
        la      t0, g_system_stack_begin
        la      t1, g_system_stack_end
        beq     t0, t1, end_set_stack_loop
        li      t2, 0xCACACACA

set_stack_loop:
        sw      t2, (t0)
        addi    t0, t0, 4
        blt     t0, t1, set_stack_loop
        li      t2, 0xCCCCCCCC
        la      t0, g_system_stack_begin
        sw      t2, (t0)
        la      t0, __stack_top__
        sw      t2, (t0)
        la      t0, __irq_stack_top__
        sw      t2, (t0)
        la      t0, __excp_stack_top__
        sw      t2, (t0)
end_set_stack_loop:
#endif
        /* set data section */
        la      t0, __data_begin__
        la      t1, __data_load__
        PREFD   0(t1)
        la      t2, __data_size__
        beq     t2, x0, end_set_data_loop

set_data_loop:
        ldmia   {a4-a7, t3-t6}, (t1)
        addi    t1, t1, 32
        PREFD   0(t1)
        stmia  {a4-a7, t3-t6}, (t0)
        addi    t0, t0, 32
        addi    t2, t2, -32
        blt     x0, t2, set_data_loop
end_set_data_loop:

        /* setup .ramtext section */
        la      t0, __ramtext_begin__
        la      t1, __ramtext_load__
        PREFD   0(t1)
        la      t2, __ramtext_size__
        beq     t2, x0, end_set_ramtext_loop

set_ramtext_loop:
        ldmia   {a4-a7, t3-t6}, (t1)
        addi    t1, t1, 32
        PREFD   0(t1)
        stmia  {a4-a7, t3-t6}, (t0)
        addi    t0, t0, 32
        addi    t2, t2, -32
        blt     x0, t2, set_ramtext_loop
end_set_ramtext_loop:

        /* setup .patch_data section */
        la      t0, __patch_data_begin__
        la      t1, __patch_data_load__
        PREFD   0(t1)
        la      t2, __patch_data_size__
        beq     t2, x0, end_set_patch_data_loop

set_patch_data_loop:
        ldmia   {a4-a7, t3-t6}, (t1)
        addi    t1, t1, 32
        PREFD   0(t1)
        stmia   {a4-a7, t3-t6}, (t0)
        addi    t0, t0, 32
        addi    t2, t2, -32
        blt     x0, t2, set_patch_data_loop
end_set_patch_data_loop:

end_set_romtext_loop:

        /* clear rombss section */
        la      t0, __rombss_begin__
        la      t1, __rombss_end__
        beq     t0, t1, end_clear_rombss_loop
        li      t2, 0x00000000

clear_rombss_loop:
        sw      t2, (t0)
        addi    t0, t0, 4
        blt     t0, t1, clear_rombss_loop
end_clear_rombss_loop:

        /* clear romram_bss section */
        la      t0, __romram_bss_begin__
        la      t1, __romram_bss_end__
        beq     t0, t1, end_clear_romram_bss_loop
        li      t2, 0x00000000

clear_romram_bss_loop:
        sw      t2, (t0)
        addi    t0, t0, 4
        blt     t0, t1, clear_romram_bss_loop
end_clear_romram_bss_loop:

        /* clear bss section */
        la      t0, __bss_begin__
        la      t1, __bss_end__
        beq     t0, t1, end_clear_bss_loop
        li      t2, 0x00000000

clear_bss_loop:
        sw      t2, (t0)
        addi    t0, t0, 4
        blt     t0, t1, clear_bss_loop
end_clear_bss_loop:

#ifdef CONFIG_ULTRA_DEEP_SLEEP_ENABLE

        lui     t0, 0x5702C
        lhu     t0, 1792(t0)
        bnez    t0, end_clear_retention_bss_loop

retention_copy:
        /* setup .retention_text section */
        la      t0, __retention_text_begin__
        la      t1, __retention_text_load__
        PREFD   0(t1)
        la      t2, __retention_text_size__
        beq     t2, x0, end_set_retention_data_loop

set_retention_loop:
        ldmia   {a4-a7, t3-t6}, (t1)
        addi    t1, t1, 32
        PREFD   0(t1)
        stmia  {a4-a7, t3-t6}, (t0)
        addi    t0, t0, 32
        addi    t2, t2, -32
        blt     x0, t2, set_retention_loop
end_set_retention_loop:

        /* setup .romtext section */
        la      t0, __romtext_begin__
        la      t1, __romtext_load__
        la      t2, __romtext_size__
        beq     t2, x0, end_set_romtext_loop
set_romtext_loop:
        lw      t3, (t1)
        sw      t3, (t0)
        addi    t0, t0, 4
        addi    t1, t1, 4
        addi    t2, t2, -4
        blt     x0, t2, set_romtext_loop

        /* setup .retention_data section */
        la      t0, __retention_data_begin__
        la      t1, __retention_data_load__
        PREFD   0(t1)
        la      t2, __retention_data_size__
        beq     t2, x0, end_set_retention_data_loop

set_retention_data_loop:
        ldmia   {a4-a7, t3-t6}, (t1)
        addi    t1, t1, 32
        PREFD   0(t1)
        stmia  {a4-a7, t3-t6}, (t0)
        addi    t0, t0, 32
        addi    t2, t2, -32
        blt     x0, t2, set_retention_data_loop

end_set_retention_data_loop:

        /* clear .retention_bss section */
        la      t0, __retention_bss_begin__
        la      t1, __retention_bss_end__
        beq     t0, t1, end_clear_retention_bss_loop
        li      t2, 0x00000000

clear_retention_bss_loop:
        sw      t2, (t0)
        addi    t0, t0, 4
        blt     t0, t1, clear_retention_bss_loop
end_clear_retention_bss_loop:
#else
        /* setup .romtext section */
        la      t0, __romtext_begin__
        la      t1, __romtext_load__
        la      t2, __romtext_size__
        beq     t2, x0, end_set_romtext_loop
set_romtext_loop:
        lw      t3, (t1)
        sw      t3, (t0)
        addi    t0, t0, 4
        addi    t1, t1, 4
        addi    t2, t2, -4
        blt     x0, t2, set_romtext_loop
#endif

        li      t0, 0x00006000
        csrs    mstatus, t0
        fssr    x0
        la t0, main
        jr t0
