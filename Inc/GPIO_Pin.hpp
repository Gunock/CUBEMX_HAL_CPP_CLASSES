/*
 * GPIO_Pin.h
 *
 *  Created on: Dec 16, 2018
 *      Author: Tomasz Kiljañczyk
 */

#ifndef GPIO_PIN_HPP_
#define GPIO_PIN_HPP_

#include "main.h"

class GPIO_Pin {
private:
	GPIO_TypeDef* port;
	const uint16_t pin = -1;

public:
	explicit GPIO_Pin(GPIO_TypeDef* GPIOx, const uint16_t& GPIO_Pin);
	~GPIO_Pin();

	void on() const;
	void off() const;
	void toggle() const;
	void write(const bool& state) const;
	void write(const GPIO_PinState& state) const;
	bool read() const;
};

#endif /* GPIO_PIN_HPP_ */
