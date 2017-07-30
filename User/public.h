/****************************************Copyright (c)***************************************
**                                  
**-------------------------------------------------------------------------------------------
** File name:           public.h
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
#ifndef _PUBLIC_H_
#define _PUBLIC_H_
#include "stm32f4xx.h"

extern uint32_t PB1_TIM_ARR;
extern uint16_t PB1_TIM_PSC;
extern uint32_t PB2_TIM_ARR;
extern uint16_t PB2_TIM_PSC;
extern uint32_t TIM_CLOCK_BASE;

//relay
/*port id  PG8*/
#define RELAY1_RCC    RCC_AHB1Periph_GPIOG 
#define RELAY1_GPIO   GPIOG 
#define RELAY1_PIN    GPIO_Pin_0 
/*port id  PH9*/	
#define RELAY2_RCC    RCC_AHB1Periph_GPIOH 
#define RELAY2_GPIO   GPIOH 
#define RELAY2_PIN    GPIO_Pin_9
/*port id  PH7*/	
#define RELAY3_RCC    RCC_AHB1Periph_GPIOH 
#define RELAY3_GPIO   GPIOH 
#define RELAY3_PIN    GPIO_Pin_7 
/*port id  PH6*/	
#define RELAY4_RCC    RCC_AHB1Periph_GPIOH 
#define RELAY4_GPIO   GPIOH 
#define RELAY4_PIN    GPIO_Pin_6 
/*port id  PB11*/	
#define RELAY5_RCC    RCC_AHB1Periph_GPIOB 
#define RELAY5_GPIO   GPIOB 
#define RELAY5_PIN    GPIO_Pin_11 
/*port id  PB10*/	
#define RELAY6_RCC    RCC_AHB1Periph_GPIOB 
#define RELAY6_GPIO   GPIOB 
#define RELAY6_PIN    GPIO_Pin_10 
/*port id  PE15*/	
#define RELAY7_RCC    RCC_AHB1Periph_GPIOE 
#define RELAY7_GPIO   GPIOE 
#define RELAY7_PIN    GPIO_Pin_15 
/*port id  PE14*/	
#define RELAY8_RCC    RCC_AHB1Periph_GPIOE 
#define RELAY8_GPIO   GPIOE 
#define RELAY8_PIN    GPIO_Pin_14 

//motor
//motor 1
#define MOTOR1_TIMRID            TIMER2
/*port id  PA15*/
#define MOTOR1_IOENABLE_RCC      RCC_AHB1Periph_GPIOA
#define MOTOR1_IOENABLE_GPIO     GPIOA
#define MOTOR1_IOENABLE_PIN      GPIO_Pin_15
/*port id  PC10*/
#define MOTOR1_IOCLOCKWISE_RCC   RCC_AHB1Periph_GPIOC
#define MOTOR1_IOCLOCKWISE_GPIO        GPIOC
#define MOTOR1_IOCLOCKWISE_PIN   GPIO_Pin_10
/*port id  PC11*/
#define MOTOR1_IOLMTP_RCC        RCC_AHB1Periph_GPIOC
#define MOTOR1_IOLMTP_GPIO       GPIOC
#define MOTOR1_IOLMTP_PIN        GPIO_Pin_11
/*port id  PC12*/
#define MOTOR1_IOLMTN_RCC        RCC_AHB1Periph_GPIOC
#define MOTOR1_IOLMTN_GPIO       GPIOC
#define MOTOR1_IOLMTN_PIN        GPIO_Pin_12
/*port id  PD1*/
#define MOTOR1_IOSTOP0_RCC       RCC_AHB1Periph_GPIOD
#define MOTOR1_IOSTOP0_GPIO      GPIOD
#define MOTOR1_IOSTOP0_PIN       GPIO_Pin_1
/*port id  PD0*/
#define MOTOR1_IOSTOP1_RCC       RCC_AHB1Periph_GPIOD
#define MOTOR1_IOSTOP1_GPIO      GPIOD
#define MOTOR1_IOSTOP1_PIN       GPIO_Pin_0

