
	.text
	.globl main
main:
		sw $fp, 0($sp)
		sw $ra, -4($sp)
		move $fp, $sp
		subu $sp, $sp, 48
		li $v1, 4
		move $s0, $v1
		move $a0, $s0
		jal _halloc
		move $s0, $v0
		move $s0, $s0
		li $v1, 4
		move $s1, $v1
		move $a0, $s1
		jal _halloc
		move $s1, $v0
		move $s1, $s1
		la $s2, Fac_ComputeFac
		sw $s2, 0($s0)
		sw $s0, 0($s1)
		move $s1, $s1
		lw $s0, 0($s1)
		lw $s0, 0($s0)
		li $v1, 10
		move $s2, $v1
		sw $t0, -8($fp)
		sw $t1, -12($fp)
		sw $t2, -16($fp)
		sw $t3, -20($fp)
		sw $t4, -24($fp)
		sw $t5, -28($fp)
		sw $t6, -32($fp)
		sw $t7, -36($fp)
		sw $t8, -40($fp)
		sw $t9, -44($fp)
		move $a0, $s1
		move $a1, $s2
		move $v0, $s0
		jalr $v0
		lw $t0, -8($fp)
		lw $t1, -12($fp)
		lw $t2, -16($fp)
		lw $t3, -20($fp)
		lw $t4, -24($fp)
		lw $t5, -28($fp)
		lw $t6, -32($fp)
		lw $t7, -36($fp)
		lw $t8, -40($fp)
		lw $t9, -44($fp)
		move $s2, $v0
		move $a0, $s2
		jal _print
		lw $ra, -4($fp)
		addu $sp, $sp, 48
		j $ra

	.text
	.globl Fac_ComputeFac
Fac_ComputeFac:
		sw $fp, 0($sp)
		sw $ra, -4($sp)
		move $fp, $sp
		subu $sp, $sp, 80
		sw $s0, -8($fp)
		sw $s1, -12($fp)
		sw $s2, -16($fp)
		sw $s3, -20($fp)
		sw $s4, -24($fp)
		sw $s5, -28($fp)
		sw $s6, -32($fp)
		sw $s7, -36($fp)
		move $s0, $a0
		move $s1, $a1
		li $v1, 0
		move $s2, $v1
		sle $v0, $s1, $s2
		move $s2, $v0
		beqz $s2, L2
		li $v1, 1
		move $s0, $v1
		move $s0, $s0
		b L3
L2:
		move $s2, $s0
		lw $s3, 0($s2)
		lw $s3, 0($s3)
		li $v1, 1
		move $s4, $v1
		sub $v0, $s1, $s4
		move $s4, $v0
		sw $t0, -40($fp)
		sw $t1, -44($fp)
		sw $t2, -48($fp)
		sw $t3, -52($fp)
		sw $t4, -56($fp)
		sw $t5, -60($fp)
		sw $t6, -64($fp)
		sw $t7, -68($fp)
		sw $t8, -72($fp)
		sw $t9, -76($fp)
		move $a0, $s2
		move $a1, $s4
		move $v0, $s3
		jalr $v0
		lw $t0, -40($fp)
		lw $t1, -44($fp)
		lw $t2, -48($fp)
		lw $t3, -52($fp)
		lw $t4, -56($fp)
		lw $t5, -60($fp)
		lw $t6, -64($fp)
		lw $t7, -68($fp)
		lw $t8, -72($fp)
		lw $t9, -76($fp)
		move $s4, $v0
		mul $v0, $s1, $s4
		move $s4, $v0
		move $s0, $s4
L3:
		move $v0, $s0
		lw $s0, -8($fp)
		lw $s1, -12($fp)
		lw $s2, -16($fp)
		lw $s3, -20($fp)
		lw $s4, -24($fp)
		lw $s5, -28($fp)
		lw $s6, -32($fp)
		lw $s7, -36($fp)
		lw $ra, -4($fp)
		lw $fp, 0($fp)
		addu $sp, $sp, 80
		j $ra

	.text
	.globl _halloc
_halloc:
		li $v0, 9
		syscall
		j $ra

	.text
	.globl _print
_print:
		li $v0, 1
		syscall
		la $a0, newl
		li $v0, 4
		syscall
		j $ra

		.data
		.align 0
newl:	.asciiz "\n"
