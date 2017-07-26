/****************************************Copyright (c)***************************************
**                                  
**-------------------------------------------------------------------------------------------
** File name:           MyTimer.c
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
#include "MyTimer.h"
#include "Gpio.h"
#include "motor.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t mytimer_arr;
uint16_t mytimer_psc;
uint32_t mytimer_stepscount = 0;
//uint32_t mytimer_stepsnum = 1000;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
//extern void LED_Flashing(void);

void MyTimer_Start(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	//TIM_OCInitTypeDef  TIM_OCInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	//uint16_t ChannelPulse = 0;
	/* TIM clock enable */
	if(MYTIMER_ISAPB1 == 1)
	{
    RCC_APB1PeriphClockCmd(MYTIMER_TIM_RCC, ENABLE);
		mytimer_arr = PB1_TIM_ARR;
		mytimer_psc = PB1_TIM_PSC;
	}
	else
	{
		RCC_APB2PeriphClockCmd(MYTIMER_TIM_RCC, ENABLE);
		mytimer_arr = PB2_TIM_ARR;
		mytimer_psc = PB2_TIM_PSC;
	}
	
	/*NVIC config*/
	NVIC_InitStructure.NVIC_IRQChannel = MYTIMER_TIM_IRQN;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  
	NVIC_Init(&NVIC_InitStructure);
	
	//ChannelPulse = (uint16_t) (((uint32_t) 5 * (mytimer_arr - 1)) / 10);
	
	/* Time Base configuration */
  TIM_TimeBaseStructure.TIM_Period = mytimer_arr;
  TIM_TimeBaseStructure.TIM_Prescaler =(mytimer_psc-1);
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	
  TIM_TimeBaseInit(MYTIMER_TIM, &TIM_TimeBaseStructure);
	
	TIM_ClearFlag(MYTIMER_TIM, MYTIMER_TIM_ITFLAG);
	TIM_ITConfig(MYTIMER_TIM,MYTIMER_TIM_IT,ENABLE);
  
	/* TIM counter enable */
  TIM_Cmd(MYTIMER_TIM, ENABLE);
}

void MyTimer_IT_Handler(void)
{
	if(TIM_GetITStatus(MYTIMER_TIM, MYTIMER_TIM_ITFLAG) != RESET)
	{
		mytimer_stepscount++;
		//Motor_ScanLmtBit();
		Motor_ScanLmtBit_test();//for test
		Motor_ScanREAD0Bit_test();
		if(mytimer_stepscount > 1000)
		{
			LED_Flashing();
			mytimer_stepscount = 0;
		}
	}
	TIM_ClearITPendingBit(MYTIMER_TIM, MYTIMER_TIM_ITFLAG);
}
