.data
myarray: .space 404
	newline: .asciiz "\n"
	#length: .word 101
	sum: .word 0
	average: .word 0
.text
main:
	la $t1, myarray
	li $t2,0
	li $t3, 101
	li $t4,0
	li $t5,0 
#STORING AN ARRAY WITH 101 ELEMENTS	
store:  	sw $t5, 200($t1)        
		add $t5, $t5,1
		add $t2,$t2,1
		add $t1,$t1,4
		blt $t2, $t3, store
	la $t1, myarray
	li $t2,0
	li $t3, 101
	li $t4,0
	li $t5,0
	li $t6,0
# CALCULATING AVERAGE			
sumloop: lw $t5,200($t1)      #t5 = array(i)
	 add $t2, $t2, 1   # t2= i+1
	  add $t4,$t4,$t5 
	  add $t1,$t1,4
	 blt $t2,$t3,sumloop
	 #sw $t4, sum
	 div $t7, $t4,$t3
	 #sw $t7, average
	 mflo $t7

	la $t1, myarray
	li $t2,1          # i=0
	li $t8,101
	li $t6,0
	lw $t4,200($t1)
#CALCULATING GREATER NUMBER IN AN ARRAY	
greater: add $t1,$t1,4
	lw $t5,200($t1)
	slt $t3,$t4,$t5
	add $t2,$t2,1
	blt $t6,$t3,shift
	blt $t2,$t8,greater
	
# CALCULATING HIGHER ADDRESS IN AN ARRAY		
	la $t1,myarray
loop:	lw $t5,200($t1)
	beq $t4,$t5,load_hadd
	addi $t1,$t1,4
	j loop
	
load_hadd: move $t9,$t4
         la $s1, 200($t1)	
	j xy	
	
shift: move $t4,$t5 
	blt $t2,$t8,greater
	j loop

xy:	la $t1, myarray
	li $t2,1          # i=0
	li $t8,101
	li $t6,0
	lw $t4,200($t1) 
	
smaller: add $t1,$t1,4
	lw $t5,200($t1)
	slt $t3,$t4,$t5
	add $t2,$t2,1
	#blt $t6,$t3,jump
	beq $t6,$t3,shiftnxt
	blt $t2,$t8,smaller
	#la $s0, 200($t1)
# CALCULATING HIGHER ADDRESS IN AN ARRAY	
loop1:	la $t1,myarray
	lw $t5,200($t1)
	beq $t4,$t5,load_ladd
	addi $t1,$t1,4
	j loop1
	 

shiftnxt: move $t6,$t5  
	blt $t2,$t8,smaller
	
		
load_ladd: la $s0, 200($t1)	
	
	
#Exit the program	 	
li $v0,10
syscall

