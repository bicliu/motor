/****************************************Copyright (c)***************************************
**                                  
**-------------------------------------------------------------------------------------------
** File name:           main.c
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
#include "stm32f4xx.h"
#include "Usart.h"
#include "Gpio.h"
#include "msg_handler.h"
#include "relay.h"
#include "motor.h"
#include "MyTimer.h"
#include "Tim_pwm.h"

int main(void)
{
	uint32_t nCount;
	//Gpio_Info gpio_pg0;
	
	MYUSART_ParaSet();
	MYUSART_Init();
	//USART_RXNE_Init();
	//uart_init();
	LEDGpio_Init();
	MyTimer_Start();
	
	for(nCount = 0; nCount <= 5; nCount++)
	{
		LED1_Flashing();
	}
	
	Relay_Init();
	
	Motor_paraset();
	Motor_Init();
	
	debug("\r\nWelcome to WaveShare STM32F4 series MCU Board Open407Z\r\n");
	//Light_13_ON();
	//Light_14_ON();
	//Light_15_ON();
	//LED3_ON;
	LED_SetFlashing(LED3, LED_FLASHING_ON);
	//LED1_ON;
	//LED2_ON;
	
  while (1)
  {
		//debug("%x", 0xaa);
		//msg_receive();
		MYMSG_receive();
  }
}



