/*name : ANAGH CS
 * ASSIGNMENT NO : 4
 * 
 * A04 - Implement the time separator with Timer 0, Timer 1 and Timer 2
 * 
 * 
 * 
 */




#include <xc.h>
#include "timer0.h"
#include "main.h"

void init_config(void)
{
	PEIE = 1;
	/* Clear old content */
	//PORTB = 0x00;

	/* Set PORTB as a Output */
	TRISB = 0x00;
    //PORTB=0X00;
    RB0=0;
    RB1=0;
    RB2=0;

	/* Config PORTB as digital */
	ADCON1 = 0x0F;

	init_timer0();
    init_timer1();
    init_timer2();

	GIE = 1;
}


void main(void)
{
	init_config();

	while (1)
	{
		;
	}
}
