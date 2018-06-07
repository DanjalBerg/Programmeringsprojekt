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

uint16_t ret(){
    uint16_t i;
    char arr[21]={0};
    for(i =0; i<20; i++){
    arr[i] = uart_getc();
    }
    if(arr=="start"){
    return(16);
    }
        else if(arr == "stop"{
            return(16);
        }
        else if(arr == "split1"){
              return(4);
        }
        else if(arr == "split2"){
            return(8);
        }
        else if(arr == "reset"){
             return(2);
        }
        else if(arr == "help"){
        return(1);
        }
}


int main(void){
    init_usb_uart( 115200 );
    gotoxy(1,1);
    clrscr();

   while(1){
    int var2=ret;
    if(var2==16)  {

    }
            uint8_t js = readJoystick();
        stopwatch(js,&ss,&push);
   }
}

/* //6.1
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
}*/
