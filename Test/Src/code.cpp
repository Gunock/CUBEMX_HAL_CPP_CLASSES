/*
 * code.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: Tomasz Kiljańczyk
 */

//STL

//Internals
#include "GPIO_Pin.hpp"
#include "Timer.hpp"
#include "ADC12.hpp"
#include "DAC12.hpp"
#include "UART.hpp"
#include "Interrupts.hpp"

#include "code.hpp"

//Pins
const GPIO_Pin blueLED(GPIOD, GPIO_PIN_15);
const GPIO_Pin redLED(GPIOD, GPIO_PIN_14);
const GPIO_Pin orangeLED(GPIOD, GPIO_PIN_13);
const GPIO_Pin greenLED(GPIOD, GPIO_PIN_12);

//Timer
Timer tim4;

//ADC/DAC
ADC12 adc1;
DAC12 dac;

//UART
UART uart3;


void code_init(
        ADC_HandleTypeDef *hadc1,
        DAC_HandleTypeDef *hdac,
        TIM_HandleTypeDef *htim4,
        UART_HandleTypeDef *huart3
) {
    adc1.init(hadc1);
    dac.init(hdac, DAC_CHANNEL_1);
    tim4.init(htim4);
    uart3.init(huart3);
}

void tim_interrupt_func() {
    pins_toggle({&blueLED, &orangeLED, &redLED});
}

void code_main_pre_loop() {
    Interrupts::add_tim_interrupt(tim4, &tim_interrupt_func);

    redLED.toggle();
    tim4.set(8399, 999);
    tim4.start_interrupt();
}

void code_main_loop() {

}
