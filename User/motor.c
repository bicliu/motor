/****************************************Copyright (c)***************************************
**                                  
**-------------------------------------------------------------------------------------------
** File name:           motor.c
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
//#include <string.h>
//#include <stdlib.h>
#include "public.h"
#include "Gpio.h"
#include "Tim_pwm.h"
#include "motor.h"
#include "Usart.h"
/* Private typedef -----------------------------------------------------------*/
typedef struct
{
	Gpio_Info io;
	uint8_t   motor_id;
}Motor_read0bit_t;
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
Motor_t motor_array[MOTOR_NUM];
Motor_read0bit_t read0bit_array[READ0BIT_NUM];
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void Motor_paraset(void)
{
	TIM_ParaSet();
	//motor 1
	motor_array[MOTOR1].tim_id = MOTOR1_TIMRID;

	motor_array[MOTOR1].io_enable.rcc = MOTOR1_IOENABLE_RCC;
	motor_array[MOTOR1].io_enable.gpio = MOTOR1_IOENABLE_GPIO;
	motor_array[MOTOR1].io_enable.pin = MOTOR1_IOENABLE_PIN;

	motor_array[MOTOR1].io_clockwise.rcc = MOTOR1_IOCLOCKWISE_RCC;
	motor_array[MOTOR1].io_clockwise.gpio = MOTOR1_IOCLOCKWISE_GPIO;
	motor_array[MOTOR1].io_clockwise.pin = MOTOR1_IOCLOCKWISE_PIN;

	motor_array[MOTOR1].io_lmtp.rcc = MOTOR1_IOLMTP_RCC;
	motor_array[MOTOR1].io_lmtp.gpio = MOTOR1_IOLMTP_GPIO;
	motor_array[MOTOR1].io_lmtp.pin = MOTOR1_IOLMTP_PIN;

	motor_array[MOTOR1].io_lmtn.rcc = MOTOR1_IOLMTN_RCC;
	motor_array[MOTOR1].io_lmtn.gpio = MOTOR1_IOLMTN_GPIO;
	motor_array[MOTOR1].io_lmtn.pin = MOTOR1_IOLMTN_PIN;

	motor_array[MOTOR1].io_stop0.rcc = MOTOR1_IOSTOP0_RCC;
	motor_array[MOTOR1].io_stop0.gpio = MOTOR1_IOSTOP0_GPIO;
	motor_array[MOTOR1].io_stop0.pin = MOTOR1_IOSTOP0_PIN;

	motor_array[MOTOR1].io_stop1.rcc = MOTOR1_IOSTOP1_RCC;
	motor_array[MOTOR1].io_stop1.gpio = MOTOR1_IOSTOP1_GPIO;
	motor_array[MOTOR1].io_stop1.pin = MOTOR1_IOSTOP1_PIN;
	
	motor_array[MOTOR1].read0bit_id = READ0BIT_NUM;

	//motor 2
	motor_array[MOTOR2].tim_id = MOTOR2_TIMRID;

	motor_array[MOTOR2].io_enable.rcc = MOTOR2_IOENABLE_RCC;
	motor_array[MOTOR2].io_enable.gpio = MOTOR2_IOENABLE_GPIO;
	motor_array[MOTOR2].io_enable.pin = MOTOR2_IOENABLE_PIN;

	motor_array[MOTOR2].io_clockwise.rcc = MOTOR2_IOCLOCKWISE_RCC;
	motor_array[MOTOR2].io_clockwise.gpio = MOTOR2_IOCLOCKWISE_GPIO;
	motor_array[MOTOR2].io_clockwise.pin = MOTOR2_IOCLOCKWISE_PIN;

	motor_array[MOTOR2].io_lmtp.rcc = MOTOR2_IOLMTP_RCC;
	motor_array[MOTOR2].io_lmtp.gpio = MOTOR2_IOLMTP_GPIO;
	motor_array[MOTOR2].io_lmtp.pin = MOTOR2_IOLMTP_PIN;

	motor_array[MOTOR2].io_lmtn.rcc = MOTOR2_IOLMTN_RCC;
	motor_array[MOTOR2].io_lmtn.gpio = MOTOR2_IOLMTN_GPIO;
	motor_array[MOTOR2].io_lmtn.pin = MOTOR2_IOLMTN_PIN;

	motor_array[MOTOR2].io_stop0.rcc = MOTOR2_IOSTOP0_RCC;
	motor_array[MOTOR2].io_stop0.gpio = MOTOR2_IOSTOP0_GPIO;
	motor_array[MOTOR2].io_stop0.pin = MOTOR2_IOSTOP0_PIN;

	motor_array[MOTOR2].io_stop1.rcc = MOTOR2_IOSTOP1_RCC;
	motor_array[MOTOR2].io_stop1.gpio = MOTOR2_IOSTOP1_GPIO;
	motor_array[MOTOR2].io_stop1.pin = MOTOR2_IOSTOP1_PIN;
	
	motor_array[MOTOR2].read0bit_id = READ0BIT_NUM;

	//motor 3
	motor_array[MOTOR3].tim_id = MOTOR3_TIMRID;

	motor_array[MOTOR3].io_enable.rcc = MOTOR3_IOENABLE_RCC;
	motor_array[MOTOR3].io_enable.gpio = MOTOR3_IOENABLE_GPIO;
	motor_array[MOTOR3].io_enable.pin = MOTOR3_IOENABLE_PIN;

	motor_array[MOTOR3].io_clockwise.rcc = MOTOR3_IOCLOCKWISE_RCC;
	motor_array[MOTOR3].io_clockwise.gpio = MOTOR3_IOCLOCKWISE_GPIO;
	motor_array[MOTOR3].io_clockwise.pin = MOTOR3_IOCLOCKWISE_PIN;

	motor_array[MOTOR3].io_lmtp.rcc = MOTOR3_IOLMTP_RCC;
	motor_array[MOTOR3].io_lmtp.gpio = MOTOR3_IOLMTP_GPIO;
	motor_array[MOTOR3].io_lmtp.pin = MOTOR3_IOLMTP_PIN;

	motor_array[MOTOR3].io_lmtn.rcc = MOTOR3_IOLMTN_RCC;
	motor_array[MOTOR3].io_lmtn.gpio = MOTOR3_IOLMTN_GPIO;
	motor_array[MOTOR3].io_lmtn.pin = MOTOR3_IOLMTN_PIN;

	motor_array[MOTOR3].io_stop0.rcc = MOTOR3_IOSTOP0_RCC;
	motor_array[MOTOR3].io_stop0.gpio = MOTOR3_IOSTOP0_GPIO;
	motor_array[MOTOR3].io_stop0.pin = MOTOR3_IOSTOP0_PIN;

	motor_array[MOTOR3].io_stop1.rcc = MOTOR3_IOSTOP1_RCC;
	motor_array[MOTOR3].io_stop1.gpio = MOTOR3_IOSTOP1_GPIO;
	motor_array[MOTOR3].io_stop1.pin = MOTOR3_IOSTOP1_PIN;
	
	motor_array[MOTOR3].read0bit_id = READ0BIT_NUM;

	//motor 4
	motor_array[MOTOR4].tim_id = MOTOR4_TIMRID;

	motor_array[MOTOR4].io_enable.rcc = MOTOR4_IOENABLE_RCC;
	motor_array[MOTOR4].io_enable.gpio = MOTOR4_IOENABLE_GPIO;
	motor_array[MOTOR4].io_enable.pin = MOTOR4_IOENABLE_PIN;

	motor_array[MOTOR4].io_clockwise.rcc = MOTOR4_IOCLOCKWISE_RCC;
	motor_array[MOTOR4].io_clockwise.gpio = MOTOR4_IOCLOCKWISE_GPIO;
	motor_array[MOTOR4].io_clockwise.pin = MOTOR4_IOCLOCKWISE_PIN;

	motor_array[MOTOR4].io_lmtp.rcc = MOTOR4_IOLMTP_RCC;
	motor_array[MOTOR4].io_lmtp.gpio = MOTOR4_IOLMTP_GPIO;
	motor_array[MOTOR4].io_lmtp.pin = MOTOR4_IOLMTP_PIN;

	motor_array[MOTOR4].io_lmtn.rcc = MOTOR4_IOLMTN_RCC;
	motor_array[MOTOR4].io_lmtn.gpio = MOTOR4_IOLMTN_GPIO;
	motor_array[MOTOR4].io_lmtn.pin = MOTOR4_IOLMTN_PIN;

	motor_array[MOTOR4].io_stop0.rcc = MOTOR4_IOSTOP0_RCC;
	motor_array[MOTOR4].io_stop0.gpio = MOTOR4_IOSTOP0_GPIO;
	motor_array[MOTOR4].io_stop0.pin = MOTOR4_IOSTOP0_PIN;

	motor_array[MOTOR4].io_stop1.rcc = MOTOR4_IOSTOP1_RCC;
	motor_array[MOTOR4].io_stop1.gpio = MOTOR4_IOSTOP1_GPIO;
	motor_array[MOTOR4].io_stop1.pin = MOTOR4_IOSTOP1_PIN;
	
	motor_array[MOTOR4].read0bit_id = READ0BIT_NUM;

	//motor 5
	motor_array[MOTOR5].tim_id = MOTOR5_TIMRID;

	motor_array[MOTOR5].io_enable.rcc = MOTOR5_IOENABLE_RCC;
	motor_array[MOTOR5].io_enable.gpio = MOTOR5_IOENABLE_GPIO;
	motor_array[MOTOR5].io_enable.pin = MOTOR5_IOENABLE_PIN;

	motor_array[MOTOR5].io_clockwise.rcc = MOTOR5_IOCLOCKWISE_RCC;
	motor_array[MOTOR5].io_clockwise.gpio = MOTOR5_IOCLOCKWISE_GPIO;
	motor_array[MOTOR5].io_clockwise.pin = MOTOR5_IOCLOCKWISE_PIN;

	motor_array[MOTOR5].io_lmtp.rcc = MOTOR5_IOLMTP_RCC;
	motor_array[MOTOR5].io_lmtp.gpio = MOTOR5_IOLMTP_GPIO;
	motor_array[MOTOR5].io_lmtp.pin = MOTOR5_IOLMTP_PIN;

	motor_array[MOTOR5].io_lmtn.rcc = MOTOR5_IOLMTN_RCC;
	motor_array[MOTOR5].io_lmtn.gpio = MOTOR5_IOLMTN_GPIO;
	motor_array[MOTOR5].io_lmtn.pin = MOTOR5_IOLMTN_PIN;

	motor_array[MOTOR5].io_stop0.rcc = MOTOR5_IOSTOP0_RCC;
	motor_array[MOTOR5].io_stop0.gpio = MOTOR5_IOSTOP0_GPIO;
	motor_array[MOTOR5].io_stop0.pin = MOTOR5_IOSTOP0_PIN;

	motor_array[MOTOR5].io_stop1.rcc = MOTOR5_IOSTOP1_RCC;
	motor_array[MOTOR5].io_stop1.gpio = MOTOR5_IOSTOP1_GPIO;
	motor_array[MOTOR5].io_stop1.pin = MOTOR5_IOSTOP1_PIN;
	
	motor_array[MOTOR5].read0bit_id = READ0BIT_NUM;

	//motor 6
	motor_array[MOTOR6].tim_id = MOTOR6_TIMRID;

	motor_array[MOTOR6].io_enable.rcc = MOTOR6_IOENABLE_RCC;
	motor_array[MOTOR6].io_enable.gpio = MOTOR6_IOENABLE_GPIO;
	motor_array[MOTOR6].io_enable.pin = MOTOR6_IOENABLE_PIN;

	motor_array[MOTOR6].io_clockwise.rcc = MOTOR6_IOCLOCKWISE_RCC;
	motor_array[MOTOR6].io_clockwise.gpio = MOTOR6_IOCLOCKWISE_GPIO;
	motor_array[MOTOR6].io_clockwise.pin = MOTOR6_IOCLOCKWISE_PIN;

	motor_array[MOTOR6].io_lmtp.rcc = MOTOR6_IOLMTP_RCC;
	motor_array[MOTOR6].io_lmtp.gpio = MOTOR6_IOLMTP_GPIO;
	motor_array[MOTOR6].io_lmtp.pin = MOTOR6_IOLMTP_PIN;

	motor_array[MOTOR6].io_lmtn.rcc = MOTOR6_IOLMTN_RCC;
	motor_array[MOTOR6].io_lmtn.gpio = MOTOR6_IOLMTN_GPIO;
	motor_array[MOTOR6].io_lmtn.pin = MOTOR6_IOLMTN_PIN;

	motor_array[MOTOR6].io_stop0.rcc = MOTOR6_IOSTOP0_RCC;
	motor_array[MOTOR6].io_stop0.gpio = MOTOR6_IOSTOP0_GPIO;
	motor_array[MOTOR6].io_stop0.pin = MOTOR6_IOSTOP0_PIN;

	motor_array[MOTOR6].io_stop1.rcc = MOTOR6_IOSTOP1_RCC;
	motor_array[MOTOR6].io_stop1.gpio = MOTOR6_IOSTOP1_GPIO;
	motor_array[MOTOR6].io_stop1.pin = MOTOR6_IOSTOP1_PIN;
	
	motor_array[MOTOR6].read0bit_id = READ0BIT_NUM;
	
	//motor 7
	motor_array[MOTOR7].tim_id = MOTOR7_TIMRID;

	motor_array[MOTOR7].io_enable.rcc = MOTOR7_IOENABLE_RCC;
	motor_array[MOTOR7].io_enable.gpio = MOTOR7_IOENABLE_GPIO;
	motor_array[MOTOR7].io_enable.pin = MOTOR7_IOENABLE_PIN;

	motor_array[MOTOR7].io_clockwise.rcc = MOTOR7_IOCLOCKWISE_RCC;
	motor_array[MOTOR7].io_clockwise.gpio = MOTOR7_IOCLOCKWISE_GPIO;
	motor_array[MOTOR7].io_clockwise.pin = MOTOR7_IOCLOCKWISE_PIN;

	motor_array[MOTOR7].io_lmtp.rcc = MOTOR7_IOLMTP_RCC;
	motor_array[MOTOR7].io_lmtp.gpio = MOTOR7_IOLMTP_GPIO;
	motor_array[MOTOR7].io_lmtp.pin = MOTOR7_IOLMTP_PIN;

	motor_array[MOTOR7].io_lmtn.rcc = MOTOR7_IOLMTN_RCC;
	motor_array[MOTOR7].io_lmtn.gpio = MOTOR7_IOLMTN_GPIO;
	motor_array[MOTOR7].io_lmtn.pin = MOTOR7_IOLMTN_PIN;

	motor_array[MOTOR7].io_stop0.rcc = MOTOR7_IOSTOP0_RCC;
	motor_array[MOTOR7].io_stop0.gpio = MOTOR7_IOSTOP0_GPIO;
	motor_array[MOTOR7].io_stop0.pin = MOTOR7_IOSTOP0_PIN;

	motor_array[MOTOR7].io_stop1.rcc = MOTOR7_IOSTOP1_RCC;
	motor_array[MOTOR7].io_stop1.gpio = MOTOR7_IOSTOP1_GPIO;
	motor_array[MOTOR7].io_stop1.pin = MOTOR7_IOSTOP1_PIN;
	
	motor_array[MOTOR7].read0bit_id = READ0BIT_NUM;
	
	//motor 8
	motor_array[MOTOR8].tim_id = MOTOR8_TIMRID;

	motor_array[MOTOR8].io_enable.rcc = MOTOR8_IOENABLE_RCC;
	motor_array[MOTOR8].io_enable.gpio = MOTOR8_IOENABLE_GPIO;
	motor_array[MOTOR8].io_enable.pin = MOTOR8_IOENABLE_PIN;

	motor_array[MOTOR8].io_clockwise.rcc = MOTOR8_IOCLOCKWISE_RCC;
	motor_array[MOTOR8].io_clockwise.gpio = MOTOR8_IOCLOCKWISE_GPIO;
	motor_array[MOTOR8].io_clockwise.pin = MOTOR8_IOCLOCKWISE_PIN;

	motor_array[MOTOR8].io_lmtp.rcc = MOTOR8_IOLMTP_RCC;
	motor_array[MOTOR8].io_lmtp.gpio = MOTOR8_IOLMTP_GPIO;
	motor_array[MOTOR8].io_lmtp.pin = MOTOR8_IOLMTP_PIN;

	motor_array[MOTOR8].io_lmtn.rcc = MOTOR8_IOLMTN_RCC;
	motor_array[MOTOR8].io_lmtn.gpio = MOTOR8_IOLMTN_GPIO;
	motor_array[MOTOR8].io_lmtn.pin = MOTOR8_IOLMTN_PIN;

	motor_array[MOTOR8].io_stop0.rcc = MOTOR8_IOSTOP0_RCC;
	motor_array[MOTOR8].io_stop0.gpio = MOTOR8_IOSTOP0_GPIO;
	motor_array[MOTOR8].io_stop0.pin = MOTOR8_IOSTOP0_PIN;

	motor_array[MOTOR8].io_stop1.rcc = MOTOR8_IOSTOP1_RCC;
	motor_array[MOTOR8].io_stop1.gpio = MOTOR8_IOSTOP1_GPIO;
	motor_array[MOTOR8].io_stop1.pin = MOTOR8_IOSTOP1_PIN;
	
	motor_array[MOTOR8].read0bit_id = READ0BIT_NUM;
	
	//motor 9
	motor_array[MOTOR9].tim_id = MOTOR9_TIMRID;

	motor_array[MOTOR9].io_enable.rcc = MOTOR9_IOENABLE_RCC;
	motor_array[MOTOR9].io_enable.gpio = MOTOR9_IOENABLE_GPIO;
	motor_array[MOTOR9].io_enable.pin = MOTOR9_IOENABLE_PIN;

	motor_array[MOTOR9].io_clockwise.rcc = MOTOR9_IOCLOCKWISE_RCC;
	motor_array[MOTOR9].io_clockwise.gpio = MOTOR9_IOCLOCKWISE_GPIO;
	motor_array[MOTOR9].io_clockwise.pin = MOTOR9_IOCLOCKWISE_PIN;

	motor_array[MOTOR9].io_lmtp.rcc = MOTOR9_IOLMTP_RCC;
	motor_array[MOTOR9].io_lmtp.gpio = MOTOR9_IOLMTP_GPIO;
	motor_array[MOTOR9].io_lmtp.pin = MOTOR9_IOLMTP_PIN;

	motor_array[MOTOR9].io_lmtn.rcc = MOTOR9_IOLMTN_RCC;
	motor_array[MOTOR9].io_lmtn.gpio = MOTOR9_IOLMTN_GPIO;
	motor_array[MOTOR9].io_lmtn.pin = MOTOR9_IOLMTN_PIN;

	motor_array[MOTOR9].io_stop0.rcc = MOTOR9_IOSTOP0_RCC;
	motor_array[MOTOR9].io_stop0.gpio = MOTOR9_IOSTOP0_GPIO;
	motor_array[MOTOR9].io_stop0.pin = MOTOR9_IOSTOP0_PIN;

	motor_array[MOTOR9].io_stop1.rcc = MOTOR9_IOSTOP1_RCC;
	motor_array[MOTOR9].io_stop1.gpio = MOTOR9_IOSTOP1_GPIO;
	motor_array[MOTOR9].io_stop1.pin = MOTOR9_IOSTOP1_PIN;
	
	motor_array[MOTOR9].read0bit_id = READ0BIT_NUM;
	
	//motor 10
	motor_array[MOTOR10].tim_id = MOTOR10_TIMRID;

	motor_array[MOTOR10].io_enable.rcc = MOTOR10_IOENABLE_RCC;
	motor_array[MOTOR10].io_enable.gpio = MOTOR10_IOENABLE_GPIO;
	motor_array[MOTOR10].io_enable.pin = MOTOR10_IOENABLE_PIN;

	motor_array[MOTOR10].io_clockwise.rcc = MOTOR10_IOCLOCKWISE_RCC;
	motor_array[MOTOR10].io_clockwise.gpio = MOTOR10_IOCLOCKWISE_GPIO;
	motor_array[MOTOR10].io_clockwise.pin = MOTOR10_IOCLOCKWISE_PIN;

	motor_array[MOTOR10].io_lmtp.rcc = MOTOR10_IOLMTP_RCC;
	motor_array[MOTOR10].io_lmtp.gpio = MOTOR10_IOLMTP_GPIO;
	motor_array[MOTOR10].io_lmtp.pin = MOTOR10_IOLMTP_PIN;

	motor_array[MOTOR10].io_lmtn.rcc = MOTOR10_IOLMTN_RCC;
	motor_array[MOTOR10].io_lmtn.gpio = MOTOR10_IOLMTN_GPIO;
	motor_array[MOTOR10].io_lmtn.pin = MOTOR10_IOLMTN_PIN;

	motor_array[MOTOR10].io_stop0.rcc = MOTOR10_IOSTOP0_RCC;
	motor_array[MOTOR10].io_stop0.gpio = MOTOR10_IOSTOP0_GPIO;
	motor_array[MOTOR10].io_stop0.pin = MOTOR10_IOSTOP0_PIN;

	motor_array[MOTOR10].io_stop1.rcc = MOTOR10_IOSTOP1_RCC;
	motor_array[MOTOR10].io_stop1.gpio = MOTOR10_IOSTOP1_GPIO;
	motor_array[MOTOR10].io_stop1.pin = MOTOR10_IOSTOP1_PIN;
	
	motor_array[MOTOR10].read0bit_id = READ0BIT1;
	
	//motor 11
	motor_array[MOTOR11].tim_id = MOTOR11_TIMRID;

	motor_array[MOTOR11].io_enable.rcc = MOTOR11_IOENABLE_RCC;
	motor_array[MOTOR11].io_enable.gpio = MOTOR11_IOENABLE_GPIO;
	motor_array[MOTOR11].io_enable.pin = MOTOR11_IOENABLE_PIN;

	motor_array[MOTOR11].io_clockwise.rcc = MOTOR11_IOCLOCKWISE_RCC;
	motor_array[MOTOR11].io_clockwise.gpio = MOTOR11_IOCLOCKWISE_GPIO;
	motor_array[MOTOR11].io_clockwise.pin = MOTOR11_IOCLOCKWISE_PIN;

	motor_array[MOTOR11].io_lmtp.rcc = MOTOR11_IOLMTP_RCC;
	motor_array[MOTOR11].io_lmtp.gpio = MOTOR11_IOLMTP_GPIO;
	motor_array[MOTOR11].io_lmtp.pin = MOTOR11_IOLMTP_PIN;

	motor_array[MOTOR11].io_lmtn.rcc = MOTOR11_IOLMTN_RCC;
	motor_array[MOTOR11].io_lmtn.gpio = MOTOR11_IOLMTN_GPIO;
	motor_array[MOTOR11].io_lmtn.pin = MOTOR11_IOLMTN_PIN;

	motor_array[MOTOR11].io_stop0.rcc = MOTOR11_IOSTOP0_RCC;
	motor_array[MOTOR11].io_stop0.gpio = MOTOR11_IOSTOP0_GPIO;
	motor_array[MOTOR11].io_stop0.pin = MOTOR11_IOSTOP0_PIN;

	motor_array[MOTOR11].io_stop1.rcc = MOTOR11_IOSTOP1_RCC;
	motor_array[MOTOR11].io_stop1.gpio = MOTOR11_IOSTOP1_GPIO;
	motor_array[MOTOR11].io_stop1.pin = MOTOR11_IOSTOP1_PIN;
	
	motor_array[MOTOR11].read0bit_id = READ0BIT2;
	
	//motor 12
	motor_array[MOTOR12].tim_id = MOTOR12_TIMRID;

	motor_array[MOTOR12].io_enable.rcc = MOTOR12_IOENABLE_RCC;
	motor_array[MOTOR12].io_enable.gpio = MOTOR12_IOENABLE_GPIO;
	motor_array[MOTOR12].io_enable.pin = MOTOR12_IOENABLE_PIN;

	motor_array[MOTOR12].io_clockwise.rcc = MOTOR12_IOCLOCKWISE_RCC;
	motor_array[MOTOR12].io_clockwise.gpio = MOTOR12_IOCLOCKWISE_GPIO;
	motor_array[MOTOR12].io_clockwise.pin = MOTOR12_IOCLOCKWISE_PIN;

	motor_array[MOTOR12].io_lmtp.rcc = MOTOR12_IOLMTP_RCC;
	motor_array[MOTOR12].io_lmtp.gpio = MOTOR12_IOLMTP_GPIO;
	motor_array[MOTOR12].io_lmtp.pin = MOTOR12_IOLMTP_PIN;

	motor_array[MOTOR12].io_lmtn.rcc = MOTOR12_IOLMTN_RCC;
	motor_array[MOTOR12].io_lmtn.gpio = MOTOR12_IOLMTN_GPIO;
	motor_array[MOTOR12].io_lmtn.pin = MOTOR12_IOLMTN_PIN;

	motor_array[MOTOR12].io_stop0.rcc = MOTOR12_IOSTOP0_RCC;
	motor_array[MOTOR12].io_stop0.gpio = MOTOR12_IOSTOP0_GPIO;
	motor_array[MOTOR12].io_stop0.pin = MOTOR12_IOSTOP0_PIN;

	motor_array[MOTOR12].io_stop1.rcc = MOTOR12_IOSTOP1_RCC;
	motor_array[MOTOR12].io_stop1.gpio = MOTOR12_IOSTOP1_GPIO;
	motor_array[MOTOR12].io_stop1.pin = MOTOR12_IOSTOP1_PIN;
	
	motor_array[MOTOR12].read0bit_id = READ0BIT3;
	
	//read0bit
	read0bit_array[READ0BIT1].io.rcc = MOTOR10_READBIT0_RCC;
	read0bit_array[READ0BIT1].io.gpio = MOTOR10_READBIT0_GPIO;
	read0bit_array[READ0BIT1].io.pin = MOTOR10_READBIT0_PIN;
	read0bit_array[READ0BIT1].motor_id = MOTOR10;
	
	read0bit_array[READ0BIT2].io.rcc = MOTOR11_READBIT0_RCC;
	read0bit_array[READ0BIT2].io.gpio = MOTOR11_READBIT0_GPIO;
	read0bit_array[READ0BIT2].io.pin = MOTOR11_READBIT0_PIN;
	read0bit_array[READ0BIT2].motor_id = MOTOR11;
	
	read0bit_array[READ0BIT3].io.rcc = MOTOR12_READBIT0_RCC;
	read0bit_array[READ0BIT3].io.gpio = MOTOR12_READBIT0_GPIO;
	read0bit_array[READ0BIT3].io.pin = MOTOR12_READBIT0_PIN;
	read0bit_array[READ0BIT3].motor_id = MOTOR12;
}

