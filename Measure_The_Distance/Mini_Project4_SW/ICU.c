/*
 ===================================================================================================
 Module      : ICU
 File Name   : ICU.c
 Author      : Mohamed Samy
 Description : Source file for the ICU driver
 ===================================================================================================
 */

#include "ICU.h"
#include "std_types.h"
#include "common_macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "gpio.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

ISR(TIMER1_CAPT_vect)
{

	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */

	}

}
/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 */
void ICU_init(const ICU_ConfigType * Config_Ptr)
{
	/* Configure ICP1/PD6 as i/p pin */
		DDRD &= ~(1<<PD6);
	/*****************************Timer Configuration**************************************
	 * select Normal port operation, OC1A/OC1B disconnected.
	 * 		COM1A1 = 0 COM1B1 =0 ,  COM1A0 = 0  COM1B0=0
	 *
	 * Force Output Compare for Compare unit A : FOC1A = 1 -->non-PWM mode.
	   Force Output Compare for Compare unit B : FOC1B = 1 -->non-PWM mode.
	 *
	 * Waveform Generation Mode --> Normal mode
	 * 		WGM13 = 0, WGM12 = 0,  WGM11 = 0, WGM10 = 0
	 *
	 * Clock Select  set by the user
	 *
	 * TCNT1 = 0
	 *************************************************************************************/
	TCCR1A =0;
	SET_BIT(TCCR1A,FOC1A);
	SET_BIT(TCCR1A,FOC1B);
	TCCR1B = (TCCR1B & TIMER_CLOCKSELECT_MASK)|(Config_Ptr->clock);


	/*****************************ICU Configuration**************************************
	 * Input Capture Edge Select (RISING OR FALLING)set by the user
	 *
	 * Put initial value on Input Capture Register --> ICR1=0
	 *
	 * Input Capture Interrupt Enable -->   TICIE1 =1 should enable I-bit at application
	 	 	 	 	 	 	 	 	 	 	 	 	  to can generate the interrupt
	 *
	 *
	 *************************************************************************************/
	TCCR1B = (TCCR1B & ICU_EDGETYPE_MASK)|( (Config_Ptr->edge) << ICES1);
	TCNT1=0;
	ICR1=0;
	SET_BIT(TIMSK,TICIE1);

}

/*
 * Description: Function to set the Call Back function address.
 */
void ICU_setCallBack(void(*a_ptr)(void))
{

	g_callBackPtr = a_ptr;
}

/*
 * Description: Function to set the required edge detection.
 */
void ICU_setEdgeDetectionType(const ICU_EdgeType edgeType)
{
	/*
	 * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B = (TCCR1B & ICU_EDGETYPE_MASK)|( (edgeType) << ICES1);
}

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 ICU_getInputCaptureValue(void)
{
	return ICR1;
}

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void ICU_clearTimerValue(void)
{
	TCNT1 =0;
}

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void ICU_deInit(void)
{
	/* Clear All Timer1/ICU Registers */
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1  = 0;
	ICR1   = 0;

	/* Disable the Input Capture interrupt */
	TIMSK &= ~(1<<TICIE1);

	/* Reset the global pointer value */
	g_callBackPtr = NULL_PTR;
}
