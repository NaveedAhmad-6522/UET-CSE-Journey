 # add.asm-- A program that computes the sum of 1 and 2,
 # leaving the result in register $t0.
 # Registers used:

.data
str0: .asciiz"the answer :"
str1: .asciiz"enter number 1: "
str2: .asciiz"enter number 2: "
str3: .asciiz"enter number 3: "
str4: .asciiz"enter number 4: "
str5: .asciiz"enter number 5: "
.text
 main:


li $v0 ,4
la $a0 , str1
syscall 

 li $v0 , 5
 syscall
 move $t1, $v0
 
li $v0 ,4
la $a0 , str2
syscall

li  $v0,5
syscall
move $t2, $v0 

li $v0 ,4
la $a0 , str3
syscall

li  $v0,5
syscall
move $t3, $v0 

li $v0 ,4
la $a0 , str4
syscall

li  $v0,5
syscall
move $t4, $v0 

li $v0 ,4
la $a0 , str5
syscall

li  $v0,5
syscall
move $t5, $v0 


 add   $t0, $t1,$t2 
 add   $t0, $t3,$t0 
 add   $t0, $t4,$t0 
 add   $t0, $t5,$t0 

li $v0 ,4
la $a0 , str0
syscall

 move $a0 , $t0
 li $v0,1
 syscall

 li  $v0, 10
 syscall

 