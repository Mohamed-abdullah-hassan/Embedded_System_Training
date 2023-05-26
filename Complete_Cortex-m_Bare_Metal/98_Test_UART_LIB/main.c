#include "configuration.h"

#include "GC9A01.h"
#include <math.h>
#include <stdio.h>


 void Delay_ms(int time_ms);
//#define BACKGROUND BLACK
//#define MARK_COLOR WHITE
//#define SUBMARK_COLOR DARKGREY // LIGHTGREY
//#define HOUR_COLOR WHITE
//#define MINUTE_COLOR BLUE // LIGHTGREY
//#define SECOND_COLOR RED

//#define SIXTIETH 0.016666667
//#define TWELFTH 0.08333333
//#define SIXTIETH_RADIAN 0.10471976
//#define TWELFTH_RADIAN 0.52359878
//#define RIGHT_ANGLE_RADIAN 1.5707963
//void writeSlashLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1,uint8_t *color);
//void draw_round_clock_mark(int16_t innerR1, int16_t outerR1, int16_t innerR2, int16_t outerR2, int16_t innerR3, int16_t outerR3);


//struct __FILE
//{
//  int dummyVar; //Just for the sake of redefining __FILE, we won't we using it anyways ;)
//};

//FILE __stdout;
//FILE __stdin;

//int fputc(int c, FILE * stream)
//{
//	UART_Write(c);
//	return c; //return the character written to denote a successfull write
//}


//#define RES PA7
//#define DC  PA6
//#define CS  PA5

//void setup(void);
//void loop(void);

//void Delay_ms(int time_ms)
//{
//    int i, j;
//    for(i = 0 ; i < time_ms; i++)
//        for(j = 0; j < 3180; j++)
//            {}  /* excute NOP for 1ms */
//}


//void GC9A01_set_reset(uint8_t val) {
//    //digitalWrite(RES, val);
//	if(val ==0)
//		GPIOA->DATA &= ~(1<<7);
//	else
//		GPIOA->DATA |= (1<<7);
//}

//void GC9A01_set_data_command(uint8_t val) {
//    //digitalWrite(DC, val);
//	if(val ==0)
//		GPIOA->DATA &= ~(1<<6);
//	else
//		GPIOA->DATA |= (1<<6);
//}

//void GC9A01_set_chip_select(uint8_t val) {
//    //digitalWrite(CS, val);
//	if(val ==0)
//		GPIOA->DATA &= ~(1<<5);
//	else
//		GPIOA->DATA |= (1<<5);
//}

//void GC9A01_spi_tx(uint8_t *data, size_t len) {
//    while (len--) {
//        SSI_Send(*data);
//        data++;
//    }
//}

//void GC9A01_delay(uint16_t ms) {
//    Delay_ms(ms);
//}

//void GC9A01_Fill_Display(uint8_t Color)
//{
//	GC9A01_set_data_command(0);
//    GC9A01_set_chip_select(0);
//    SSI_Send(0x2C);
//	GC9A01_set_data_command(1);
//    GC9A01_set_chip_select(0);
//	for (size_t i=0; i< (240*240*3);i++)
//	{
//			SSI_Send_Fast(Color);		
//	}
//	
//}
//void GC9A01_Fill_Display_Color(uint8_t R_Color,uint8_t G_Color,uint8_t B_Color)
//{
//	
//}



//int main (void)
//{
//	SSI_Init();
//	SYSCTL->RCGCGPIO |= 1<<0;
//	GPIOA->DIR |= 0b11100000;
//	GPIOA->DEN |= 0b11100000;
//	GPIOA->DATA |= 0b11100000;
//	setup();
//	while(1)
//	{
//		loop();
//	}
//}

//void setup() {
//    
//    //pinMode(RES, OUTPUT);
//    //pinMode(DC, OUTPUT);
//    //pinMode(CS, OUTPUT);
//    //SPI.begin();
//    GC9A01_init();
//    struct GC9A01_frame frame = {{0,0},{239,239}};
//    GC9A01_set_frame(frame);  
//		UART_Init();
//		
//}

//void loop() {
//	UART_Write('H');
//	UART_Write('\n');
//	_printf("Hello from Mohamed\n");

//    uint8_t color[3];

//    // Triangle
//    color[0] = 0xFF;
//    color[1] = 0xFF;
//    for (int x = 0; x < 240; x++) {
//        for (int y = 0; y < 240; y++) {
//            if (x < y) {
//                color[2] = 0xFF;
//            } else {
//                color[2] = 0x00;
//            }
//            if (x == 0 && y == 0) {
//                //GC9A01_write(color, sizeof(color));
//							GC9A01_write_frame(color, sizeof(color));
//            } else {
//                //GC9A01_write_continue(color, sizeof(color));
//							GC9A01_write_continue_frame(color, sizeof(color));
//            }
//        }
//    }
//		GC9A01_flush_frame();

//    Delay_ms(100);

