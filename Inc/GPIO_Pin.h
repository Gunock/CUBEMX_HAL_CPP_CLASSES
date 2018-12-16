/*
 * GPIO_Pin.h
 *
 *  Created on: Dec 16, 2018
 *      Author: Tomasz Kiljañczyk
 */

#ifndef GPIO_PIN_H_
#define GPIO_PIN_H_

#include "main.h"

class GPIO_Pin {
private:
	GPIO_TypeDef* port;
	const uint16_t pin = -1;

public:
	GPIO_Pin(GPIO_TypeDef* GPIOx, const uint16_t& GPIO_Pin);
	~GPIO_Pin();

	void on();
	void off();
	void toggle();
	void write(const bool& state);
	void write(const GPIO_PinState& state);
	bool read();
};

#endif /* GPIO_PIN_H_ */
