.data 
str1: .asciiz "enter the first number: "
str2: .asciiz "enter the second number: "
ope: asciiz "enter the operator: "

main:
li $v0, 4
la $a0, str1
syscall
li $v0, 5
syscall
move $t0, $v0
li $v0, 4
la $a0, msg2
syscall
li $v0, 5
syscall
move $t1, $v0