//    // Rainbow
//    float frequency = 0.026;
//    for (int x = 0; x < 240; x++) {
//        color[0] = sin(frequency*x + 0) * 127 + 128;
//        color[1] = sin(frequency*x + 2) * 127 + 128;
//        color[2] = sin(frequency*x + 4) * 127 + 128;
//        for (int y = 0; y < 240; y++) {
//            if (x == 0 && y == 0) {
//                //GC9A01_write(color, sizeof(color));
//							GC9A01_write_frame(color, sizeof(color));
//            } else {
//                //GC9A01_write_continue(color, sizeof(color));
//							GC9A01_write_continue_frame(color, sizeof(color));
//            }
//        }
//    }
//		GC9A01_flush_frame();

//    Delay_ms(1000);

//    // Checkerboard
//    for (int x = 0; x < 240; x++) {
//        for (int y = 0; y < 240; y++) {
//            if ((x / 10) % 2 ==  (y / 10) % 2) {
//                color[0] = 0xFF;
//                color[1] = 0xFF;
//                color[2] = 0xFF;
//            } else {
//                color[0] = 0x00;
//                color[1] = 0x00;
//                color[2] = 0x00;
//            }
//            //if (x == 0 && y == 0) {
//           //     GC9A01_write(color, sizeof(color));
//            //} else {
//            //    GC9A01_write_continue(color, sizeof(color));
//           // }
//						if (x == 0 && y == 0) {
//                //GC9A01_write(color, sizeof(color));
//							GC9A01_write_frame(color, sizeof(color));
//            } else {
//                //GC9A01_write_continue(color, sizeof(color));
//							GC9A01_write_continue_frame(color, sizeof(color));
//            }
//        }
//    }
//		GC9A01_flush_frame();
//		

//    Delay_ms(1000);
//		GC9A01_Fill_Display(0);
//		//_printf("Defening lcd boundary\n Horisontal\n");
//		color[0] = 0XFF;
//		color[1] = 0;
//		color[2] = 0;
//		for(int x = 0; x<240;x++)
//		{
//		//	_printf("X=%d, Y=%d\n",x,120);
//		drawPixel( x,  120, color,  sizeof(color));
//			//if((x<=5) || (x>=235))
//			//Delay_ms (5000);
//		//GC9A01_write_continue(color,  sizeof(color));
//			//GC9A01_write_continue(color,  sizeof(color));
//			
//		}
//		color[0] = 0;
//		color[1] = 0XFF;
//		color[2] = 0XFF;
//		for(int x = 0; x<240;x++)
//		{
//			
//		drawPixel( x,  x, color,  sizeof(color));
//		//GC9A01_write_continue(color,  sizeof(color));
//			//GC9A01_write_continue(color,  sizeof(color));
//			
//		}
//		//_printf("\n\n\n    Vertical    \n");
//		color[0] = 0XFF;
//		color[1] = 0X3F;
//		color[2] = 0X7F;
//		Delay_ms (1000);
//		for(int x = 0; x<240;x++)
//		{
//			//_printf("X=%d, Y=%d\n",120,x);
//			//Delay_ms (1000);
//		drawPixel( 120,  x, color,  sizeof(color));
//			//if((x<=5) || (x>=220))
//			//Delay_ms (5000);
//		//GC9A01_write_continue(color,  sizeof(color));
//			//GC9A01_write_continue(color,  sizeof(color));

//		}
//		Delay_ms(10000);
//		cler_drawPixel();
//		GC9A01_Fill_Display(00);
//		
//		draw_round_clock_mark(120 - 16, 120,
//													120 - (16 * 2 / 3), 120,
//													120 - (16 / 2), 120);

//		
//		//GC9A01_write_continue(color,  sizeof(color));
//		//GC9A01_write_continue(color,  sizeof(color));
//		//GC9A01_write_continue(color,  sizeof(color));
//		//GC9A01_write_continue(color,  sizeof(color));
//		//GC9A01_write_continue(color,  sizeof(color));
//		//GC9A01_write_continue(color,  sizeof(color));
//		//for (int yyy= 0; yyy<10; yyy++)
//		//{
//		//	GC9A01_write_continue(color,  sizeof(color));
//		//GC9A01_write_continue(color,  sizeof(color));
//		//}
//		Delay_ms(10000);
//		cler_drawPixel();
//		Delay_ms(100);
//		GC9A01_Fill_Display(0x00);
//		Delay_ms(100);
//		GC9A01_Fill_Display(0x11);
//		//Delay_ms(100);
//		GC9A01_Fill_Display(0x22);
//		//Delay_ms(100);
//		GC9A01_Fill_Display(0x33);
//		//Delay_ms(100);
//		GC9A01_Fill_Display(0x44);
//		//Delay_ms(100);
//		GC9A01_Fill_Display(0x55);
//		//Delay_ms(100);
//		GC9A01_Fill_Display(0x66);
//		//Delay_ms(100);
//		GC9A01_Fill_Display(0x77);
//		//Delay_ms(100);
//		GC9A01_Fill_Display(0x88);
//		//Delay_ms(100);
//		GC9A01_Fill_Display(0x99);
//		//Delay_ms(100);
//		GC9A01_Fill_Display(0xAA);
//		//Delay_ms(100);
//		GC9A01_Fill_Display(0xBB);
//		//Delay_ms(100);
//		GC9A01_Fill_Display(0xCC);
//		//Delay_ms(100);
//		GC9A01_Fill_Display(0xDD);
//		//Delay_ms(100);
//		GC9A01_Fill_Display(0xEE);
//		//Delay_ms(100);
//		GC9A01_Fill_Display(0xFF);
//		
//		Delay_ms(1000);

