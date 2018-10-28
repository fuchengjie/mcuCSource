#include<reg52.h>
#include<intrins.h>
#include "../delay.h"

#define on 0
#define off 1
sbit fm=P2^3;

void main()
{
	unsigned int time=500;
	P1=0xfe;
	while(1)
	{
		delay(time-200);
		P1=_crol_(P1,2);
		
		fm=on;
		delay(time+300);
		fm=off;
		
		
	}
}
