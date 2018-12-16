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
