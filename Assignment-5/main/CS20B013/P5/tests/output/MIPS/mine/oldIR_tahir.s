.text
.globl main
main:
sw $fp, -8($sp)
move $fp, $sp
subu $sp, $sp, 48
sw $ra, -4($fp)
li $s0, 12
move $a0, $s0
jal _halloc
move $s1, $v0
li $s2, 0
sw $s2, 0($s1)
sw $s2, 4($s1)
sw $s2, 8($s1)
li $s0, 12
move $a0, $s0
jal _halloc
move $s3, $v0
la $s4, yeaboi_fn
sw $s4, 8($s3)
la $s4, urmom_fn2
sw $s4, 4($s3)
la $s4, fkboy_fn3
sw $s4, 0($s3)
sw $s3, 0($s1)
lw $v0, 0($s1)
move $s4, $v0
lw $v0, 8($s4)
move $s4, $v0
li $s0, 3
li $s2, 8
move $a0, $s1
move $a1, $s0
move $a2, $s2
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
jalr $s4
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
move $s3, $v0
move $a0, $s3
jal _print
lw $ra, -4($fp)
lw $fp, -8($fp)
addu $sp, $sp, 48
j $ra
.text
.globl yeaboi_fn
yeaboi_fn:
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
move $s2, $a2
lw $v0, 0($s0)
move $s3, $v0
lw $v0, 4($s3)
move $s3, $v0
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
jalr $s3
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
move $s0, $s0
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
addu $sp, $sp, 80
j $ra
.text
.globl urmom_fn2
urmom_fn2:
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
move $s1, $a0
move $s2, $a1
move $v1, $a2
li $s0, 3
sw $s0, 4($s1)
lw $v0, 0($s1)
move $s0, $v0
lw $v0, 0($s0)
move $s0, $v0
lw $v0, 4($s1)
move $s3, $v0
move $a0, $s1
move $a1, $s3
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
jalr $s0
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
move $s0, $s0
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
addu $sp, $sp, 80
j $ra
.text
.globl fkboy_fn3
fkboy_fn3:
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
move $v1, $a0
move $s0, $a1
move $s1, $a2
add $s2, $s0, $s1
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
