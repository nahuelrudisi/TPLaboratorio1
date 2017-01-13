
#ifndef BSP_BSP_H_
#define BSP_BSP_H_

#include "stdint.h"

#define RGB_PORT 	GPIOB
#define ADC_PORT 	GPIOC


enum{
	RGB_ROJO = 0,
	RGB_VERDE,
	RGB_AZUL
}leds;


void BSP_Init(void);
void RGB_PWM(uint32_t led, uint32_t value);
float BSP_GetBrightness(void);
void delay(uint16_t delay);

#endif /* BSP_BSP_H_ */
