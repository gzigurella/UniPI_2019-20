	.data
array:	.word 10, 33, 74, 8, 9, 6, 42, 55, 42, 3
fmt:	.string "Il primo indice con valore 42  è: %d\n"

	.text
	.global main

main:
	LDR R1, =array	@read array in R1
	MOV R2, #0	@offset index
	PUSH {R1, LR}	@save array values and Link Register

trova42:
	LDR R4, [R1, R2, LSL #2]	@read the number in r1[r2]
	CMP R4, #42			@R4 == 42 ? 1 : 0
	BEQ stampa			@jump to stampa
	ADD R2, R2, #1			@increment index value
	BL trova42			@jump to trova42
stampa:
	MOV R1, R2	@move to index to print on screen
	LDR R0, =fmt	@read string in R0
	BL printf	@link to printf function, prints R0 with R1 as operand

fine:
	POP {R1, LR}	@restore R1 and Link Register values
	MOV R0, #0	@define exit number
	MOV PC, LR	@return main
	MOV R7, #1	@syscall 1 (exit type)
	SVC 0		@call exit function