//motor 2
#define MOTOR2_TIMRID            TIMER3
/*port id  PB5*/
#define MOTOR2_IOENABLE_RCC      RCC_AHB1Periph_GPIOB
#define MOTOR2_IOENABLE_GPIO     GPIOB
#define MOTOR2_IOENABLE_PIN      GPIO_Pin_5
/*port id  PG15*/
#define MOTOR2_IOCLOCKWISE_RCC   RCC_AHB1Periph_GPIOG
#define MOTOR2_IOCLOCKWISE_GPIO        GPIOG
#define MOTOR2_IOCLOCKWISE_PIN   GPIO_Pin_15
/*port id  PG12*/
#define MOTOR2_IOLMTP_RCC        RCC_AHB1Periph_GPIOG
#define MOTOR2_IOLMTP_GPIO       GPIOG
#define MOTOR2_IOLMTP_PIN        GPIO_Pin_12
/*port id  PG10*/
#define MOTOR2_IOLMTN_RCC        RCC_AHB1Periph_GPIOG
#define MOTOR2_IOLMTN_GPIO       GPIOG
#define MOTOR2_IOLMTN_PIN        GPIO_Pin_10
/*port id  PD2*/
#define MOTOR2_IOSTOP0_RCC       RCC_AHB1Periph_GPIOD
#define MOTOR2_IOSTOP0_GPIO      GPIOD
#define MOTOR2_IOSTOP0_PIN       GPIO_Pin_2
/*port id  PG9*/
#define MOTOR2_IOSTOP1_RCC       RCC_AHB1Periph_GPIOG
#define MOTOR2_IOSTOP1_GPIO      GPIOG
#define MOTOR2_IOSTOP1_PIN       GPIO_Pin_9

//motor 3
#define MOTOR3_TIMRID            TIMER11
/*port id  PI7*/
#define MOTOR3_IOENABLE_RCC      RCC_AHB1Periph_GPIOI
#define MOTOR3_IOENABLE_GPIO     GPIOI
#define MOTOR3_IOENABLE_PIN      GPIO_Pin_7
/*port id  PE2*/
#define MOTOR3_IOCLOCKWISE_RCC   RCC_AHB1Periph_GPIOE
#define MOTOR3_IOCLOCKWISE_GPIO        GPIOE
#define MOTOR3_IOCLOCKWISE_PIN   GPIO_Pin_2
/*port id  PE3*/
#define MOTOR3_IOLMTP_RCC        RCC_AHB1Periph_GPIOE
#define MOTOR3_IOLMTP_GPIO       GPIOE
#define MOTOR3_IOLMTP_PIN        GPIO_Pin_3
/*port id  PE4*/
#define MOTOR3_IOLMTN_RCC        RCC_AHB1Periph_GPIOE
#define MOTOR3_IOLMTN_GPIO       GPIOE
#define MOTOR3_IOLMTN_PIN        GPIO_Pin_4
/*port id  PI8*/
#define MOTOR3_IOSTOP0_RCC       RCC_AHB1Periph_GPIOI
#define MOTOR3_IOSTOP0_GPIO      GPIOI
#define MOTOR3_IOSTOP0_PIN       GPIO_Pin_8
/*port id  PE6*/
#define MOTOR3_IOSTOP1_RCC       RCC_AHB1Periph_GPIOE
#define MOTOR3_IOSTOP1_GPIO      GPIOE
#define MOTOR3_IOSTOP1_PIN       GPIO_Pin_6

//motor 4
#define MOTOR4_TIMRID            TIMER10
/*port id  PI6*/
#define MOTOR4_IOENABLE_RCC      RCC_AHB1Periph_GPIOI
#define MOTOR4_IOENABLE_GPIO     GPIOI
#define MOTOR4_IOENABLE_PIN      GPIO_Pin_6
/*port id  PI4*/
#define MOTOR4_IOCLOCKWISE_RCC   RCC_AHB1Periph_GPIOI
#define MOTOR4_IOCLOCKWISE_GPIO        GPIOI
#define MOTOR4_IOCLOCKWISE_PIN   GPIO_Pin_4
/*port id  PE1*/
#define MOTOR4_IOLMTP_RCC        RCC_AHB1Periph_GPIOE
#define MOTOR4_IOLMTP_GPIO       GPIOE
#define MOTOR4_IOLMTP_PIN        GPIO_Pin_1
/*port id  PE0*/
#define MOTOR4_IOLMTN_RCC        RCC_AHB1Periph_GPIOE
#define MOTOR4_IOLMTN_GPIO       GPIOE
#define MOTOR4_IOLMTN_PIN        GPIO_Pin_0
/*port id  PC13*/
#define MOTOR4_IOSTOP0_RCC       RCC_AHB1Periph_GPIOC
#define MOTOR4_IOSTOP0_GPIO      GPIOC
#define MOTOR4_IOSTOP0_PIN       GPIO_Pin_13
/*port id  PD7*/
#define MOTOR4_IOSTOP1_RCC       RCC_AHB1Periph_GPIOD
#define MOTOR4_IOSTOP1_GPIO      GPIOD
#define MOTOR4_IOSTOP1_PIN       GPIO_Pin_7

