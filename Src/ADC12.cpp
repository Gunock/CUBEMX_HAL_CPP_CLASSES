/*
 * ADC.cpp
 *
 *  Created on: Dec 17, 2018
 *      Author: aszcz
 */

#include <ADC12.hpp>

ADC12::ADC12(ADC_HandleTypeDef* hadcx) : handle(hadcx) {}

ADC12::~ADC12() {}

int16_t ADC12::get_value() const
{
	HAL_ADC_Start(handle);
	if (HAL_ADC_PollForConversion(handle, 10) == HAL_OK)
	{
		return HAL_ADC_GetValue(handle);
	}
	else{ return -1; }
}

float ADC12::get_voltage() const
{
	return (ref_voltage / max_value)*(float)this->get_value();
}

