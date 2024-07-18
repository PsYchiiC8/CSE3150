#       CSE 3666 uint2decstr

        .globl  main

        .text
main:   
        # create an array of 128 bytes on the stack
        addi    sp, sp, -128

        # copy array's address to a0
        addi    a0, sp, 0

	# set all bytes in the buffer to 'A'
        addi    a1, x0, 0       # a1 is the index
	addi	a2, x0, 128
	addi	t2, x0, 'A'
clear:
        add     t0, a0, a1
	sb	t2, 0(t0)
        addi    a1, a1, 1
	bne	a1, a2, clear
	
        # change -1 to other numbers to test
        # use li to make it easier to load the number 
        li	a1, -1
	jal	ra, uint2decstr

        # print the string
        addi    a0, sp, 0
        addi    a7, x0, 4
        ecall

exit:   addi    a7, x0, 10      
        ecall

# char * uint2decstr(char *s, unsigned int v) 
# the function converts an unsigned 32-bit value to a decimal string
# Here are some examples:
# 0:    "0"
# 2022: "2022"
# -1:   "4294967295"
# -3666:   "4294963630"
uint2decstr:
	addi t0, x0, 10		#store value 10 in t0
	blt a1, t0, skip
	div a1, a1, 10
	jal a0, uint2decstr
	skip:
		remu t1, a1, t0		# r = v % 10
		addi t2, x0, t1		# 0 + r
		add t3, a0, x0		# find s[0] address
		sb t1, 0(t3)		# store 0 + r in s[0]
		addi t3, t3, 4		# find s[1] address
		sb 0, 0(t3)		# store 0 in s[1]
		jr t3			# return &s[1]
		




