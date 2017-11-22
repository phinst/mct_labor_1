//Prozessorspezifische Headerdatei
#include <p33FJ128GP802.h>
//Config Header
#include "basics.h"

void pwm_init()
{
    OC1CONbits.OCM = 0b000;     //Disable Output Compare Module
    OC1R = 100;                 //Duty cycle first PWM pulse
    OC1RS = 200;                //Duty cycle second PWM pulse
    OC1CONbits.OCTSEL = 0;      //select timer 2 as output compare base time
    OC1R = 100;                 //Load the Compare Register Value               ???
    OC1CONbits.OCM = 0b110;     //Select output compare mode
    set_timer2(61);             //Set timer 2 to 4 kHz

    //// WO WIRD DER OUTPUT PORT DEFINIERT?
}
