


; Seting Symbolic names
SYSCTRK_RCGCGPIO_R		equ		0x400FE608
GPIO_PORTF_DIR_R		EQU		0x40025400
GPIO_PORTF_DEN_R		EQU		0x4002551C
GPIO_PORTF_DATA_R		equ		0x400253FC


		AREA	|.text|, CODE, READONLY, ALIGN=2
		THUMB
		EXPORT	Main

Main
		BL		LED_Init						; Call {LED_Init} sub-rotine.
		
Loop
		BL		Light_On						; Call {Light_On}
		B		Loop							; Jump un-conditionaly to Loop lable.

LED_Init

;Step 1 Enable port F Clock

		LDR		R1, =SYSCTRK_RCGCGPIO_R 		; Using Indexed Addressing
												; SYSCTRK_RCGCGPIO_R is a name given to the address
												; it can be named by anything but prefer using stadard naming

		LDR		R0, [R1]						; Get the data from memory location pointed by R1 and place
												; it in R0 register
		
		ORR		R0, R0, #0x20					; ORR  RD, RS, #value ==>  Rd = RS | #value
												; In datasheet port f enable bit is located in bit loaction 5
												; then what interrest is the 5th bit only
												; so putting 1 in the 5th ==> 0 0 0 1   0 0 0 0
												;						 bit  8 7 6 5   4 3 2 1
												
		STR		R0, [R1]						; Stroing the new values to the destination address pointed by R1

		NOP										; Wait for 2 clocks to ensure proper activation.
		NOP
		
;		LDR		R1, =GPIO_PORTF_LOCK_R
;		LDR		R0, =GPIO_LOCK_KEY

;Step 2 Set Pin PF1 as an output 
		ldr		r1, =GPIO_PORTF_DIR_R
		mov		r0, #0x02						; Position of PF1 pin in PortF DEN register
		str		r0, [r1]

;Step 3 Enable PF1 pin as digital pen
		ldr		r1, =GPIO_PORTF_DEN_R
		mov		r0, #0x02
		str		r0, [r1]
		
		bx		lr								; Return from this sub-rotine to the calling function
		
Light_On
		ldr		r1,	=GPIO_PORTF_DATA_R
		mov		r0, #0x02
		str		r0, [r1]
		bx		lr
		
		
		align
		end
		