//motor 5
#define MOTOR5_TIMRID            TIMER9
/*port id  PI9*/
#define MOTOR5_IOENABLE_RCC      RCC_AHB1Periph_GPIOI
#define MOTOR5_IOENABLE_GPIO     GPIOI
#define MOTOR5_IOENABLE_PIN      GPIO_Pin_9
/*port id  PI10*/
#define MOTOR5_IOCLOCKWISE_RCC   RCC_AHB1Periph_GPIOI
#define MOTOR5_IOCLOCKWISE_GPIO        GPIOI
#define MOTOR5_IOCLOCKWISE_PIN   GPIO_Pin_10
/*port id  PF1*/
#define MOTOR5_IOLMTP_RCC        RCC_AHB1Periph_GPIOF
#define MOTOR5_IOLMTP_GPIO       GPIOF
#define MOTOR5_IOLMTP_PIN        GPIO_Pin_1
/*port id  PF0*/
#define MOTOR5_IOLMTN_RCC        RCC_AHB1Periph_GPIOF
#define MOTOR5_IOLMTN_GPIO       GPIOF
#define MOTOR5_IOLMTN_PIN        GPIO_Pin_0
/*port id  PF2*/
#define MOTOR5_IOSTOP0_RCC       RCC_AHB1Periph_GPIOF
#define MOTOR5_IOSTOP0_GPIO      GPIOF
#define MOTOR5_IOSTOP0_PIN       GPIO_Pin_2
/*port id  PI11*/
#define MOTOR5_IOSTOP1_RCC       RCC_AHB1Periph_GPIOI
#define MOTOR5_IOSTOP1_GPIO      GPIOI
#define MOTOR5_IOSTOP1_PIN       GPIO_Pin_11

//motor 6
#define MOTOR6_TIMRID            TIMER14
/*port id  PF6*/
#define MOTOR6_IOENABLE_RCC      RCC_AHB1Periph_GPIOF
#define MOTOR6_IOENABLE_GPIO     GPIOF
#define MOTOR6_IOENABLE_PIN      GPIO_Pin_6
/*port id  PF7*/
#define MOTOR6_IOCLOCKWISE_RCC   RCC_AHB1Periph_GPIOF
#define MOTOR6_IOCLOCKWISE_GPIO        GPIOF
#define MOTOR6_IOCLOCKWISE_PIN   GPIO_Pin_7
/*port id  PF4*/
#define MOTOR6_IOLMTP_RCC        RCC_AHB1Periph_GPIOF
#define MOTOR6_IOLMTP_GPIO       GPIOF
#define MOTOR6_IOLMTP_PIN        GPIO_Pin_4
/*port id  PF3*/
#define MOTOR6_IOLMTN_RCC        RCC_AHB1Periph_GPIOF
#define MOTOR6_IOLMTN_GPIO       GPIOF
#define MOTOR6_IOLMTN_PIN        GPIO_Pin_3
/*port id  PF5*/
#define MOTOR6_IOSTOP0_RCC       RCC_AHB1Periph_GPIOF
#define MOTOR6_IOSTOP0_GPIO      GPIOF
#define MOTOR6_IOSTOP0_PIN       GPIO_Pin_5
/*port id  PF8*/
#define MOTOR6_IOSTOP1_RCC       RCC_AHB1Periph_GPIOF
#define MOTOR6_IOSTOP1_GPIO      GPIOF
#define MOTOR6_IOSTOP1_PIN       GPIO_Pin_8

