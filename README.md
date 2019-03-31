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

## Examples
IMPORTANT: To use C++ wrappers first you have to configure desired periphery in CubeMX!
### GPIO_Pin
```cpp
  // Constructor
	GPIO_Pin blueLED(GPIOD, GPIO_PIN_15);
  
  // Switch state methods
  blueLed.on();
  blueLed.off();
  blueLed.toggle();
  
  // Write method (every variant does the same thing)
  blueLed.write(GPIO_PIN_SET);
  blueLed.write(true);
  blueLed.write(1);
```
### Timer
```cpp
  // Constructor
  Timer tim4(&htim4);
  
  // Start/stop methods
  tim4.start();             // Starts timer (no interrupt)
  tim4.start_interrupt();   // Starts timer (with interrupt)
  tim4.stop();
  
  // PWM methods
  tim4.start_PWM_channel(1) // Starts given PWM channel
  tim4.set_PWM_channel_ccr(1,100)
  
  // Other methods
  tim4.set_period(100);
  tim4.set_prescaler(100);
  tim4.set(100,100)         // Combined above methods, first argument is prescaler, second is period
  tim4.interrupt_enable();
  tim4.inerrupt_disable();
```
### ADC/DAC
### UART
### USB VCPt
### Interrupts
