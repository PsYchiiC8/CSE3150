#       CSE 3666 Lab 3: remove spaces

        .data
        # allocating space for both strings
str:    .space  128
res:    .space  128

        .globl  main

        .text
main:   
        # load address of strings 
        la      s0, str
        la      s1, res

        # we do not need LA pseudoinstructions from now on

        # read a string into str
        addi    a0, s0, 0 	#original string, 1st position
        addi    a1, x0, 120	#
        addi    a7, x0, 8
        ecall
	
	addi t0, x0, 0 		#i
	addi t1, x0, 0		#j
	addi t6, x0, ' ' 	#makes comparisons easier, set t6 to space
        # str's addres is already in s0
        # copy res's address to a1
        addi    a1, s1, 0

        # TODO
	# remove spaces in str
	# print res
        # your code assumes str's address is in a0 and res's address is in a1
        
        loop:
        	add t2, a0, t0
        	lb t4, 0(t2)
        	addi t0, t0, 1
        	
        	beq t4, t6, skip	#continue if not a space, if space, go to label skip
        	add t3, a1, t1		#adds j to res
        	sb t4, 0(t3)		#stores char
        	addi t1, t1, 1		#increments j
        	
        skip:
        	bne t4, x0, loop	#if t4 is not at the end, go back to loop
        	
        	addi a7, x0, 4
        	add a0, s1, zero
        	ecall
               
exit:   addi    a7, x0, 10
        ecall