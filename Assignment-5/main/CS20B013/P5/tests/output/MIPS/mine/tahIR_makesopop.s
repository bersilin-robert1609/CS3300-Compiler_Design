.text
.globl main
main:
sw $fp, -8($sp)
move $fp, $sp
subu $sp, $sp, 48
sw $ra, -4($fp)
la $s0, rnad_1
li $s1, 1
li $v1, 2
li $s2, 12
move $a0, $s2
jal _halloc
move $s3, $v0
sw $s2, 0($s3)
move $s2, $s2
li $s4, 13
move $a0, $s1
move $a1, $s3
move $a2, $s2
move $a3, $s4
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
jalr $s0
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
sw $s0, 4($s3)
lw $v0, 0($s3)
move $s0, $v0
lw $v0, 4($s3)
move $s1, $v0
add $s2, $s0, $s1
sw $s2, 8($s3)
move $a0, $s3
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
jalr rnad_2
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
move $s2, $v0
sle $s3, $s0, $s1
move $s3, $s3
move $a0, $s3
jal _print
sne $s3, $s0, $s1
move $s3, $s3
move $a0, $s3
jal _print
sub $s3, $s0, $s1
move $s3, $s3
move $a0, $s3
jal _print
mul $s3, $s0, $s1
move $s3, $s3
move $a0, $s3
jal _print
div $s3, $s0, $s1
move $s3, $s3
move $a0, $s3
jal _print
add $s0, $s0, $s1
move $s0, $s0
move $a0, $s0
jal _print
move $a0, $s2
jal _print
lw $ra, -4($fp)
lw $fp, -8($fp)
addu $sp, $sp, 48
j $ra
.text
.globl rnad_1
rnad_1:
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
move $s0, $a0
move $s1, $a1
move $v1, $a2
move $s2, $a3
move $a0, $s0
move $a1, $s1
move $a2, $s2
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
jalr rnad_3
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
move $s3, $v0
move $v0, $s3
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
.globl rnad_2
rnad_2:
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
move $s1, $s0
li $v1, 0
lw $v0, 0($s1)
move $s0, $v0
li $s2, 4
move $a0, $s0
jal _print
lw $v0, 4($s1)
move $s0, $v0
move $a0, $s0
jal _print
lw $v0, 8($s1)
move $s0, $v0
move $a0, $s0
jal _print
move $v0, $s2
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
.globl rnad_3
rnad_3:
sw $fp, -8($sp)
move $fp, $sp
subu $sp, $sp, 96
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
move $s2, $a1
move $s3, $a2
add $s0, $s3, 18
lw $v0, 0($s2)
move $s4, $v0
sub $s5, $s4, $s3
lw $v0, 0($s2)
move $s6, $v0
mul $s7, $s6, $s0
move $a0, $s1
move $a1, $s2
move $a2, $s3
move $a3, $s0
sw $s4, -12($sp)
sw $s5, -16($sp)
sw $s6, -20($sp)
sw $s7, -24($sp)
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
jalr rnad_4
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
move $v1, $v0
move $s2, $s1
move $s3, $s2
move $s0, $s3
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
addu $sp, $sp, 96
j $ra
.text
.globl rnad_4
rnad_4:
sw $fp, -8($sp)
move $fp, $sp
subu $sp, $sp, 56
sw $ra, -4($fp)
sw $s0, -28($fp)
sw $s1, -32($fp)
sw $s2, -36($fp)
sw $s3, -40($fp)
sw $s4, -44($fp)
sw $s5, -48($fp)
sw $s6, -52($fp)
sw $s7, -56($fp)
move $v1, $a0
move $v1, $a1
move $s4, $a2
move $s5, $a3
lw $v0, -12($fp)
move $s0, $v0
lw $v0, -16($fp)
move $s3, $v0
lw $v0, -20($fp)
move $s1, $v0
lw $v0, -24($fp)
move $s2, $v0
move $a0, $s4
jal _print
move $a0, $s5
jal _print
move $a0, $s0
jal _print
move $a0, $s3
jal _print
move $a0, $s1
jal _print
move $a0, $s2
jal _print
sle $s0, $s4, $s3
move $a0, $s0
jal _print
move $s0, $s4
move $a0, $s0
jal _print
move $s0, $s5
move $v0, $s0
lw $s7, -56($fp)
lw $s6, -52($fp)
lw $s5, -48($fp)
lw $s4, -44($fp)
lw $s3, -40($fp)
lw $s2, -36($fp)
lw $s1, -32($fp)
lw $s0, -28($fp)
lw $ra, -4($fp)
lw $fp, -8($fp)
addu $sp, $sp, 56
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
