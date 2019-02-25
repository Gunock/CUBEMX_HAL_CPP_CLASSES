/*
 * code.hpp
 *
 *  Created on: Feb 25, 2019
 *      Author: Tomasz Kiljañczyck
 */

#ifndef CODE_HPP_
#define CODE_HPP_

#include "main.h"

void code_init(
	ADC_HandleTypeDef* 	hadc1,
	DAC_HandleTypeDef* 	hdac,
	TIM_HandleTypeDef* 	htim4,
	UART_HandleTypeDef* huart3
);
void code_main_pre_loop();
void code_main_loop();

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* CODE_HPP_ */