//    // Swiss flag
//    color[0] = 0xFF;
//    for (int x = 0; x < 240; x++) {
//        for (int y = 0; y < 240; y++) {
//            if ((x >= 1*48 && x < 4*48 && y >= 2*48 && y < 3*48) ||
//                (x >= 2*48 && x < 3*48 && y >= 1*48 && y < 4*48)) {
//                color[1] = 0xFF;
//                color[2] = 0xFF;
//            } else {
//                color[1] = 0x00;
//                color[2] = 0x00;
//            }
//           // if (x == 0 && y == 0) {
//           //     GC9A01_write(color, sizeof(color));
//           // } else {
//            //    GC9A01_write_continue(color, sizeof(color));
//            //}
//						if (x == 0 && y == 0) {
//                //GC9A01_write(color, sizeof(color));
//							GC9A01_write_frame(color, sizeof(color));
//            } else {
//                //GC9A01_write_continue(color, sizeof(color));
//							GC9A01_write_continue_frame(color, sizeof(color));
//            }
//        }
//    }
//		
//		GC9A01_flush_frame();

//    Delay_ms(100);

//}


//static float mdeg;
//static int16_t center;

//void draw_round_clock_mark(int16_t innerR1, int16_t outerR1, int16_t innerR2, int16_t outerR2, int16_t innerR3, int16_t outerR3)
//{
//  float x, y;
//	center = 120;
////	w = 120;
////	h = 120;
//  int16_t x0, x1, y0, y1, innerR, outerR;
//  uint8_t c[3];

//  for (uint8_t i = 0; i < 60; i++)
//  {
//    if ((i % 15) == 0)
//    {
//      innerR = innerR1;
//      outerR = outerR1;
//       c[0] = c[1] = c[2] = 0XFF;
//    }
//    else if ((i % 5) == 0)
//    {
//      innerR = innerR2;
//      outerR = outerR2;
//      c[0] = c[1] = c[2] = 0XFF;
//    }
//    else
//    {
//      innerR = innerR3;
//      outerR = outerR3;
//      c[0] = 0xff;
//			c[1] = 0;
//			c[2] = 0X1F;
//    }

//    mdeg = (SIXTIETH_RADIAN * i) - RIGHT_ANGLE_RADIAN;
//    x = cos(mdeg);
//    y = sin(mdeg);
//    x0 = x * outerR + center;
//    y0 = y * outerR + center;
//    x1 = x * innerR + center;
//    y1 = y * innerR + center;

//    writeSlashLine(x0, y0, x1, y1, c);
//  }
//}
//#define _diff(a, b) ((a > b) ? (a - b) : (b - a))
//#define _swap_int16_t(a, b) \
//  {                         \
//    int16_t t = a;          \
//    a = b;                  \
//    b = t;                  \
//  }
//void writeSlashLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
//                                 uint8_t *color)
//{
//    unsigned char steep = _diff(y1, y0) > _diff(x1, x0);
//    if (steep)
//    {
//        _swap_int16_t(x0, y0);
//        _swap_int16_t(x1, y1);
//    }

//    if (x0 > x1)
//    {
//        _swap_int16_t(x0, x1);
//        _swap_int16_t(y0, y1);
//    }

//    int16_t dx = x1 - x0;
//    int16_t dy = _diff(y1, y0);
//    int16_t err = dx >> 1;
//    int16_t step = (y0 < y1) ? 1 : -1;

