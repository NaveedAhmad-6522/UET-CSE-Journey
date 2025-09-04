 # add.asm-- A program that computes the sum of 1 and 2,
 # leaving the result in register $t0.
 # Registers used:


.data
str0: .asciiz"  m = "
str1: .asciiz"enter number 1"
str2: .asciiz"enter number 2"
str3: .asciiz"enter number 3"
str4: .asciiz"enter number 4"
str5: .asciiz"enter number 5"
str6: .asciiz"enter number 6"
str7: .asciiz"enter number 7"
str8: .asciiz"enter number 8"
str9: .asciiz"  n = "
str10: .asciiz"  y = "
str11: .asciiz"  z = "
str12: .asciiz"  x = "
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

li $v0 ,4
la $a0 , str6
syscall

li  $v0,5
syscall
move $t6, $v0 


li $v0 ,4
la $a0 , str7
syscall

li  $v0,5
syscall
move $t7, $v0 


li $v0 ,4
la $a0 , str8
syscall

li  $v0,5
syscall
move $t8, $v0 


 add   $t0, $t1,$t2 
 add   $t0, $t3,$t0 
 add   $t0, $t4,$t0 


li $v0 ,4
la $a0 , str0
syscall

 move $a0 , $t0
 li $v0,1
 syscall




sub   $s0, $t0,$t5 
sub   $s0, $s0,$t6 
sub   $s0, $s0,$t7 


li $v0 ,4
la $a0 , str9
syscall

 move $a0 , $s0
 li $v0,1
 syscall



mul   $s1, $t0,$s0
mul   $s1, $s1,$t8 

li $v0 ,4
la $a0 , str10
syscall

 move $a0 , $s1
 li $v0,1
 syscall





add   $s2, $t0,$s0 
sub   $s2, $s2,$s1
mul   $s2, $s2,$t8

li $v0 ,4
la $a0 , str11
syscall

 move $a0 , $s2
 li $v0,1
 syscall


div   $s2,$t2 
mfhi $s3
rh

li $v0 ,4
la $a0 , str12
syscall

 move $a0 , $s3
 li $v0,1
 syscall






 li  $v0, 10
 syscall

 