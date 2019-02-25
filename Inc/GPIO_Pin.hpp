/*
 * GPIO_Pin.h
 *
 *  Created on: Dec 16, 2018
 *      Author: Tomasz Kiljañczyk
 */

#ifndef GPIO_PIN_HPP_
#define GPIO_PIN_HPP_

#include "main.h"
#include <initializer_list>


class GPIO_Pin final {
public:
	GPIO_TypeDef* port;
	const uint16_t pin = -1;

	explicit GPIO_Pin(GPIO_TypeDef* GPIOx, const uint16_t& GPIO_Pin);
	~GPIO_Pin() = default;

	void on() const;
	void off() const;
	void toggle() const;
	void write(const bool& state) const;
	void write(const GPIO_PinState& state) const;
	bool read() const;
};

void pins_toggle(const std::initializer_list<const GPIO_Pin*>& pins);
void pins_write(const std::initializer_list<const GPIO_Pin*>& pins, const GPIO_PinState& state);
void pins_write(const std::initializer_list<const GPIO_Pin*>& pins, const bool& state);

#endif /* GPIO_PIN_HPP_ */
