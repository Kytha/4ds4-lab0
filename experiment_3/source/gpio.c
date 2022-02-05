#include "gpio.h"

void ky_GPIO_PinInit(GPIO_Struct* base, int pin, int isInput)
{
    if (isInput)
    {
        base->PDDR &= ~(1UL << pin);
    }
    else
    {
        base->PDDR |= (1UL << pin);
    }
}


void ky_GPIO_PortSet(GPIO_Struct* base, int mask)
{
	base->PSOR = mask;
}

void ky_GPIO_PortClear(GPIO_Struct* base, int mask)
{
	base->PCOR = mask;
}


