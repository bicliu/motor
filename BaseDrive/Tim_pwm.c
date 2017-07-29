/**
  ******************************************************************************
  * @file    TIM/7PWM_Output/main.c 
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    13-April-2012
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Usart.h"
#include "Tim_pwm.h"
#include "public.h"

/*clear warining 550-D*/
//#pragma diag_suppress 550

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define TIMR_CNL_1       1
#define TIMR_CNL_2       2
#define TIMR_CNL_3       3
#define TIMR_CNL_4       4
#define PWM_TIM_INTERRUPT_PRIORITY   0
#define PWM_TIM_INTERRUPT_SUB_PRI    3

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
TIM_OCInitTypeDef  TIM_OCInitStructure;
NVIC_InitTypeDef NVIC_InitStructure;  
GPIO_InitTypeDef GPIO_InitStructure;
uint16_t TimerPeriod = 0;
uint16_t Channel1Pulse = 0, Channel2Pulse = 0, Channel3Pulse = 0, Channel4Pulse = 0;
//uint16_t current_circle = 0;
//uint16_t plus_counter = 10;
uint32_t PB1_TIM_ARR = 1000;
uint16_t PB1_TIM_PSC = 26;
uint32_t PB2_TIM_ARR = 1000;
uint16_t PB2_TIM_PSC = 52;
uint32_t TIM_CLOCK_BASE = 1000000;

Timer_Para timer_array[TIMER_NUM];

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
void freshFrequency(uint8_t tim_id);
extern void Motor_Stop(uint8_t motor_id);
extern uint8_t Motor_timid2motorid(uint8_t timid);

