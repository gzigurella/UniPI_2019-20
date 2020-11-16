	.data
arr:	.skip 200*4	@UNinitialized array of words

	.text
	.global main

main:
	LDR R1, =arr	@mem array
	MOV R0, #0	@array index/mem offset
	PUSH {LR}	@store link register

loop:
	CMP R0, #200			@check index
	BGE fine			@jump to fine
	STR R0, [R1, R0, LSL #2]	@store arr[i] = i
	ADD R0, R0, #1			@increase index by 1 the index
	BL loop			@jump to loop

fine:
	POP {LR}	@take link register from stack
	MOV R0, #0	@define exit number
	MOV PC, LR	@return main
	MOV R7, #1	@syscall 1 (exit type)
	SVC 0
