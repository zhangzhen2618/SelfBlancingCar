#ifndef __CC2530_LCD_H__
#define __CC2530_LCD_H__		

#include <cc2530.h>
#include <stdint.h>
#include "cc2530io_bitdef.h"
#include "sys_config.h"

/////////////////////////////////////用户配置区///////////////////////////////////	 
//支持横竖屏快速定义切换
#define USE_HORIZONTAL  	0 //定义液晶屏顺时针旋转方向 	0-0度旋转，1-90度旋转，2-180度旋转，3-270度旋转
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////	  
//定义LCD的尺寸
#define LCD_W 						128
#define LCD_H 						128

//IO连接
#define LCD_RS 	 	 				P1_7  		 //数据/命令切换
#define LCD_SDI 	 				P1_6		  //SPI写
// #define LCD_SDO 	 P1_2		     //SPI读
#define LCD_CS 	 	 				P1_4		//片选	
#define LCD_CLK 	 				P1_5   //SPI时钟
#define LCD_RESET 	 				P1_2	      //复位 
#define LCD_BL		 				P1_3		//背光控制，STC89C52RC单片滑接3.3V

//画笔颜色
#define WHITE         	 			0xFFFF
#define BLACK         	 			0x0000	  
#define BLUE         	 			0x001F  
#define BRED             			0XF81F
#define GRED 			 			0XFFE0
#define GBLUE			 			0X07FF
#define RED           	 			0xF800
#define MAGENTA       	 			0xF81F
#define GREEN         	 			0x07E0
#define CYAN          	 			0x7FFF
#define YELLOW        	 			0xFFE0
#define BROWN 			 			0XBC40 //棕色
#define BRRED 			 			0XFC07 //棕红色
#define GRAY  			 			0X8430 //灰色
#define GRAY0       	 			0xEF7D 
#define GRAY1       	 			0x8410      	//灰色1      00000 000000 00000
#define GRAY2       	 			0x4208 
//GUI颜色

#define DARKBLUE      	 			0X01CF	//深蓝色
#define LIGHTBLUE      	 			0X7D7C	//浅蓝色  
#define GRAYBLUE       	 			0X5458 //灰蓝色
//以上三色为PANEL的颜色 
 
#define LIGHTGREEN     	 			0X841F //浅绿色
#define LGRAY 			 			0XC618 //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE        			0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           			0X2B12 //浅棕蓝色(选择条目的反色)

void delay_ms(uint16_t count);
void delay_us(uint16_t count);

//LCD的画笔颜色和背景色	   
// extern static uint16_t  POINT_COLOR;//默认红色    
// extern static uint16_t  BACK_COLOR; //背景颜色.默认为白色

//LCD重要参数集
typedef struct  
{										    
	uint16_t 	 width;			//LCD 宽度
	uint16_t 	 height;			//LCD 高度
	uint16_t 	 id;				//LCD ID
	uint8_t  	 dir;			//横屏还是竖屏控制：0，竖屏；1，横屏。	
	uint16_t	 wramcmd;		//开始写gram指令
	uint16_t  	 setxcmd;		//设置x坐标指令
	uint16_t  	 setycmd;		//设置y坐标指令	
	uint8_t   	 xoffset;    
	uint8_t	 	 yoffset;	
}_lcd_dev; 	

//LCD参数
// extern _lcd_dev lcddev;	//管理LCD重要参数

void LCD_Init(void (*write_byte)(uint8_t)); 
void LCD_Clear(uint16_t Color);
void LCD_WR_DATA(uint8_t Data); 
void LCD_WR_REG(uint8_t Reg);
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);//设置光标位置
void LCD_SetWindows(uint16_t xStar, uint16_t yStar,uint16_t xEnd,uint16_t yEnd);//设置显示窗口
void LCD_DrawPoint(uint16_t x,uint16_t y);//画点
void LCD_WriteRAM_Prepare(void);
void LCD_direction(uint8_t direction );
void LCD_WR_DATA_16Bit(uint16_t Data);
#endif  