void TIM_ParaSet(void)
{
	// tim1 ch1n PE9 - motor 10
	timer_array[TIMER1].IsPWM = TIMR1_ISPWM;
	timer_array[TIMER1].gpio_clock = TIMR1_GPIO_RCC;
	timer_array[TIMER1].gpio_pin = TIMR1_GPIO_PIN;
	timer_array[TIMER1].gpio_port = TIMR1_GPIO;
	timer_array[TIMER1].gpio_source = TIMR1_GPIO_PSRCE;
	timer_array[TIMER1].tim_af = TIMR1_TIM_AF;
	timer_array[TIMER1].Isapb1 = TIMR1_ISAPB1;
	timer_array[TIMER1].tim_clock = TIMR1_TIM_RCC;
	timer_array[TIMER1].tim_ircn = TIMR1_TIM_IRQN;
	timer_array[TIMER1].tim_name = TIMR1_TIM;
	timer_array[TIMER1].tim_it_flag = TIMR1_TIM_ITFLAG;
	timer_array[TIMER1].tim_it = TIMR1_TIM_IT;
	timer_array[TIMER1].tim_channel = TIMR1_TIM_CNL;
	timer_array[TIMER1].step_count = 0;
	timer_array[TIMER1].step_total = 0;
	timer_array[TIMER1].arr = PB2_TIM_ARR;
	timer_array[TIMER1].psc = PB2_TIM_PSC;

	// tim2 ch1 PA15 --> pb3  motor 1
	timer_array[TIMER2].IsPWM = TIMR2_ISPWM;
  timer_array[TIMER2].gpio_clock = TIMR2_GPIO_RCC;
	timer_array[TIMER2].gpio_pin = TIMR2_GPIO_PIN;
	timer_array[TIMER2].gpio_port = TIMR2_GPIO;
	timer_array[TIMER2].gpio_source = TIMR2_GPIO_PSRCE;
	timer_array[TIMER2].tim_af = TIMR2_TIM_AF;
	timer_array[TIMER2].Isapb1 = TIMR2_ISAPB1;
	timer_array[TIMER2].tim_clock = TIMR2_TIM_RCC;
	timer_array[TIMER2].tim_ircn = TIMR2_TIM_IRQN;
	timer_array[TIMER2].tim_name = TIMR2_TIM;
	timer_array[TIMER2].tim_it_flag = TIMR2_TIM_ITFLAG;
	timer_array[TIMER2].tim_it = TIMR2_TIM_IT;
	timer_array[TIMER2].tim_channel = TIMR2_TIM_CNL;
	timer_array[TIMER2].step_count = 0;
	timer_array[TIMER2].step_total = 0;
	timer_array[TIMER2].arr = PB1_TIM_ARR;
	timer_array[TIMER2].psc = PB1_TIM_PSC;
	// tim3 ch1 PB4 - motor 2
	timer_array[TIMER3].IsPWM = TIMR3_ISPWM;
    timer_array[TIMER3].gpio_clock = TIMR3_GPIO_RCC;
	timer_array[TIMER3].gpio_pin = TIMR3_GPIO_PIN;
	timer_array[TIMER3].gpio_port = TIMR3_GPIO;
	timer_array[TIMER3].gpio_source = TIMR3_GPIO_PSRCE;
	timer_array[TIMER3].tim_af = TIMR3_TIM_AF;
	timer_array[TIMER3].Isapb1 = TIMR3_ISAPB1;
	timer_array[TIMER3].tim_clock = TIMR3_TIM_RCC;
	timer_array[TIMER3].tim_ircn = TIMR3_TIM_IRQN;
	timer_array[TIMER3].tim_name = TIMR3_TIM;
	timer_array[TIMER3].tim_it_flag = TIMR3_TIM_ITFLAG;
	timer_array[TIMER3].tim_it = TIMR3_TIM_IT;
	timer_array[TIMER3].tim_channel = TIMR3_TIM_CNL;
	timer_array[TIMER3].step_count = 0;
	timer_array[TIMER3].step_total = 0;
	timer_array[TIMER3].arr = PB1_TIM_ARR;
	timer_array[TIMER3].psc = PB1_TIM_PSC;
	// tim4 tch1 PD12  - motor 12
	timer_array[TIMER4].IsPWM = TIMR4_ISPWM;
	timer_array[TIMER4].gpio_clock = TIMR4_GPIO_RCC;
	timer_array[TIMER4].gpio_pin = TIMR4_GPIO_PIN;
	timer_array[TIMER4].gpio_port = TIMR4_GPIO;
	timer_array[TIMER4].gpio_source = TIMR4_GPIO_PSRCE;
	timer_array[TIMER4].tim_af = TIMR4_TIM_AF;
	timer_array[TIMER4].Isapb1 = TIMR4_ISAPB1;
	timer_array[TIMER4].tim_clock = TIMR4_TIM_RCC;
	timer_array[TIMER4].tim_ircn = TIMR4_TIM_IRQN;
	timer_array[TIMER4].tim_name = TIMR4_TIM;
	timer_array[TIMER4].tim_it_flag = TIMR4_TIM_ITFLAG;
	timer_array[TIMER4].tim_it = TIMR4_TIM_IT;
	timer_array[TIMER4].tim_channel = TIMR4_TIM_CNL;
	timer_array[TIMER4].step_count = 0;
	timer_array[TIMER4].step_total = 0;
	timer_array[TIMER4].arr = PB1_TIM_ARR;
	timer_array[TIMER4].psc = PB1_TIM_PSC;
	// tim5 tch1 PA0 -motor7
	timer_array[TIMER5].IsPWM = TIMR5_ISPWM;
    timer_array[TIMER5].gpio_clock = TIMR5_GPIO_RCC;
	timer_array[TIMER5].gpio_pin = TIMR5_GPIO_PIN;
	timer_array[TIMER5].gpio_port = TIMR5_GPIO;
	timer_array[TIMER5].gpio_source = TIMR5_GPIO_PSRCE;
	timer_array[TIMER5].tim_af = TIMR5_TIM_AF;
	timer_array[TIMER5].Isapb1 = TIMR5_ISAPB1;
	timer_array[TIMER5].tim_clock = TIMR5_TIM_RCC;
	timer_array[TIMER5].tim_ircn = TIMR5_TIM_IRQN;
	timer_array[TIMER5].tim_name = TIMR5_TIM;
	timer_array[TIMER5].tim_it_flag = TIMR5_TIM_ITFLAG;
	timer_array[TIMER5].tim_it = TIMR5_TIM_IT;
	timer_array[TIMER5].tim_channel = TIMR5_TIM_CNL;
	timer_array[TIMER5].step_count = 0;
	timer_array[TIMER5].step_total = 0;
	timer_array[TIMER5].arr = PB1_TIM_ARR;
	timer_array[TIMER5].psc = PB1_TIM_PSC;
	// tim6
	timer_array[TIMER6].IsPWM = TIMR6_ISPWM;
	// tim7
	timer_array[TIMER7].IsPWM = TIMR7_ISPWM;
	// tim8 ch1n PI5
	timer_array[TIMER8].IsPWM = TIMR8_ISPWM;
    timer_array[TIMER8].gpio_clock = TIMR8_GPIO_RCC;
	timer_array[TIMER8].gpio_pin = TIMR8_GPIO_PIN;
	timer_array[TIMER8].gpio_port = TIMR8_GPIO;
	timer_array[TIMER8].gpio_source = TIMR8_GPIO_PSRCE;
	timer_array[TIMER8].tim_af = TIMR8_TIM_AF;
	timer_array[TIMER8].Isapb1 = TIMR8_ISAPB1;
	timer_array[TIMER8].tim_clock = TIMR8_TIM_RCC;
	timer_array[TIMER8].tim_ircn = TIMR8_TIM_IRQN;
	timer_array[TIMER8].tim_name = TIMR8_TIM;
	timer_array[TIMER8].tim_it_flag = TIMR8_TIM_ITFLAG;
	timer_array[TIMER8].tim_it = TIMR8_TIM_IT;
	timer_array[TIMER8].tim_channel = TIMR8_TIM_CNL;
	timer_array[TIMER8].step_count = 0;
	timer_array[TIMER8].step_total = 0;
	timer_array[TIMER8].arr = PB2_TIM_ARR;
	timer_array[TIMER8].psc = PB2_TIM_PSC;
	// tim9 ch1 PE5 - motor 5
	timer_array[TIMER9].IsPWM = TIMR9_ISPWM;
    timer_array[TIMER9].gpio_clock = TIMR9_GPIO_RCC;
	timer_array[TIMER9].gpio_pin = TIMR9_GPIO_PIN;
	timer_array[TIMER9].gpio_port = TIMR9_GPIO;
	timer_array[TIMER9].gpio_source = TIMR9_GPIO_PSRCE;
	timer_array[TIMER9].tim_af = TIMR9_TIM_AF;
	timer_array[TIMER9].Isapb1 = TIMR9_ISAPB1;
	timer_array[TIMER9].tim_clock = TIMR9_TIM_RCC;
	timer_array[TIMER9].tim_ircn = TIMR9_TIM_IRQN;
	timer_array[TIMER9].tim_name = TIMR9_TIM;
	timer_array[TIMER9].tim_it_flag = TIMR9_TIM_ITFLAG;
	timer_array[TIMER9].tim_it = TIMR9_TIM_IT;
	timer_array[TIMER9].tim_channel = TIMR9_TIM_CNL;
	timer_array[TIMER9].step_count = 0;
	timer_array[TIMER9].step_total = 0;
	timer_array[TIMER9].arr = PB2_TIM_ARR;
	timer_array[TIMER9].psc = PB2_TIM_PSC;
	// tim10 ch1 PB8 - motor4
	timer_array[TIMER10].IsPWM = TIMR10_ISPWM;
    timer_array[TIMER10].gpio_clock = TIMR10_GPIO_RCC;
	timer_array[TIMER10].gpio_pin = TIMR10_GPIO_PIN;
	timer_array[TIMER10].gpio_port = TIMR10_GPIO;
	timer_array[TIMER10].gpio_source = TIMR10_GPIO_PSRCE;
	timer_array[TIMER10].tim_af = TIMR10_TIM_AF;
	timer_array[TIMER10].Isapb1 = TIMR10_ISAPB1;
	timer_array[TIMER10].tim_clock = TIMR10_TIM_RCC;
	timer_array[TIMER10].tim_ircn = TIMR10_TIM_IRQN;
	timer_array[TIMER10].tim_name = TIMR10_TIM;
	timer_array[TIMER10].tim_it_flag = TIMR10_TIM_ITFLAG;
	timer_array[TIMER10].tim_it = TIMR10_TIM_IT;
	timer_array[TIMER10].tim_channel = TIMR10_TIM_CNL;
	timer_array[TIMER10].step_count = 0;
	timer_array[TIMER10].step_total = 0;
	timer_array[TIMER10].arr = PB2_TIM_ARR;
	timer_array[TIMER10].psc = PB2_TIM_PSC;
	// tim11 ch1 PF7 ->PB9 motor3
	timer_array[TIMER11].IsPWM = TIMR11_ISPWM;
    timer_array[TIMER11].gpio_clock = TIMR11_GPIO_RCC;
	timer_array[TIMER11].gpio_pin = TIMR11_GPIO_PIN;
	timer_array[TIMER11].gpio_port = TIMR11_GPIO;
	timer_array[TIMER11].gpio_source = TIMR11_GPIO_PSRCE;
	timer_array[TIMER11].tim_af = TIMR11_TIM_AF;
	timer_array[TIMER11].Isapb1 = TIMR11_ISAPB1;
	timer_array[TIMER11].tim_clock = TIMR11_TIM_RCC;
	timer_array[TIMER11].tim_ircn = TIMR11_TIM_IRQN;
	timer_array[TIMER11].tim_name = TIMR11_TIM;
	timer_array[TIMER11].tim_it_flag = TIMR11_TIM_ITFLAG;
	timer_array[TIMER11].tim_it = TIMR11_TIM_IT;
	timer_array[TIMER11].tim_channel = TIMR11_TIM_CNL;
	timer_array[TIMER11].step_count = 0;
	timer_array[TIMER11].step_total = 0;
	timer_array[TIMER11].arr = PB2_TIM_ARR;
	timer_array[TIMER11].psc = PB2_TIM_PSC;
	// tim12 ch2 PB15 - motor 11
	timer_array[TIMER11].IsPWM = TIMR11_ISPWM;
	timer_array[TIMER12].gpio_clock = TIMR12_GPIO_RCC;
	timer_array[TIMER12].gpio_pin = TIMR12_GPIO_PIN;
	timer_array[TIMER12].gpio_port = TIMR12_GPIO;
	timer_array[TIMER12].gpio_source = TIMR12_GPIO_PSRCE;
	timer_array[TIMER12].tim_af = TIMR12_TIM_AF;
	timer_array[TIMER12].Isapb1 = TIMR12_ISAPB1;
	timer_array[TIMER12].tim_clock = TIMR12_TIM_RCC;
	timer_array[TIMER12].tim_ircn = TIMR12_TIM_IRQN;
	timer_array[TIMER12].tim_name = TIMR12_TIM;
	timer_array[TIMER12].tim_it_flag = TIMR12_TIM_ITFLAG;
	timer_array[TIMER12].tim_it = TIMR12_TIM_IT;
	timer_array[TIMER12].tim_channel = TIMR12_TIM_CNL;
	timer_array[TIMER12].step_count = 0;
	timer_array[TIMER12].step_total = 0;
	timer_array[TIMER12].arr = PB1_TIM_ARR;
	timer_array[TIMER12].psc = PB1_TIM_PSC;
	// tim13 ch1 PA6 motor8
	timer_array[TIMER13].IsPWM = TIMR13_ISPWM;
    timer_array[TIMER13].gpio_clock = TIMR13_GPIO_RCC;
	timer_array[TIMER13].gpio_pin = TIMR13_GPIO_PIN;
	timer_array[TIMER13].gpio_port = TIMR13_GPIO;
	timer_array[TIMER13].gpio_source = TIMR13_GPIO_PSRCE;
	timer_array[TIMER13].tim_af = TIMR13_TIM_AF;
	timer_array[TIMER13].Isapb1 = TIMR13_ISAPB1;
	timer_array[TIMER13].tim_clock = TIMR13_TIM_RCC;
	timer_array[TIMER13].tim_ircn = TIMR13_TIM_IRQN;
	timer_array[TIMER13].tim_name = TIMR13_TIM;
	timer_array[TIMER13].tim_it_flag = TIMR13_TIM_ITFLAG;
	timer_array[TIMER13].tim_it = TIMR13_TIM_IT;
	timer_array[TIMER13].tim_channel = TIMR13_TIM_CNL;
	timer_array[TIMER13].step_count = 0;
	timer_array[TIMER13].step_total = 0;
	timer_array[TIMER13].arr = PB1_TIM_ARR;
	timer_array[TIMER13].psc = PB1_TIM_PSC;
	// tim14 ch1 pf9 motor6
	timer_array[TIMER14].IsPWM = TIMR14_ISPWM;
    timer_array[TIMER14].gpio_clock = TIMR14_GPIO_RCC;
	timer_array[TIMER14].gpio_pin = TIMR14_GPIO_PIN;
	timer_array[TIMER14].gpio_port = TIMR14_GPIO;
	timer_array[TIMER14].gpio_source = TIMR14_GPIO_PSRCE;
	timer_array[TIMER14].tim_af = TIMR14_TIM_AF;
	timer_array[TIMER14].Isapb1 = TIMR14_ISAPB1;
	timer_array[TIMER14].tim_clock = TIMR14_TIM_RCC;
	timer_array[TIMER14].tim_ircn = TIMR14_TIM_IRQN;
	timer_array[TIMER14].tim_name = TIMR14_TIM;
	timer_array[TIMER14].tim_it_flag = TIMR14_TIM_ITFLAG;
	timer_array[TIMER14].tim_it = TIMR14_TIM_IT;
	timer_array[TIMER14].tim_channel = TIMR14_TIM_CNL;
	timer_array[TIMER14].step_count = 0;
	timer_array[TIMER14].step_total = 0;
	timer_array[TIMER14].arr = PB1_TIM_ARR;
	timer_array[TIMER14].psc = PB1_TIM_PSC;
}


