
.align 4
.section .text
.extern stack
.global _start
_start:
	la t0, stack
	li t1, 4096
	add sp, t0,t1
	call main
_spin:
	wfi
	j _spin
