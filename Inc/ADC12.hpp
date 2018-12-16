/*
 * ADC.hpp
 *
 *  Created on: Dec 17, 2018
 *      Author: aszcz
 */

#ifndef ADC12_HPP_
#define ADC12_HPP_

#include "main.h"
class ADC12 {
	const float ref_voltage = 2.95;
	const int16_t max_value = 4095;
	ADC_HandleTypeDef* handle;

public:
	ADC12(ADC_HandleTypeDef* hadcx);
	~ADC12();

	int16_t get_value() const;
	float get_voltage() const;
};

#endif /* ADC12_HPP_ */
