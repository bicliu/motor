/****************************************Copyright (c)***************************************
**                                  
**-------------------------------------------------------------------------------------------
** File name:           Relay.c
** Last modified Date:  2017-07-14
** Last Version:        V1.00
** Descriptions:        
**
**-------------------------------------------------------------------------------------------
** Created by:          LBC
** Last modified Date:  2017-07-14
** Last Version:        V1.00
** Descriptions:        
**
**-------------------------------------------------------------------------------------------
** Modified by:         
** Modified date:       
** Version:             
** Descriptions:        
**-------------------------------------------------------------------------------------------
********************************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "public.h"
#include "Gpio.h"
#include "relay.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
Gpio_Info relay_array[RELAY_NUM] = {
	{ RELAY1_RCC, RELAY1_GPIO, RELAY1_PIN },
	{ RELAY2_RCC, RELAY2_GPIO, RELAY2_PIN },
	{ RELAY3_RCC, RELAY3_GPIO, RELAY3_PIN },
	{ RELAY4_RCC, RELAY4_GPIO, RELAY4_PIN },
	{ RELAY5_RCC, RELAY5_GPIO, RELAY5_PIN },
	{ RELAY6_RCC, RELAY6_GPIO, RELAY6_PIN },
	{ RELAY7_RCC, RELAY7_GPIO, RELAY7_PIN },
	{ RELAY8_RCC, RELAY8_GPIO, RELAY8_PIN }
};
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void Relay_Init(void)
{
    uint8_t i;
    for (i = 0; i < RELAY_NUM; i++)
	{
		Gpio_out_Init(relay_array[i]);
	  //Gpio_Writebit(relay_array[i], Bit_RESET);
		//Relay_resetbit(i);
		Relay_setbit(i);
	}
}

void Relay_setbit(uint8_t rid)
{
    if(rid < RELAY_NUM)
    {
        Gpio_Writebit(relay_array[rid], Bit_SET);
    }
}

void Relay_resetbit(uint8_t rid)
{
    if(rid < RELAY_NUM)
    {
        Gpio_Writebit(relay_array[rid], Bit_RESET);
    }
}

void Relay_writebit(uint8_t rid, uint8_t bit)
{
    if(rid < RELAY_NUM)
    {
				if(0 == bit)
				{
						Gpio_Writebit(relay_array[rid], Bit_RESET);
				}
				else
				{
					Gpio_Writebit(relay_array[rid], Bit_SET);
				}
    }
}
