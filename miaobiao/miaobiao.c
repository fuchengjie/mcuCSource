#include<reg51.h>


#define uchar unsigned char
#define dula P0
#define wela P2

sbit k1 = P3^3;	//按键1
sbit k2 = P3^4; //按键2
sbit beep = P2^3;	//蜂鸣器

bit stop = 1;

uchar sec,min,count=0; //变量定义
uchar num[4];
uchar time_count; //计数

uchar code weitable[]={
	0x8f,0x4f,0x4f,0x1f
};
uchar code table[]={
	0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
	0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71
};

uchar code table1[]={
	0xbf,0x86,0xdb,0xcf,0xe6,0xed,0xfd,0x87,0xff,0xef
};

void delay(uchar xms)
{//延时函数
	uchar i = 113;
	for(;xms>0;xms--)
		for(;i>0;i--)
			;
}

void display1(uchar wei,uchar shu)
{
	wei -= 1;
	
	wela |= 0xf0; //置1
	
	if(wei == 2)
		P0 = table1[shu];
	else
		P0 = table[shu];
	
	wela = wela&weitable[wei];
	
	delay(5);
}

void display(uchar a,uchar b,uchar c,uchar d)
{
	display1(4,a);
	display1(3,b);
	display1(2,c);
	display1(1,d);
}

void start_timer()
{
	ET0 = 1;
	EA = 1;
	TR0 = 1;
}
void stop_timer()
{
	ET0 = 0;
	EA = 0;
	TR0 = 0;
}

void main()
{
	TMOD = 0x01; //工作模式1
	TH0 = (65536-46080)/256;
	TL0 = (65536-46080)%256;
	
	while(1)
	{
		if(k1 == 0)
		{
			delay(10);
			if(k1 == 0)
			{
				
				while(k1 == 0)//按键1按下
				{
						if(stop)
							start_timer();
						else
							stop_timer();
							
						stop = ~stop;
							
						beep = 1; //蜂鸣器响
						P1=0xff;
				}
				
			}
		}
		
		if(k2 == 0)
		{
			delay(10);
			if(k2 == 0)
			{
				while(k2 == 0)
				{
					
					stop_timer();
					stop = 1;
					beep = 1;
					P1 = 0xff;
					count = 0 ;
					time_count = 0;
					sec = 0;
					min = 0;
					
				}
			}
			
		}
		
		if(stop)
		{
			count++;
			if(count == 100)
			{
				P1 = ~P1;
				
				count = 0;
			}
		}
		
		if(time_count == 20)
		{
			count = 0;
			time_count = 0;
			sec++;
			
			if(sec == 60)
			{
				sec = 0;
				min++;
				
				beep = 0;
				beep = 1;	//蜂鸣器响
			}
			if(min == 60)
			{
				min = 0;
			}
			beep = 0;
			delay(10);
			beep = 1;
		}
		
		num[0]=sec%10;
		num[1]=sec/10;
		num[2]=min%10;
		num[3]=min/10;
		
		display(num[3],num[2],num[1],num[0]); //显示数字
	}
}	

void timer0() interrupt 1
{
	TH0 = (65536-46080)/256;
	TL0 = (65536-46080)%256;
	time_count++;
}
