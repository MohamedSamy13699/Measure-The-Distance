/*
 ===================================================================================================
 Module      : GLOBAL INTERRUBT
 File Name   : g_interrupt.c
 Author      : Mohamed Samy
 Description : Source file for the GLOBAL INTERRUBT driver
 ===================================================================================================
 */
#include <avr/io.h>
#include "common_macros.h"
#include "g_interrupt.h"
void Global_interruptEnable(void)
{
	SET_BIT(SREG,7);
}
void Global_interruptDisable(void)
{
	CLEAR_BIT(SREG,7);
}
