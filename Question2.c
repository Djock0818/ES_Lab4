#include <msp430.h>
int main(void)
{
   WDTCTL = WDTPW | WDTHOLD;  //Stop WDT
   P1DIR |= BIT6;  
   P1SEL1 |= BIT6;
   PM5CTL0 &= ~LOCKLPM5; 
   TB0CCR0 = 16384-1;  //PWM Period
   TB0CCTL1 = OUTMOD_7;
   TB0CCR1 = 1638;
   TB0CTL = TBSSEL__ACLK | MC__UP | TBCLR;  // CCR2 PWM Duty Cycle
   while(1)
   {
      P1OUT ^=BIT6;  //For Debugger 
   }
}
