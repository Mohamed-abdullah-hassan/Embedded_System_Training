

; Seting Symbolic names
SYSCTRL_RCGCGPIO_R		equ		0x400FE608
GPIO_PORTF_DIR_R		EQU		0x40025400
GPIO_PORTF_DEN_R		EQU		0x4002551C
GPIO_PORTF_DATA_R		equ		0x400253FC
GPIO_PORTF_PUR_R		equ		0x40025510
GPIO_PORTF_LOCK_R		equ		0x40025520
GPIO_PORTF_CR_R			equ		0x40025524

GPIO_Lock_Key			equ		0x4C4F434B

Switch_1				equ		0x10		
											;PortF pin 0 this pin is active low 
RED_LED					equ		0x02
Blue_LED				equ		0x04
Green_LED				equ		0x08
	

delay_200ms_count		equ		1066666		
											; for 16MHz MCU to get 200 ms delay => 16/5 = 3200000 and assuming for
											;each count its require 3 instruction to complete one count down
											;then ther result => 3200000/3 = 1066666 
									
			

		AREA	|.text|, CODE, READONLY, ALIGN=2
		THUMB
								; The __main is the default function which is called from rest handler

__main	PROC
		EXPORT	__main
GPIO_Init
		LDR		r1, =SYSCTRL_RCGCGPIO_R
		ldr		r0,	[r1]
		orr		r0,r0,#0x20
		str		r0, [r1]
			
		ldr		r1, =GPIO_PORTF_LOCK_R
		ldr		r0, =GPIO_Lock_Key
		str		r0, [r1]
		
		ldr		r1, =GPIO_PORTF_CR_R	
		mov		r0, #0xFF
		str		r0, [r1]
		
		ldr 	r1, =GPIO_PORTF_DIR_R
		mov		r0, #( RED_LED :OR: Blue_LED :OR: Green_LED)
		str		r0, [r1]
		
		ldr		r1, =GPIO_PORTF_PUR_R
		mov		r0,	#0x10
		str		r0, [r1]
		
		ldr		r1, =GPIO_PORTF_DEN_R
;		mov		r0,	#0x13
		mov		r0,	#(Switch_1 :OR: RED_LED :OR: Blue_LED :OR: Green_LED)
		str		r0, [r1]


Loop	
		ldr		r0, =delay_200ms_count
		bl		Delay
		bl		Switch
		cmp		r0, #0x00
;		orrs	r0, #0x10
		beq		LED_On
		bl		Output
		b		Loop
		ENDP

LED_On	PROC
		mov		r0,#RED_LED
		BL		Output
		b		Loop
		ENDP
			
Output	PROC
		ldr		r1, =GPIO_PORTF_DATA_R
		str		r0, [r1]
		bx		lr
		ENDP
		
Switch	PROC
		ldr		r1, =GPIO_PORTF_DATA_R
		ldr		r0, [r1]
		and		r0,	r0,	#0x10				; For both Switch 1 and Switch 2
		bx		lr
		ENDP
			
Delay	PROC
		subs	r0,r0,#1
		bne		Delay
		bx		lr
		ENDP
		
		align
		end
		