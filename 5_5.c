//Prozessorspezifische Headerdatei
#include <p33FJ128GP802.h>
//Config Header
#include "basics.h"

uint8_t ADCValue = 0;

void __attribute__((__interrupt__, no_auto_psv)) _ADC1Interrupt(void) //ISR ADC
{
    while (!AD1CON1bits.DONE); // Warten auf das Ende der Konvertierung
    ADCValue = ADC1BUF0; // Lesen des Ergebnisses
    ADCValue = ADCValue >> 4; // Nur die oberen 4 Bit interessieren
    IFS0bits.AD1IF = 0; // Clear AD1 Interrupt Flag
}

void __attribute__((__interrupt__)) _T2Interrupt(void) //ISR PWM
{
    switch (ADCValue) {
            case 0:
                //duty cycle OC1RS= ??
                break;
            case 1:
                //duty cycle
                break;
            case 2:
                //duty cycle
                break;
            case 3:
                //duty cycle
                break;
            case 4:
                //duty cycle
                break;
            case 5:
                //duty cycle
                break;
            case 6:
                //duty cycle
                break;
            case 7:
                //duty cycle
                break;
            case 8:
                //duty cycle
                break;
            case 9:
                //duty cycle
                break;
            case 10:
                //duty cycle
                break;
            case 11:
                //duty cycle
                break;
            case 12:
                //duty cycle
                break;
            case 13:
                //duty cycle
                break;
            case 14:
                //duty cycle
                break;
            case 15:
                //duty cycle
                break;
        }
}

int main(void) {
    port_reset();
    para_ADW_12bit();
    pwm_init();

    while (1) // Endless loop
    {
        switch (ADCValue) {
            case 0:
                PORTB=PORTB||0x0000;
                break;
            case 1:
                PORTB=PORTB||0x0100;
                break;
            case 2:
                PORTB=PORTB||0x0300;
                break;
            case 3:
                PORTB=PORTB||0x0300;
                break;
            case 4:
                PORTB=PORTB||0x0700;
                break;
            case 5:
                PORTB=PORTB||0x0700;
                break;
            case 6:
                PORTB=PORTB||0x0F00;
                break;
            case 7:
                PORTB=PORTB||0x0F00;
                break;
            case 8:
                PORTB=PORTB||0x1F00;
                break;
            case 9:
                PORTB=PORTB||0x1F00;
                break;
            case 10:
                PORTB=PORTB||0x3F00;
                break;
            case 11:
                PORTB=PORTB||0x3F00;
                break;
            case 12:
                PORTB=PORTB||0x7F00;
                break;
            case 13:
                PORTB=PORTB||0x7F00;
                break;
            case 14:
                PORTB=PORTB||0xFF00;
                break;
            case 15:
                PORTB=PORTB||0xFF00;
                break;
        }
    }
}