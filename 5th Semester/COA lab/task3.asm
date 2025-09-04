.data
str: .asciiz "The Answer: "
.text
main:
li $v0, 5
syscall
move $t0, $v0
li $v0, 5
syscall
move $t1, $v0
add $t2, $t1, $t0
li$v0,4
la $a0,str
syscall
move $a0, $t2
li $v0, 1
syscall

li $v0, 10
syscall