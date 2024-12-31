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

#include <STC15W.h>
#include "Keypad.h"
#include "Delay.h"

//-------------------------------------------------------------------------------
//子程序名称:IO_Init(void)
//功能：端口初始化
//-------------------------------------------------------------------------------
void Keypad_IO_Init(void)
{
	Button_1=1;
	Button_2=1;
}

//-------------------------------------------------------------------------------
//子程序名称:unsigned char GetKey(void)
//功能：获得被按下的键的键值
//说明：按键1被按下时，返回1，按键2被按下时返回2，没有按键按下时返回0
//-------------------------------------------------------------------------------
unsigned char GetKey(void)
{
	unsigned char i;
	Button_1=1;
	Button_2=1;

	if(Button_1==0)				//如果按键1被按下
	{
		DelayMs(10);			//延时10毫秒后判断
		if(Button_1==0)					 
		{
			for(i=0;i<100;i++)
			{
				if(Button_1==1)	//在超时时间内按键被松开，则认为按键1触发有效
				{
					return 1;	//返回结果1，代表按键1被按下
				}
				DelayMs(10);	//超时时间为1秒，如果超过1秒按键没抬起，则认为按下无效
			}
		}
	}
	if(Button_2==0)				//如果按键1没有被按下，开始判断按键2
	{
		DelayMs(10);
		if(Button_2==0)
		{
			for(i=0;i<100;i++)
			{
				if(Button_2==1)	//在超时时间内按键被松开，则认为按键1触发有效
				{
					return 2;	//返回结果1，代表按键1被按下
				}
				DelayMs(10);	//超时时间为1秒
			}
		}
	}
	return 0;
}