void TIM_Config(uint8_t timer_id)
{
	Timer_Para timer;
	if(timer_id >= TIMER_NUM)
	{
		return;
	}
	timer = timer_array[timer_id];
	/* GPIOB Clocks enable */
	RCC_AHB1PeriphClockCmd( timer.gpio_clock, ENABLE);
	
	/* GPIOB Configuration: Channel 1, 3 and 4 as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = timer.gpio_pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
	GPIO_Init(timer.gpio_port, &GPIO_InitStructure);
  
	GPIO_PinAFConfig(timer.gpio_port, timer.gpio_source, timer.tim_af);
	/* TIM clock enable */
	if(timer.Isapb1)
	{
    RCC_APB1PeriphClockCmd(timer.tim_clock, ENABLE);
	}
	else
	{
		RCC_APB2PeriphClockCmd(timer.tim_clock, ENABLE);
	}
	
	/*NVIC config*/
	NVIC_InitStructure.NVIC_IRQChannel = timer.tim_ircn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = PWM_TIM_INTERRUPT_PRIORITY;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = PWM_TIM_INTERRUPT_SUB_PRI;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  
	NVIC_Init(&NVIC_InitStructure);
}

void Timer_Init(uint8_t timer_id)  
{
	Timer_Para timer;
	if(timer_id >= TIMER_NUM)
	{
		return;
	}
	timer = timer_array[timer_id];
	/* Compute CCR1 value to generate a duty cycle at 50% for channel 1 and 1N */
	Channel1Pulse = (uint16_t) (((uint32_t) 5 * (timer.arr - 1)) / 10);
  
	/* Time Base configuration */
  TIM_TimeBaseStructure.TIM_Period = timer.arr;
  TIM_TimeBaseStructure.TIM_Prescaler =(timer.psc-1);
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	
  TIM_TimeBaseInit(timer.tim_name, &TIM_TimeBaseStructure);
	
	/* Channel 1, 2,3 and 4 Configuration in PWM mode */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
  TIM_OCInitStructure.TIM_Pulse = Channel1Pulse;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
  TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
  TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset;

	switch(timer.tim_channel)
	{
		case TIMR_CNL_1:
			TIM_OC1Init(timer.tim_name, &TIM_OCInitStructure);
			TIM_OC1PreloadConfig(timer.tim_name, TIM_OCPreload_Enable);
			break;
		case TIMR_CNL_2:
			TIM_OC2Init(timer.tim_name, &TIM_OCInitStructure);
			TIM_OC2PreloadConfig(timer.tim_name, TIM_OCPreload_Enable);
			break;
		case TIMR_CNL_3:
			TIM_OC3Init(timer.tim_name, &TIM_OCInitStructure);
			TIM_OC3PreloadConfig(timer.tim_name, TIM_OCPreload_Enable);
			break;
		case TIMR_CNL_4:
			TIM_OC4Init(timer.tim_name, &TIM_OCInitStructure);
			TIM_OC4PreloadConfig(timer.tim_name, TIM_OCPreload_Enable);
			break;
		default:
			break;
	}
	TIM_ARRPreloadConfig(timer.tim_name, ENABLE);
	/*clear flag & enable IT*/
	//TIM_ClearFlag(timer.tim_name, timer.tim_it_flag);
	//TIM_ITConfig(timer.tim_name,timer.tim_it,ENABLE);
  
	/* TIM1 counter enable */
  	//TIM_Cmd(timer.tim_name, ENABLE);
	
	/* TIM1 Main Output Enable */
  	//TIM_CtrlPWMOutputs(timer.tim_name, ENABLE);
}