//motor 7
#define MOTOR7_TIMRID            TIMER5
/*port id  PF10*/
#define MOTOR7_IOENABLE_RCC      RCC_AHB1Periph_GPIOF
#define MOTOR7_IOENABLE_GPIO     GPIOF
#define MOTOR7_IOENABLE_PIN      GPIO_Pin_10
/*port id  PC0*/
#define MOTOR7_IOCLOCKWISE_RCC   RCC_AHB1Periph_GPIOC
#define MOTOR7_IOCLOCKWISE_GPIO        GPIOC
#define MOTOR7_IOCLOCKWISE_PIN   GPIO_Pin_0
/*port id  PH2*/
#define MOTOR7_IOLMTP_RCC        RCC_AHB1Periph_GPIOH
#define MOTOR7_IOLMTP_GPIO       GPIOH
#define MOTOR7_IOLMTP_PIN        GPIO_Pin_2
/*port id  PC3*/
#define MOTOR7_IOLMTN_RCC        RCC_AHB1Periph_GPIOC
#define MOTOR7_IOLMTN_GPIO       GPIOC
#define MOTOR7_IOLMTN_PIN        GPIO_Pin_3
/*port id  PH3*/
#define MOTOR7_IOSTOP0_RCC       RCC_AHB1Periph_GPIOH
#define MOTOR7_IOSTOP0_GPIO      GPIOH
#define MOTOR7_IOSTOP0_PIN       GPIO_Pin_3
/*port id  PC2*/
#define MOTOR7_IOSTOP1_RCC       RCC_AHB1Periph_GPIOC
#define MOTOR7_IOSTOP1_GPIO      GPIOC
#define MOTOR7_IOSTOP1_PIN       GPIO_Pin_2

//motor 8
#define MOTOR8_TIMRID            TIMER13
/*port id  PH4*/
#define MOTOR8_IOENABLE_RCC      RCC_AHB1Periph_GPIOH
#define MOTOR8_IOENABLE_GPIO     GPIOH
#define MOTOR8_IOENABLE_PIN      GPIO_Pin_4
/*port id  PH5*/
#define MOTOR8_IOCLOCKWISE_RCC   RCC_AHB1Periph_GPIOH
#define MOTOR8_IOCLOCKWISE_GPIO        GPIOH
#define MOTOR8_IOCLOCKWISE_PIN   GPIO_Pin_5
/*port id  PA5*/
#define MOTOR8_IOLMTP_RCC        RCC_AHB1Periph_GPIOA
#define MOTOR8_IOLMTP_GPIO       GPIOA
#define MOTOR8_IOLMTP_PIN        GPIO_Pin_5
/*port id  PA4*/
#define MOTOR8_IOLMTN_RCC        RCC_AHB1Periph_GPIOA
#define MOTOR8_IOLMTN_GPIO       GPIOA
#define MOTOR8_IOLMTN_PIN        GPIO_Pin_4
/*port id  PB0*/
#define MOTOR8_IOSTOP0_RCC       RCC_AHB1Periph_GPIOB
#define MOTOR8_IOSTOP0_GPIO      GPIOB
#define MOTOR8_IOSTOP0_PIN       GPIO_Pin_0
/*port id  PA3*/
#define MOTOR8_IOSTOP1_RCC       RCC_AHB1Periph_GPIOA
#define MOTOR8_IOSTOP1_GPIO      GPIOA
#define MOTOR8_IOSTOP1_PIN       GPIO_Pin_3

//motor 9
#define MOTOR9_TIMRID            TIMER8
/*port id  PB1*/
#define MOTOR9_IOENABLE_RCC      RCC_AHB1Periph_GPIOB
#define MOTOR9_IOENABLE_GPIO     GPIOB
#define MOTOR9_IOENABLE_PIN      GPIO_Pin_1
/*port id  PF11*/
#define MOTOR9_IOCLOCKWISE_RCC   RCC_AHB1Periph_GPIOF
#define MOTOR9_IOCLOCKWISE_GPIO        GPIOF
#define MOTOR9_IOCLOCKWISE_PIN   GPIO_Pin_11
/*port id  PF12*/
#define MOTOR9_IOLMTP_RCC        RCC_AHB1Periph_GPIOF
#define MOTOR9_IOLMTP_GPIO       GPIOF
#define MOTOR9_IOLMTP_PIN        GPIO_Pin_12
/*port id  PF13*/
#define MOTOR9_IOLMTN_RCC        RCC_AHB1Periph_GPIOF
#define MOTOR9_IOLMTN_GPIO       GPIOF
#define MOTOR9_IOLMTN_PIN        GPIO_Pin_13
/*port id  PF15*/
#define MOTOR9_IOSTOP0_RCC       RCC_AHB1Periph_GPIOF
#define MOTOR9_IOSTOP0_GPIO      GPIOF
#define MOTOR9_IOSTOP0_PIN       GPIO_Pin_15
/*port id  PF14*/
#define MOTOR9_IOSTOP1_RCC       RCC_AHB1Periph_GPIOF
#define MOTOR9_IOSTOP1_GPIO      GPIOF
#define MOTOR9_IOSTOP1_PIN       GPIO_Pin_14

