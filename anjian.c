#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char
 
sbit PWM=P0^0;//  P0.0���pwm
uchar time;  // ����ռ�ձȵı���
 
void main()
{
	TMOD=0x01;//��ʱ��0������ʽ1
	TH0=0xff;//(65536-10)/256;//����ֵ��ʱ
	TL0=0xf7;//(65536-10)%256;//0.01ms
	EA=1;//�����ж�
	ET0=1;//����ʱ��0�ж�
	TR0=1;//������ʱ��0 
	while(1)
	{			
	}			
}
 
void tim0() interrupt 1
{
	TR0=0;//����ֵʱ���رն�ʱ��
	TH0=0xff;//(65536-10)/256;//����ֵ��ʱ
	TL0=0xf7;//(65536-10)%256;//0.01ms
	TR0=1;//�򿪶�ʱ��
 
	time++;
	if(time>=100)  //1khz
	  time=0;   
	if(time<=20)   //ռ�ձ�%30,�ɸ�
	  PWM=1;  
	else PWM=0;
}