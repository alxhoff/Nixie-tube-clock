################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LwIP/src/api/api_lib.c \
../Middlewares/Third_Party/LwIP/src/api/api_msg.c \
../Middlewares/Third_Party/LwIP/src/api/err.c \
../Middlewares/Third_Party/LwIP/src/api/netbuf.c \
../Middlewares/Third_Party/LwIP/src/api/netdb.c \
../Middlewares/Third_Party/LwIP/src/api/netifapi.c \
../Middlewares/Third_Party/LwIP/src/api/sockets.c \
../Middlewares/Third_Party/LwIP/src/api/tcpip.c 

OBJS += \
./Middlewares/Third_Party/LwIP/src/api/api_lib.o \
./Middlewares/Third_Party/LwIP/src/api/api_msg.o \
./Middlewares/Third_Party/LwIP/src/api/err.o \
./Middlewares/Third_Party/LwIP/src/api/netbuf.o \
./Middlewares/Third_Party/LwIP/src/api/netdb.o \
./Middlewares/Third_Party/LwIP/src/api/netifapi.o \
./Middlewares/Third_Party/LwIP/src/api/sockets.o \
./Middlewares/Third_Party/LwIP/src/api/tcpip.o 

C_DEPS += \
./Middlewares/Third_Party/LwIP/src/api/api_lib.d \
./Middlewares/Third_Party/LwIP/src/api/api_msg.d \
./Middlewares/Third_Party/LwIP/src/api/err.d \
./Middlewares/Third_Party/LwIP/src/api/netbuf.d \
./Middlewares/Third_Party/LwIP/src/api/netdb.d \
./Middlewares/Third_Party/LwIP/src/api/netifapi.d \
./Middlewares/Third_Party/LwIP/src/api/sockets.d \
./Middlewares/Third_Party/LwIP/src/api/tcpip.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LwIP/src/api/%.o: ../Middlewares/Third_Party/LwIP/src/api/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D_TIMEVAL_DEFINED -D_SYS_TIME_H_ '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F429xx -DSTM32F4xx -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Inc" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/system" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/lwip" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/lwip/apps" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/lwip/priv" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/lwip/prot" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/netif" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/netif/ppp" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/netif/ppp/polarssl" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/posix" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/posix/sys" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/system/arch" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Drivers/CMSIS/Include" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/libraries"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