//motor 10
#define MOTOR10_TIMRID            TIMER1
/*port id  PE13*/
#define MOTOR10_IOENABLE_RCC      RCC_AHB1Periph_GPIOE
#define MOTOR10_IOENABLE_GPIO     GPIOE
#define MOTOR10_IOENABLE_PIN      GPIO_Pin_13
/*port id  PE12*/
#define MOTOR10_IOCLOCKWISE_RCC   RCC_AHB1Periph_GPIOE
#define MOTOR10_IOCLOCKWISE_GPIO  GPIOE
#define MOTOR10_IOCLOCKWISE_PIN   GPIO_Pin_12
/*port id  PE11*/
#define MOTOR10_READBIT0_RCC      RCC_AHB1Periph_GPIOE
#define MOTOR10_READBIT0_GPIO     GPIOE
#define MOTOR10_READBIT0_PIN      GPIO_Pin_11
/*port id  XX*/
#define MOTOR10_IOLMTP_RCC        0
#define MOTOR10_IOLMTP_GPIO       0
#define MOTOR10_IOLMTP_PIN        0
/*port id  XX*/
#define MOTOR10_IOLMTN_RCC        0
#define MOTOR10_IOLMTN_GPIO       0
#define MOTOR10_IOLMTN_PIN        0
/*port id  XX*/
#define MOTOR10_IOSTOP0_RCC       0
#define MOTOR10_IOSTOP0_GPIO      0
#define MOTOR10_IOSTOP0_PIN       0
/*port id  XX*/
#define MOTOR10_IOSTOP1_RCC       0
#define MOTOR10_IOSTOP1_GPIO      0
#define MOTOR10_IOSTOP1_PIN       0

//motor 11
#define MOTOR11_TIMRID            TIMER12
/*port id  PH11*/
#define MOTOR11_IOENABLE_RCC      RCC_AHB1Periph_GPIOH
#define MOTOR11_IOENABLE_GPIO     GPIOH
#define MOTOR11_IOENABLE_PIN      GPIO_Pin_11
/*port id  PH8*/
#define MOTOR11_IOCLOCKWISE_RCC   RCC_AHB1Periph_GPIOH
#define MOTOR11_IOCLOCKWISE_GPIO  GPIOH
#define MOTOR11_IOCLOCKWISE_PIN   GPIO_Pin_8
/*port id  PH10*/
#define MOTOR11_READBIT0_RCC      RCC_AHB1Periph_GPIOH
#define MOTOR11_READBIT0_GPIO     GPIOH
#define MOTOR11_READBIT0_PIN      GPIO_Pin_10
/*port id  XX*/
#define MOTOR11_IOLMTP_RCC        0
#define MOTOR11_IOLMTP_GPIO       0
#define MOTOR11_IOLMTP_PIN        0
/*port id  XX*/
#define MOTOR11_IOLMTN_RCC        0
#define MOTOR11_IOLMTN_GPIO       0
#define MOTOR11_IOLMTN_PIN        0
/*port id  XX*/
#define MOTOR11_IOSTOP0_RCC       0
#define MOTOR11_IOSTOP0_GPIO      0
#define MOTOR11_IOSTOP0_PIN       0
/*port id  XX*/
#define MOTOR11_IOSTOP1_RCC       0
#define MOTOR11_IOSTOP1_GPIO      0
#define MOTOR11_IOSTOP1_PIN       0

