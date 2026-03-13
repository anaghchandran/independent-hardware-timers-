#include <xc.h>
#include "timer0.h"

void init_timer0(void)
{
	/*
	 * Setting instruction cycle clock (Fosc / 4) as the source of
	 * timer0
	 */

/*Setting 8 bit timer register*/
	T08BIT = 1;

/* Selecting internal clock source */
	T0CS = 0;

/* Enabling timer0*/
	TMR0ON = 1;

/* disabling prescaler*/
	PSA = 1;

	TMR0 = 6;

	/* Clearing timer0 overflow interrupt flag bit */
	TMR0IF = 0;

	/* Enabling timer0 overflow interrupt */
	TMR0IE = 1;
    
}
void init_timer1(void)

{
    /* Enabling Timer1 */
    TMR1ON = 1;
    
    /* Load Timer1 register with initial value */
    TMR1 = 3036;

    /* Clearing Timer1 overflow interrupt flag bit */
    TMR1IF = 0;

    /* Enabling Timer1 overflow interrupt */
    TMR1IE = 1;
    
}


void init_timer2(void)
{
     /* Setting instruction cycle clock (Fosc / 4) as the source of timer2 */
    
    /* Enabling Timer2 */
    TMR2ON = 1;

    /* Setting Timer2 period register */
    PR2 = 124;

    /* Clearing Timer2 overflow interrupt flag bit */
    TMR2IF = 0;

    /* Enabling Timer2 overflow interrupt */
    TMR2IE = 1;
}