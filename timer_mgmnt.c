//Prozessorspezifische Headerdatei
#include <p33FJ128GP802.h>
//Config Header
#include "basics.h"

void set_timer1(int PR1_value)
{
    T1CONbits.TON = 0;      // Disable Timer
    T1CONbits.TCS = 0; // Select internal instruction cycle clock
    T1CONbits.TGATE = 0; // Disable Gated Timer mode
    T1CONbits.TCKPS = 0b01; // Select 1:8 Prescaler
    TMR1 = 0x00; // Clear timer register
    PR1 = PR1_value; // Load the period value (249 for 1kHz or 124 for 2kHz)
    IPC0bits.T1IP = 0x01; // Set Timer1 Interrupt Priority Level
    IFS0bits.T1IF = 0; // Clear Timer1 Interrupt Flag
    IEC0bits.T1IE = 1; // Enable Timer1 interrupt
    T1CONbits.TON = 1; // Start Timer
}

void set_timer2(int PR2_value)
{
    T2CONbits.TON = 0;      // Disable Timer
    T2CONbits.TCS = 0;      // Select internal instruction cycle clock
    T2CONbits.TGATE = 0; // Disable Gated Timer mode
    T2CONbits.TCKPS = 0b01; // Select 1:8 Prescaler
    TMR2 = 0x00; // Clear timer register
    PR2 = PR2_value; // Load the period value
    IPC1bits.T2IP = 0x01; // Set Timer1 Interrupt Priority Level
    IFS0bits.T2IF = 0; // Clear Timer1 Interrupt Flag
    IEC0bits.T2IE = 1; // Enable Timer1 interrupt
    T2CONbits.TON = 1; // Start Timer
}