void Motor_Init(void)
{
	uint8_t i = 0;
	for (i = 0; i < MOTOR_NUM; i++)
	{
		TIM_Config(motor_array[i].tim_id);
		Timer_Init(motor_array[i].tim_id);

		Gpio_out_Init(motor_array[i].io_enable);
		//Gpio_Writebit(motor_array[i].io_enable, Bit_RESET);
		Gpio_Writebit(motor_array[i].io_enable, IOENABLE_DISABLE);

		Gpio_out_Init(motor_array[i].io_clockwise);
		Gpio_Writebit(motor_array[i].io_clockwise, Bit_RESET);

		Gpio_IN_Init(motor_array[i].io_lmtp);
		motor_array[i].lmtp_bit = Motor_ReadLMTP(i);
		Gpio_IN_Init(motor_array[i].io_lmtn);
		motor_array[i].lmtn_bit = Motor_ReadLMTN(i);
		Gpio_IN_Init(motor_array[i].io_stop0);
		motor_array[i].stop0_bit = Motor_ReadSTOP0(i);
		Gpio_IN_Init(motor_array[i].io_stop1);
		motor_array[i].stop1_bit = Motor_ReadSTOP1(i);
		Motor_ReportBit(i);
	}
	for(i = 0; i < READ0BIT_NUM; i++)
	{
		Gpio_IN_Init(read0bit_array[i].io);
		motor_array[read0bit_array[i].motor_id].read0bit_bit = Motor_ReadREAD0(read0bit_array[i].motor_id);
	}
	Motor_ReportREAD0();
}