void Timer_Run(uint8_t timer_id)
{
	Timer_Para timer;
	if(timer_id >= TIMER_NUM)
	{
		return;
	}
	timer = timer_array[timer_id];
	//TIM_ARRPreloadConfig(timer.tim_name, ENABLE);
	
	/*clear flag & enable IT*/
	TIM_ClearFlag(timer.tim_name, timer.tim_it_flag);
	TIM_ITConfig(timer.tim_name,timer.tim_it,ENABLE);
  
	/* TIM1 counter enable */
  	TIM_Cmd(timer.tim_name, ENABLE);
	
	/* TIM1 Main Output Enable */
  	TIM_CtrlPWMOutputs(timer.tim_name, ENABLE);
}

void Timer_Stop(uint8_t timer_id)
{
	if(timer_id >= TIMER_NUM)
	{
		return;
	}
	TIM_Cmd(timer_array[timer_id].tim_name, DISABLE);
	TIM_ITConfig(timer_array[timer_id].tim_name,timer_array[timer_id].tim_it,DISABLE);
	debug("TIM%d close\r\n",(timer_id+1));
	timer_array[timer_id].step_count = 0;
}

void Timer_set_step_num(uint8_t tim_id, uint32_t s_num)
{
	if(tim_id >= TIMER_NUM)
	{
		return;
	}
	timer_array[tim_id].step_total = s_num;
}

