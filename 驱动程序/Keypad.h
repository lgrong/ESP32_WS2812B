/*--------------------------------------------------------------------------------   
 * 项目名称:

     RGB流水灯板键盘驱动程序

 * 功能描述:

     1、获得被按下按键的键值

 * 版权信息:

     (c) 飞翼电子, 2014.

 * 历史版本:
     2014-03-15:
       - 初始版本 V1.0.0;

 * 配置说明:
     MCU:             STC15F104E
     晶振:      	  内部晶振：33MHz
     扩展模块:  	  -
     软件:            Keil.C51.V9.01

 * 备注:

--------------------------------------------------------------------------------*/   

#ifndef _KEYPAD_H_
#define _KEYPAD_H_


/********************************通信接口配置************************************/

sbit Button_1 = P3^2;	 //按钮1连接P3.2
sbit Button_2 = P3^3;	 //按钮2连接P3.3

/*---------------------------------函数声明-------------------------------------*/  
 
void Keypad_IO_Init(void);		 //按键端口初始化
unsigned char GetKey(void);		 //获取键值

#endif

//-------------------------THE END------------------------*/   
