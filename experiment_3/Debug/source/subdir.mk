################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/gpio.c \
../source/gpio_led_output.c \
../source/semihost_hardfault.c 

OBJS += \
./source/gpio.o \
./source/gpio_led_output.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/gpio.d \
./source/gpio_led_output.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MK66FN2M0VMD18 -DCPU_MK66FN2M0VMD18_cm4 -DFRDM_K66F -DFREEDOM -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/experiment_3/board" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/experiment_3/source" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/experiment_3/utilities" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/experiment_3/drivers" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/experiment_3/device" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/experiment_3/component/uart" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/experiment_3/component/lists" -I"/home/ds/Documents/MCUXpresso_11.4.1_6260/workspace/experiment_3/CMSIS" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


