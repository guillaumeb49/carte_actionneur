################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Application/A_I2C.c \
../src/Application/A_capteur_ultrason.c \
../src/Application/A_servo_moteur.c 

OBJS += \
./src/Application/A_I2C.o \
./src/Application/A_capteur_ultrason.o \
./src/Application/A_servo_moteur.o 

C_DEPS += \
./src/Application/A_I2C.d \
./src/Application/A_capteur_ultrason.d \
./src/Application/A_servo_moteur.d 


# Each subdirectory must supply rules for building sources it contributes
src/Application/%.o: ../src/Application/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DOS_USE_SEMIHOSTING -DTRACE -DOS_USE_TRACE_SEMIHOSTING_STDOUT -DSTM32F30X -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f3-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


