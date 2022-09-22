// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.


// CODE:

(DET)
	// (RE-) SETTING THE COUNTER
	@i
	M=0

	@KBD
	D=M
	
	// JUMP TO WHITE IF NO KEY IS PRESSED
	@WHITE
	D;JEQ
	
	// ELSE JUMP TO BLACK
	@BLACK
	0;JMP

(WHITE)
	@i
	D=M

	@SCREEN
	
	// i -> OFFSET (CURRENT REGISTER)
	A=A+D
	
	M=0
	
	// INCREMENTING i
	@i
	M=M+1
	D=M
	
	// IF M == 8192 -> WE REACHED THE END OF THE SCREEN MEMORY MAP
	@8192
	D=D-A
	
	// -> JUMP BACK
	@DET
	D;JEQ
	
	// ELSE LOOP BACK
	@WHITE
	0;JMP
	

(BLACK)
	@i
	D=M

	@SCREEN
	
	// i -> OFFSET (CURRENT REGISTER)
	A=A+D
	
	M=-1
	
	// INCREMENTING i
	@i
	M=M+1
	D=M
	
	// IF M == 8192 -> THE PROGRAM REACHED THE END OF THE SCREEN MEMORY MAP
	@8192
	D=D-A
	
	// -> JUMP BACK
	@DET
	D;JEQ
	
	// ELSE LOOP BACK
	@BLACK
	0;JMP