#include<reg52.h>
#define s P0

sbit w1 = P2^4;
sbit w2 = P2^5;
sbit w3 = P2^6;
sbit w4 = P2^7;

sbit k1 = P3^4;
sbit k2 = P3^5;
sbit k3 = P3^6;
sbit k4 = P3^7;


void delay(unsigned int xms)
{
	unsigned int i,j;
	for(i=xms;i>0;i--)
		for(j=112;j>0;j--);
}

void main()
{	
	w1 = 0;
	w2 = 0;
	w3 = 0;
	w4 = 0;
	while(1)
	{
		if(k1 == 0)
		{
			delay(10);
			if(k1 == 0)
			{
				while(1)
				{
					unsigned int t;
					for(t=0;t<50;t++)
					{
						w2=1;
						w4=1;
						w1=0;
						w3=0;
						s=0xb7;
						delay(5);
						w1=1;
						w3=1;
						w2=0;
						w4=0;
						s=0x88;
						delay(5);
					}
					for(t=0;t<50;t++)
					{
						w2=1;
						w4=1;
						w1=0;
						w3=0;
						s=0x88;
						delay(5);
						w1=1;
						w3=1;
						w2=0;
						w4=0;
						s=0xb7;
						delay(5);
					}
				}
			}			
		}
	}

}