//Prozessorspezifische Headerdatei
#include <p33FJ128GP802.h>
//Config Header
#include "basics.h"

//bool IsTimerSet = 0;
int IsTimerSet = 0;

void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
 PORTBbits.RB6=!PORTBbits.RB6;//stark fragwürdig ob richtig
 IFS0bits.T1IF = 0; // Clear Timer1 Interrupt Flag
}

int main (void)
{
    port_reset();
    set_portb(15, "o"); //RB15 als Ausgang definieren
    set_portb(6, "i"); //RB6 als Eingang definieren

    while (1)                 // Endless loop
    {
        if(PORTBbits.RB6 && IsTimerSet){
            set_timer1(249);
            IsTimerSet=0;

        }
        if(!PORTBbits.RB6 && IsTimerSet==0){
            set_timer1(124);
            IsTimerSet=1;
        }
    }

return 0;
}
