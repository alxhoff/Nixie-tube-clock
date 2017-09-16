################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/adc.c \
../Src/buttons.c \
../Src/draw.c \
../Src/ds3231_stm32_alex.c \
../Src/ethernetif.c \
../Src/freertos.c \
../Src/httpserver-netconn.c \
../Src/lwip.c \
../Src/main.c \
../Src/my_timers.c \
../Src/render.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/syscalls.c \
../Src/system_stm32f4xx.c \
../Src/temp.c 

OBJS += \
./Src/adc.o \
./Src/buttons.o \
./Src/draw.o \
./Src/ds3231_stm32_alex.o \
./Src/ethernetif.o \
./Src/freertos.o \
./Src/httpserver-netconn.o \
./Src/lwip.o \
./Src/main.o \
./Src/my_timers.o \
./Src/render.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f4xx.o \
./Src/temp.o 

C_DEPS += \
./Src/adc.d \
./Src/buttons.d \
./Src/draw.d \
./Src/ds3231_stm32_alex.d \
./Src/ethernetif.d \
./Src/freertos.d \
./Src/httpserver-netconn.d \
./Src/lwip.d \
./Src/main.d \
./Src/my_timers.d \
./Src/render.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/syscalls.d \
./Src/system_stm32f4xx.d \
./Src/temp.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D_TIMEVAL_DEFINED -D_SYS_TIME_H_ '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F429xx -DSTM32F4xx -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Inc" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/system" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/lwip" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/lwip/apps" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/lwip/priv" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/lwip/prot" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/netif" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/netif/ppp" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/netif/ppp/polarssl" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/posix" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/posix/sys" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/system/arch" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Drivers/CMSIS/Include" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/libraries"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


