################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ICU.c \
../g_interrupt.c \
../gpio.c \
../lcd.c \
../project.c \
../ultrasonic.c 

OBJS += \
./ICU.o \
./g_interrupt.o \
./gpio.o \
./lcd.o \
./project.o \
./ultrasonic.o 

C_DEPS += \
./ICU.d \
./g_interrupt.d \
./gpio.d \
./lcd.d \
./project.d \
./ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


