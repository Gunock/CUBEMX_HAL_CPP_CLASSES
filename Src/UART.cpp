/*
 * UART.cpp
 *
 *  Created on: Dec 17, 2018
 *      Author: Tomasz Kiljañczyck
 */

#include "UART.hpp"
#include <string>

UART::UART(UART_HandleTypeDef* huartx) : handle(huartx){}

UART::~UART() {}

void UART::transmit(uint8_t* tData, const uint32_t& size) const
{
	HAL_UART_Transmit_IT(handle, tData, size);
}

void UART::transmit(const char* tData) const
{
	const int32_t size = std::string(tData).size();
	uint8_t converted[size];
	for(int32_t i = 0; i < size; i++){converted[i] = tData[i];}
	this->transmit(converted, size);
}

void UART::receive(uint8_t* rData, const uint32_t& size) const
{
	HAL_UART_Receive_IT(handle, rData, size);
}
