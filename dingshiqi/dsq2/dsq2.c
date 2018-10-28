#include<reg52.h>


void delay(unsigned int xms)
{
	unsigned int i;
	for(;xms>0;xms--)
		for(i=112;i>0;i--);
}





void jump_low() interrupt 2
{
	P1=~P1;
}

void main()
{
	P1=0xf0;
	EX1=1;
	EA=1;
	IT1=1;
	
	while(1);
}
