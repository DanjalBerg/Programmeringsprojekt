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

/*
int main(void){
    init_usb_uart( 115200 );
    clrscr();


    // Port A
    RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A
    // Set pin PA0 to input
    GPIOA->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
    GPIOA->MODER |=  (0x00000000 << (4 * 2)); // Set mode register (0x00 - Input,
    //0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOA->PUPDR &= ~(0x00000003 << (4 * 2)); // Clear push/pull register
    GPIOA->PUPDR |=  (0x00000000 << (4 * 2)); // Set push/pull register (0x00 -
    //No pull, 0x01 - Pull-up, 0x02 - Pull-down)

    uint16_t valup = GPIOA->IDR & (0x001 << 4);

    // Port B
 RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port B
    // Set pin PA0 to input
    GPIOB->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
    GPIOB->MODER |=  (0x00000000 << (0 * 2)); // Set mode register (0x00 - Input,
    //0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOB->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
    GPIOB->PUPDR |=  (0x00000000 << (0 * 2)); // Set push/pull register (0x00 -
    //No pull, 0x01 - Pull-up, 0x02 - Pull-down)

    uint16_t valdown = GPIOB->IDR & (0x001 << 0);

    printf("%d\n",valdown);



//
//    // Set pin PA1 to output
//    GPIOA->OSPEEDR &= ~(0x00000003 << (1 * 2)); // Clear speed register
//    GPIOA->OSPEEDR |= (0x00000002 << (1 * 2)); // set speed register (0x01 - 10
//    //MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
//    GPIOA->OTYPER &= ~(0x0001 << (1)); // Clear output type register
//    GPIOA->OTYPER |= (0x0000 << (1)); // Set output type register (0x00 -
//    //Push pull, 0x01 - Open drain)
//    GPIOA->MODER &= ~(0x00000003 << (1 * 2)); // Clear mode register
//    GPIOA->MODER |= (0x00000001 << (1 * 2)); // Set mode register (0x00 - Input,
//    //0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
//    uint16_t val = GPIOA->IDR & (0x0001 << 0);
//    GPIOA->ODR |= (0x0001 << 1); //Set pin PA1 to high
//
//    // Set pin PA0 to input
//    GPIOA->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
//    GPIOA->MODER |= (0x00000004 << (0 * 2)); // Set mode register (0x00 - Input,
   while(1){}
}
*/




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
if ((b.posi.x <= (borderX/2+6 << 14)) && (b.posi.x >= ((borderX/2-6) << 14 )) && (b.posi.y <= (borderY/2+2 << 14)) && (b.posi.y >= ((borderY/2-2) << 14 ))) {}
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
