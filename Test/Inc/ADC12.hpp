/*
 * ADC.hpp
 *
 *  Created on: Dec 17, 2018
 *      Author: aszcz
 */

#ifndef ADC12_HPP_
#define ADC12_HPP_

#include "main.h"

class ADC12 final {
	ADC_HandleTypeDef* handle;

	const float ref_voltage = 2.95;
	const int16_t max_value = 4095;

public:
	explicit ADC12() : handle(nullptr) {}
	explicit ADC12(ADC_HandleTypeDef* hadcx);
	~ADC12() = default;

	void init(ADC_HandleTypeDef* hadcx);

	int16_t get_value() const;
	float get_voltage() const;
};

#endif /* ADC12_HPP_ */
