#include "port_mgmnt.h"
//Prozessorspezifische Headerdatei
#include "p33FJ128GP802.h"

//Port A: 5 Pins (0-4), TRISA Register
//Eingang 1, Ausgang 0
//default: 1
//Port B: 16 Pins (0-15), TRISB Register
//Eingang 1, Ausgang 0
//default: 1

//Analog: AN0-5 AN9-12, AD1PCFGL Register
//digital 1, analog 0
//default 0

void clr_ports() {
    //Analoge Pins digital setzten
    AD1PCFGL=0xFFFF;
    //Alle Pins als Ausgänge definieren
    TRISA=0;
    TRISB=0;
    //Ausschalten aller Pullups
    CNPU1=0;
    CNPU2=0;
}

void pin_cfg(int pinnummer, char mode, char richtung){
    //Konfiguration eines Pins als digitalen oder analogen Ein- bzw. Ausgang
    //pinnummer: # des verwendeten Pins z.B. RA0/AN0 liegt auf Pin#2
    //mode: a analog, d digital
    //richtung: i in, o out
    if (mode == 'd'){
        if (richtung == 'o'){
            //Ausgang
            switch(pinnummer){
                //pin 1:    /reset (/mclr)
                case 2:     AD1PCFGLbits.PCFG0=1;
                            //Pin digital schalten
                            TRISAbits.TRISA0=0;
                            //Pin als Ausgang schalten
                            break;
                case 3:     AD1PCFGLbits.PCFG1=1;
                            TRISAbits.TRISA1=0;
                            break;
                case 4:     AD1PCFGLbits.PCFG2=1;
                            TRISBbits.TRISB0=0;
                            break;
                case 5:     AD1PCFGLbits.PCFG3=1;
                            TRISBbits.TRISB1=0;
                            break;
                case 6:     AD1PCFGLbits.PCFG4=1;
                            TRISBbits.TRISB2=0;
                            break;
                case 7:     AD1PCFGLbits.PCFG5=1;
                            TRISBbits.TRISB3=0;
                            break;
                //pin 8:    gnd (vss)
                case 9:     TRISAbits.TRISA2=0;
                            break;
                case 10:    TRISAbits.TRISA3=0;
                            break;
                case 11:    TRISBbits.TRISB4=0;
                            break;
                case 12:    TRISAbits.TRISA4=0;
                            break;
                //pin 13:   vdd (3.3V)
                case 14:    TRISBbits.TRISB5=0;
                            break;
                case 15:    TRISBbits.TRISB6=0;
                            break;
                case 16:    TRISBbits.TRISB7=0;
                            break;
                case 17:    TRISBbits.TRISB8=0;
                            break;
                case 18:    TRISBbits.TRISB9=0;
                            break;
                //pin 19:   gnd (vss2)
                //pin 20:   vcap
                case 21:    TRISBbits.TRISB10=0;
                            break;
                case 22:    TRISBbits.TRISB11=0;
                            break;
                case 23:    AD1PCFGLbits.PCFG12=1;
                            TRISBbits.TRISB12=0;
                            break;
                case 24:    AD1PCFGLbits.PCFG11=1;
                            TRISBbits.TRISB13=0;
                            break;
                case 25:    AD1PCFGLbits.PCFG10=1;
                            TRISBbits.TRISB14=0;
                            break;
                case 26:    AD1PCFGLbits.PCFG9=1;
                            TRISBbits.TRISB15=0;
                            break;
                //pin 27:   avss
                //pin 28:   avdd            
            }
        }
        else if (richtung == 'i'){
            //Eingang
            switch(pinnummer){
                //pin 1:    /reset (/mclr)
                case 2:     AD1PCFGLbits.PCFG0=1;
                            //Pin digital schalten
                            TRISAbits.TRISA0=1;
                            //Pin als Eingang schalten
                            break;
                case 3:     AD1PCFGLbits.PCFG1=1;
                            TRISAbits.TRISA1=1;
                            break;
                case 4:     AD1PCFGLbits.PCFG2=1;
                            TRISBbits.TRISB0=1;
                            break;
                case 5:     AD1PCFGLbits.PCFG3=1;
                            TRISBbits.TRISB1=1;
                            break;
                case 6:     AD1PCFGLbits.PCFG4=1;
                            TRISBbits.TRISB2=1;
                            break;
                case 7:     AD1PCFGLbits.PCFG5=1;
                            TRISBbits.TRISB3=1;
                            break;
                //pin 8:    gnd (vss)
                case 9:     TRISAbits.TRISA2=1;
                            break;
                case 10:    TRISAbits.TRISA3=1;
                            break;
                case 11:    TRISBbits.TRISB4=1;
                            break;
                case 12:    TRISAbits.TRISA4=1;
                            break;
                //pin 13:   vdd (3.3V)
                case 14:    TRISBbits.TRISB5=1;
                            break;
                case 15:    TRISBbits.TRISB6=1;
                            break;
                case 16:    TRISBbits.TRISB7=1;
                            break;
                case 17:    TRISBbits.TRISB8=1;
                            break;
                case 18:    TRISBbits.TRISB9=1;
                            break;
                //pin 19:   gnd (vss2)
                //pin 20:   vcap
                case 21:    TRISBbits.TRISB10=1;
                            break;
                case 22:    TRISBbits.TRISB11=1;
                            break;
                case 23:    AD1PCFGLbits.PCFG12=1;
                            TRISBbits.TRISB12=1;
                            break;
                case 24:    AD1PCFGLbits.PCFG11=1;
                            TRISBbits.TRISB13=1;
                            break;
                case 25:    AD1PCFGLbits.PCFG10=1;
                            TRISBbits.TRISB14=1;
                            break;
                case 26:    AD1PCFGLbits.PCFG9=1;
                            TRISBbits.TRISB15=1;
                            break;
                //pin 27:   avss
                //pin 28:   avdd            
            }
        }
    }
    else if (mode == 'a'){
        if (richtung == 'i'){
        //Konfiguration eines Pins als analogen Eingang
            switch(pinnummer){
                case 2:     AD1PCFGLbits.PCFG0=0;
                            //Pin analog schalten
                            TRISAbits.TRISA0=1;
                            //Pin als Eingang schalten
                            break;
                case 3:     AD1PCFGLbits.PCFG1=0;
                            TRISAbits.TRISA1=1;
                            break;
                case 4:     AD1PCFGLbits.PCFG2=0;
                            TRISBbits.TRISB0=1;
                            break;
                case 5:     AD1PCFGLbits.PCFG3=0;
                            TRISBbits.TRISB1=1;
                            break;
                case 6:     AD1PCFGLbits.PCFG4=0;
                            TRISBbits.TRISB2=1;
                            break;
                case 7:     AD1PCFGLbits.PCFG5=0;
                            TRISBbits.TRISB3=1;
                            break;
                case 23:    AD1PCFGLbits.PCFG12=0;
                            TRISBbits.TRISB12=1;
                            break;
                case 24:    AD1PCFGLbits.PCFG11=0;
                            TRISBbits.TRISB13=1;
                            break;
                case 25:    AD1PCFGLbits.PCFG10=0;
                            TRISBbits.TRISB14=1;
                            break;
                case 26:    AD1PCFGLbits.PCFG9=0;
                            TRISBbits.TRISB15=1;
                            break;
            }
        }
        else if (richtung == 'o'){
        //noch nicht konfiguriert, haben wir überhaupt einen dac?
        }
    }
}

