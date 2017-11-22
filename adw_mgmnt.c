//Prozessorspezifische Headerdatei
#include <p33FJ128GP802.h>
//Config Header
#include "basics.h"

void adw12_cfg()
{
    AD1CON1bits.AD12B = 1;      //12bit Auflösung
    
    AD1CON2bits.CHPS = 0b00;    //Bei 12 Bit nur CH0 möglich
    
    AD1CHS0bits.CH0NA   = 0;    // S/H Kanal 0, neg.Input ist VREFL
    AD1CHS0bits.CH0SA   = 0;    // AN0 ist Signaleingang für S/H 0

    set_timer1(61);              //setze Timer 1 auf 8kHz
    
    AD1CON3bits.ADRC = 1;        //1 = internal / 0 = external

    AD1CON1bits.ASAM    = 1;    // automatische Abtastung
    AD1CON1bits.SSRC = 0b111;   //automatisches Triggern

    AD1CON1bits.FORM = 0b00;    //Einstellung des Ausgabeformats: unsignend int
    
    AD1CON1bits.ADON = 1;       // AD-Wandler aktiv

    IPC3bits.AD1IP = 3;       // IRQ priority 3
    IFS0bits.AD1IF  = 0;       // clear ADC Interrupt Flag
    IEC0bits.AD1IE = 1;       // enable the ADC Interrupt
}

