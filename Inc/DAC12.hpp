/*
 * DAC12.hpp
 *
 *  Created on: Dec 17, 2018
 *      Author: Tomasz Kiljañczyck
 */

#ifndef DAC12_HPP_
#define DAC12_HPP_

#include "main.h"

class DAC12 {
	DAC_HandleTypeDef* handle;
	uint8_t channel;

	uint16_t value = 0;

public:
	explicit DAC12(DAC_HandleTypeDef* hdacx, uint8_t channel);
	~DAC12();

	void set_value(const uint16_t& value_);
	const int16_t get_value() const;

	void start() const;
};

#endif /* DAC12_HPP_ */
