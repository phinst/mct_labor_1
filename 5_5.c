#include <p33FJ128GP802.h>
//Prozessorspezifische Headerdatei
#include "port_mgmnt.h"
#include "adw_mgmnt.h"
#include "pwm_mgmnt.h"
#include "system_init.h"
#include "read_write.h"
//custom headers


void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void){
    //Eigentlich überflüsig, ohne mag der Compiler aber nicht
    IFS0bits.T2IF = 0;
}

int main(void) {
    clr_ports();
    //Portkonfiguration zurücksetzen
    pin_cfg(2, 'a', 'i');
    //analoger Eingang auf Pin#2
    pin_cfg(26, 'd', 'o');
    pin_cfg(25, 'd', 'o');
    pin_cfg(24, 'd', 'o');
    pin_cfg(23, 'd', 'o');
    pin_cfg(22, 'd', 'o');
    pin_cfg(21, 'd', 'o');
    pin_cfg(18, 'd', 'o');
    pin_cfg(17, 'd', 'o');
    //obere Hälfte von Port B
    adw12_cfg(2, 'a');
    //adw konfigurieren
    pwm1_init(16, 61);
    //PWM Initialisierung

    while(1){
        
        switch(adw_read1>>8){
            //12 Bit Wandlung, nur oberste 4 Bit interessant
            case 0:
                PORTB=PORTB&0x0011;
                PORTB=PORTB|0x0000;
                pwm1_duty(5);
                break;
            case 1:
                PORTB=PORTB&0x0011;
                PORTB=PORTB|0x0100;
                pwm1_duty(10);
                break;
            case 2:
                PORTB=PORTB&0x0011;
                PORTB=PORTB|0x0300;
                pwm1_duty(20);
                break;
            case 3:
                PORTB=PORTB&0x0011;
                PORTB=PORTB|0x0300;
                pwm1_duty(20);
                break;
            case 4:
                PORTB=PORTB&0x0011;
                PORTB=PORTB|0x0700;
                pwm1_duty(40);
                break;
            case 5:
                PORTB=PORTB&0x0011;
                PORTB=PORTB|0x0700;
                pwm1_duty(40);
                break;
            case 6:
                PORTB=PORTB&0x0011;
                PORTB=PORTB|0x0F00;
                pwm1_duty(50);
                break;
            case 7:
                PORTB=PORTB&0x0011;
                PORTB=PORTB|0x0F00;
                pwm1_duty(50);
                break;
            case 8:
                PORTB=PORTB&0x0011;
                PORTB=PORTB|0x1F00;
                pwm1_duty(60);
                break;
            case 9:
                PORTB=PORTB&0x0011;
                PORTB=PORTB|0x1F00;
                pwm1_duty(60);
                break;
            case 10:
                PORTB=PORTB&0x0011;
                PORTB=PORTB|0x3F00;
                pwm1_duty(80);
                break;
            case 11:
                PORTB=PORTB&0x0011;
                PORTB=PORTB|0x3F00;
                pwm1_duty(80);
                break;
            case 12:
                PORTB=PORTB&0x0011;
                PORTB=PORTB|0x7F00;
                pwm1_duty(90);
                break;
            case 13:
                PORTB=PORTB&0x0011;
                PORTB=PORTB|0x7F00;
                pwm1_duty(90);
                break;
            case 14:
                PORTB=PORTB&0x0011;
                PORTB=PORTB|0xFF00;
                pwm1_duty(95);
                break;
            case 15:
                PORTB=PORTB&0x0011;
                PORTB=PORTB|0xFF00;
                pwm1_duty(95);
                break;
        }
    }
}