#include<reg52.h>
#define uchar unsigned char
#define duan P0

uchar code sz[4]={0x77,0x7c,0x39,0x5e};
	
sbit k1=P3^4;
sbit k2=P3^5;
sbit k3=P3^6;
sbit k4=P3^7;

sbit wei1=P2^4;	
sbit wei2=P2^5;
sbit wei3=P2^6;	
sbit wei4=P2^7;	

void delay(unsigned int xms)
{
	unsigned int i,j;
	for(i=xms;i>0;i--)
	  for(j=112;j>0;j--);
}

void displayA()
{
	duan=sz[0];
	wei1=1;
	wei2=0;
	wei3=0;
	wei4=0;
}
void displayB()
{
	duan=sz[1];
	wei1=0;
	wei2=1;
	wei3=0;
	wei4=0;
}
void displayC()
{
	duan=sz[2];
	wei1=0;
	wei2=0;
	wei3=1;
	wei4=0;
}
void displayD()
{
	duan=sz[3];
	wei1=0;
	wei2=0;
	wei3=0;
	wei4=1;
}
void buxunhuan()
{
	

	displayA();
	delay(1);
	//显示A
	
	displayB();
	delay(1);
	//显示B
	
	displayC();
	delay(1);
	//显示C
	
	displayD();
	delay(1);
	//显示D
	
	
}	

void a()
{
	
}
void xunhuan()
{
	int time=1;
	
	displayA();delay(time);
	displayB();delay(time);
	displayC();delay(time);
	displayD();delay(time);
	
	
	duan=sz[1];	wei1=1;	wei2=0;	wei3=0;	wei4=0;delay(time);
	duan=sz[2];	wei1=0;	wei2=1;	wei3=0;	wei4=0;delay(time);
	duan=sz[3];	wei1=0;	wei2=0;	wei3=1;	wei4=0;delay(time);
	duan=sz[0];	wei1=0;	wei2=0;	wei3=0;	wei4=1;delay(time);
	
	
	duan=sz[2];	wei1=1;	wei2=0;	wei3=0;	wei4=0;delay(time);
	duan=sz[3];	wei1=0;	wei2=1;	wei3=0;	wei4=0;delay(time);
	duan=sz[0];	wei1=0;	wei2=0;	wei3=1;	wei4=0;delay(time);
	duan=sz[1];	wei1=0;	wei2=0;	wei3=0;	wei4=1;delay(time);
	
	
	duan=sz[3];	wei1=1;	wei2=0;	wei3=0;	wei4=0;delay(time);
	duan=sz[0];	wei1=0;	wei2=1;	wei3=0;	wei4=0;delay(time);
	duan=sz[1];	wei1=0;	wei2=0;	wei3=1;	wei4=0;delay(time);
	duan=sz[2];	wei1=0;	wei2=0;	wei3=0;	wei4=1;delay(time);
	
	
	
}	
void displayZero()
{
	duan=0x00;
	wei1=1;
	wei2=1;
	wei3=1;
	wei4=1;
}

void main()
{
	int i=0;
	while(1)
	{
		
		//buxunhuan();
		
		xunhuan();
		
		
			
		
		
	}
	
	
}



	
	
	