//    for (; x0 <= x1; x0++)
//    {
//			//Delay_ms (10);
//        if (steep)
//        {
//            drawPixel(y0, x0, color,3);
//					
//        }
//        else
//        {
//            drawPixel(x0, y0, color,3);
//        }
//        err -= dy;
//        if (err < 0)
//        {
//            err += dx;
//            y0 += step;
//        }
//    }
//}

















 ////////////////////
 #include <stdint.h>
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include "TM4C123.h"                    // Device header
 #include "math.h"
 const uint8_t OledFont[][8] =
 {
   {0x00,0x00,0x00,0x00,0x00},
   {0x00,0x5F,0x00,0x00,0x00},
   {0x00,0x07,0x00,0x07,0x00},
   {0x14,0x7F,0x14,0x7F,0x14},
   {0x24,0x2A,0x7F,0x2A,0x12},
   {0x23,0x13,0x08,0x64,0x62},
   {0x36,0x49,0x55,0x22,0x50},
   {0x00,0x05,0x03,0x00,0x00},
   {0x1C,0x22,0x41,0x00,0x00},
   {0x41,0x22,0x1C,0x00,0x00},
   {0x08,0x2A,0x1C,0x2A,0x08},
   {0x08,0x08,0x3E,0x08,0x08},
   {0xA0,0x60,0x00,0x00,0x00},
   {0x08,0x08,0x08,0x08,0x08},
   {0x60,0x60,0x00,0x00,0x00},
   {0x20,0x10,0x08,0x04,0x02},//
   {0x3E,0x51,0x49,0x45,0x3E},
   {0x00,0x42,0x7F,0x40,0x00},
   {0x62,0x51,0x49,0x49,0x46},
   {0x22,0x41,0x49,0x49,0x36},
   {0x18,0x14,0x12,0x7F,0x10},
   {0x27,0x45,0x45,0x45,0x39},
   {0x3C,0x4A,0x49,0x49,0x30},
   {0x01,0x71,0x09,0x05,0x03},
   {0x36,0x49,0x49,0x49,0x36},
   {0x06,0x49,0x49,0x29,0x1E},
   {0x00,0x36,0x36,0x00,0x00},
   {0x00,0xAC,0x6C,0x00,0x00},
   {0x08,0x14,0x22,0x41,0x00},
   {0x14,0x14,0x14,0x14,0x14},
   {0x41,0x22,0x14,0x08,0x00},
   {0x02,0x01,0x51,0x09,0x06},
   {0x32,0x49,0x79,0x41,0x3E},
   {0x7E,0x09,0x09,0x09,0x7E},
   {0x7F,0x49,0x49,0x49,0x36},
   {0x3E,0x41,0x41,0x41,0x22},
   {0x7F,0x41,0x41,0x22,0x1C},
   {0x7F,0x49,0x49,0x49,0x41},
   {0x7F,0x09,0x09,0x09,0x01},
   {0x3E,0x41,0x41,0x51,0x72},
   {0x7F,0x08,0x08,0x08,0x7F},
   {0x41,0x7F,0x41,0x00,0x00},
   {0x20,0x40,0x41,0x3F,0x01},
   {0x7F,0x08,0x14,0x22,0x41},
   {0x7F,0x40,0x40,0x40,0x40},
   {0x7F,0x02,0x0C,0x02,0x7F},
   {0x7F,0x04,0x08,0x10,0x7F},
   {0x3E,0x41,0x41,0x41,0x3E},
   {0x7F,0x09,0x09,0x09,0x06},
   {0x3E,0x41,0x51,0x21,0x5E},
   {0x7F,0x09,0x19,0x29,0x46},
   {0x26,0x49,0x49,0x49,0x32},
   {0x01,0x01,0x7F,0x01,0x01},
   {0x3F,0x40,0x40,0x40,0x3F},
   {0x1F,0x20,0x40,0x20,0x1F},
   {0x3F,0x40,0x38,0x40,0x3F},
   {0x63,0x14,0x08,0x14,0x63},
   {0x03,0x04,0x78,0x04,0x03},
   {0x61,0x51,0x49,0x45,0x43},
   {0x7F,0x41,0x41,0x00,0x00},
   {0x02,0x04,0x08,0x10,0x20},
   {0x41,0x41,0x7F,0x00,0x00},
   {0x04,0x02,0x01,0x02,0x04},
   {0x80,0x80,0x80,0x80,0x80},
   {0x01,0x02,0x04,0x00,0x00},
   {0x20,0x54,0x54,0x54,0x78},
   {0x7F,0x48,0x44,0x44,0x38},
   {0x38,0x44,0x44,0x28,0x00},
   {0x38,0x44,0x44,0x48,0x7F},
   {0x38,0x54,0x54,0x54,0x18},
   {0x08,0x7E,0x09,0x02,0x00},
   {0x18,0xA4,0xA4,0xA4,0x7C},
   {0x7F,0x08,0x04,0x04,0x78},
   {0x00,0x7D,0x00,0x00,0x00},
   {0x80,0x84,0x7D,0x00,0x00},
   {0x7F,0x10,0x28,0x44,0x00},
   {0x41,0x7F,0x40,0x00,0x00},
   {0x7C,0x04,0x18,0x04,0x78},
   {0x7C,0x08,0x04,0x7C,0x00},
   {0x38,0x44,0x44,0x38,0x00},
   {0xFC,0x24,0x24,0x18,0x00},
   {0x18,0x24,0x24,0xFC,0x00},
   {0x00,0x7C,0x08,0x04,0x00},
   {0x48,0x54,0x54,0x24,0x00},
   {0x04,0x7F,0x44,0x00,0x00},
   {0x3C,0x40,0x40,0x7C,0x00},
   {0x1C,0x20,0x40,0x20,0x1C},
   {0x3C,0x40,0x30,0x40,0x3C},
   {0x44,0x28,0x10,0x28,0x44},
   {0x1C,0xA0,0xA0,0x7C,0x00},
   {0x44,0x64,0x54,0x4C,0x44},
   {0x08,0x36,0x41,0x00,0x00},
   {0x00,0x7F,0x00,0x00,0x00},
   {0x41,0x36,0x08,0x00,0x00},
   {0x02,0x01,0x01,0x02,0x01},
   {0x02,0x05,0x05,0x02,0x00},
 };

 //#define USE_OLED_128X32
 #define USE_OLED_128X64

	
 // Define OLED dimensions
 #ifdef	USE_OLED_128X32
 #define OLED_WIDTH 128
 #define OLED_HEIGHT 32
 #define slaveaddress 0x3C
 #else
 #ifdef USE_OLED_128X64
 	#define OLED_WIDTH 128
 	#define OLED_HEIGHT 64
 	#define slaveaddress 0x78
 #endif
 #endif


 // Define command macros
 #define OLED_SETCONTRAST 0x81
 #define OLED_DISPLAYALLON_RESUME 0xA4
 #define OLED_DISPLAYALLON 0xA5
 #define OLED_NORMALDISPLAY 0xA6
 #define OLED_INVERTDISPLAY 0xA7
 #define OLED_DISPLAYOFF 0xAE
 #define OLED_DISPLAYON 0xAF
 #define OLED_SETDISPLAYOFFSET 0xD3
 #define OLED_SETCOMPINS 0xDA
 #define OLED_SETVCOMDETECT 0xDB
 #define OLED_SETDISPLAYCLOCKDIV 0xD5
 #define OLED_SETPRECHARGE 0xD9
 #define OLED_SETMULTIPLEX 0xA8
 #define OLED_SETLOWCOLUMN 0x00
 #define OLED_SETHIGHCOLUMN 0x10
 #define OLED_SETSTARTLINE 0x40
 #define OLED_MEMORYMODE 0x20
 #define OLED_COLUMNADDR 0x21
 #define OLED_PAGEADDR   0x22
 #define OLED_COMSCANINC 0xC0
 #define OLED_COMSCANDEC 0xC8
 #define OLED_SEGREMAP 0xA0
 #define OLED_CHARGEPUMP 0x8D


 // Function declarations
 void OLED_Command( uint8_t temp);
 void OLED_Data( uint8_t  temp);
 void OLED_Init(void);
 void OLED_YX(unsigned char Row, unsigned char Column); // *warning!* max 4 rows
 void OLED_PutChar( char ch );
 void OLED_Clear(void);
 void OLED_Write_String( char *s );
 void OLED_Write_Integer(uint32_t  i);
 void OLED_Write_Float(float f);
 char OLED_Write_Multiple(int slave_address, char slave_memory_address, int bytes_count, uint8_t* data);


 char I2C3_Write_Multiple(int slave_address, char slave_memory_address, int bytes_count, uint8_t* data);

 static int I2C_wait_till_done(void);

 // Function prototypes initialize, tranmit and rea functions 
 //void I2C3_Init ( void );  
 //static int I2C_wait_till_done(void);
 //char I2C3_Write_Multiple(int slave_address, char slave_memory_address, int bytes_count, uint8_t* data);
 //char I2C3_Wr(int slaveAddr, char memAddr, uint8_t data);


 /////////////////////////////
 void Delay(unsigned long );

 int main(void)
 {
 	I2C_Init();
 	UART_Init();
 	//////////
 	 OLED_Init();
 	 OLED_Clear();
 	    int count = 0;
	 OLED_Clear();
	  OLED_Clear();
	  OLED_Clear();
	 
	
 	//////////
	
	
	
 	while(1){
 	UART_Write('H');
 	UART_Write('e');
 	UART_Write('l');
 	UART_Write('l');
 	UART_Write('o');
 	UART_Write('!');
 	UART_Write('\n');

 		/////////////////////
 		// Strings
 		///////////////////

 		OLED_YX( 0, 0 );
 		OLED_Write_String( "OLED SSD1306" );
 		Delay_ms(1000);

 		OLED_YX(1, 0);
 		OLED_Write_String ("TM4C123GH6PM.");
 		Delay_ms(1000);

 		OLED_YX(3, 0);
 		OLED_Write_String ("Mohohamed");
 		OLED_YX(4, 0);
 		OLED_Write_String (" Abdullah");
 		OLED_YX(5, 0);
 		OLED_Write_String ("  Mohohamed");
 		OLED_YX(6, 0);
 		OLED_Write_String ("   Abdulhamed");
 		OLED_YX(7, 0);
 		OLED_Write_String ("    Hassan");
 		Delay_ms(100);

 		/////////////////////
 		// Integer Count
 		////////////////////
 		OLED_YX(2, 0 );
 		OLED_Write_String( "Count:" );
 		Delay_ms(1000);
		
 		for (count = -5999; count <= 5999; count++){
 		OLED_YX(2, 7);
 		OLED_Write_Integer(count);
 		//Delay_ms(50);
 		}
 		Delay_ms(5000);
 		OLED_Clear();
 		Delay_ms(100);
            
 	Delay(10000);	
 }
 	}


	
	
 void Delay(unsigned long counter)
 {
 	unsigned long i = 0;
	
 	for(i=0; i< counter; i++);
 }






 void OLED_Command( uint8_t cmd){
    
 	I2C_Multi_Write_Start(0x3C,0x00);
 	I2C_Multi_Write_Stop(cmd);
 	  //I2C3_Wr(0x3C,0x00,cmd);
 }

 static int I2C_wait_till_done(void)
 {
     while(I2C_get_Status() & 1);   /* wait until I2C master is not busy */
     return 0;//(I2C_get_Status() & 0xE); /* return I2C error code, 0 if no error*/
 }



 void OLED_Data( uint8_t data){
 
 	I2C_Multi_Write_Start(0x3C,0x40);
 	I2C_Multi_Write_Stop(data);	 
 }



 void OLED_Init() {
    
     OLED_Command(OLED_DISPLAYOFF);         // 0xAE
     OLED_Command(OLED_SETDISPLAYCLOCKDIV); // 0xD5
     OLED_Command(0x80);                    // the suggested ratio 0x80
     OLED_Command(OLED_SETMULTIPLEX);       // 0xA8
     OLED_Command(0x3F);// Old is 0x1f
 		//OLED_Command(0x1F);// Old is 0x1f
     OLED_Command(OLED_SETDISPLAYOFFSET);   // 0xD3
     OLED_Command(0x0);                        // no offset
     OLED_Command(OLED_SETSTARTLINE | 0x0); // line #0
     OLED_Command(OLED_CHARGEPUMP);         // 0x8D
     OLED_Command(0xAF);
     OLED_Command(OLED_MEMORYMODE);         // 0x20
     OLED_Command(0x00);                    // 0x0 act like ks0108
     OLED_Command(OLED_SEGREMAP | 0x1);
     OLED_Command(OLED_COMSCANDEC);
     OLED_Command(OLED_SETCOMPINS);         // 0xDA
     OLED_Command(0x12);// old was 0x02
 		// OLED_Command(0x02);// old was 0x02
	
     OLED_Command(OLED_SETCONTRAST);        // 0x81
     OLED_Command(0x8F);
     OLED_Command(OLED_SETPRECHARGE);       // 0xd9
     OLED_Command(0xF1);
     OLED_Command(OLED_SETVCOMDETECT);      // 0xDB
     OLED_Command(0x40);
     OLED_Command(OLED_DISPLAYALLON_RESUME);// 0xA4
     OLED_Command(OLED_NORMALDISPLAY);      // 0xA6
     OLED_Command(OLED_DISPLAYON);          //--turn on oled panel

 }

 void OLED_YX(unsigned char Row, unsigned char Column)
 {
     OLED_Command( 0xB0 + Row);
     OLED_Command( 0x00 + (8*Column & 0x0F) );
     OLED_Command( 0x10 + ((8*Column>>4)&0x0F) );
 }

 void OLED_PutChar(char ch )
 {
     if ( ( ch < 32 ) || ( ch > 127 ) ){
         ch = ' ';
     }

    const uint8_t *base = &OledFont[ch - 32][0];

     uint8_t bytes[7];
     bytes[0] = 0x0;
     bytes[1] = 0x0;

     // memmove( bytes + 1, base, 8 );
     memmove( bytes + 2, base, 5 );
       
 		//OLED_Write_Multiple(0x3C,0x40,9,bytes);
     //Delay_ms(50);
 		// I2C3_Write_Multiple(0x3C,0x40,9,bytes);
 		I2C3_Write_Multiple(0x3C,0x40,7,bytes);

 }

 char I2C3_Write_Multiple(int slave_address, char slave_memory_address, int bytes_count, uint8_t* data)
 {   
     char error;
     if (bytes_count <= 0)
         return (char)-1;                  /* no write was performed */
     /* send slave address and starting address */
     I2C3->MSA = slave_address << 1;
     I2C3->MDR = slave_memory_address;
     I2C3->MCS = 3;                  /* S-(saddr+w)-ACK-maddr-ACK */

     error = I2C_wait_till_done();   /* wait until write is complete */
     if (error) return error;

     /* send data one byte at a time */
     while (bytes_count > 1)
     {
         I2C3->MDR = *data++;             /* write the next byte */
         I2C3->MCS = 1;                   /* -data-ACK- */
         error = I2C_wait_till_done();
         if (error) return error;
         bytes_count--;
			 Delay_ms(1);
     }
    
     /* send last byte and a STOP */
     I2C3->MDR = *data++;                 /* write the last byte */
     I2C3->MCS = 5;                       /* -data-ACK-P */
     error = I2C_wait_till_done();
     while(I2C3->MCS & 0x40);             /* wait until bus is not busy */
     if (error) return error;
		 		 Delay_ms(1);
     return 0;       /* no error */

 }

 void OLED_Clear()
 {
     for ( uint16_t row = 0; row < 8; row++ ) {
         for ( uint16_t col = 0; col < 26; col++ ) {
             OLED_YX( row, col );
             OLED_PutChar('*');
					 Delay_ms(100);
         }
     }
 }

 void OLED_Write_String( char *s )
 {
     while (*s) 
 		{
 			OLED_PutChar( *s++);
 			//Delay_ms(100);
 		}
 }

 void OLED_Write_Integer(uint32_t  i)
 {
      char s[20];
      sprintf( s, "%+05d", i );
      OLED_Write_String( s );
      //OLED_Write_String( "     " );
 }
 void OLED_Write_Float(float f)
 {
     char* buf11;
 //    int status;
     sprintf( buf11, "%f", f );
     OLED_Write_String(buf11);
     OLED_Write_String( "     " );
 }
 void Delay_ms(int time_ms)
 {
     int i, j;
     for(i = 0 ; i < time_ms; i++)
         for(j = 0; j < 3180; j++)
             {}  /* excute NOP for 1ms */
 }

 char OLED_Write_Multiple(int slave_address, char slave_memory_address, int bytes_count, uint8_t* data)
 {
 	char error;
     if (bytes_count <= 0)
         return (char)-1;                  /* no write was performed */
     /* send slave address and starting address */
 		error = I2C_Multi_Write_Start(slave_address,slave_memory_address);
     if (error) return error;
     /* send data one byte at a time */
     while (bytes_count > 1)
     {
			
         error = I2C_Multi_Write(*data++);
         if (error) return error;
         bytes_count--;
     }
    
     /* send last byte and a STOP */
     error = I2C_Multi_Write_Stop(*data++);
     while(I2C_get_Status() & 0x40);             /* wait until bus is not busy */
     if (error) return error;
     return 0;       /* no error */
 }


