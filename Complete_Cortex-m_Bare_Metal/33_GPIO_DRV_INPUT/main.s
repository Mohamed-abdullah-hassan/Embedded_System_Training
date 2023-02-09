

;ARM ASSEMBLY PROGRAMMING FROM GROUND UP

SYSCTL_BASE				EQU			0X400FE000
RCGCGPIO_OFFSET			EQU			0X608
SYSCTL_RCGCGPIO_R		EQU			SYSCTL_BASE	+ RCGCGPIO_OFFSET

GPIOF_PORT_EN			EQU			1<<5
GPIOF_BASE				EQU			0X40025000
GPIOF_DATA_OFFSET		EQU			0X3FC
GPIOF_DIR_OFFSET		EQU			0X400
GPIOF_DEN_OFFSET		EQU			0X51C
GPIOF_PUR_OFFSET		EQU			0X510
GPIOF_LOCK_OFFSET		EQU			0X520
GPIOF_CR_OFFSET			EQU			0X524

GPIOF_DATA_R			EQU			GPIOF_BASE + GPIOF_DATA_OFFSET
GPIOF_DIR_R				EQU			GPIOF_BASE + GPIOF_DIR_OFFSET
GPIOF_DEN_R				EQU			GPIOF_BASE + GPIOF_DEN_OFFSET
GPIOF_PUR_R				EQU			GPIOF_BASE + GPIOF_PUR_OFFSET
GPIOF_LOCK_R			EQU			GPIOF_BASE + GPIOF_LOCK_OFFSET
GPIOF_CR_R				EQU			GPIOF_BASE + GPIOF_CR_OFFSET

LOCK_KEY				EQU			0X4C4F434B

SW_2					EQU			1<<0
LED_RED					EQU			1<<1
LED_BLUE				EQU			1<<2
LED_GREEN				EQU			1<<3
SW_1					EQU			1<<4

ONE_SEC					EQU			5333333
HSEC					EQU			266667

			AREA	|.text|, CODE, READONLY, ALIGN =2
			THUMB
			ENTRY
			EXPORT	__main

__main
		bl		GPIO_INIT
loop
		bl		GPIO_READ
		cmp		r0,#0x01
		beq		__switch1
		cmp		r0,#0x10
		beq		__switch2
		cmp		r0,#0x00
		beq		__switch12
		cmp		r0,#0x11
		beq		__switch_off

__switch1
		mov		r0,#LED_RED
		bl		LED_ON
		b		loop
__switch2
		mov		r0,#LED_BLUE
		bl		LED_ON
		b		loop
__switch12
		mov		r0,#LED_GREEN
		bl		LED_ON
		b		loop
__switch_off
		mov		r0,#0x00
		bl		LED_ON
		b		loop


GPIO_INIT
		ldr		r1,=SYSCTL_RCGCGPIO_R
		ldr		r0,[r1]
		orr		r0,r0,#GPIOF_PORT_EN
		str 	r0,[r1]
		nop
		nop
		ldr		r1,=GPIOF_LOCK_R
		ldr		r0,=LOCK_KEY
		str		r0,[r1]
		ldr 	r1,=GPIOF_CR_R
		mov		r0,#0XFF
		str		r0,[r1]

		ldr		r1,=GPIOF_DIR_R
		ldr		r0,[r1]
		orr		r0,r0,#( LED_RED :OR: LED_BLUE :OR: LED_GREEN)
		str		r0,[r1]

		ldr		r1,=GPIOF_DEN_R
		ldr		r0,[r1]
		orr		r0,r0,#( SW_2 :OR: LED_RED :OR: LED_BLUE :OR: LED_GREEN :OR: SW_1) ;it can be #(SW_2 + LED_RED + LED_BLUE + LED_GREEN + SW_1)
		str		r0,[r1]

		ldr 	r1,=GPIOF_PUR_R
		ldr		r0,[r1]
		orr		r0,r0,#(SW_1 :or: SW_2)
		str		r0,[r1]
		
		bx		lr

GPIO_READ
		ldr 	r1,=GPIOF_DATA_R
		ldr		r0,[r1]
		and		r0,r0,#(SW_1 :or: SW_2)
		bx		lr

LED_ON
		ldr		r1,=GPIOF_DATA_R
		str		r0,[r1]
		bx		lr

DELAY
		subs	r3,r3,#1
		bne		DELAY
		bx		lr

LED_Blink
		ldr		r1,=GPIOF_DATA_R
		ldr		r0,[r1]
		orr		r0,r0,#LED_RED
		str		r0,[r1]
		ldr		r3,=ONE_SEC
		bl		DELAY
		eor 	r0,r0,#LED_RED
		str		r0,[r1]
		b		LED_Blink


		ALIGN
		END