void Motor_set_setpNum(uint8_t motor_id, uint32_t s_num)
{
	if(motor_id < MOTOR_NUM)
	{
		Timer_set_step_num(motor_array[motor_id].tim_id, s_num);
	}
}

void Motor_set_clockwise(uint8_t motor_id, uint8_t bit)
{
	if(motor_id < MOTOR_NUM)
	{
		if(0 == bit)
		{
			Gpio_Writebit(motor_array[motor_id].io_clockwise, Bit_RESET);
		}
		else
		{
			Gpio_Writebit(motor_array[motor_id].io_clockwise, Bit_SET);
		}
	}
}

void Motor_setFrequency(uint8_t motor_id, uint32_t i_init, uint32_t i_final, uint16_t i_up)
{
	if(motor_id < MOTOR_NUM)
	{
		setFrequency(motor_array[motor_id].tim_id, i_init,i_final,i_up);
	}
}

void Motor_Run(uint8_t motor_id)
{
	if(motor_id < MOTOR_NUM)
	{
		Gpio_Writebit(motor_array[motor_id].io_enable, IOENABLE_ENABLE);
		Timer_Run(motor_array[motor_id].tim_id);
	}
}

void Motor_Stop(uint8_t motor_id)
{
	if(motor_id < MOTOR_NUM)
	{
		Timer_Stop(motor_array[motor_id].tim_id);
		Gpio_Writebit(motor_array[motor_id].io_enable, IOENABLE_DISABLE);
	}
}

