/*
 * Timer.h
 *
 *  Created on: Dec 16, 2018
 *      Author: aszcz
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "main.h"

class Timer {
	TIM_HandleTypeDef* handle;

public:
	Timer(TIM_HandleTypeDef* htimx);
	~Timer();

	void set(const uint16_t& prescaler, const uint16_t& period);
	void set_period(const uint16_t& period);
	void start();
};

#endif /* TIMER_H_ */
