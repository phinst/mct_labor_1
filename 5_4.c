#include <p33FJ128GP802.h>
//Prozessorspezifische Headerdatei
#include "system_init.h"
#include "port_mgmnt.h"
//custom headers

//bool IsTimerSet = 0;
int IsTimerSet = 0;

void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void){
    d_write(26, ~d_read(26));
    IsTimerSet=0;
    IFS0bits.T1IF = 0;
    // Clear Timer1 Interrupt Flag
}

void main(){
    clr_ports();
    pin_cfg(26, 'd', "o"); 
    //RB15 als Ausgang definieren
    pin_cfg(15, 'd', 'i'); 
    //RB6 als Eingang definieren

    while (1){
        if(d_read(15) && !IsTimerSet){
            set_timer1(249);
            IsTimerSet=1;

        }
        if(!d_read(15) && !IsTimerSet){
            set_timer1(124);
            IsTimerSet=1;
        }
    }
}