uint8_t Motor_ReadREAD0(uint8_t motor_id)
{
	uint8_t id;
	if(motor_id < MOTOR_NUM)
	{
		id = motor_array[motor_id].read0bit_id;
		if(id < READ0BIT_NUM)
		{
			return Gpio_ReadBit(read0bit_array[id].io);
		}
	}
	return 0xff;
}

uint8_t Motor_ReadLMTP(uint8_t motor_id)
{
	if(motor_id < MOTOR_NUM)
	{
		return Gpio_ReadBit(motor_array[motor_id].io_lmtp);
	}
	return 0xff;
}

uint8_t Motor_ReadLMTN(uint8_t motor_id)
{
	if(motor_id < MOTOR_NUM)
	{
		return Gpio_ReadBit(motor_array[motor_id].io_lmtn);
	}
	return 0xff;
}

uint8_t Motor_ReadSTOP0(uint8_t motor_id)
{
	if(motor_id < MOTOR_NUM)
	{
		return Gpio_ReadBit(motor_array[motor_id].io_stop0);
	}
	return 0xff;
}

uint8_t Motor_ReadSTOP1(uint8_t motor_id)
{
	if(motor_id < MOTOR_NUM)
	{
		return Gpio_ReadBit(motor_array[motor_id].io_stop1);
	}
	return 0xff;
}