void Timer_set_Freq(uint8_t tim_id, uint16_t s_num)
{
	if(tim_id >= TIMER_NUM)
	{
		return;
	}
	//timer.arr = ;
	timer_array[tim_id].psc = 2;
}

void TIM_IT_Handler(uint8_t tim_id)
{
	if(tim_id >= TIMER_NUM)
	{
		return;
	}
	if(TIM_GetITStatus(timer_array[tim_id].tim_name, timer_array[tim_id].tim_it_flag) != RESET)
	{
		if(timer_array[tim_id].step_total == 0)
		{
			TIM_ClearITPendingBit(timer_array[tim_id].tim_name, timer_array[tim_id].tim_it_flag);
			return;
		}
		if(timer_array[tim_id].step_count < timer_array[tim_id].step_total)
		{
			if(timer_array[tim_id].arr != timer_array[tim_id].speed_final)
			{
				if(timer_array[tim_id].step_count == timer_array[tim_id].speed_step_incr)
				{
					timer_array[tim_id].speed_up += 1;
				}
				if(timer_array[tim_id].step_count % timer_array[tim_id].speed_step == 0)
				{
					freshFrequency(tim_id);
				}
			}
			//debug("TIM%d arr = %d,finalspeed = %d\r\n",(tim_id+1),timer_array[tim_id].arr,timer_array[tim_id].speed_final);
			timer_array[tim_id].step_count++;
		}
		else
		{
			//TIM_Cmd(timer_array[tim_id].tim_name,DISABLE);
			//TIM_ITConfig(timer_array[tim_id].tim_name,timer_array[tim_id].tim_it,DISABLE);
			debug("Motor %d stop,run %d times\r\n",(Motor_timid2motorid(tim_id)+1),timer_array[tim_id].step_count);
			//dma_debug("TIM%d run %d times,close\r\n",(tim_id+1),timer_array[tim_id].step_count);
			//timer_array[tim_id].step_count = 0;
			Motor_Stop(Motor_timid2motorid(tim_id));
		}
	}
	else
	{
		debug("TIM%d it_flag didn't match\r\n",(tim_id+1));
		//dma_debug("TIM%d it_flag didn't match\r\n",(tim_id+1));
	}
	TIM_ClearITPendingBit(timer_array[tim_id].tim_name, timer_array[tim_id].tim_it_flag);
}

