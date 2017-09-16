################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LwIP/src/core/def.c \
../Middlewares/Third_Party/LwIP/src/core/dns.c \
../Middlewares/Third_Party/LwIP/src/core/inet_chksum.c \
../Middlewares/Third_Party/LwIP/src/core/init.c \
../Middlewares/Third_Party/LwIP/src/core/ip.c \
../Middlewares/Third_Party/LwIP/src/core/mem.c \
../Middlewares/Third_Party/LwIP/src/core/memp.c \
../Middlewares/Third_Party/LwIP/src/core/netif.c \
../Middlewares/Third_Party/LwIP/src/core/pbuf.c \
../Middlewares/Third_Party/LwIP/src/core/raw.c \
../Middlewares/Third_Party/LwIP/src/core/stats.c \
../Middlewares/Third_Party/LwIP/src/core/sys.c \
../Middlewares/Third_Party/LwIP/src/core/tcp.c \
../Middlewares/Third_Party/LwIP/src/core/tcp_in.c \
../Middlewares/Third_Party/LwIP/src/core/tcp_out.c \
../Middlewares/Third_Party/LwIP/src/core/timeouts.c \
../Middlewares/Third_Party/LwIP/src/core/udp.c 

OBJS += \
./Middlewares/Third_Party/LwIP/src/core/def.o \
./Middlewares/Third_Party/LwIP/src/core/dns.o \
./Middlewares/Third_Party/LwIP/src/core/inet_chksum.o \
./Middlewares/Third_Party/LwIP/src/core/init.o \
./Middlewares/Third_Party/LwIP/src/core/ip.o \
./Middlewares/Third_Party/LwIP/src/core/mem.o \
./Middlewares/Third_Party/LwIP/src/core/memp.o \
./Middlewares/Third_Party/LwIP/src/core/netif.o \
./Middlewares/Third_Party/LwIP/src/core/pbuf.o \
./Middlewares/Third_Party/LwIP/src/core/raw.o \
./Middlewares/Third_Party/LwIP/src/core/stats.o \
./Middlewares/Third_Party/LwIP/src/core/sys.o \
./Middlewares/Third_Party/LwIP/src/core/tcp.o \
./Middlewares/Third_Party/LwIP/src/core/tcp_in.o \
./Middlewares/Third_Party/LwIP/src/core/tcp_out.o \
./Middlewares/Third_Party/LwIP/src/core/timeouts.o \
./Middlewares/Third_Party/LwIP/src/core/udp.o 

C_DEPS += \
./Middlewares/Third_Party/LwIP/src/core/def.d \
./Middlewares/Third_Party/LwIP/src/core/dns.d \
./Middlewares/Third_Party/LwIP/src/core/inet_chksum.d \
./Middlewares/Third_Party/LwIP/src/core/init.d \
./Middlewares/Third_Party/LwIP/src/core/ip.d \
./Middlewares/Third_Party/LwIP/src/core/mem.d \
./Middlewares/Third_Party/LwIP/src/core/memp.d \
./Middlewares/Third_Party/LwIP/src/core/netif.d \
./Middlewares/Third_Party/LwIP/src/core/pbuf.d \
./Middlewares/Third_Party/LwIP/src/core/raw.d \
./Middlewares/Third_Party/LwIP/src/core/stats.d \
./Middlewares/Third_Party/LwIP/src/core/sys.d \
./Middlewares/Third_Party/LwIP/src/core/tcp.d \
./Middlewares/Third_Party/LwIP/src/core/tcp_in.d \
./Middlewares/Third_Party/LwIP/src/core/tcp_out.d \
./Middlewares/Third_Party/LwIP/src/core/timeouts.d \
./Middlewares/Third_Party/LwIP/src/core/udp.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LwIP/src/core/%.o: ../Middlewares/Third_Party/LwIP/src/core/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D_TIMEVAL_DEFINED -D_SYS_TIME_H_ '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F429xx -DSTM32F4xx -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Inc" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/system" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/lwip" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/lwip/apps" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/lwip/priv" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/lwip/prot" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/netif" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/netif/ppp" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/netif/ppp/polarssl" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/posix" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/src/include/posix/sys" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Middlewares/Third_Party/LwIP/system/arch" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/Drivers/CMSIS/Include" -I"/home/alxhoff/git/Embedded/stm32_nixie_clock_firmware/Nixie_firmware/libraries"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


