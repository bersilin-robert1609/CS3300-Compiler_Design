.text
.globl main
main:
sw $fp, -8($sp)
move $fp, $sp
subu $sp, $sp, 64
sw $ra, -4($fp)
li $s0, 4
move $a0, $s0
jal _halloc
move $s0, $v0
move $s0, $s0
li $s1, 4
move $a0, $s1
jal _halloc
move $s1, $v0
move $s1, $s1
la $s2, huh_lol
sw $s2, 0($s0)
sw $s0, 0($s1)
move $s0, $s1
lw $v0, 0($s0)
move $s1, $v0
lw $v0, 0($s1)
move $s1, $v0
li $s2, 1
li $s3, 2
li $s4, 3
li $s5, 4
li $s6, 5
li $s7, 6
li $t0, 7
move $a0, $s0
move $a1, $s2
move $a2, $s3
move $a3, $s4
sw $s5, -12($sp)
sw $s6, -16($sp)
sw $s7, -20($sp)
sw $t0, -24($sp)
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
jalr $s1
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
addu $sp, $sp, 64
j $ra
.text
.globl huh_lol
huh_lol:
sw $fp, -8($sp)
move $fp, $sp
subu $sp, $sp, 112
sw $ra, -4($fp)
sw $s0, -28($fp)
sw $s1, -32($fp)
sw $s2, -36($fp)
sw $s3, -40($fp)
sw $s4, -44($fp)
sw $s5, -48($fp)
sw $s6, -52($fp)
sw $s7, -56($fp)
move $s1, $a0
move $s2, $a1
move $t0, $a2
move $s6, $a3
lw $v0, -12($fp)
move $s7, $v0
lw $v0, -16($fp)
move $s3, $v0
lw $v0, -20($fp)
move $s4, $v0
lw $v0, -24($fp)
move $s5, $v0
li $s0, 7
sne $s0, $s2, $s0
beqz $s0, huh_lol_L2
move $s0, $s1
lw $v0, 0($s0)
move $s1, $v0
lw $v0, 0($s1)
move $s1, $v0
move $a0, $s0
move $a1, $t0
move $a2, $s6
move $a3, $s7
sw $s3, -12($sp)
sw $s4, -16($sp)
sw $s5, -20($sp)
sw $s2, -24($sp)
sw $t0, -60($fp)
sw $t1, -64($fp)
sw $t2, -68($fp)
sw $t3, -72($fp)
sw $t4, -76($fp)
sw $t5, -80($fp)
sw $t6, -84($fp)
sw $t7, -88($fp)
sw $t8, -92($fp)
sw $t9, -96($fp)
jalr $s1
lw $t9, -96($fp)
lw $t8, -92($fp)
lw $t7, -88($fp)
lw $t6, -84($fp)
lw $t5, -80($fp)
lw $t4, -76($fp)
lw $t3, -72($fp)
lw $t2, -68($fp)
lw $t1, -64($fp)
lw $t0, -60($fp)
move $s0, $v0
move $s0, $s0
b huh_lol_L3
huh_lol_L2:
add $s1, $s6, $s7
add $s1, $t0, $s1
move $s0, $s1
huh_lol_L3:
nop
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
addu $sp, $sp, 112
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