void TIM_UPDATE_ARR(uint8_t tim_id)
{
	if(tim_id >= TIMER_NUM)
	{
		return;
	}
	
	timer_array[tim_id].tim_name->ARR = timer_array[tim_id].arr;
	Channel1Pulse = (uint16_t) (((uint32_t) 5 * (timer_array[tim_id].arr - 1)) / 10);
	switch(timer_array[tim_id].tim_channel)
	{
		case TIMR_CNL_1:
			timer_array[tim_id].tim_name->CCR1 = Channel1Pulse;
			break;
		case TIMR_CNL_2:
			timer_array[tim_id].tim_name->CCR2 = Channel1Pulse;
			break;
		case TIMR_CNL_3:
			timer_array[tim_id].tim_name->CCR3 = Channel1Pulse;
			break;
		case TIMR_CNL_4:
			timer_array[tim_id].tim_name->CCR4 = Channel1Pulse;
			break;
		default:
			break;
	}
	return;
}

void freshFrequency(uint8_t tim_id)
{
	//Timer_Para t_tim;
	uint32_t i_temp = 0;
	if(tim_id >= TIMER_NUM)
	{
		return;
	}
	//t_tim = timer_array[tim_id];
	if(timer_array[tim_id].arr > timer_array[tim_id].speed_final)
	{
		i_temp = timer_array[tim_id].arr - timer_array[tim_id].speed_up;
		if(i_temp > timer_array[tim_id].speed_final)
		{
			timer_array[tim_id].arr = i_temp;
		}
		else
		{
			timer_array[tim_id].arr = timer_array[tim_id].speed_final;
		}
		
		TIM_UPDATE_ARR(tim_id);
	}
}