void pullup_cfg(int pinnummer, int state ) {
    //Zu- bzw. Abschalten eines Pullups an einem bestimmten Pin
    //state: 0 disabled, 1 enabled
    if (state == 1) {
        switch(pinnummer){
            //pin 1:    /reset (/mclr)
            case 2:     CNPU1bits.CN2PUE=1;
                        break;
            case 3:     CNPU1bits.CN3PUE=1;
                        break;
            case 4:     CNPU1bits.CN4PUE=1;
                        break;
            case 5:     CNPU1bits.CN5PUE=1;
                        break;
            case 6:     CNPU1bits.CN6PUE=1;
                        break;
            case 7:     CNPU1bits.CN7PUE=1;
                        break;
            //pin 8:    gnd (vss)
            case 9:     CNPU2bits.CN30PUE=1;
                        break;
            case 10:    CNPU2bits.CN29PUE=1;
                        break;
            case 11:    CNPU1bits.CN1PUE=1;
                        break;
            case 12:    CNPU1bits.CN0PUE=1;
                        break;
            //pin 13:   vdd (3.3V)
            case 14:    CNPU2bits.CN27PUE=1;
                        break;
            case 15:    CNPU2bits.CN24PUE=1;
                        break;
            case 16:    CNPU2bits.CN23PUE=1;
                        break;
            case 17:    CNPU2bits.CN22PUE=1;
                        break;
            case 18:    CNPU2bits.CN21PUE=1;
                        break;
            //pin 19:   gnd (vss2)
            //pin 20:   vcap
            case 21:    CNPU2bits.CN16PUE=1;
                        break;
            case 22:    CNPU1bits.CN15PUE=1;
                        break;
            case 23:    CNPU1bits.CN14PUE=1;
                        break;
            case 24:    CNPU1bits.CN13PUE=1;
                        break;
            case 25:    CNPU1bits.CN12PUE=1;
                        break;
            case 26:    CNPU1bits.CN11PUE=1;
                        break;
            //pin 27:   avss
            //pin 28:   avdd            
        }
    }
    else if (state == 0) {
        switch(pinnummer){
            //pin 1:    /reset (/mclr)
            case 2:     CNPU1bits.CN2PUE=0;
                        break;
            case 3:     CNPU1bits.CN3PUE=0;
                        break;
            case 4:     CNPU1bits.CN4PUE=0;
                        break;
            case 5:     CNPU1bits.CN5PUE=0;
                        break;
            case 6:     CNPU1bits.CN6PUE=0;
                        break;
            case 7:     CNPU1bits.CN7PUE=0;
                        break;
            //pin 8:    gnd (vss)
            case 9:     CNPU2bits.CN30PUE=0;
                        break;
            case 10:    CNPU2bits.CN29PUE=0;
                        break;
            case 11:    CNPU1bits.CN1PUE=0;
                        break;
            case 12:    CNPU1bits.CN0PUE=0;
                        break;
            //pin 13:   vdd (3.3V)
            case 14:    CNPU2bits.CN27PUE=0;
                        break;
            case 15:    CNPU2bits.CN24PUE=0;
                        break;
            case 16:    CNPU2bits.CN23PUE=0;
                        break;
            case 17:    CNPU2bits.CN22PUE=0;
                        break;
            case 18:    CNPU2bits.CN21PUE=0;
                        break;
            //pin 19:   gnd (vss2)
            //pin 20:   vcap
            case 21:    CNPU2bits.CN16PUE=0;
                        break;
            case 22:    CNPU1bits.CN15PUE=0;
                        break;
            case 23:    CNPU1bits.CN14PUE=0;
                        break;
            case 24:    CNPU1bits.CN13PUE=0;
                        break;
            case 25:    CNPU1bits.CN12PUE=0;
                        break;
            case 26:    CNPU1bits.CN11PUE=0;
                        break;
            //pin 27:   avss
            //pin 28:   avdd            
        }
    }
}