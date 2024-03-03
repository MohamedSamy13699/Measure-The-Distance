# Measure-The_Distance

Implementation of the system to measure the distance using ultrasonic sensor HC-SR04

To implement a system that measures distance using the HC-SR04 Ultrasonic sensor with an ATmega32 microcontroller, you'll integrate various drivers based on a layered architecture model. Below is an outline of how you can structure your project, including brief descriptions of each component and pseudo-code snippets to guide your implementation.

You'll be using an ATmega32 running at 8 MHz, interfacing with an HC-SR04 Ultrasonic sensor to measure distance. The distance measured will be displayed on a 4x16 LCD. The system will be built on a layered architecture model, comprising GPIO, ICU (Input Capture Unit), LCD, and Ultrasonic drivers.
