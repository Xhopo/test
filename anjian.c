#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char
 
sbit PWM=P0^0;//  P0.0输出pwm
uchar time;  // 定义占空比的变量
 
void main()
{
	TMOD=0x01;//定时器0工作方式1
	TH0=0xff;//(65536-10)/256;//赋初值定时
	TL0=0xf7;//(65536-10)%256;//0.01ms
	EA=1;//开总中断
	ET0=1;//开定时器0中断
	TR0=1;//启动定时器0 
	while(1)
	{			
	}			
}
 
void tim0() interrupt 1
{
	TR0=0;//赋初值时，关闭定时器
	TH0=0xff;//(65536-10)/256;//赋初值定时
	TL0=0xf7;//(65536-10)%256;//0.01ms
	TR0=1;//打开定时器
 
	time++;
	if(time>=100)  //1khz
	  time=0;   
	if(time<=20)   //占空比%30,可改
	  PWM=1;  
	else PWM=0;
}