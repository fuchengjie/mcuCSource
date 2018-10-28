#include<reg52.h>

sbit led = P1^0;
sbit fm = P2^3;

unsigned int flag = 0,i = 0;

void delay(unsigned int xms)
{
	unsigned int i;
	for(;xms>0;xms--)
		for(i=112;i>0;i--);
}

void timer_init()
{
	TMOD = 0x01;
	TH0 = 0x3c;
	TL0 = 0xb0;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}	

void main()
{
	led = 1;
	timer_init();
	while(1)
	{
		if(flag == 20)
		{
			led = ~led;
			flag = 0;
		}
		
		if(i == 100)
		{
			fm = 0;
			delay(50);
			fm = 1;
			
			i=0;
		}
	}
}

void timer() interrupt 1
{
	TH0 = 0x3c;
	TL0 = 0xb0;
	flag++;
	i++;
}

