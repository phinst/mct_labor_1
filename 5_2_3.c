//Prozessorspezifische Headerdatei
#include <p33FJ128GP802.h>
//custom headers
#include "system_init.h"
#include "port_mgmnt.h"

void main() {
    clr_ports();
    pin_cfg(26, 'd', 'o');
    //RB15 als Ausgang definieren
    pin_cfg(25, 'd', 'o');
    //RB14 als Ausgang definieren
    clk_boost(80);    
    //Clock auf 80MHz mit ext. Oszi + PLL
    
    while (1) {
        LATBbits.LATB15 = 1;
        LATBbits.LATB14 = 1;
        LATBbits.LATB15 = 0;
        LATBbits.LATB14 = 0;
    }
}