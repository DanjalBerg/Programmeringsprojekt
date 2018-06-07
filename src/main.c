/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   Last committed:     $Revision: 00 $
   Last changed by:    $Author: $
   Last changed date:  $Date:  $
   ID:                 $Id:  $

**********************************************************************/

#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "ansi.h"
#include "LUT.h"
#include "trig.h"
#include "controller.h"
#include "timer.h"






int main(void){
    init_usb_uart( 115200 );
    printf("%c[?25l",ESC);
    uint16_t priority = 1;
    init_joystick();
    gotoxy(1,1);
    uint8_t ss =1, push=0;
    time(&t);
   // uint8_t ss = 1;
 //   uint8_t push = 0;


// Lav vindue
    clrscr();
    init_stopwatch();
    init_timer(priority);

   while(1){
        uint8_t js = readJoystick();
        stopwatch(js,&ss,&push);
}
}


