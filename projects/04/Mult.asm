// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)


// CODE:

	@R2
	M=0
	
	// if either R0 or R1 == 0 -> jmp to end
	@R0
	D=M
	@END
	D;JEQ
	
	@R1
	D=M
	@END
	D;JEQ
	
(ADD)
	// add RAM[0] to the current sum
	@R0
	D=M
	@R2
	M=M+D
	
	// repeat if r1 != 0
	@R1
	M=M-1
	D=M
	@ADD
	D;JNE
	
(END)
	@END
	0;JMP