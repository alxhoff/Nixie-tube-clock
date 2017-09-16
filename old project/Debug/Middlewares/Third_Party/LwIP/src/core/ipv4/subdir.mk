################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LwIP/src/core/ipv4/autoip.c \
../Middlewares/Third_Party/LwIP/src/core/ipv4/dhcp.c \
../Middlewares/Third_Party/LwIP/src/core/ipv4/etharp.c \
../Middlewares/Third_Party/LwIP/src/core/ipv4/icmp.c \
../Middlewares/Third_Party/LwIP/src/core/ipv4/igmp.c \
../Middlewares/Third_Party/LwIP/src/core/ipv4/ip4.c \
../Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_addr.c \
../Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_frag.c 

OBJS += \
./Middlewares/Third_Party/LwIP/src/core/ipv4/autoip.o \
./Middlewares/Third_Party/LwIP/src/core/ipv4/dhcp.o \
./Middlewares/Third_Party/LwIP/src/core/ipv4/etharp.o \
./Middlewares/Third_Party/LwIP/src/core/ipv4/icmp.o \
./Middlewares/Third_Party/LwIP/src/core/ipv4/igmp.o \
./Middlewares/Third_Party/LwIP/src/core/ipv4/ip4.o \
./Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_addr.o \
./Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_frag.o 

C_DEPS += \
./Middlewares/Third_Party/LwIP/src/core/ipv4/autoip.d \
./Middlewares/Third_Party/LwIP/src/core/ipv4/dhcp.d \
./Middlewares/Third_Party/LwIP/src/core/ipv4/etharp.d \
./Middlewares/Third_Party/LwIP/src/core/ipv4/icmp.d \
./Middlewares/Third_Party/LwIP/src/core/ipv4/igmp.d \
./Middlewares/Third_Party/LwIP/src/core/ipv4/ip4.d \
./Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_addr.d \
./Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_frag.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LwIP/src/core/ipv4/%.o: ../Middlewares/Third_Party/LwIP/src/core/ipv4/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D_TIMEVAL_DEFINED -D_SYS_TIME_H_ '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F429xx -DSTM32F4xx -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Inc" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/system" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/lwip" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/lwip/apps" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/lwip/priv" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/lwip/prot" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/netif" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/netif/ppp" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/netif/ppp/polarssl" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/posix" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/posix/sys" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/system/arch" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Drivers/CMSIS/Include" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/libraries"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


