//Prozessorspezifische Headerdatei
#include <p33FJ128GP802.h>
//custom headers
#include "system_init.h"
#include "port_mgmnt.h"
#include "clk_mgmnt.h"


void main() {
    clr_ports();
    pin_cfg(26, 'd', 'o');
    clk_boost(80);
    //setup
    while(1){
        //PORTBbits.RB15=~PORTBbits.RB15;
        PORTBbits.RB15 = 1;
        PORTBbits.RB15 = 0;
    }
}