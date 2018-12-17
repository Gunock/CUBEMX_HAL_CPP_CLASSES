/*
 * UART.hpp
 *
 *  Created on: Dec 17, 2018
 *      Author: Tomasz Kiljañczyck
 */

#ifndef UART_HPP_
#define UART_HPP_

#include "main.h"

class UART {
	UART_HandleTypeDef* handle;

public:
	UART(UART_HandleTypeDef* huartx);
	~UART();

	void transmit(uint8_t* tData, const uint32_t& size) const;
	void transmit(const char* tData) const;
	void receive(uint8_t* rData, const uint32_t& size) const;
};

#endif /* UART_HPP_ */
