/*
 * Timer.cpp
 *
 *  Created on: Dec 16, 2018
 *      Author: aszcz
 */

#include "Timer.hpp"

Timer::Timer(TIM_HandleTypeDef* htimx) : handle(htimx) {}

Timer::~Timer() {}

void Timer::set(const uint16_t& prescaler, const uint16_t& period) const
{
	if(prescaler == 0){handle->Instance->PSC = 1;}
	else { handle->Instance->PSC = prescaler; }
	if(period == 0){handle->Instance->ARR = 1;}
	else {handle->Instance->ARR = period;}

	handle->Instance->EGR = TIM_EGR_UG;
}

void Timer::set_period(const uint16_t& period) const
{
	if(period == 0){handle->Instance->ARR = 1;}
	else {handle->Instance->ARR = period;}
}

void Timer::start() const
{
	HAL_TIM_Base_Start(handle);
}

void Timer::stop() const
{
	HAL_TIM_Base_Stop(handle);
}

void Timer::interrupt_enable() const
{
	__HAL_TIM_ENABLE_IT(handle, TIM_IT_UPDATE);
}

void Timer::start_interrupt() const
{
	HAL_TIM_Base_Start_IT(handle);
}

void Timer::start_PWM_channel(const uint8_t channel) const
{
	HAL_TIM_PWM_Start(handle, channel);
}

void Timer::set_PWM_channel_ccr(const uint8_t channel, const uint16_t value) const
{
	switch(channel){
	case 1 : handle->Instance->CCR1 = value; break;
	case 2 : handle->Instance->CCR2 = value; break;
	case 3 : handle->Instance->CCR3 = value; break;
	case 4 : handle->Instance->CCR4 = value; break;
	}
}