/**
  * @brief  max common divisor of x and y.
  * @param  uint16 x,y
  * @retval max common divisor
  */
uint16_t measure(uint16_t x, uint16_t y)  
{
	uint16_t z = y;
	if(x < y)
	{
		z = x;
		x = y;
		y = z;
	}
	while(x%y!=0)
	{
		z = x%y;
		x = y;
		y = z;
	}
	return z;  
}  

void setFrequency(uint8_t tim_id, uint32_t i_init, uint32_t i_final, uint16_t i_up)
{
	//Timer_Para t_tim;
	uint16_t i_multiple = 1;
	uint16_t i_count;
	if(tim_id >= TIMER_NUM)
	{
		return;
	}
	//t_tim = timer_array[tim_id];
	timer_array[tim_id].arr = TIM_CLOCK_BASE / i_init;
	timer_array[tim_id].speed_final = TIM_CLOCK_BASE / i_final;
	/*i_temp = measure(i_step, i_up);
	timer_array[tim_id].speed_step = i_up / i_temp;
	timer_array[tim_id].speed_up = i_step / i_temp;*/
	if(timer_array[tim_id].arr > timer_array[tim_id].speed_final)
	{
		i_count = timer_array[tim_id].arr - timer_array[tim_id].speed_final;
		while(i_count < i_up)
		{
			i_count *= 10;
			i_multiple *= 10;
		}
		timer_array[tim_id].speed_step = i_multiple;
		timer_array[tim_id].speed_up = i_count / i_up;
		timer_array[tim_id].speed_step_incr = i_up - (i_count % i_up);
	}
	else
	{
		timer_array[tim_id].arr = timer_array[tim_id].speed_final;
	}
	TIM_UPDATE_ARR(tim_id);
	//debug("TIM%d arr = %d, finalspeed = %d,step = %d,up = %d\r\n", tim_id+1,timer_array[tim_id].arr,timer_array[tim_id].speed_final,timer_array[tim_id].speed_step,timer_array[tim_id].speed_up);
	//dma_debug("TIM%d arr = %d, finalspeed = %d,step = %d,up = %d\r\n", tim_id+1,timer_array[tim_id].arr,timer_array[tim_id].speed_final,timer_array[tim_id].speed_step,timer_array[tim_id].speed_up);
	
	return;
}

