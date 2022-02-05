/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
//Problem 1
#define MEM_LOC(x) 				*((int*)x)
#define LOC1_LOCATION 			MEM_LOC(0x20001000)
#define LOC2_LOCATION 			MEM_LOC(0x20001001)
#define LOC3_LOCATION 			MEM_LOC(0x20001005)
#define LOC4_LOCATION 			MEM_LOC(0x20001007)
//Problem 2
#define ARBITRARY_LOCATION 		MEM_LOC(0x20001004)
#define MODULE 					((ARBITRARY_MODULE*)0x20001000)


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void problem_1();
void problem_2();

/*******************************************************************************
 * Code
 ******************************************************************************/
typedef struct __attribute__((__packed__))
{
	int location_1;
	char location_2;
	int location_3;
} ARBITRARY_MODULE;

/*!
 * @brief Main function
 */




int main(void)
{
    char ch;

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    LOC1_LOCATION = 0xAC;
	char loc1 = LOC1_LOCATION;
	LOC2_LOCATION = 0xAABBCCDD;
	int loc2 = LOC2_LOCATION;
	LOC3_LOCATION = 0xABCD;
	short loc3 = LOC3_LOCATION;
	LOC4_LOCATION = 0xAABBCCDD;
	int loc4 = LOC4_LOCATION;
    //problem_2();

    PRINTF("hello world.\r\n");

    while (1)
    {
        ch = GETCHAR();
        PUTCHAR(ch);
    }
}

