
#ifndef	__GLCD_ST7735_H
#define	__GLCD_ST7735_H

#include "TM4C123.h"                    // Device header
#include <stdint.h>
//LCD Pin
//REST----->PA7
//CS------->PA3
//DC------->PA6


#define SPI_CR1_SSE						0x00000002
#define SPI_CR1_MS						0x00000004
#define SPI_CC_CS_M						0x0000000F
#define SPI_CC_CS_SYSPLL			0x00000000
#define SPI_CPSR_CPSDVSR_M		0x000000FF
#define SPI_CR0_SCR_M					0x0000FF00
#define SPI_CR0_SPH						0x00000080
#define SPI_CR0_SPO						0x00000040
#define SPI_CR0_FRF_M					0x00000030
#define SPI_CR0_FRF_MOTO			0x00000000
#define SPI_CR0_DSS_M					0x0000000F
#define SPI_CR0_DSS_8					0x00000007
#define SPI_SR_BSY						0x00000010
#define SPI_SR_TNF						0x00000002

#define	DC										(*((volatile uint32_t *) 0X40004100))
#define DC_COMMAND						0
#define	DC_DATA								0X40

#define	LCD_PORT							GPIOA
#define	RS_PIN								(1U<<7)
#define	CS_PIN								(1U<<3)
#define DC_PIN								(1U<<6)

#define LCD_RS0								LCD_PORT->DATA		&=	~RS_PIN
#define	LCD_RS1								LCD_PORT->DATA		|=	 RS_PIN

#define LCD_CS0								LCD_PORT->DATA		&=	~CS_PIN
#define	LCD_CS1								LCD_PORT->DATA		|=	 CS_PIN

#define LCD_DC0								LCD_PORT->DATA		&=	~DC_PIN
#define	LCD_DC1								LCD_PORT->DATA		|=	 DC_PIN

#define	ST7735_TFT_Width			128
#define	ST7735_TFT_HEIGHT			160

#define	COLOR_BLACK						0X0000
#define	COLOR_BLUE						0XF800
#define	COLOR_RED							0X001F
#define	COLOR_GREEN						0X07E0
#define	COLOR_CYAN						0XFFE0
#define	COLOR_MAGENTA					0XF81F
#define	COLOR_YELLOW					0X07FF
#define	COLOR_WHITE						0XFFFF
#define	COLOR_ORANGE					0XFD60
#define	COLOR_LIGHT_GREEN			0X07EF


#define	ST7735_RA_SET					0X2B
#define	ST7735_CA_SET					0X2A
#define	ST7735_RA_MWR					0X2C
#define	ST7735_GMCTRP1				0XE0
#define	ST7735_GMCTRN1				0XE1
#define	ST7735_NORON					0X13
#define	ST7735_DISPON					0X29

#define	BG_COLOR							COLOR_BLACK
#define	AXIS_COLOR						COLOR_ORANGE
#define	LIGHT_COLOR						COLOR_LIGHT_GREEN

static const unsigned char	font[54];

#endif


