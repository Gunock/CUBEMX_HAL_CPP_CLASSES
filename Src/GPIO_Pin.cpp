/*
 * GPIO_Pin.cpp
 *
 *  Created on: Dec 16, 2018
 *      Author: Tomasz Kiljañczyk
 */

#include "GPIO_Pin.hpp"

 /*
  * @biref Initializes GPIO_Pin.
  * @param base GPIOx where x can be (A..K) to select the GPIO peripheral for STM32F429X device or
  *                      	x can be (A..I) to select the GPIO peripheral for STM32F40XX and STM32F427X devices.
  * @param GPIO_Pin specifies the port bit.
  * @retval None
  */
GPIO_Pin::GPIO_Pin(GPIO_TypeDef* GPIOx, const uint16_t& GPIO_Pin) : port(GPIOx), pin(GPIO_Pin) {}

GPIO_Pin::~GPIO_Pin() {}

/*
 * @biref Sets the pin.
 * @retval None
 */
void GPIO_Pin::on() const
{
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
}

/*
 * @biref Clears the pin.
 * @retval None
 */
void GPIO_Pin::off() const
{
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
}

/*
 * @biref Toggles the pin.
 * @retval None
 */
void GPIO_Pin::toggle() const
{
	HAL_GPIO_TogglePin(port, pin);
}

/*
 * @biref Sets or clears the pin.
 * @param state specifies the value to be written.
 *          This parameter can be bool value:
 *           	@arg true: to clear the pin
 *           	@arg false: to set the pin
 * @retval None
 */
void GPIO_Pin::write(const bool& state) const
{
	if (state == false) { HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET); }
	else if (state == true) { HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET); }
}

/*
 * @biref Sets or clears the pin.
 * @param state specifies the value to be written.
 *          This parameter can be one of the GPIO_PinState enum values:
 *           	@arg GPIO_PIN_RESET: to clear the pin
 *           	@arg GPIO_PIN_SET: to set the pin
 * @retval None
 */
void GPIO_Pin::write(const GPIO_PinState& state) const
{
	HAL_GPIO_WritePin(port, pin, state);
}

/*
 * @biref Reads the pin.
 * @retval The pin value.
 */
bool GPIO_Pin::read() const
{
	if (HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_RESET) { return false; }
	else { return true; }
}
