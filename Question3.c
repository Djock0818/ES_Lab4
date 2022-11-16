#include <msp430.h>
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;                 // Stop WDT
    P1DIR |= BIT6 | BIT7;                    
    P1SEL1 |= BIT6 | BIT7;                    //options select
    PM5CTL0 &= ~LOCKLPM5;
    TB0CCR0 = 8192-1;                         // PWM Period
    TB0CCTL1 = OUTMOD_7;                     
    TB0CCR1 = 1638;                           
    TB0CCTL2 = OUTMOD_7;                    
    TB0CCR2 = 14746;                           
    TB0CTL = TBSSELACLK | MCUP | TBCLR;  // SMCLK, up mode, clear TBR
    while(1)
    {
        P1OUT ^=BIT6;// For debugger
    }
}