void Motor_ScanLmtBit(void)
{
	uint8_t i = 0;
	uint8_t lmtp = 0xff;
	uint8_t lmtn = 0xff;
	uint8_t stop0 = 0xff;
	uint8_t stop1 = 0xff;
	for (i = 0; i < MOTOR_NUM; i++)
	{
		lmtp = Motor_ReadLMTP(i);
		lmtn = Motor_ReadLMTN(i);
		stop0 = Motor_ReadSTOP0(i);
		stop1 = Motor_ReadSTOP1(i);
		if(motor_array[i].lmtp_bit != lmtp || 
			 motor_array[i].lmtn_bit != lmtn ||
			 motor_array[i].stop0_bit != stop0 ||
			 motor_array[i].stop1_bit != stop1)
		{
			motor_array[i].lmtp_bit = lmtp;
			motor_array[i].lmtn_bit = lmtn;
			motor_array[i].stop0_bit = stop0;
			motor_array[i].stop1_bit = stop1;
			Motor_ReportBit(i);
		}
	}
}

void Motor_ReportBit(uint8_t motor_id)
{
	if(motor_id < MOTOR_NUM)
	{
		debug("REPORT_LMT#ID@%d#LMTP@%d#LMTN@%d#STOP0@%d#STOP1@%d\r\n",
						motor_id,
						motor_array[motor_id].lmtp_bit,
						motor_array[motor_id].lmtn_bit,
						motor_array[motor_id].stop0_bit,
						motor_array[motor_id].stop1_bit);
	}
}