//motor 12
#define MOTOR12_TIMRID            TIMER4
/*port id  PD14*/
#define MOTOR12_IOENABLE_RCC      RCC_AHB1Periph_GPIOD
#define MOTOR12_IOENABLE_GPIO     GPIOD
#define MOTOR12_IOENABLE_PIN      GPIO_Pin_14
/*port id  PD11*/
#define MOTOR12_IOCLOCKWISE_RCC   RCC_AHB1Periph_GPIOD
#define MOTOR12_IOCLOCKWISE_GPIO  GPIOD
#define MOTOR12_IOCLOCKWISE_PIN   GPIO_Pin_11
/*port id  PD13*/
#define MOTOR12_READBIT0_RCC      RCC_AHB1Periph_GPIOD
#define MOTOR12_READBIT0_GPIO     GPIOD
#define MOTOR12_READBIT0_PIN      GPIO_Pin_13
/*port id  XX*/
#define MOTOR12_IOLMTP_RCC        0
#define MOTOR12_IOLMTP_GPIO       0
#define MOTOR12_IOLMTP_PIN        0
/*port id  XX*/
#define MOTOR12_IOLMTN_RCC        0
#define MOTOR12_IOLMTN_GPIO       0
#define MOTOR12_IOLMTN_PIN        0
/*port id  XX*/
#define MOTOR12_IOSTOP0_RCC       0
#define MOTOR12_IOSTOP0_GPIO      0
#define MOTOR12_IOSTOP0_PIN       0
/*port id  XX*/
#define MOTOR12_IOSTOP1_RCC       0
#define MOTOR12_IOSTOP1_GPIO      0
#define MOTOR12_IOSTOP1_PIN       0

//timer
//timer1 ch1 PE9 - motor 10
#define TIMR1_ISPWM       true;
/*port id  PE9*/
#define TIMR1_GPIO_RCC    RCC_AHB1Periph_GPIOE
#define TIMR1_GPIO_PIN    GPIO_Pin_9
#define TIMR1_GPIO        GPIOE
#define TIMR1_GPIO_PSRCE  GPIO_PinSource9
#define TIMR1_TIM_AF      GPIO_AF_TIM1
#define TIMR1_ISAPB1      false
#define TIMR1_TIM_RCC     RCC_APB2Periph_TIM1
#define TIMR1_TIM_IRQN    TIM1_CC_IRQn
#define TIMR1_TIM         TIM1
#define TIMR1_TIM_ITFLAG  TIM_FLAG_CC1
#define TIMR1_TIM_IT      TIM_IT_CC1
#define TIMR1_TIM_CNL     TIMR_CNL_1

//tim2 ch1 PB3 - motor 1
#define TIMR2_ISPWM       true;
/*port id  PB3*/
#define TIMR2_GPIO_RCC    RCC_AHB1Periph_GPIOB
#define TIMR2_GPIO_PIN    GPIO_Pin_3
#define TIMR2_GPIO        GPIOB
#define TIMR2_GPIO_PSRCE  GPIO_PinSource3
#define TIMR2_TIM_AF      GPIO_AF_TIM2
#define TIMR2_ISAPB1      true
#define TIMR2_TIM_RCC     RCC_APB1Periph_TIM2
#define TIMR2_TIM_IRQN    TIM2_IRQn
#define TIMR2_TIM         TIM2
#define TIMR2_TIM_ITFLAG  TIM_FLAG_Update
#define TIMR2_TIM_IT      TIM_IT_Update
#define TIMR2_TIM_CNL     TIMR_CNL_2

//tim3 ch1 PB4 - motor 2
#define TIMR3_ISPWM       true;
/*port id  PB4*/
#define TIMR3_GPIO_RCC    RCC_AHB1Periph_GPIOB
#define TIMR3_GPIO_PIN    GPIO_Pin_4
#define TIMR3_GPIO        GPIOB
#define TIMR3_GPIO_PSRCE  GPIO_PinSource4
#define TIMR3_TIM_AF      GPIO_AF_TIM3
#define TIMR3_ISAPB1      true
#define TIMR3_TIM_RCC     RCC_APB1Periph_TIM3
#define TIMR3_TIM_IRQN    TIM3_IRQn
#define TIMR3_TIM         TIM3
#define TIMR3_TIM_ITFLAG  TIM_FLAG_Update
#define TIMR3_TIM_IT      TIM_IT_Update
#define TIMR3_TIM_CNL     TIMR_CNL_1

//tim4 tch1 PD12 - motor 12
#define TIMR4_ISPWM       true;
/*port id  PD12*/
#define TIMR4_GPIO_RCC    RCC_AHB1Periph_GPIOD
#define TIMR4_GPIO_PIN    GPIO_Pin_12
#define TIMR4_GPIO        GPIOD
#define TIMR4_GPIO_PSRCE  GPIO_PinSource12
#define TIMR4_TIM_AF      GPIO_AF_TIM4
#define TIMR4_ISAPB1      true
#define TIMR4_TIM_RCC     RCC_APB1Periph_TIM4
#define TIMR4_TIM_IRQN    TIM4_IRQn
#define TIMR4_TIM         TIM4
#define TIMR4_TIM_ITFLAG  TIM_FLAG_Update
#define TIMR4_TIM_IT      TIM_IT_Update
#define TIMR4_TIM_CNL     TIMR_CNL_1

