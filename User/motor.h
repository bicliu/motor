/****************************************Copyright (c)***************************************
**                                  
**-------------------------------------------------------------------------------------------
** File name:           motor.h
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
#ifndef _MOTOR_H_
#define _MOTOR_H_
#include "stm32f4xx.h"

#define MOTOR1      0
#define MOTOR2      1
#define MOTOR3      2
#define MOTOR4      3
#define MOTOR5      4
#define MOTOR6      5
#define MOTOR7      6
#define MOTOR8      7
#define MOTOR9      8
#define MOTOR10     9
#define MOTOR11     10
#define MOTOR12     11
#define MOTOR_NUM   12
//#define MOTOR_NUM   7

#define IOENABLE_ENABLE    Bit_RESET
#define IOENABLE_DISABLE   Bit_SET

#define READ0BIT1      0
#define READ0BIT2      1
#define READ0BIT3      2
#define READ0BIT_NUM   3

typedef struct
{
	Gpio_Info io_enable;
	Gpio_Info io_clockwise;
	
	Gpio_Info io_lmtp;
	Gpio_Info io_lmtn;
	Gpio_Info io_stop0;
	Gpio_Info io_stop1;
	
	uint8_t   tim_id;
	uint8_t   read0bit_id;
	
	uint8_t   read0bit_bit;
	uint8_t   lmtp_bit;
	uint8_t   lmtn_bit;
	uint8_t   stop0_bit;
	uint8_t   stop1_bit;
}Motor_t;

extern Motor_t motor_array[MOTOR_NUM];

void Motor_paraset(void);
void Motor_Init(void);

void Motor_set_setpNum(uint8_t motor_id, uint32_t s_num);
void Motor_set_clockwise(uint8_t motor_id, uint8_t bit);
void Motor_setFrequency(uint8_t motor_id, uint32_t i_init, uint32_t i_final, uint16_t i_up);
void Motor_Run(uint8_t motor_id);
void Motor_Stop(uint8_t motor_id);
void Motor_Enable(uint8_t motor_id);
void Motor_Disable(uint8_t motor_id);
void Motor_ReportBit(uint8_t motor_id);
void Motor_ReportREAD0(void);
void Motor_ScanLmtBit(void);
void Motor_ScanLmtBit_test(void);
void Motor_ScanREAD0Bit_test(void);
uint8_t Motor_timid2motorid(uint8_t timid);

uint8_t Motor_ReadREAD0(uint8_t motor_id);
uint8_t Motor_ReadLMTP(uint8_t motor_id);
uint8_t Motor_ReadLMTN(uint8_t motor_id);
uint8_t Motor_ReadSTOP0(uint8_t motor_id);
uint8_t Motor_ReadSTOP1(uint8_t motor_id);

#endif