void Motor_ReportREAD0(void)
{
	debug("REPORT_READ0#MOTOR10@%d#MOTOR11@%d#MOTOR12@%d\r\n",
					motor_array[read0bit_array[READ0BIT1].motor_id].read0bit_bit,
					motor_array[read0bit_array[READ0BIT2].motor_id].read0bit_bit,
					motor_array[read0bit_array[READ0BIT3].motor_id].read0bit_bit);
}

void Motor_ScanREAD0Bit_test(void)
{
	uint8_t i = 0;
	uint8_t bit = 0xff;
	for (i = 0; i < READ0BIT_NUM; i++)
	{
		bit = Motor_ReadREAD0(read0bit_array[i].motor_id);
		if(motor_array[read0bit_array[i].motor_id].read0bit_bit != bit)
		{
			motor_array[read0bit_array[i].motor_id].read0bit_bit = bit;
			debug("motor %d lmtp = %d\r\n", read0bit_array[i].motor_id+1, bit);
			bit = 0xff;
		}
	}
}

void Motor_ScanLmtBit_test(void)
{
	uint8_t i = 0;
	uint8_t bit = 0xff;
	for (i = 0; i < MOTOR_NUM; i++)
	{
		bit = Motor_ReadLMTP(i);
		if(motor_array[i].lmtp_bit != bit)
		{
			motor_array[i].lmtp_bit = bit;
			debug("motor %d lmtp = %d\r\n", i+1, motor_array[i].lmtp_bit);
			bit = 0xff;
		}
		bit = Motor_ReadLMTN(i);
		if(motor_array[i].lmtn_bit != bit)
		{
			motor_array[i].lmtn_bit = bit;
			debug("motor %d lmtn = %d\r\n", i+1, motor_array[i].lmtn_bit);
			bit = 0xff;
		}
		bit = Motor_ReadSTOP0(i);
		if(motor_array[i].stop0_bit != bit)
		{
			motor_array[i].stop0_bit = bit;
			debug("motor %d stop0 = %d\r\n", i+1, motor_array[i].stop0_bit);
			bit = 0xff;
		}
		bit = Motor_ReadSTOP1(i);
		if(motor_array[i].stop1_bit != bit)
		{
			motor_array[i].stop1_bit = bit;
			debug("motor %d stop1 = %d\r\n", i+1, motor_array[i].stop1_bit);
			bit = 0xff;
		}
	}
}

uint8_t Motor_timid2motorid(uint8_t timid)
{
	uint8_t i = 0;
	for (i = 0; i < MOTOR_NUM; i++)
	{
		if(motor_array[i].tim_id == timid)
		{
			break;
		}
	}
	return i;
}
