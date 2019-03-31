# CUBEMX_HAL_CPP_WRAPPER
Wrapper classes made to be used with CubeMX generated projects converted to C++. It's my personal project I made to make programming STM32F4 in C++ easier.

## What's done
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
  tim4.start_PWM_channel(channel)
  tim4.set_PWM_channel_ccr(channel, ccr)
  
  // Other methods
  tim4.set_prescaler(psc);
  tim4.set_period(per);
  tim4.set(psc, per)        // Combined above methods, first argument is prescaler, second is period
  tim4.interrupt_enable();
  tim4.inerrupt_disable();
```
### ADC/DAC
```cpp
  // Constructors
  ADC12 adc1(&hadc1);
  DAC12 dac(&hdac);
  
  // DAC methods
  dac.set_value(val);
  dac.start();
  dac.stop();
  
  // ADC methods
  adc.read_value();
  adc.read_voltage();
```
### UART
```cpp
  // Constructor
  UART uart(&huart3);
  
  // Methods
  uart.transmit("text");
  uart.receive(string, size);
  uart.receive(cString, size);
  uart.receive_all(string);  // Saves data until not receiving
  uart.discard_all();	     // Discards data until not receiving
```
### USB VCP
IMPORTANT: In order for this class to work you need to include USB_Serial.hpp in usb_device.c and use USB_Serial_init function in USB_Init_PostTreatment section. REMEMBER to write your code in USER sections.
```cpp
  // USB_Serial is static class
  // Methods
  USB_Serial::transmit(string);
```
### Interrupts
```cpp
  // Interrupts is static class
  // used_headers.h file required (include there all wrappers that you use)
 
  // Adds function to interrupts (must be void)
  Interrupts::add_moduleName_interrupt(module_class, &func);
 
  // Removes specific function from interrupts
  Interrupts::remove_moduleName_interrupt(module_class, &void_func_ptr);
```
### Init methods
Use init methods when using constructors causes problems.
```cpp
  moduleClass obj;
  obj.init(&handle);
```
