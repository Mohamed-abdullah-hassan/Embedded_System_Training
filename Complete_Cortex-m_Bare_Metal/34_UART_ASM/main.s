;Using UART0 for communication
;UART0_RX      PA0
;UART0_TX      PA1


SYSCTL_BASE				EQU			0X400FE000
RCGCGPIO_OFFSET			EQU			0X608
RCGCUART_OFFSET         EQU         0X618  

SYSCTL_RCGCGPIO_R		EQU			SYSCTL_BASE	+ RCGCGPIO_OFFSET
SYSCTL_RCGCUART_0       EQU         SYSCTL_BASE + RCGCUART_OFFSET

GPIO_DATA_OFFSET		EQU			0X3FC
GPIO_DIR_OFFSET	    	EQU			0X400
GPIO_DEN_OFFSET		    EQU			0X51C
GPIO_AFSEL_OFFSET       EQU         0X420
GPIO_PCTL_OFFSET        EQU         0X52C

GPIOA_BASE				EQU			0X40004000
GPIOA_PORT_EN			EQU			1<<0
GPIOA_DATA_R			EQU			GPIOA_BASE + GPIO_DATA_OFFSET
GPIOA_DIR_R				EQU			GPIOA_BASE + GPIO_DIR_OFFSET
GPIOA_DEN_R				EQU			GPIOA_BASE + GPIO_DEN_OFFSET
GPIOA_PCTL_R            EQU         GPIOA_BASE + GPIO_PCTL_OFFSET
GPIOA_AFSEL_R           EQU         GPIOA_BASE + GPIO_AFSEL_OFFSET


UART_0_ENABLE           EQU         1<<0
UART_DATA_OFFSET        EQU         0
UART_FLAG_OFFSET        EQU         0X018
UART_IBRD_OFFSET        EQU         0X024
UART_FBRD_OFFSET        EQU         0X028
UART_LCRH_OFFSETT       EQU         0X02C
UART_CTL_OFFSET         EQU         0X030
UART_IFLS_OFFSET        EQU         0X034
UART_IM_OFFSET          EQU         0X038
UART_RIS_OFFSET         EQU         0X03C
UART_ICR_OFFSET         EQU         0X044

UART0_BASE              EQU         0X4000C000
UART0_DATA_R            EQU         UART0_BASE + UART_DATA_OFFSET
UART0_FLAG_R            EQU         UART0_BASE + UART_FLAG_OFFSET
UART0_IBRD_R            EQU         UART0_BASE + UART_IBRD_OFFSET
UART0_FBRD_R            EQU         UART0_BASE + UART_FBRD_OFFSET
UART0_LCRH_R            EQU         UART0_BASE + UART_LCRH_OFFSETT
UART0_CTL_R             EQU         UART0_BASE + UART_CTL_OFFSET
UART0_IM_R              EQU         UART0_BASE + UART_IM_OFFSET
UART0_IFSL_R            EQU         UART0_BASE + UART_IFLS_OFFSET
UART0_RIS_R             EQU         UART0_BASE + UART_RIS_OFFSET
UART0_ICR_R             EQU         UART0_BASE + UART_ICR_OFFSET

UART_FR_RX_FE_V         EQU         0X00000010
UART_LCRH_WRD_LEN_8_V   EQU         0X00000060
UART_LCRH_F_EN_V        EQU         0X00000010
UART_CTL_UART_ENV       EQU         0X00000001
UART_IM_TR_IM_V         EQU         0X00000040

ASCII_CARRAGE_RETURN    EQU         0X0D
ASCII_BACK_SPACE        EQU         0X08
ASCII_LINE_FEED         EQU         0X0A
ASCII_ESCAPE            EQU         0X1B
ASCII_SPACE       		EQU         0X20
ASCII_DELETE            EQU         0X7F



                        AREA    |.text|, CODE, READONLY,ALIGN=2
                        THUMB
                        ENTRY
                        EXPORT __main

__main
        bl          __UART_int
        mov         r4,#'A'

__lp0   mov         r0,r4
        bl          __UART_write_char
        add         r4,r4,#1
        cmp         r4,#'z'
        bls         __lp0
        bl          __New_line
        mov         r0,#'!'
        bl          __UART_write_char

__New_line
        push        {lr}
        mov         r0,#ASCII_CARRAGE_RETURN
        bl          __UART_write_char
        mov         r0,#ASCII_LINE_FEED
        bl          __UART_write_char
        pop             {pc}

__UART_int
        push        {lr}
        ldr         r1,=SYSCTL_RCGCUART_0
        ldr         r0,[r1]
        orr         r0,r0,#UART_0_ENABLE
        str         r0,[r1]

        ldr         r1,=SYSCTL_RCGCGPIO_R
        ldr         r0,[r1]
        orr         r0,r0,#GPIOA_PORT_EN
        str         r0,[r1]

        ldr         r1,=GPIOA_AFSEL_R
        ldr         r0,[r1]
        orr         r0,#0x03

        ldr         r1,=GPIOA_DEN_R
        ldr         r0,[r1]
        orr         r0,r0,#0x03
        str         r0,[r1]

        ldr         r1,=GPIOA_PCTL_R
        ldr         r0,[r1]
        bic         r0,r0,#0x000000FF
        add         r0,r0,#0x00000011
        str         r0,[r1]


        ldr         r1,=UART0_CTL_R
        ldr         r0,[r1]
        bic         r0,r0,#UART_CTL_UART_ENV
        str         r0,[r1]

        ldr         r1,=UART0_IBRD_R
        ;baude rate = 16mhz / (16* 115200) =>8.6805
        mov         r0,#0x08
        str         r0,[r1]

        ldr         r1,=UART0_FBRD_R
        ;(0.6805) * 64 + 0.5 => 44.052
        mov         r0,#44
        str         r0,[r1]

        ldr         r1,=UART0_LCRH_R
        ldr         r0,[r1]
        bic         r0,r0,#0xff
        and         r0,r0,#(UART_CTL_UART_ENV + UART_LCRH_F_EN_V)
        str         r0,[r1]

        ldr         r1,=UART0_CTL_R
        ldr         r0,[r1]
        orr         r0,#UART_CTL_UART_ENV
        str         r0,[r1]

        pop         {pc}

__UART_read_char
        ldr         r1,=UART0_FLAG_R
__lp1   ldr         r0,[r1]
        ands         r0,r0,#0x0010
        bne         __lp1
        ldr         r1,=UART0_DATA_R
        ldr         r0,[r1]
        bx          lr
        
__UART_write_char
        ldr         r1,=UART0_FLAG_R
__lp2   ldr         r2,[r1]
        ands        r2,r2,#0x0020
        bne         __lp2
        ldr         r1,=UART0_DATA_R
        str         r0,[r1]
        bx          lr

        ALIGN
        END
