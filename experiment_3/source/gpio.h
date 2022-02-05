/*
 * gpio.h
 *
 *  Created on: Feb. 4, 2022
 *      Author: ds
 */

#ifndef GPIO_H_
#define GPIO_H_


typedef struct
{
	int PDOR;                              /**< Port Data Output Register, offset: 0x0 */
	int PSOR;                              /**< Port Set Output Register, offset: 0x4 */
	int PCOR;                              /**< Port Clear Output Register, offset: 0x8 */
	int PTOR;                              /**< Port Toggle Output Register, offset: 0xC */
	int PDIR;                              /**< Port Data Input Register, offset: 0x10 */
	int PDDR;
} GPIO_Struct;





#define ky_GPIOA_BASE                               (0x400FF000)
#define ky_GPIOA                                    ((GPIO_Struct *)ky_GPIOA_BASE)

#define ky_GPIOB_BASE                               (0x400FF040u)
#define ky_GPIOB                                    ((GPIO_Struct *)ky_GPIOB_BASE)

#define ky_GPIOC_BASE                               (0x400FF080u)
#define ky_GPIOC                                    ((GPIO_Struct *)ky_GPIOC_BASE)

#define ky_GPIOD_BASE                               (0x400FF0C0u)
#define ky_GPIOD                                    ((GPIO_Struct *)ky_GPIOD_BASE)


void ky_GPIO_PortSet(GPIO_Struct* base, int mask);
void ky_GPIO_PortClear(GPIO_Struct* base, int mask);
void ky_GPIO_PinInit(GPIO_Struct* base, int pin, int isInput);

#endif /* GPIO_H_ */
