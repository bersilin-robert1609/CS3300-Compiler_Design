.text
.globl main
main:
sw $fp, -8($sp)
move $fp, $sp
subu $sp, $sp, 48
sw $ra, -4($fp)
li $s0, 20
move $a0, $s0
jal _halloc
move $s1, $v0
li $s2, 0
sw $s2, 0($s1)
sw $s2, 4($s1)
sw $s2, 8($s1)
sw $s2, 12($s1)
sw $s2, 16($s1)
li $s0, 4
move $a0, $s0
jal _halloc
move $s0, $v0
la $s2, Fac_fn
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
.globl Fac_fn
Fac_fn:
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
li $s0, 5
sw $s0, 16($s1)
li $s0, 83
sw $s0, 12($s1)
li $s0, 5934
sw $s0, 8($s1)
li $s0, 183
sw $s0, 4($s1)
lw $v0, 16($s1)
move $s0, $v0
lw $v0, 12($s1)
move $s2, $v0
add $s0, $s0, $s2
move $s0, $s0
move $a0, $s0
jal _print
lw $v0, 16($s1)
move $s2, $v0
lw $v0, 12($s1)
move $s3, $v0
sub $s2, $s2, $s3
move $s0, $s2
move $a0, $s0
jal _print
lw $v0, 16($s1)
move $s2, $v0
lw $v0, 12($s1)
move $s3, $v0
mul $s2, $s2, $s3
move $s0, $s2
move $a0, $s0
jal _print
lw $v0, 16($s1)
move $s2, $v0
lw $v0, 12($s1)
move $s3, $v0
div $s2, $s2, $s3
move $s0, $s2
move $a0, $s0
jal _print
lw $v0, 16($s1)
move $s2, $v0
lw $v0, 12($s1)
move $s3, $v0
lw $v0, 8($s1)
move $s4, $v0
div $s3, $s3, $s4
mul $s2, $s2, $s3
move $s0, $s2
move $a0, $s0
jal _print
lw $v0, 16($s1)
move $s2, $v0
lw $v0, 12($s1)
move $s3, $v0
lw $v0, 8($s1)
move $s4, $v0
div $s3, $s3, $s4
lw $v0, 4($s1)
move $s4, $v0
add $s3, $s3, $s4
mul $s2, $s2, $s3
move $s0, $s2
move $a0, $s0
jal _print
lw $v0, 16($s1)
move $s2, $v0
lw $v0, 12($s1)
move $s3, $v0
lw $v0, 8($s1)
move $s4, $v0
lw $v0, 4($s1)
move $s1, $v0
add $s1, $s4, $s1
div $s1, $s3, $s1
mul $s1, $s2, $s1
move $s0, $s1
move $a0, $s0
jal _print
li $s0, 1
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
