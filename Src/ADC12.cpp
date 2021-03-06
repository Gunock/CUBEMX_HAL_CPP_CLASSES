/*
 * ADC.cpp
 *
 *  Created on: Dec 17, 2018
 *      Author: aszcz
 */

#include <ADC12.hpp>

ADC12::ADC12(ADC_HandleTypeDef *hadcx) : handle(hadcx) {}

void ADC12::init(ADC_HandleTypeDef *hadcx) {
    handle = hadcx;
}

uint16_t ADC12::read_value() const {
    HAL_ADC_Start(handle);
    if (HAL_ADC_PollForConversion(handle, 10) == HAL_OK) {
        return HAL_ADC_GetValue(handle);
    } else { return -1; }
}

float ADC12::read_voltage() const {
    return (this->ref_voltage / this->max_value) * (float) this->read_value();
}

