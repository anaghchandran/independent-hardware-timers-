#include <xc.h>
#include "main.h"

void __interrupt() isr(void)
{
	static unsigned short count;
    static unsigned short count1;
    static unsigned short count2;
     
	if (TMR0IF)
	{
		TMR0 = TMR0 + 8;

		if (count++ == 10000)
		{
			count = 0;
			LED1 = !LED1;
		}
		TMR0IF = 0;
	}
    
    
    if (TMR1IF)
	{
		TMR1 = TMR1 + 3038;

		if (count1++ == 40)
		{
			count1 = 0;
			LED2 = !LED2;
		}
		TMR1IF = 0;
	}
    
    
    if (TMR2IF)
	{
		//TMR0 = TMR0 + 8;

		if (count2++ == 10000)
		{
			count2 = 0;
			LED3 = !LED3;
		}
		TMR2IF = 0;
	}
}