#include<reg52.h>
#define duan P0
#define uchar unsigned char

uchar code sz[4]={0x06,0x5b,0x4f,0x66};

sbit w1=P2^4;
sbit w2=P2^5;
sbit w3=P2^6;
sbit w4=P2^7;

void delay(unsigned int xms)
{
	unsigned int i;
	for(;xms>0;xms--)
		for(i=112;i>0;i--);
}

/*
void low() interrupt 0
{
	P1=~P1;
	delay(200);
}*/

void show1()
{
	duan=sz[0];	w1=1;	w2=0;	w3=0;	w4=0;
}

void show2()
{
	duan=sz[1];	w1=0;	w2=1;	w3=0;	w4=0;
}
void show3()
{
	duan=sz[2];	w1=0;	w2=0;	w3=1;	w4=0;
}
void show4()
{
	duan=sz[3];	w1=0;	w2=0;	w3=0;	w4=1;
}

void jump_low() interrupt 2
{
	P1=~P1;
}

void main()
{
	P1=0x0f;
	EX1=1;
	EA=1;
	IT1=1;
	
	while(1)
	{
		show1();
	}
	
	
	
}