//tim5 tch1 PA0 - motor 7
#define TIMR5_ISPWM       true;
/*port id  PA0*/
#define TIMR5_GPIO_RCC    RCC_AHB1Periph_GPIOA
#define TIMR5_GPIO_PIN    GPIO_Pin_0
#define TIMR5_GPIO        GPIOA
#define TIMR5_GPIO_PSRCE  GPIO_PinSource0
#define TIMR5_TIM_AF      GPIO_AF_TIM5
#define TIMR5_ISAPB1      true
#define TIMR5_TIM_RCC     RCC_APB1Periph_TIM5
#define TIMR5_TIM_IRQN    TIM5_IRQn
#define TIMR5_TIM         TIM5
#define TIMR5_TIM_ITFLAG  TIM_FLAG_Update
#define TIMR5_TIM_IT      TIM_IT_Update
#define TIMR5_TIM_CNL     TIMR_CNL_1

//tim6 - no use
#define TIMR6_ISPWM       false;
//tim7 - no use
#define TIMR7_ISPWM       false;

//tim8 ch1n PI5 - motor 9
#define TIMR8_ISPWM       true;
/*port id  PI5*/
#define TIMR8_GPIO_RCC    RCC_AHB1Periph_GPIOI
#define TIMR8_GPIO_PIN    GPIO_Pin_5
#define TIMR8_GPIO        GPIOI
#define TIMR8_GPIO_PSRCE  GPIO_PinSource5
#define TIMR8_TIM_AF      GPIO_AF_TIM8
#define TIMR8_ISAPB1      false
#define TIMR8_TIM_RCC     RCC_APB2Periph_TIM8
#define TIMR8_TIM_IRQN    TIM8_CC_IRQn
#define TIMR8_TIM         TIM8
#define TIMR8_TIM_ITFLAG  TIM_FLAG_CC1
#define TIMR8_TIM_IT      TIM_IT_CC1
#define TIMR8_TIM_CNL     TIMR_CNL_1

//tim9 ch1 PE5 - motor 5
#define TIMR9_ISPWM       true;
/*port id  PE5*/
#define TIMR9_GPIO_RCC    RCC_AHB1Periph_GPIOE
#define TIMR9_GPIO_PIN    GPIO_Pin_5
#define TIMR9_GPIO        GPIOE
#define TIMR9_GPIO_PSRCE  GPIO_PinSource5
#define TIMR9_TIM_AF      GPIO_AF_TIM9
#define TIMR9_ISAPB1      false
#define TIMR9_TIM_RCC     RCC_APB2Periph_TIM9
#define TIMR9_TIM_IRQN    TIM1_BRK_TIM9_IRQn
#define TIMR9_TIM         TIM9
#define TIMR9_TIM_ITFLAG  TIM_FLAG_Update
#define TIMR9_TIM_IT      TIM_IT_Update
#define TIMR9_TIM_CNL     TIMR_CNL_1

//tim10 ch1 PB8 - motor 4
#define TIMR10_ISPWM       true;
/*port id  PB8*/
#define TIMR10_GPIO_RCC    RCC_AHB1Periph_GPIOB
#define TIMR10_GPIO_PIN    GPIO_Pin_8
#define TIMR10_GPIO        GPIOB
#define TIMR10_GPIO_PSRCE  GPIO_PinSource8
#define TIMR10_TIM_AF      GPIO_AF_TIM10
#define TIMR10_ISAPB1      false
#define TIMR10_TIM_RCC     RCC_APB2Periph_TIM10
#define TIMR10_TIM_IRQN    TIM1_UP_TIM10_IRQn
#define TIMR10_TIM         TIM10
#define TIMR10_TIM_ITFLAG  TIM_FLAG_Update
#define TIMR10_TIM_IT      TIM_IT_Update
#define TIMR10_TIM_CNL     TIMR_CNL_1

