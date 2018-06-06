#include "controller.h"

uint8_t readJoystick(){
    RCC->AHBENR |= RCC_AHBPeriph_GPIOA;
    RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port B
    RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port c
    // Port A (up)
    // Enable clock for GPIO Port A
    // Set pin PA0 to input
    GPIOA->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
    GPIOA->MODER |=  (0x00000000 << (4 * 2)); // Set mode register (0x00 - Input,
    //0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOA->PUPDR &= ~(0x00000003 << (4 * 2)); // Clear push/pull register
    GPIOA->PUPDR |=  (0x00000000 << (4 * 2)); // Set push/pull register (0x00 -
    //No pull, 0x01 - Pull-up, 0x02 - Pull-down)

    uint16_t valup = GPIOA->IDR & (0x001 << 4);
 //   uint16_t valup0 = (valup >> 4);
    // Port B (down)

    // Set pin PA0 to input
    GPIOB->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
    GPIOB->MODER |=  (0x00000000 << (0 * 2)); // Set mode register (0x00 - Input,
    //0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOB->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
    GPIOB->PUPDR |=  (0x00000000 << (0 * 2)); // Set push/pull register (0x00 -
    //No pull, 0x01 - Pull-up, 0x02 - Pull-down)
    uint16_t valdown = GPIOB->IDR & (0x001 << 0);

    // Port C(right)
    // Set pin PA0 to input
    GPIOC->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
    GPIOC->MODER |=  (0x00000000 << (0 * 2)); // Set mode register (0x00 - Input,
    //0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOC->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
    GPIOC->PUPDR |=  (0x00000000 << (0 * 2)); // Set push/pull register (0x00 -
    //No pull, 0x01 - Pull-up, 0x02 - Pull-down)

    uint16_t valright = GPIOC->IDR & (0x001 << 0);
 // Port C(left)
    // Set pin PC1 to input
    GPIOC->MODER &= ~(0x00000003 << (1 * 2)); // Clear mode register
    GPIOC->MODER |=  (0x00000000 << (1 * 2)); // Set mode register (0x00 - Input,
    //0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOC->PUPDR &= ~(0x00000003 << (1 * 2)); // Clear push/pull register
    GPIOC->PUPDR |=  (0x00000000 << (1 * 2)); // Set push/pull register (0x00 -
    //No pull, 0x01 - Pull-up, 0x02 - Pull-down)
    uint16_t valleft = GPIOC->IDR & (0x001 << 1);

  // PortB(Center)

    // Set pin PB5 to input
    GPIOB->MODER &= ~(0x00000003 << (5 * 2)); // Clear mode register
    GPIOB->MODER |=  (0x00000000 << (5 * 2)); // Set mode register (0x00 - Input,
    //0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
    GPIOB->PUPDR &= ~(0x00000003 << (5 * 2)); // Clear push/pull register
    GPIOB->PUPDR |=  (0x00000000 << (5 * 2)); // Set push/pull register (0x00 -
    //No pull, 0x01 - Pull-up, 0x02 - Pull-down)
    uint16_t valcenter = GPIOB->IDR & (0x001 << 5);

    if(valup){
    valup = 1;
    }

    if(valdown){
    valdown = 1;
    }

if(valright){
    valright = 1;
    }

    if(valleft){
    valleft = 1;
    }

    if(valcenter){
    valcenter = 1;
    }
//printf("000%d%d%d%d%d\n",valcenter,valright,valleft,valdown,valup);

    int8_t val1 = (valdown << 1);
    int8_t val2 = (valleft << 2);
    int8_t val3 = (valright << 3);
    int8_t val4 = (valcenter << 4);

    int8_t output = valup |= val1 |= val2 |= val3 |= val4;

    // printf("%d\n",output);

    return(output);
//    printf("%d\n",output);
}
