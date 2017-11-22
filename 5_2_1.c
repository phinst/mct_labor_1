//Prozessorspezifische Headerdatei
#include <p33FJ128GP802.h>
//custom headers
#include "system_init.h"
#include "port_mgmnt.h"
#include "read_write.h"

void main() {
    clr_ports();
    pin_cfg(26, 'd', 'o');
    //setup
    while (1) {
        //PORTBbits.RB15=~PORTBbits.RB15;
        //direkt
        d_write(26, ~d_read(26));
        //über eigene Funtionen
    }
}