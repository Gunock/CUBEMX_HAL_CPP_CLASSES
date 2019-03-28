# CUBEMX_HAL_CPP_WRAPPER
Wrapper classes made to be used with CubeMX generated projects converted to C++.

## Whats done
- GPIO wrapper (with functions for multi pin toggle/write)
- Timer wrapper
- ADC and DAC wrappers
- UART wrapper
- USB VCP (transmit only)
- Interrupts wrapper

## Test project
Test project is included in this repo. It's located in test folder. It was made for STM32F4 Discovery (STM32F407).

## How to compile C++ for STM
To compile C++ program for STM you have to rename main.c to main.cpp. If that won't work then you have to change makefile to use C++ compiler for .cpp.
The second opiton is to use CLion. To do that i recommend to follow this [tutorial](https://blog.jetbrains.com/clion/2017/12/clion-for-embedded-development-part-ii/).
