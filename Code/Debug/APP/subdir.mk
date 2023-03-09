################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/main.c 

OBJS += \
./APP/main.o 

C_DEPS += \
./APP/main.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c APP/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Cooling System\Code\APP" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Cooling System\Code\CONFIG" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Cooling System\Code\HAL" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Cooling System\Code\HAL\L298N" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Cooling System\Code\HAL\LCD" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Cooling System\Code\HAL\LM35" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Cooling System\Code\LIB" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Cooling System\Code\MCAL" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Cooling System\Code\MCAL\ADC" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Cooling System\Code\MCAL\DIO" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Cooling System\Code\MCAL\GID" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Cooling System\Code\MCAL\PORT" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Cooling System\Code\MCAL\TIMER0" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


