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

uint16_t ret() {
    uint16_t i;
    char arr[21] = {0};
    for (i = 0; i < 20; i++) {
        arr[i] = uart_getc();
    }
    if (arr == "start") {
        return (16);
    }
    else if (arr == "stop" {
    return (16);
    }
    else if (arr == "split1") {
    return (4);
    }
    else if (arr == "split2") {
    return (8);
    }
    else if (arr == "reset") {
    return (2);
    }
    else if (arr == "help") {
    return (1);
    }
}


int main(void) {
    init_usb_uart( 115200 );
    gotoxy(1, 1);
    clrscr();

    while (1) {
        int var2 = ret;
        if (var2 == 16)  {

        }
        uint8_t js = readJoystick();
        stopwatch(js, &ss, &push);
    }
}






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


/*
int main(void){
    init_usb_uart( 115200 );
    init_RGB();
    init_joystick();

clrscr();
gotoxy(1,1);


    // Port A (BLUE)
    GPIOA->ODR |= (0x0001 << 9); //Set pin PA9 to high

    // Port C (GREEN)
    GPIOC->ODR |= (0x0001 << 7); //Set pin PC7 to high

    // Port B (RED)
    GPIOB->ODR |= (0x0001 << 4); //Set pin PB4 to high





   while(1){
    int8_t val = readJoystick();
    int8_t val_old;
    if(val != val_old){
    printf("%d\n",val);
    }
    val_old = val;
    set_Led(val);
   }

}
*/



/*
int main(void){
    init_usb_uart( 115200 );
   clrscr();
   // showCursor(false);
   int32_t borderX = 50; // Skal v�re et lige tal
   int32_t borderY = 20; // Skal v�re et lige tal
   int32_t cunt = 0;

    window(1,1,borderX,borderY, "hello Video game player!");
    counter(borderX/2-5,borderY/2-1,borderX/2+5,borderY/2+1);
    struct ball_t b;
    initVector(&b.posi, 25,10);
    initVector(&b.vel, 1,1);
    gotoxy(borderX/2-4,borderY/2);
    printf("Hits: 0");
 //   rotate(&v,-50);
 //   printFix(expand(v.x));
 //   printf("\n");
 //   printFix(expand(v.y));

   while(1){


    if((b.posi.x <= (2 << 14)) || (b.posi.x >= ((borderX) << 14 )))
    {
    b.vel.x = -b.vel.x;
    gotoxy(b.posi.x >> 14,b.posi.y >> 14);
    printf("%c",179);
    cunt++;
    gotoxy(borderX/2+2,borderY/2);
    printf("%d",cunt);
    }
    else if ((b.posi.y >= ((borderY)<< 14)))
        {
        b.vel.y = -b.vel.y;
        gotoxy(b.posi.x >> 14,b.posi.y >> 14);
        printf("%c",196);
        cunt++;
        gotoxy(borderX/2+2,borderY/2);
        printf("%d",cunt);
        }
    else if (b.posi.y <= (3<<14))
        {
            b.vel.y = -b.vel.y;
            cunt++;
            gotoxy(borderX/2+2,borderY/2);
            printf("%d",cunt);
        }

updatepos(&b);
if ((b.posi.x <= (borderX/2+6 << 14)) && (b.posi.x >= ((borderX/2-6) << 14 ))
    && (b.posi.y <= (borderY/2+2 << 14)) && (b.posi.y >= ((borderY/2-2) << 14 ))) {}
 //  counter(borderX/2-5,borderY/2-1,borderX/2+5,borderY/2+1);

    else {


    gotoxy(b.posi.x >> 14,b.posi.y >> 14);
    printf("o");

    gotoxy(b.posi.x >> 14,b.posi.y >> 14);
    printf(" ");

}


//    gotoxy(borderX+1,borderY+1);
//    printf("x = %d : y = %d",b.posi.x >>14,b.posi.y>>14);



    }
}
*/


/*
int main(void){
    init_usb_uart( 9600 );
   clrscr();

 int32_t grader = -110; //Degrees/360*512


 int32_t sinus_exp = cos(grader);
  printFix(sinus_exp);
      while(1){}
*/




/*
int8_t power(int8_t a, int8_t exp) {
int8_t i, r = a;
for (i = 1; i <= exp; i++)
    r*=a;
    return(r);

}
  int main(void){
    int8_t a;

    printf("\n\n x x^2 x^3 x^4\n");
    for (a = 0; a < 10; a++)
        printf("%8d %8d %8d %8d\n",a, power(a, 2), power(a, 3), power(a, 4));
    fgcolor(13);

    clrscr();
    gotoxy(1, 1);
    window(3,3,30,30,"hello");
    while(1){}
*/



 /*
int main(void){
  init_usb_uart( 9600 );
    printf("hello World!\n");
    while(1){}

>>>>>>> parent of 4bd0666... 6.2 start
}
}*/