/*void PA15_Init(void)
{
	GPIO_InitTypeDef GPIO_t_InitStructure;

	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA, ENABLE);
	
  	GPIO_t_InitStructure.GPIO_Pin = GPIO_Pin_15;
  	GPIO_t_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  	GPIO_t_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  	GPIO_t_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_t_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
  	GPIO_Init(GPIOA, &GPIO_t_InitStructure);
	
	//GPIO_SetBits(GPIOA, GPIO_Pin_15);
	GPIO_ResetBits(GPIOA, GPIO_Pin_15);
	
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOB, ENABLE);
	GPIO_t_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_1;
	GPIO_Init(GPIOB, &GPIO_t_InitStructure);
	GPIO_ResetBits(GPIOB, GPIO_Pin_5);
	GPIO_ResetBits(GPIOB, GPIO_Pin_1);
	
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOI, ENABLE);
	GPIO_t_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_9;
	GPIO_Init(GPIOI, &GPIO_t_InitStructure);
	GPIO_ResetBits(GPIOI, GPIO_Pin_6);
	GPIO_ResetBits(GPIOI, GPIO_Pin_7);
	GPIO_ResetBits(GPIOI, GPIO_Pin_9);
	
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOF, ENABLE);
	GPIO_t_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_10;
	GPIO_Init(GPIOF, &GPIO_t_InitStructure);
	GPIO_ResetBits(GPIOF, GPIO_Pin_6);
	GPIO_ResetBits(GPIOF, GPIO_Pin_10);
	
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOH, ENABLE);
	GPIO_t_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init(GPIOH, &GPIO_t_InitStructure);
	GPIO_ResetBits(GPIOH, GPIO_Pin_4);
}

void PC10_Init(void)
{
	GPIO_InitTypeDef GPIO_t_InitStructure;

	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOC, ENABLE);
	
  	GPIO_t_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_0;
  	GPIO_t_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  	GPIO_t_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  	GPIO_t_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_t_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
  	GPIO_Init(GPIOC, &GPIO_t_InitStructure);
	
	//GPIO_SetBits(GPIOC, GPIO_Pin_10);
	GPIO_ResetBits(GPIOC, GPIO_Pin_10);
	GPIO_ResetBits(GPIOC, GPIO_Pin_0);
	
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOG, ENABLE);
	GPIO_t_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_Init(GPIOG, &GPIO_t_InitStructure);
	GPIO_ResetBits(GPIOG, GPIO_Pin_15);
	
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOE, ENABLE);
	GPIO_t_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_Init(GPIOE, &GPIO_t_InitStructure);
	GPIO_ResetBits(GPIOE, GPIO_Pin_2);
	
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOH, ENABLE);
	GPIO_t_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_Init(GPIOH, &GPIO_t_InitStructure);
	GPIO_ResetBits(GPIOH, GPIO_Pin_5);
	
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOF, ENABLE);
	GPIO_t_InitStructure.GPIO_Pin = GPIO_Pin_7 |GPIO_Pin_11;
	GPIO_Init(GPIOF, &GPIO_t_InitStructure);
	GPIO_ResetBits(GPIOF, GPIO_Pin_7);
	GPIO_ResetBits(GPIOF, GPIO_Pin_11);
	
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOI, ENABLE);
	GPIO_t_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_10;
	GPIO_Init(GPIOI, &GPIO_t_InitStructure);
	GPIO_ResetBits(GPIOI, GPIO_Pin_4);
	GPIO_ResetBits(GPIOI, GPIO_Pin_10);
}*/

