


SYSCTL_BASE				EQU			0X400FE000
RCGCGPIO_OFFSET			EQU			0X608
SYSCTL_RCGCGPIO_R		EQU			SYSCTL_BASE	+ RCGCGPIO_OFFSET

GPIOF_PORT_EN			EQU			1<<5
GPIOF_BASE				EQU			0X40025000
GPIOF_DATA_OFFSET		EQU			0X3FC
GPIOF_DIR_OFFSET		EQU			0X400
GPIOF_DEN_OFFSET		EQU			0X51C

GPIOF_DATA_R			EQU			GPIOF_BASE + GPIOF_DATA_OFFSET
GPIOF_DIR_R				EQU			GPIOF_BASE + GPIOF_DIR_OFFSET
GPIOF_DEN_R				EQU			GPIOF_BASE + GPIOF_DEN_OFFSET

LED_RED					EQU			1<<1
LED_BLUE				EQU			1<<2
LED_GREEN				EQU			1<<3

ONE_SEC					EQU			5333333
HSEC					EQU			266667

		;ARM ASSEMBLY PROGRAMMING FROM GROUND UP

			AREA	|.text|, CODE, READONLY, ALIGN =2
			THUMB
			ENTRY
			EXPORT	__main

__main
		bl		GPIO_INIT
		bl		LED_Blink

GPIO_INIT
		ldr		r1,=SYSCTL_RCGCGPIO_R
		ldr		r0,[r1]
		orr		r0,r0,#GPIOF_PORT_EN
		str 	r0,[r1]
		nop
		nop
		ldr		r1,=GPIOF_DIR_R
		ldr		r0,[r1]
		orr		r0,r0,#LED_RED
		str		r0,[r1]

		ldr		r1,=GPIOF_DEN_R
		ldr		r0,[r1]
		orr		r0,r0,#LED_RED
		str		r0,[r1]

		bx		lr


LED_ON
		ldr		r1,=GPIOF_DATA_R
		ldr		r0,[r1]
		orr		r0,r0,#LED_RED
		str		r0,[r1]

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
