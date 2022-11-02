.text
.globl main
main:
sw $fp, -8($sp)
move $fp, $sp
subu $sp, $sp, 48
sw $ra, -4($fp)
li $s0, 4
move $a0, $s0
jal _halloc
move $s1, $v0
li $s2, 0
sw $s2, 0($s1)
li $s0, 4
move $a0, $s0
jal _halloc
move $s0, $v0
la $s2, Caller_Start
sw $s2, 0($s0)
sw $s0, 0($s1)
lw $v0, 0($s1)
move $s2, $v0
lw $v0, 0($s2)
move $s2, $v0
move $a0, $s1
sw $t0, -12($fp)
sw $t1, -16($fp)
sw $t2, -20($fp)
sw $t3, -24($fp)
sw $t4, -28($fp)
sw $t5, -32($fp)
sw $t6, -36($fp)
sw $t7, -40($fp)
sw $t8, -44($fp)
sw $t9, -48($fp)
jalr $s2
lw $t9, -48($fp)
lw $t8, -44($fp)
lw $t7, -40($fp)
lw $t6, -36($fp)
lw $t5, -32($fp)
lw $t4, -28($fp)
lw $t3, -24($fp)
lw $t2, -20($fp)
lw $t1, -16($fp)
lw $t0, -12($fp)
move $s0, $v0
move $a0, $s0
jal _print
lw $ra, -4($fp)
lw $fp, -8($fp)
addu $sp, $sp, 48
j $ra
.text
.globl A_get
A_get:
sw $fp, -8($sp)
move $fp, $sp
subu $sp, $sp, 40
sw $ra, -4($fp)
sw $s0, -12($fp)
sw $s1, -16($fp)
sw $s2, -20($fp)
sw $s3, -24($fp)
sw $s4, -28($fp)
sw $s5, -32($fp)
sw $s6, -36($fp)
sw $s7, -40($fp)
move $s0, $a0
lw $v0, 4($s0)
move $s1, $v0
li $s0, 0
sne $s0, $s1, $s0
beqz $s0, A_get_L1
li $s0, 1
move $s0, $s0
b A_get_L2
A_get_L1:
li $s1, 0
move $s0, $s1
A_get_L2:
nop
move $v0, $s0
lw $s7, -40($fp)
lw $s6, -36($fp)
lw $s5, -32($fp)
lw $s4, -28($fp)
lw $s3, -24($fp)
lw $s2, -20($fp)
lw $s1, -16($fp)
lw $s0, -12($fp)
lw $ra, -4($fp)
lw $fp, -8($fp)
addu $sp, $sp, 40
j $ra
.text
.globl B_set
B_set:
sw $fp, -8($sp)
move $fp, $sp
subu $sp, $sp, 40
sw $ra, -4($fp)
sw $s0, -12($fp)
sw $s1, -16($fp)
sw $s2, -20($fp)
sw $s3, -24($fp)
sw $s4, -28($fp)
sw $s5, -32($fp)
sw $s6, -36($fp)
sw $s7, -40($fp)
move $s1, $a0
lw $v0, 4($s1)
move $s0, $v0
move $v1, $s0
li $s0, 1
sw $s0, 4($s1)
lw $v0, 4($s1)
move $s0, $v0
move $v0, $s0
lw $s7, -40($fp)
lw $s6, -36($fp)
lw $s5, -32($fp)
lw $s4, -28($fp)
lw $s3, -24($fp)
lw $s2, -20($fp)
lw $s1, -16($fp)
lw $s0, -12($fp)
lw $ra, -4($fp)
lw $fp, -8($fp)
addu $sp, $sp, 40
j $ra
.text
.globl C_reset
C_reset:
sw $fp, -8($sp)
move $fp, $sp
subu $sp, $sp, 40
sw $ra, -4($fp)
sw $s0, -12($fp)
sw $s1, -16($fp)
sw $s2, -20($fp)
sw $s3, -24($fp)
sw $s4, -28($fp)
sw $s5, -32($fp)
sw $s6, -36($fp)
sw $s7, -40($fp)
move $s1, $a0
lw $v0, 4($s1)
move $s0, $v0
move $v1, $s0
li $s0, 0
sw $s0, 4($s1)
lw $v0, 4($s1)
move $s0, $v0
move $v0, $s0
lw $s7, -40($fp)
lw $s6, -36($fp)
lw $s5, -32($fp)
lw $s4, -28($fp)
lw $s3, -24($fp)
lw $s2, -20($fp)
lw $s1, -16($fp)
lw $s0, -12($fp)
lw $ra, -4($fp)
lw $fp, -8($fp)
addu $sp, $sp, 40
j $ra
.text
.globl Caller_Start
Caller_Start:
sw $fp, -8($sp)
move $fp, $sp
subu $sp, $sp, 80
sw $ra, -4($fp)
sw $s0, -12($fp)
sw $s1, -16($fp)
sw $s2, -20($fp)
sw $s3, -24($fp)
sw $s4, -28($fp)
sw $s5, -32($fp)
sw $s6, -36($fp)
sw $s7, -40($fp)
move $v1, $a0
li $s0, 8
move $a0, $s0
jal _halloc
move $s1, $v0
li $s2, 0
sw $s2, 0($s1)
sw $s2, 4($s1)
li $s0, 4
move $a0, $s0
jal _halloc
move $s3, $v0
la $s4, A_get
sw $s4, 0($s3)
sw $s3, 0($s1)
move $v1, $s1
li $s2, 8
move $a0, $s2
jal _halloc
move $s3, $v0
li $s1, 0
sw $s1, 0($s3)
sw $s1, 4($s3)
li $s2, 8
move $a0, $s2
jal _halloc
move $s4, $v0
la $s0, B_set
sw $s0, 4($s4)
la $s0, A_get
sw $s0, 0($s4)
sw $s4, 0($s3)
move $s3, $s3
li $s1, 8
move $a0, $s1
jal _halloc
move $s4, $v0
li $s5, 0
sw $s5, 0($s4)
sw $s5, 4($s4)
li $s1, 12
move $a0, $s1
jal _halloc
move $s0, $v0
la $s2, C_reset
sw $s2, 8($s0)
la $s2, B_set
sw $s2, 4($s0)
la $s2, A_get
sw $s2, 0($s0)
sw $s0, 0($s4)
move $s0, $s4
lw $v0, 0($s3)
move $s1, $v0
lw $v0, 4($s1)
move $s1, $v0
move $a0, $s3
sw $t0, -44($fp)
sw $t1, -48($fp)
sw $t2, -52($fp)
sw $t3, -56($fp)
sw $t4, -60($fp)
sw $t5, -64($fp)
sw $t6, -68($fp)
sw $t7, -72($fp)
sw $t8, -76($fp)
sw $t9, -80($fp)
jalr $s1
lw $t9, -80($fp)
lw $t8, -76($fp)
lw $t7, -72($fp)
lw $t6, -68($fp)
lw $t5, -64($fp)
lw $t4, -60($fp)
lw $t3, -56($fp)
lw $t2, -52($fp)
lw $t1, -48($fp)
lw $t0, -44($fp)
move $s2, $v0
move $v1, $s2
lw $v0, 0($s0)
move $s1, $v0
lw $v0, 8($s1)
move $s1, $v0
move $a0, $s0
sw $t0, -44($fp)
sw $t1, -48($fp)
sw $t2, -52($fp)
sw $t3, -56($fp)
sw $t4, -60($fp)
sw $t5, -64($fp)
sw $t6, -68($fp)
sw $t7, -72($fp)
sw $t8, -76($fp)
sw $t9, -80($fp)
jalr $s1
lw $t9, -80($fp)
lw $t8, -76($fp)
lw $t7, -72($fp)
lw $t6, -68($fp)
lw $t5, -64($fp)
lw $t4, -60($fp)
lw $t3, -56($fp)
lw $t2, -52($fp)
lw $t1, -48($fp)
lw $t0, -44($fp)
move $s5, $v0
move $v1, $s5
lw $v0, 0($s3)
move $s1, $v0
lw $v0, 0($s1)
move $s1, $v0
move $a0, $s3
sw $t0, -44($fp)
sw $t1, -48($fp)
sw $t2, -52($fp)
sw $t3, -56($fp)
sw $t4, -60($fp)
sw $t5, -64($fp)
sw $t6, -68($fp)
sw $t7, -72($fp)
sw $t8, -76($fp)
sw $t9, -80($fp)
jalr $s1
lw $t9, -80($fp)
lw $t8, -76($fp)
lw $t7, -72($fp)
lw $t6, -68($fp)
lw $t5, -64($fp)
lw $t4, -60($fp)
lw $t3, -56($fp)
lw $t2, -52($fp)
lw $t1, -48($fp)
lw $t0, -44($fp)
move $s1, $v0
move $a0, $s1
jal _print
lw $v0, 0($s0)
move $s1, $v0
lw $v0, 0($s1)
move $s1, $v0
move $a0, $s0
sw $t0, -44($fp)
sw $t1, -48($fp)
sw $t2, -52($fp)
sw $t3, -56($fp)
sw $t4, -60($fp)
sw $t5, -64($fp)
sw $t6, -68($fp)
sw $t7, -72($fp)
sw $t8, -76($fp)
sw $t9, -80($fp)
jalr $s1
lw $t9, -80($fp)
lw $t8, -76($fp)
lw $t7, -72($fp)
lw $t6, -68($fp)
lw $t5, -64($fp)
lw $t4, -60($fp)
lw $t3, -56($fp)
lw $t2, -52($fp)
lw $t1, -48($fp)
lw $t0, -44($fp)
move $s0, $v0
move $a0, $s0
jal _print
li $s1, 1
move $v0, $s1
lw $s7, -40($fp)
lw $s6, -36($fp)
lw $s5, -32($fp)
lw $s4, -28($fp)
lw $s3, -24($fp)
lw $s2, -20($fp)
lw $s1, -16($fp)
lw $s0, -12($fp)
lw $ra, -4($fp)
lw $fp, -8($fp)
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
.align   0
newl:    .asciiz "\n"
.data
.align   0
str_er:  .asciiz " ERROR: abnormal termination\n"
