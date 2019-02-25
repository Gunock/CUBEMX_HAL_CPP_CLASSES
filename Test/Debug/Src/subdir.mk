################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/system_stm32f4xx.c 

CPP_SRCS += \
../Src/ADC12.cpp \
../Src/DAC12.cpp \
../Src/GPIO_Pin.cpp \
../Src/Timer.cpp \
../Src/UART.cpp \
../Src/code.cpp \
../Src/main.cpp 

OBJS += \
./Src/ADC12.o \
./Src/DAC12.o \
./Src/GPIO_Pin.o \
./Src/Timer.o \
./Src/UART.o \
./Src/code.o \
./Src/main.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/system_stm32f4xx.o 

C_DEPS += \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/system_stm32f4xx.d 

CPP_DEPS += \
./Src/ADC12.d \
./Src/DAC12.d \
./Src/GPIO_Pin.d \
./Src/Timer.d \
./Src/UART.d \
./Src/code.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F407xx -I"C:/Users/Tomasz Kiljañczyk/OneDrive - student.put.poznan.pl/Prace studia/Projekty Mikrokontroler/TEST_CPP/Inc" -I"C:/Users/Tomasz Kiljañczyk/OneDrive - student.put.poznan.pl/Prace studia/Projekty Mikrokontroler/TEST_CPP/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Tomasz Kiljañczyk/OneDrive - student.put.poznan.pl/Prace studia/Projekty Mikrokontroler/TEST_CPP/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Tomasz Kiljañczyk/OneDrive - student.put.poznan.pl/Prace studia/Projekty Mikrokontroler/TEST_CPP/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Tomasz Kiljañczyk/OneDrive - student.put.poznan.pl/Prace studia/Projekty Mikrokontroler/TEST_CPP/Drivers/CMSIS/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F407xx -I"C:/Users/Tomasz Kiljañczyk/OneDrive - student.put.poznan.pl/Prace studia/Projekty Mikrokontroler/TEST_CPP/Inc" -I"C:/Users/Tomasz Kiljañczyk/OneDrive - student.put.poznan.pl/Prace studia/Projekty Mikrokontroler/TEST_CPP/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Tomasz Kiljañczyk/OneDrive - student.put.poznan.pl/Prace studia/Projekty Mikrokontroler/TEST_CPP/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Tomasz Kiljañczyk/OneDrive - student.put.poznan.pl/Prace studia/Projekty Mikrokontroler/TEST_CPP/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Tomasz Kiljañczyk/OneDrive - student.put.poznan.pl/Prace studia/Projekty Mikrokontroler/TEST_CPP/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


