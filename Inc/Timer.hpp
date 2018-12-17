/*
 * Timer.h
 *
 *  Created on: Dec 16, 2018
 *      Author: aszcz
 */

#ifndef TIMER_HPP_
#define TIMER_HPP_

#include "main.h"

class Timer {
	TIM_HandleTypeDef* handle;

public:
	explicit Timer(TIM_HandleTypeDef* htimx);
	~Timer();

	void set(const uint16_t& prescaler, const uint16_t& period) const;
	void set_period(const uint16_t& period) const;

	void start() const;
	void stop() const;
	void interrupt_enable() const;

	void start_interrupt() const;

	void start_PWM_channel(const uint8_t channel) const;
	void set_PWM_channel_ccr(const uint8_t channel, const uint16_t value) const;

};

#endif /* TIMER_HPP_ */