// /*const uint8_t OledFont[][8] =
// {
//   {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
//   {0x00,0x00,0x5F,0x00,0x00,0x00,0x00,0x00},
//   {0x00,0x00,0x07,0x00,0x07,0x00,0x00,0x00},
//   {0x00,0x14,0x7F,0x14,0x7F,0x14,0x00,0x00},
//   {0x00,0x24,0x2A,0x7F,0x2A,0x12,0x00,0x00},
//   {0x00,0x23,0x13,0x08,0x64,0x62,0x00,0x00},
//   {0x00,0x36,0x49,0x55,0x22,0x50,0x00,0x00},
//   {0x00,0x00,0x05,0x03,0x00,0x00,0x00,0x00},
//   {0x00,0x1C,0x22,0x41,0x00,0x00,0x00,0x00},
//   {0x00,0x41,0x22,0x1C,0x00,0x00,0x00,0x00},
//   {0x00,0x08,0x2A,0x1C,0x2A,0x08,0x00,0x00},
//   {0x00,0x08,0x08,0x3E,0x08,0x08,0x00,0x00},
//   {0x00,0xA0,0x60,0x00,0x00,0x00,0x00,0x00},
//   {0x00,0x08,0x08,0x08,0x08,0x08,0x00,0x00},
//   {0x00,0x60,0x60,0x00,0x00,0x00,0x00,0x00},
//   {0x00,0x20,0x10,0x08,0x04,0x02,0x00,0x00},//
//   {0x00,0x3E,0x51,0x49,0x45,0x3E,0x00,0x00},
//   {0x00,0x00,0x42,0x7F,0x40,0x00,0x00,0x00},
//   {0x00,0x62,0x51,0x49,0x49,0x46,0x00,0x00},
//   {0x00,0x22,0x41,0x49,0x49,0x36,0x00,0x00},
//   {0x00,0x18,0x14,0x12,0x7F,0x10,0x00,0x00},
//   {0x00,0x27,0x45,0x45,0x45,0x39,0x00,0x00},
//   {0x00,0x3C,0x4A,0x49,0x49,0x30,0x00,0x00},
//   {0x00,0x01,0x71,0x09,0x05,0x03,0x00,0x00},
//   {0x00,0x36,0x49,0x49,0x49,0x36,0x00,0x00},
//   {0x00,0x06,0x49,0x49,0x29,0x1E,0x00,0x00},
//   {0x00,0x00,0x36,0x36,0x00,0x00,0x00,0x00},
//   {0x00,0x00,0xAC,0x6C,0x00,0x00,0x00,0x00},
//   {0x00,0x08,0x14,0x22,0x41,0x00,0x00,0x00},
//   {0x00,0x14,0x14,0x14,0x14,0x14,0x00,0x00},
//   {0x00,0x41,0x22,0x14,0x08,0x00,0x00,0x00},
//   {0x00,0x02,0x01,0x51,0x09,0x06,0x00,0x00},
//   {0x00,0x32,0x49,0x79,0x41,0x3E,0x00,0x00},
//   {0x00,0x7E,0x09,0x09,0x09,0x7E,0x00,0x00},
//   {0x00,0x7F,0x49,0x49,0x49,0x36,0x00,0x00},
//   {0x00,0x3E,0x41,0x41,0x41,0x22,0x00,0x00},
//   {0x00,0x7F,0x41,0x41,0x22,0x1C,0x00,0x00},
//   {0x00,0x7F,0x49,0x49,0x49,0x41,0x00,0x00},
//   {0x00,0x7F,0x09,0x09,0x09,0x01,0x00,0x00},
//   {0x00,0x3E,0x41,0x41,0x51,0x72,0x00,0x00},
//   {0x00,0x7F,0x08,0x08,0x08,0x7F,0x00,0x00},
//   {0x00,0x41,0x7F,0x41,0x00,0x00,0x00,0x00},
//   {0x00,0x20,0x40,0x41,0x3F,0x01,0x00,0x00},
//   {0x00,0x7F,0x08,0x14,0x22,0x41,0x00,0x00},
//   {0x00,0x7F,0x40,0x40,0x40,0x40,0x00,0x00},
//   {0x00,0x7F,0x02,0x0C,0x02,0x7F,0x00,0x00},
//   {0x00,0x7F,0x04,0x08,0x10,0x7F,0x00,0x00},
//   {0x00,0x3E,0x41,0x41,0x41,0x3E,0x00,0x00},
//   {0x00,0x7F,0x09,0x09,0x09,0x06,0x00,0x00},
//   {0x00,0x3E,0x41,0x51,0x21,0x5E,0x00,0x00},
//   {0x00,0x7F,0x09,0x19,0x29,0x46,0x00,0x00},
//   {0x00,0x26,0x49,0x49,0x49,0x32,0x00,0x00},
//   {0x00,0x01,0x01,0x7F,0x01,0x01,0x00,0x00},
//   {0x00,0x3F,0x40,0x40,0x40,0x3F,0x00,0x00},
//   {0x00,0x1F,0x20,0x40,0x20,0x1F,0x00,0x00},
//   {0x00,0x3F,0x40,0x38,0x40,0x3F,0x00,0x00},
//   {0x00,0x63,0x14,0x08,0x14,0x63,0x00,0x00},
//   {0x00,0x03,0x04,0x78,0x04,0x03,0x00,0x00},
//   {0x00,0x61,0x51,0x49,0x45,0x43,0x00,0x00},
//   {0x00,0x7F,0x41,0x41,0x00,0x00,0x00,0x00},
//   {0x00,0x02,0x04,0x08,0x10,0x20,0x00,0x00},
//   {0x00,0x41,0x41,0x7F,0x00,0x00,0x00,0x00},
//   {0x00,0x04,0x02,0x01,0x02,0x04,0x00,0x00},
//   {0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00},
//   {0x00,0x01,0x02,0x04,0x00,0x00,0x00,0x00},
//   {0x00,0x20,0x54,0x54,0x54,0x78,0x00,0x00},
//   {0x00,0x7F,0x48,0x44,0x44,0x38,0x00,0x00},
//   {0x00,0x38,0x44,0x44,0x28,0x00,0x00,0x00},
//   {0x00,0x38,0x44,0x44,0x48,0x7F,0x00,0x00},
//   {0x00,0x38,0x54,0x54,0x54,0x18,0x00,0x00},
//   {0x00,0x08,0x7E,0x09,0x02,0x00,0x00,0x00},
//   {0x00,0x18,0xA4,0xA4,0xA4,0x7C,0x00,0x00},
//   {0x00,0x7F,0x08,0x04,0x04,0x78,0x00,0x00},
//   {0x00,0x00,0x7D,0x00,0x00,0x00,0x00,0x00},
//   {0x00,0x80,0x84,0x7D,0x00,0x00,0x00,0x00},
//   {0x00,0x7F,0x10,0x28,0x44,0x00,0x00,0x00},
//   {0x00,0x41,0x7F,0x40,0x00,0x00,0x00,0x00},
//   {0x00,0x7C,0x04,0x18,0x04,0x78,0x00,0x00},
//   {0x00,0x7C,0x08,0x04,0x7C,0x00,0x00,0x00},
//   {0x00,0x38,0x44,0x44,0x38,0x00,0x00,0x00},
//   {0x00,0xFC,0x24,0x24,0x18,0x00,0x00,0x00},
//   {0x00,0x18,0x24,0x24,0xFC,0x00,0x00,0x00},
//   {0x00,0x00,0x7C,0x08,0x04,0x00,0x00,0x00},
//   {0x00,0x48,0x54,0x54,0x24,0x00,0x00,0x00},
//   {0x00,0x04,0x7F,0x44,0x00,0x00,0x00,0x00},
//   {0x00,0x3C,0x40,0x40,0x7C,0x00,0x00,0x00},
//   {0x00,0x1C,0x20,0x40,0x20,0x1C,0x00,0x00},
//   {0x00,0x3C,0x40,0x30,0x40,0x3C,0x00,0x00},
//   {0x00,0x44,0x28,0x10,0x28,0x44,0x00,0x00},
//   {0x00,0x1C,0xA0,0xA0,0x7C,0x00,0x00,0x00},
//   {0x00,0x44,0x64,0x54,0x4C,0x44,0x00,0x00},
//   {0x00,0x08,0x36,0x41,0x00,0x00,0x00,0x00},
//   {0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00},
//   {0x00,0x41,0x36,0x08,0x00,0x00,0x00,0x00},
//   {0x00,0x02,0x01,0x01,0x02,0x01,0x00,0x00},
//   {0x00,0x02,0x05,0x05,0x02,0x00,0x00,0x00},
// };*/