//tim11 ch1 PB9 - motor 3
#define TIMR11_ISPWM       true;
/*port id  PB9*/
#define TIMR11_GPIO_RCC    RCC_AHB1Periph_GPIOB
#define TIMR11_GPIO_PIN    GPIO_Pin_9
#define TIMR11_GPIO        GPIOB
#define TIMR11_GPIO_PSRCE  GPIO_PinSource9
#define TIMR11_TIM_AF      GPIO_AF_TIM11
#define TIMR11_ISAPB1      false
#define TIMR11_TIM_RCC     RCC_APB2Periph_TIM11
#define TIMR11_TIM_IRQN    TIM1_TRG_COM_TIM11_IRQn
#define TIMR11_TIM         TIM11
#define TIMR11_TIM_ITFLAG  TIM_FLAG_Update
#define TIMR11_TIM_IT      TIM_IT_Update
#define TIMR11_TIM_CNL     TIMR_CNL_1

//tim12 ch2 PB15 - motor 11
#define TIMR12_ISPWM       false;
/*port id  PB15*/
#define TIMR12_GPIO_RCC    RCC_AHB1Periph_GPIOB
#define TIMR12_GPIO_PIN    GPIO_Pin_15
#define TIMR12_GPIO        GPIOB
#define TIMR12_GPIO_PSRCE  GPIO_PinSource15
#define TIMR12_TIM_AF      GPIO_AF_TIM12
#define TIMR12_ISAPB1      true
#define TIMR12_TIM_RCC     RCC_APB1Periph_TIM12
#define TIMR12_TIM_IRQN    TIM8_BRK_TIM12_IRQn
#define TIMR12_TIM         TIM12
#define TIMR12_TIM_ITFLAG  TIM_FLAG_Update
#define TIMR12_TIM_IT      TIM_IT_Update
#define TIMR12_TIM_CNL     TIMR_CNL_2

//tim13 ch1 PA6 - motor 8
#define TIMR13_ISPWM       true;
/*port id  PA6*/
#define TIMR13_GPIO_RCC    RCC_AHB1Periph_GPIOA
#define TIMR13_GPIO_PIN    GPIO_Pin_6
#define TIMR13_GPIO        GPIOA
#define TIMR13_GPIO_PSRCE  GPIO_PinSource6
#define TIMR13_TIM_AF      GPIO_AF_TIM13
#define TIMR13_ISAPB1      true
#define TIMR13_TIM_RCC     RCC_APB1Periph_TIM13
#define TIMR13_TIM_IRQN    TIM8_UP_TIM13_IRQn
#define TIMR13_TIM         TIM13
#define TIMR13_TIM_ITFLAG  TIM_FLAG_Update
#define TIMR13_TIM_IT      TIM_IT_Update
#define TIMR13_TIM_CNL     TIMR_CNL_1

//tim14 ch1 pf9 - motor 6
#define TIMR14_ISPWM       true;
/*port id  PF9*/
#define TIMR14_GPIO_RCC    RCC_AHB1Periph_GPIOF
#define TIMR14_GPIO_PIN    GPIO_Pin_9
#define TIMR14_GPIO        GPIOF
#define TIMR14_GPIO_PSRCE  GPIO_PinSource9
#define TIMR14_TIM_AF      GPIO_AF_TIM14
#define TIMR14_ISAPB1      true
#define TIMR14_TIM_RCC     RCC_APB1Periph_TIM14
#define TIMR14_TIM_IRQN    TIM8_TRG_COM_TIM14_IRQn
#define TIMR14_TIM         TIM14
#define TIMR14_TIM_ITFLAG  TIM_FLAG_Update
#define TIMR14_TIM_IT      TIM_IT_Update
#define TIMR14_TIM_CNL     TIMR_CNL_1

//My Timer tim 6
#define MYTIMER_ISAPB1      1
#define MYTIMER_TIM_RCC     RCC_APB1Periph_TIM6
#define MYTIMER_TIM_IRQN    TIM6_DAC_IRQn
#define MYTIMER_TIM         TIM6
#define MYTIMER_TIM_ITFLAG  TIM_FLAG_Update
#define MYTIMER_TIM_IT      TIM_IT_Update
#define MYTIMER_TIM_CNL     TIMR_CNL_1

//My Timer tim 7
#define MYTIMER7_ISAPB1      1
#define MYTIMER7_TIM_RCC     RCC_APB1Periph_TIM7
#define MYTIMER7_TIM_IRQN    TIM7_IRQn
#define MYTIMER7_TIM         TIM7
#define MYTIMER7_TIM_ITFLAG  TIM_FLAG_Update
#define MYTIMER7_TIM_IT      TIM_IT_Update
#define MYTIMER7_TIM_CNL     TIMR_CNL_1

#endif
