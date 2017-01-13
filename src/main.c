//	TABLA DE VERDAD Y SECUENCIA EN QUE ENCIENDEN LOS LEDS
//		R		G		B
//		1		0		0
//		1		1		0
//		0		1		0
//		0		1		1
//		0		0		1
//		1		0		1
//		1		0		0

#include "bsp/bsp.h"

int main(void)
{
	int i;
	float adc[5],valor;
	uint32_t potenciometro = 0;
	uint32_t valor_ROJO = 0, valor_VERDE = 0, valor_AZUL = 0;
	BSP_Init();

	while (1)
	{
		for(i=0;i<=5;i++)
		{
			adc[i] = BSP_GetBrightness();
			if (((i == 0) || (adc[i] < valor)) && (adc[i] < 5000))
				valor = adc[i];											// Saco el menor para que no me afecte la variacion del ADC
			if (((i == 0) || (adc[i] > valor)) && (adc[i] >= 5000))
				valor = adc[i];											// Saco el mayor para que no me afecte la variacion del ADC
		}

		potenciometro = (uint32_t) valor;

		if(potenciometro <= 1250)
		{
			valor_ROJO  = 100;
			valor_VERDE = (uint32_t) (0.08 * potenciometro);
			valor_AZUL  = 0;
		}

		if((potenciometro > 1250) && (potenciometro <= 2500))
		{
			valor_ROJO  = (uint32_t) (-0.08 * potenciometro + 200);
			valor_VERDE = 100;
			valor_AZUL  = 0;
		}

		if((potenciometro > 2500) && (potenciometro <= 4250))
		{
			valor_ROJO  = 0;
			valor_VERDE = 100;
			valor_AZUL  = (uint32_t) (0.05714 * potenciometro - 143);
		}

		if((potenciometro > 4250) && (potenciometro <= 6000))
		{
			valor_ROJO  = 0;
			valor_VERDE = (uint32_t) (-0.05714 * potenciometro + 343);
			valor_AZUL  = 100;
		}

		if((potenciometro > 6000) && (potenciometro <= 8000))
		{
			valor_ROJO  = (uint32_t) (0.05 * potenciometro - 300);
			valor_VERDE = 0;
			valor_AZUL  = 100;
		}

		if((potenciometro > 8000) && (potenciometro <= 10000))
		{
			valor_ROJO  = 100;
			valor_VERDE = 0;
			valor_AZUL  = (uint32_t) (-0.05 * potenciometro + 500);
		}

		RGB_PWM(RGB_AZUL, valor_AZUL);
		RGB_PWM(RGB_ROJO, valor_ROJO);
		RGB_PWM(RGB_VERDE, valor_VERDE);
	}
}


