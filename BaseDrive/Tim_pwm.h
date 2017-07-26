#ifndef _TIM_PWM_H_
#define _TIM_PWM_H_

#include <stdbool.h>

#define TIMER1      0
#define TIMER2      1
#define TIMER3      2
#define TIMER4      3
#define TIMER5      4
#define TIMER6      5
#define TIMER7      6
#define TIMER8      7
#define TIMER9      8
#define TIMER10     9
#define TIMER11     10
#define TIMER12     11
#define TIMER13     12
#define TIMER14     13
#define TIMER_NUM   14

typedef struct
{
	uint32_t gpio_clock;
	uint16_t gpio_pin;
	GPIO_TypeDef *gpio_port;
	uint8_t gpio_source;
	uint8_t tim_af;
	bool Isapb1;
	bool IsPWM;
	uint32_t tim_clock;
	uint8_t tim_ircn;
	TIM_TypeDef* tim_name;
	uint16_t tim_it_flag;
	uint16_t tim_it;
	uint8_t tim_channel;
	
	uint32_t step_count;
	uint32_t step_total;
	uint32_t arr;
	uint16_t psc;
	
	uint32_t speed_final;
	uint16_t speed_up;
	uint16_t speed_step;
	uint16_t speed_step_incr;
	
	//Gpio_Info io_enable;
}Timer_Para;

extern Timer_Para timer_array[TIMER_NUM];

void TIM_ParaSet(void);
//void OUT_ParaSet(void);
void TIM_Config(uint8_t timer_id);
void Timer_Init(uint8_t timer_id);
void Timer_Run(uint8_t timer_id);
void Timer_Stop(uint8_t timer_id);
void Timer_set_step_num(uint8_t tim_id, uint32_t s_num);
void Timer_set_Freq(uint8_t tim_id, uint16_t s_num);
void TIM_IT_Handler(uint8_t tim_id);
void setFrequency(uint8_t tim_id, uint32_t i_init, uint32_t i_final, uint16_t i_up);

//void PA15_Init(void);
//void PC10_Init(void);

#endif
