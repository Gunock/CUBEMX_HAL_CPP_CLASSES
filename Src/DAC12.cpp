/*
 * DAC12.cpp
 *
 *  Created on: Dec 17, 2018
 *      Author: Tomasz Kiljañczyck
 */

#include <DAC12.hpp>

DAC12::DAC12(DAC_HandleTypeDef* hdacx, uint8_t channel)
			: handle(hdacx),channel(channel){}

DAC12::~DAC12() {}

void DAC12::set_value(const uint16_t& value_)
{
	this->value = value_;
	HAL_DAC_SetValue(handle, channel, DAC_ALIGN_12B_R, value_);
}

const int16_t DAC12::get_value() const { return this->value; }

void DAC12::start() const {
	HAL_DAC_Start(handle, channel);
}
