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
la $s2, Test_Start
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
.globl ArrayTest_test
ArrayTest_test:
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
move $s2, $a0
move $s0, $a1
add $s1, $s0, 1
mul $s0, $s1, 4
move $a0, $s0
jal _halloc
move $s3, $v0
sw $s1, 0($s3)
li $s4, 0
li $s5, 4
sub $s0, $s0, 4
ArrayTest_test_L1:
sle $s1, $s5, $s0
beqz $s1, ArrayTest_test_L2
add $s6, $s3, $s5
sw $s4, 0($s6)
add $s5, $s5, 4
b ArrayTest_test_L1
ArrayTest_test_L2:
nop
move $s3, $s3
li $s1, 0
sw $s1, 4($s2)
lw $v0, 4($s2)
move $s0, $v0
move $a0, $s0
jal _print
lw $v0, 0($s3)
move $s5, $v0
sub $s5, $s5, 1
move $a0, $s5
jal _print
li $s4, 0
move $s0, $s4
li $s1, 111
move $a0, $s1
jal _print
ArrayTest_test_L3:
lw $v0, 0($s3)
move $s1, $v0
sub $s1, $s1, 1
li $s2, 1
sub $s1, $s1, $s2
sle $s1, $s0, $s1
beqz $s1, ArrayTest_test_L4
li $s1, 1
add $s1, $s0, $s1
move $a0, $s1
jal _print
mul $s1, $s0, 4
add $s1, $s1, 4
add $s1, $s1, $s3
li $s2, 1
add $s2, $s0, $s2
sw $s2, 0($s1)
li $s1, 1
add $s1, $s0, $s1
move $s0, $s1
b ArrayTest_test_L3
ArrayTest_test_L4:
nop
li $s1, 222
move $a0, $s1
jal _print
li $s1, 0
move $s0, $s1
ArrayTest_test_L5:
lw $v0, 0($s3)
move $s1, $v0
sub $s1, $s1, 1
li $s2, 1
sub $s1, $s1, $s2
sle $s1, $s0, $s1
beqz $s1, ArrayTest_test_L6
mul $s1, $s0, 4
add $s1, $s1, 4
add $s1, $s3, $s1
lw $v0, 0($s1)
move $s2, $v0
move $a0, $s2
jal _print
li $s2, 1
add $s1, $s0, $s2
move $s0, $s1
b ArrayTest_test_L5
ArrayTest_test_L6:
nop
li $s0, 333
move $a0, $s0
jal _print
lw $v0, 0($s3)
move $s0, $v0
sub $s0, $s0, 1
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
.globl B_test
B_test:
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
move $s2, $a0
move $s0, $a1
add $s1, $s0, 1
mul $s0, $s1, 4
move $a0, $s0
jal _halloc
move $s3, $v0
sw $s1, 0($s3)
li $s4, 0
li $s5, 4
sub $s0, $s0, 4
B_test_L7:
sle $s1, $s5, $s0
beqz $s1, B_test_L8
add $s6, $s3, $s5
sw $s4, 0($s6)
add $s5, $s5, 4
b B_test_L7
B_test_L8:
nop
move $s3, $s3
li $s1, 12
sw $s1, 20($s2)
lw $v0, 20($s2)
move $s0, $v0
move $a0, $s0
jal _print
lw $v0, 0($s3)
move $s5, $v0
sub $s5, $s5, 1
move $a0, $s5
jal _print
li $s4, 0
move $s0, $s4
li $s1, 111
move $a0, $s1
jal _print
B_test_L9:
lw $v0, 0($s3)
move $s1, $v0
sub $s1, $s1, 1
li $s2, 1
sub $s1, $s1, $s2
sle $s1, $s0, $s1
beqz $s1, B_test_L10
li $s1, 1
add $s1, $s0, $s1
move $a0, $s1
jal _print
mul $s1, $s0, 4
add $s1, $s1, 4
add $s1, $s1, $s3
li $s2, 1
add $s2, $s0, $s2
sw $s2, 0($s1)
li $s1, 1
add $s1, $s0, $s1
move $s0, $s1
b B_test_L9
B_test_L10:
nop
li $s1, 222
move $a0, $s1
jal _print
li $s1, 0
move $s0, $s1
B_test_L11:
lw $v0, 0($s3)
move $s1, $v0
sub $s1, $s1, 1
li $s2, 1
sub $s1, $s1, $s2
sle $s1, $s0, $s1
beqz $s1, B_test_L12
mul $s1, $s0, 4
add $s1, $s1, 4
add $s1, $s3, $s1
lw $v0, 0($s1)
move $s2, $v0
move $a0, $s2
jal _print
li $s2, 1
add $s1, $s0, $s2
move $s0, $s1
b B_test_L11
B_test_L12:
nop
li $s0, 333
move $a0, $s0
jal _print
lw $v0, 0($s3)
move $s0, $v0
sub $s0, $s0, 1
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
.globl Test_Start
Test_Start:
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
li $s0, 16
move $a0, $s0
jal _halloc
move $s1, $v0
li $s2, 0
sw $s2, 0($s1)
sw $s2, 4($s1)
sw $s2, 8($s1)
sw $s2, 12($s1)
li $s0, 4
move $a0, $s0
jal _halloc
move $s3, $v0
la $s4, ArrayTest_test
sw $s4, 0($s3)
sw $s3, 0($s1)
move $s1, $s1
lw $v0, 0($s1)
move $s0, $v0
lw $v0, 0($s0)
move $s0, $v0
li $s2, 3
move $a0, $s1
move $a1, $s2
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
move $s4, $v0
move $a0, $s4
jal _print
li $s2, 0
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
