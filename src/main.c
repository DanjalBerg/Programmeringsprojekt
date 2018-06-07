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


struct interrupt_t{
    volatile int16_t h, m, s, hs;
};

struct interrupt_t t;

void time(struct interrupt_t *t){
    t->h = 0;
    t->m = 0;
    t->s = 0;
    t->hs = 0;
}

void TIM2_IRQHandler(void){

  //  printf("kris da noda jedi master son of Goku\n");
    TIM2->SR &= ~0x0001; // clear interrupt bit
    t.hs++;
    if (t.hs == 100){
    t.hs=0;
    t.s++;
    }
    if (t.s==60){
    t.s=0;
    t.m++;
    }
    if (t.m==60){
    t.m=0;
    t.h++;
    }
}


int main(void){
    init_usb_uart( 115200 );
    printf("%c[?25l",ESC);
    uint16_t Priority = 1;
    init_joystick();
    gotoxy(1,1);

    time(&t);
    uint8_t ss = 1;
    uint8_t push = 0;


// Lav vindue
    clrscr();
    gotoxy(1,1);
  window(1, 1, 31, 6, "Stop watch");
  gotoxy(2,3);
  printf("Time since start: ");
  gotoxy(2,4);
  printf("Split time 1:");
  gotoxy(2,5);
  printf("Split time 2:");


    RCC->APB1ENR |= RCC_APB1Periph_TIM2;
    TIM2->CR1 = 0x0000; // Disable time
    TIM2->ARR = 639999; // Set auto reload value (100e-2*64e6)-1
    TIM2->PSC = 0;
    TIM2->DIER |=0x0001;
    NVIC_SetPriority(TIM2_IRQn, Priority);
    NVIC_EnableIRQ(TIM2_IRQn);

    TIM2->CR1 |= 0x0001; // enable time


   while(1){

        // Print time since start
        if ((t.s < 10) && (t.m <10 )){
        gotoxy(20,3);
        printf("%d:0%d:0%d.%d",t.h,t.m,t.s,t.hs);
        }
        else if (t.s < 10){
        gotoxy(20,3);
        printf("%d:%d:0%d.%d",t.h,t.m,t.s,t.hs);
        }
        else if (t.m < 10){
        gotoxy(20,3);
        printf("%d:0%d:%d.%d",t.h,t.m,t.s,t.hs);
        }
        else {
        gotoxy(20,3);
        printf("%d:%d:%d.%d",t.h,t.m,t.s,t.hs);
        }


        // Print Split time 1
        uint8_t val = readJoystick();
        if (val == 4){

            if ((t.s < 10) && (t.m <10 )){
            gotoxy(20,4);
            printf("%d:0%d:0%d.%d",t.h,t.m,t.s,t.hs);
            }
            else if (t.s < 10){
            gotoxy(20,4);
            printf("%d:%d:0%d.%d",t.h,t.m,t.s,t.hs);
            }
            else if (t.m < 10){
            gotoxy(20,4);
            printf("%d:0%d:%d.%d",t.h,t.m,t.s,t.hs);
            }
            else {
            gotoxy(20,4);
            printf("%d:%d:%d.%d",t.h,t.m,t.s,t.hs);
            }
        }
        else if (val == 8){
            if ((t.s < 10) && (t.m <10 )){
            gotoxy(20,5);
            printf("%d:0%d:0%d.%d",t.h,t.m,t.s,t.hs);
            }
            else if (t.s < 10){
            gotoxy(20,5);
            printf("%d:%d:0%d.%d",t.h,t.m,t.s,t.hs);
            }
            else if (t.m < 10){
            gotoxy(20,5);
            printf("%d:0%d:%d.%d",t.h,t.m,t.s,t.hs);
            }
            else {
            gotoxy(20,5);
            printf("%d:%d:%d.%d",t.h,t.m,t.s,t.hs);
            }

        }
        else if (val == 16){

            if (ss==1 && push ==0){
                __disable_irq();
                ss=0;
                push = 1;
            }
            else if (ss==0 && push == 0) {
                __enable_irq();
                ss=1;
                push = 1;
            }
        }
        else if (val == 0){
           push = 0;
        }
        else if (val == 2){
            time(&t);
            gotoxy(20,3);
            printf("%d:0%d:0%d.0%d",t.h,t.m,t.s,t.hs);
        }
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
   int32_t borderX = 50; // Skal være et lige tal
   int32_t borderY = 20; // Skal være et lige tal
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

}
*/
