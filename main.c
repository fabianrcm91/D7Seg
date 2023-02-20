#include <msp430.h> 
#include "d7SegX3.h"
#include "lcd2x16.h"


void main(void){
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	lcd2x16Init();
    lcd2x16Data('H');
    lcd2x16Data('o');
    lcd2x16Data('l');
    lcd2x16Data('a');



	while(-1){
	    lcd2x16Data(keypadGetc());
	}
}
