#include<reg52.h>

#define uchar unsigned char
#define uint unsigned int

sbit wei1=P2^4;
sbit wei2=P2^5;
sbit wei3=P2^6;
sbit wei4=P2^7;

uchar code table[17]={
	0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,
	0x07,0x7f,0x6f,0x77,0x7c,0x39,
	0x5e,0x79,0x71,0x00
};

enum state{jia,jian,chen,chu}keyState;//按下哪运算键
	
int inputNum1=0,inputNum2=0;

int isYunSuan=0;

void delay(uchar xms)
{
	uchar j;
	for(;xms>0;xms--)
		for(j=112;j>0;j--)
			;
}

void display(uchar num)
{
	P0=table[num];
}

void keyscan1()
{
	uchar temp,key;
	
	inputNum1=0;
	inputNum2=0;
	
	P3=0xfe;
	temp=P3;
	temp&=0xf0;
	
	if(temp!=0xf0)
	{
		delay(10);
		temp=P3;
		temp&=0xf0;
		
		if(temp!=0xf0)
		{
			temp=P3;
			switch(temp)
			{
				//第一排
				case 0xee:
					key=1;
					if(isYunSuan==0){
						inputNum1+=key;
					}
					if(isYunSuan==1){
						inputNum2+=key;
					}
					break;
				case 0xde:
					key=2;
					if(isYunSuan==0){
						inputNum1+=key;
					}
					if(isYunSuan==1){
						inputNum2+=key;
					}
					break;
				case 0xbe:
					key=3;
					if(isYunSuan==0){
						inputNum1+=key;
					}
					if(isYunSuan==1){
						inputNum2+=key;
					}
					break;
				case 0x7e:
					keyState=jia;
					isYunSuan=1;
					key=10;break;
			}
			
			while(temp!=0xf0)
			{
				temp=P3;
				temp&=0xf0;
			}
			display(key);
		}
		
	}
	
	P3=0xfd;
	temp=P3;
	temp&=0xf0;
	
	if(temp!=0xf0)
	{
		delay(10);
		temp=P3;
		temp&=0xf0;
		
		if(temp!=0xf0)
		{
			temp=P3;
			switch(temp)
			{
			
				//第二排
				case 0xed:
					key=4;break;
				case 0xdd:
					key=5;break;
				case 0xbd:
					key=6;break;
				case 0x7d:
					key=11;
					keyState=jian;
					isYunSuan=1;
					break;
				
			}
			
			while(temp!=0xf0)
			{
				temp=P3;
				temp&=0xf0;
			}
			display(key);
		}
		
	}
	
	P3=0xfb;
	temp=P3;
	temp&=0xf0;
	
	if(temp!=0xf0)
	{
		delay(10);
		temp=P3;
		temp&=0xf0;
		
		if(temp!=0xf0)
		{
			temp=P3;
			switch(temp)
			{
				
				//第三排
				case 0xeb:
					key=7;break;
				case 0xdb:
					key=8;break;
				case 0xbb:
					key=9;break;
				case 0x7b:
					key=12;
					keyState=chen;
					isYunSuan=1;
					break;
			}
			
			while(temp!=0xf0)
			{
				temp=P3;
				temp&=0xf0;
			}
			display(key);
		}
		
	}
	
	P3=0xf7;
	temp=P3;
	temp&=0xf0;
	
	if(temp!=0xf0)
	{
		delay(10);
		temp=P3;
		temp&=0xf0;
		
		if(temp!=0xf0)
		{
			temp=P3;
			switch(temp)
			{
				
				//第4排
				
				case 0xd7:
					key=0;break;
//				case 0xb7:
//					key=9;break;
				case 0x77:
					key=13;
					keyState=chu;
					isYunSuan=1;
					break;
			}
			
			while(temp!=0xf0)
			{
				temp=P3;
				temp&=0xf0;
			}
			display(key);
		}
		
	}
	
	
}


void main()
{
	P2 |= 0xf0;
	
	//显示器选择哪些亮
	wei1=1;
	wei2=0;
	wei3=0;
	wei4=0;
	
	while(1)
	{
		keyscan1();
	}
}

