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
#include <string.h>
#include "charset.h"
#include "lcd.h"



int main(void)
{
    init_usb_uart( 115200 );
    clrscr();
    gotoxy(1,1);

    RCC->CFGR2  &= ~RCC_CFGR2_ADCPRE12;         // Clear ADC12 prescaler bits
    RCC->CFGR2  |=  RCC_CFGR2_ADCPRE12_DIV6;    // Set ADC12 prescaler to 6
    RCC->AHBENR |=  RCC_AHBPeriph_ADC12;        // Enable clock for ADC12

    ADC1->CR    = 0x00000000;                   // Clear CR register
    ADC1->CFGR &=  0xFDFFC007;                  // Clear ADC1 config register
    ADC1->SQR1 &= ~ADC_SQR1_L;                  // Clear regular sequence register 1

    ADC1->CR |= 0x10000000;                     // Enable internal ADC voltage regulator
    for(int i = 0 ; i < 1000 ; i++) {}          // Wait for about 16 microseconds

    ADC1->CR |= 0x80000000;                     // Start ADC1 calibration
    while (!(ADC1->CR & 0x80000000));           // Wait for calibration to finish
        for (int i = 0 ; i < 100 ; i++) {}      // Wait for a little while

    ADC1->CR |= 0x00000001;                     // Enable ADC1 (0x01 -Enable, 0x02 -Disable)
    while (!(ADC1->ISR& 0x00000001));           // Wait until ready



    while (1){
       ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_1Cycles5);

    ADC_StartConversion(ADC1);                  // Start ADC read
    while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

    uint16_t x = ADC_GetConversionValue(ADC1);  // Read the ADC value

    ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_1Cycles5);
    ADC_StartConversion(ADC1);                  // Start ADC read
    while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

    uint16_t y = ADC_GetConversionValue(ADC1);  // Read the ADC value
    gotoxy(1,1);
    printf("%d %d",x,y);
    clrscr();

    }
}



/*
int main(void)
{
    init_usb_uart( 115200 );
    clrscr();
    gotoxy(1,1);

    init_spi_lcd();
    uint8_t buffer[512];
    memset(buffer,0x00,512);
    uint8_t priority = 1;
    uint8_t x = 1;


    init_timer(priority);

    while (1)
    {
        if (get_flag() == 1)
        {
            lcd_update(buffer, &x,1);
            lcd_push_buffer(buffer);
            set_flag(0);
        }
    }
}
*/






/*
int main(void) {
    init_usb_uart( 115200 );
    gotoxy(1, 1);
    clrscr();
    uint16_t priority = 1;
    uint8_t ss =1, push=0;
    time(&t);



    // Lav vindue
    clrscr();
    init_stopwatch();
    init_timer(priority);
    while (1) {

        uint8_t js = ret();
        stopwatch(js, &ss, &push);
    }
}
*/




/*
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
*/





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

>>>>>>> parent of 4bd0666... 6.2 start
}
}*/
