/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_debug_console.h"
//#include "fsl_gpio.h"
#include "gpio.h"



/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_LED_GPIO_BLUE     ky_GPIOC
#define BOARD_LED_PIN_BLUE 		8

#define BOARD_LED_GPIO_GREEN    ky_GPIOC
#define BOARD_LED_PIN_GREEN 	9

#define BOARD_LED_GPIO_RED    	ky_GPIOD
#define BOARD_LED_PIN_RED 		1

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief delay a while.
 */
void delay(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
void delay(void)
{
    volatile uint32_t i = 0;
    for (i = 0; i < 800000; ++i)
    {
        __asm("NOP"); /* delay */
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    /* Define the init structure for the output LED pin*/
    gpio_pin_config_t led_config = {
        kGPIO_DigitalOutput,
        0,
    };

    /* Board pin, clock, debug console init */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    /* Print a note to terminal. */
    PRINTF("\r\n GPIO Driver example\r\n");
    PRINTF("\r\n The LED is blinking.\r\n");

    ky_GPIO_PinInit(BOARD_LED_GPIO_BLUE, BOARD_LED_PIN_BLUE, 0);
    ky_GPIO_PinInit(BOARD_LED_GPIO_GREEN, BOARD_LED_PIN_GREEN, 0);
    ky_GPIO_PinInit(BOARD_LED_GPIO_RED, BOARD_LED_PIN_RED, 0);
    /* Init output LED GPIO. */
    /*
    GPIO_PinInit(BOARD_LED_GPIO_BLUE, BOARD_LED_PIN_BLUE, &led_config);
    GPIO_PinInit(BOARD_LED_GPIO_GREEN, BOARD_LED_PIN_GREEN, &led_config);
    GPIO_PinInit(BOARD_LED_GPIO_RED, BOARD_LED_PIN_RED, &led_config);
    */

    while (1)
    {
    	delay();
    	ky_GPIO_PortSet(BOARD_LED_GPIO_BLUE, 1u << BOARD_LED_PIN_BLUE);
        delay();
        ky_GPIO_PortClear(BOARD_LED_GPIO_BLUE, 1u << BOARD_LED_PIN_BLUE);
        delay();
        ky_GPIO_PortSet(BOARD_LED_GPIO_GREEN, 1u << BOARD_LED_PIN_GREEN);
        delay();
        ky_GPIO_PortClear(BOARD_LED_GPIO_GREEN, 1u << BOARD_LED_PIN_GREEN);
        delay();
        ky_GPIO_PortSet(BOARD_LED_GPIO_RED, 1u << BOARD_LED_PIN_RED);
        delay();
        ky_GPIO_PortClear(BOARD_LED_GPIO_RED, 1u << BOARD_LED_PIN_RED);

    	/*
    	delay();
    	GPIO_PortSet(BOARD_LED_GPIO_BLUE, 1u << BOARD_LED_PIN_BLUE);
        delay();
        GPIO_PortClear(BOARD_LED_GPIO_BLUE, 1u << BOARD_LED_PIN_BLUE);
        delay();
        GPIO_PortSet(BOARD_LED_GPIO_GREEN, 1u << BOARD_LED_PIN_GREEN);
        delay();
        GPIO_PortClear(BOARD_LED_GPIO_GREEN, 1u << BOARD_LED_PIN_GREEN);
        delay();
        GPIO_PortSet(BOARD_LED_GPIO_RED, 1u << BOARD_LED_PIN_RED);
        delay();
        GPIO_PortClear(BOARD_LED_GPIO_RED, 1u << BOARD_LED_PIN_RED);
        */
    }
}
