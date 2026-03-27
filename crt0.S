        .title "crt0.S for m68k bare metal - PC relative application"

        /* A bunch of variables supplied by the linker */
        .extern _bss_start
        .extern _bss_end
        .extern main

        .section .text
        .align 2
        .byte 0x7c
        .ascii "load"
        .byte 0xfd, 0xc4, 0x55
        .type _start, @function
        .globl _start
_start:
        nop
        nop
        nop
        
        /* Jump to main() */
1:      jmp     main

        .ascii " L 0.01\0"
        .ascii "  FREE SOFTWARE WITHOUT ANY WARRANTY 2026  \0"
        .byte 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00

        .end
