/*
 * GPIO_Pin.cpp
 *
 *  Created on: Dec 16, 2018
 *      Author: Tomasz Kiljañczyk
 */

#include "GPIO_Pin.hpp"

// STL
#include <unordered_map>


/*
 * @brief Initializes GPIO_Pin.
 * @param base GPIOx where x can be (A..K) to select the GPIO peripheral for STM32F429X device or
 *                      	x can be (A..I) to select the GPIO peripheral for STM32F40XX and STM32F427X devices.
 * @param GPIO_Pin specifies the port bit.
 * @retval None
 */
GPIO_Pin::GPIO_Pin(GPIO_TypeDef* GPIOx, const uint16_t& GPIO_Pin) : port(GPIOx), pin(GPIO_Pin) {}

/*
 * @brief Sets the pin.
 * @retval None
 */
void GPIO_Pin::on() const
{
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
}

/*
 * @brief Clears the pin.
 * @retval None
 */
void GPIO_Pin::off() const
{
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
}

/*
 * @brief Toggles the pin.
 * @retval None
 */
void GPIO_Pin::toggle() const
{
	HAL_GPIO_TogglePin(port, pin);
}

/*
 * @brief Sets or clears the pin.
 * @param state specifies the value to be written.
 *          This parameter can be bool value:
 *           	@arg true: to clear the pin
 *           	@arg false: to set the pin
 * @retval None
 */
void GPIO_Pin::write(const bool& state) const
{
	if (state == false) 	{ HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET); }
	else if (state == true) { HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET); 	}
}

/*
 * @brief Sets or clears the pin.
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
 * @brief Reads the pin.
 * @retval The pin value.
 */
bool GPIO_Pin::read() const
{
	if (HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_RESET) { return false; }
	else { return true; }
}



// Pin group functions ----------------

/*
 * @brief Toggles given pins.
 * @param pins specifies group of pins to toggle.
 * @retval None
 */
void pins_toggle(const std::initializer_list<const GPIO_Pin*>& pins)
{
	if(pins.size() > 0)
	{
		/*
		 * key: GPIO port
		 * value: pin sum
		 * max_size: 5 (ports A, B, C, D, E)
		 */
		std::unordered_map<GPIO_TypeDef*, uint16_t> portPinMap {
			{GPIOA, 0},
			{GPIOB, 0},
			{GPIOC, 0},
			{GPIOD, 0},
			{GPIOE, 0}
		};

		for(const GPIO_Pin* pin : pins) { portPinMap[pin->port] |= pin->pin; }
		for(const auto& elem : portPinMap)
		{
			if(elem.second != 0){ HAL_GPIO_TogglePin(elem.first, elem.second); }
		}
	}
}

/*
 * @brief Sets or clears group of pins.
 * @param state specifies the value to be written.
 *          This parameter can be one of the GPIO_PinState enum values:
 *           	@arg GPIO_PIN_RESET: to clear the pin
 *           	@arg GPIO_PIN_SET: to set the pin
 * @retval None
 */
void pins_write(const std::initializer_list<const GPIO_Pin*>& pins, const GPIO_PinState& state)
{
	if(pins.size() > 0)
	{
		/*
		 * key: GPIO port
		 * value: pin sum
		 * max_size: 5 (ports A, B, C, D, E)
		 */
		std::unordered_map<GPIO_TypeDef*, uint16_t> portPinMap {
			{GPIOA, 0},
			{GPIOB, 0},
			{GPIOC, 0},
			{GPIOD, 0},
			{GPIOE, 0}
		};

		for(const GPIO_Pin* pin : pins) { portPinMap[pin->port] |= pin->pin; }
		for(const auto& elem : portPinMap)
		{
			if(elem.second != 0) { HAL_GPIO_WritePin(elem.first, elem.second, state); }
		}
	}
}

/*
 * @brief Sets or clears group of pins.
 * @param state specifies the value to be written.
 *          This parameter can be bool value:
 *           	@arg true: to clear the pin
 *           	@arg false: to set the pin
 * @retval None
 */
void pins_write(const std::initializer_list<const GPIO_Pin*>& pins, const bool& state)
{
	if(state) { pins_write(pins, GPIO_PIN_SET); }
	else { pins_write(pins, GPIO_PIN_RESET); }
}
