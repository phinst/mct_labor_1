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
    pullup_cfg(25, 1);
    while (1) {
        //PORTBbits.RB15 =~ PORTBbits.RB12;
        d_write(25, ~d_read(26));
        
    }
}