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
uint32_t mytimer7_stepscount = 0;
uint8_t mytimer7_iobit = 0;
uint32_t mytimer7_stepsnum = 5000;
uint8_t mytimer7_clcwise = 0;
uint8_t mytimer7_model = 0;
uint8_t mytimer7_zindex = 0;

uint16_t z5_array[5] = {0x240, 0x90, 0x24, 0x9, 0x102};
uint16_t z10_array[10] = {0x210, 0x294, 0x84, 0xA5, 0x21, 0x129, 0x108, 0x14A, 0x42, 0x252};

Gpio_Info myT7io_array[10];
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

void MyTimer7_Start(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	//TIM_OCInitTypeDef  TIM_OCInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	//uint16_t ChannelPulse = 0;
	/* TIM clock enable */
	if(MYTIMER7_ISAPB1 == 1)
	{
    RCC_APB1PeriphClockCmd(MYTIMER7_TIM_RCC, ENABLE);
		mytimer_arr = PB1_TIM_ARR;
		mytimer_psc = PB1_TIM_PSC;
	}
	else
	{
		RCC_APB2PeriphClockCmd(MYTIMER7_TIM_RCC, ENABLE);
		mytimer_arr = PB2_TIM_ARR;
		mytimer_psc = PB2_TIM_PSC;
	}
	
	/*NVIC config*/
	NVIC_InitStructure.NVIC_IRQChannel = MYTIMER7_TIM_IRQN;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  
	NVIC_Init(&NVIC_InitStructure);
	
	//ChannelPulse = (uint16_t) (((uint32_t) 5 * (MYTIMER7_arr - 1)) / 10);
	
	/* Time Base configuration */
  TIM_TimeBaseStructure.TIM_Period = mytimer_arr;
  TIM_TimeBaseStructure.TIM_Prescaler =(mytimer_psc-1);
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	
  TIM_TimeBaseInit(MYTIMER7_TIM, &TIM_TimeBaseStructure);
	
	TIM_ClearFlag(MYTIMER7_TIM, MYTIMER7_TIM_ITFLAG);
	TIM_ITConfig(MYTIMER7_TIM,MYTIMER7_TIM_IT,ENABLE);
  
	/* TIM counter enable */
  TIM_Cmd(MYTIMER7_TIM, ENABLE);
}

void MyTimer7_IT_Handler(void)
{
	uint16_t mytimer7_a = 0;
	uint8_t i = 0;
	if(TIM_GetITStatus(MYTIMER7_TIM, MYTIMER7_TIM_ITFLAG) != RESET)
	{
		mytimer7_stepscount++;
		if(mytimer7_stepscount > mytimer7_stepsnum)
		{
			MYTimer7_Stop();
			return;
		}
		if(mytimer7_iobit == 0)
			mytimer7_iobit = 1;
		else
			mytimer7_iobit = 0;
		
		if(mytimer7_clcwise == 0)
				mytimer7_zindex++;
			else
				mytimer7_zindex--;
		
		if(0 == mytimer7_model)
			mytimer7_a = z5_array[mytimer7_zindex%5];
		else
			mytimer7_a = z10_array[mytimer7_zindex%5];
		for(i = 0; i < 10; i++)
		{
			//GPIO_WriteBit(myT7io_array[i].gpio,myT7io_array[i].pin, (BitAction)(mytimer7_iobit & (mytimer7_a & ((1 << i) >> i))));
			Gpio_Writebit(myT7io_array[i], (BitAction)(mytimer7_iobit & (mytimer7_a & ((1 << i) >> i))));
		}
	}
	TIM_ClearITPendingBit(MYTIMER7_TIM, MYTIMER7_TIM_ITFLAG);
}

void MYTimer7_Run(void)
{
	/*clear flag & enable IT*/
	TIM_ClearFlag(MYTIMER7_TIM, MYTIMER7_TIM_ITFLAG);
	TIM_ITConfig(MYTIMER7_TIM,MYTIMER7_TIM_IT,ENABLE);
  
	/* TIM counter enable */
  TIM_Cmd(MYTIMER7_TIM, ENABLE);
}

void MYTimer7_Stop(void)
{
	TIM_Cmd(MYTIMER7_TIM, DISABLE);
	TIM_ITConfig(MYTIMER7_TIM,MYTIMER7_TIM_IT,DISABLE);
	mytimer7_stepscount = 0;
}

void MYTimer7_dataInit(void)
{
	uint8_t i = 0;
	myT7io_array[0].gpio = MOTOR7_IOLMTP_GPIO;
	myT7io_array[0].rcc = MOTOR7_IOLMTP_RCC;
	myT7io_array[0].pin = MOTOR7_IOLMTP_PIN;
	
	myT7io_array[1].gpio = MOTOR7_IOLMTN_GPIO;
	myT7io_array[1].rcc = MOTOR7_IOLMTN_RCC;
	myT7io_array[1].pin = MOTOR7_IOLMTN_PIN;
	
	myT7io_array[2].gpio = MOTOR7_IOSTOP0_GPIO;
	myT7io_array[2].rcc = MOTOR7_IOSTOP0_RCC;
	myT7io_array[2].pin = MOTOR7_IOSTOP0_PIN;
	
	myT7io_array[3].gpio = MOTOR7_IOSTOP1_GPIO;
	myT7io_array[3].rcc = MOTOR7_IOSTOP1_RCC;
	myT7io_array[3].pin = MOTOR7_IOSTOP1_PIN;
	
	myT7io_array[4].gpio = MOTOR8_IOLMTP_GPIO;
	myT7io_array[4].rcc = MOTOR8_IOLMTP_RCC;
	myT7io_array[4].pin = MOTOR8_IOLMTP_PIN;
	
	myT7io_array[5].gpio = MOTOR8_IOLMTN_GPIO;
	myT7io_array[5].rcc = MOTOR8_IOLMTN_RCC;
	myT7io_array[5].pin = MOTOR8_IOLMTN_PIN;
	
	myT7io_array[6].gpio = MOTOR8_IOSTOP0_GPIO;
	myT7io_array[6].rcc = MOTOR8_IOSTOP0_RCC;
	myT7io_array[6].pin = MOTOR8_IOSTOP0_PIN;
	
	myT7io_array[7].gpio = MOTOR8_IOSTOP1_GPIO;
	myT7io_array[7].rcc = MOTOR8_IOSTOP1_RCC;
	myT7io_array[7].pin = MOTOR8_IOSTOP1_PIN;
	
	myT7io_array[8].gpio = MOTOR9_IOLMTP_GPIO;
	myT7io_array[8].rcc = MOTOR9_IOLMTP_RCC;
	myT7io_array[8].pin = MOTOR9_IOLMTP_PIN;
	
	myT7io_array[9].gpio = MOTOR9_IOLMTN_GPIO;
	myT7io_array[9].rcc = MOTOR9_IOLMTN_RCC;
	myT7io_array[9].pin = MOTOR9_IOLMTN_PIN;
	
	
	for(i = 0; i < 10; i++)
	{
		Gpio_out_Init(myT7io_array[i]);
		Gpio_Writebit(myT7io_array[i], (BitAction)0);
	}
}
