/*
 ===================================================================================================
 Module      : ULTRASONIC
 File Name   : ultrasonic.h
 Author      : Mohamed Samy
 Description : Header file for the ULTRASONIC driver
 ===================================================================================================
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"  // Include standard types header file
#include "gpio.h"       // Include GPIO header file for pin configuration

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ULTRASONIC_TRIGGER_PORT PORTB_ID
#define ULTRASONIC_TRIGGER_PIN  PIN5_ID

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description: Function responsible for initialization of ultrasonic sensor
 * 1. Initialize Input Capture Unit (ICU).
 * 2. Setup the ICU callback function.
 * 3. Setup the direction for the trigger pin as an output pin through the GPIO driver.
 */
void Ultrasonic_init(void);

/*
 * Description: Function responsible for sending the trigger pulse to the ultrasonic sensor.
 */
void Ultrasonic_Trigger(void);

/*
 * Function description: Function responsible for reading distance using ultrasonic sensor.
 *  1. Send the trigger pulse by using Ultrasonic_Trigger function so the ultrasonic sensor starts to produce echo pulse.
 *	2. Start the measurements by the Input Capture Unit (ICU) from this moment.
 *
 *	Return: The measured distance in centimeters.
 */
uint16 Ultrasonic_readDistance(void);

/*
 * Function description:
 * This is the callback function called by the ICU driver.
 * We initialize the callback in Ultrasonic_init().
 * The function is used to calculate the high time (pulse time) generated by the ultrasonic sensor.
 */
void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */
