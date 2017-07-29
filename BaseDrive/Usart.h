#ifndef _USART_H_
#define _USART_H_
#include "stm32f4xx.h"
#include <stdio.h>

#if 1
	#define	USART1_OPEN
	#if 1
		#define USART1_PB6_PB7
	#else
		#define USART1_PA9_PA10
	#endif
#endif
/**
 * @brief Definition for COM port1, connected to USART1
 */ 
#ifdef	USART1_OPEN  
	#define Open_USART                        USART1
	#define Open_USART_CLK                    RCC_APB2Periph_USART1
	
	#ifdef USART1_PA9_PA10
		#define Open_USART_TX_PIN                 GPIO_Pin_9
		#define Open_USART_TX_GPIO_PORT           GPIOA
		#define Open_USART_TX_GPIO_CLK            RCC_AHB1Periph_GPIOA
		#define Open_USART_TX_SOURCE              GPIO_PinSource9
		#define Open_USART_TX_AF                  GPIO_AF_USART1
	
		#define Open_USART_RX_PIN                 GPIO_Pin_10
		#define Open_USART_RX_GPIO_PORT           GPIOA
		#define Open_USART_RX_GPIO_CLK            RCC_AHB1Periph_GPIOA
		#define Open_USART_RX_SOURCE              GPIO_PinSource10
		#define Open_USART_RX_AF                  GPIO_AF_USART1
	#elif defined USART1_PB6_PB7
		#define Open_USART_TX_PIN                 GPIO_Pin_6
		#define Open_USART_TX_GPIO_PORT           GPIOB
		#define Open_USART_TX_GPIO_CLK            RCC_AHB1Periph_GPIOB
		#define Open_USART_TX_SOURCE              GPIO_PinSource6
		#define Open_USART_TX_AF                  GPIO_AF_USART1
	
		#define Open_USART_RX_PIN                 GPIO_Pin_7
		#define Open_USART_RX_GPIO_PORT           GPIOB
		#define Open_USART_RX_GPIO_CLK            RCC_AHB1Periph_GPIOB
		#define Open_USART_RX_SOURCE              GPIO_PinSource7
		#define Open_USART_RX_AF                  GPIO_AF_USART1
	#else
		#error "Please select The COM1_IOPort to be used (in usart.h)"
	#endif
	
	#define Open_USART_IRQn                   USART1_IRQn
	#define USARTx_IRQHANDLER  				        USART1_IRQHandler
	
	#define Open_USART_DMA_TX_STREAM          DMA2_Stream7
	#define Open_USART_DMA_TX_CHANNEL         DMA_Channel_4
  #define Open_USART_DMA_TX_IRQn            DMA2_Stream7_IRQn
	
	#define Open_USART_DMA_RX_STREAM          DMA2_Stream5
	#define Open_USART_DMA_RX_CHANNEL         DMA_Channel_4
	#define Open_USART_DMA_RX_IRQn            DMA2_Stream5_IRQn
#else
	#error "Please select The COM to be used (in usart.h)"
#endif

/*Usart 1*/
#define USART1_NAME                  USART1
#define USART1_ISAPB1                0
#define USART1_CLK                   RCC_APB2Periph_USART1
	
#define USART1_TX_PIN                GPIO_Pin_6
#define USART1_TX_GPIO_PORT          GPIOB
#define USART1_TX_GPIO_CLK           RCC_AHB1Periph_GPIOB
#define USART1_TX_SOURCE             GPIO_PinSource6
#define USART1_TX_AF                 GPIO_AF_USART1
	
#define USART1_RX_PIN                GPIO_Pin_7
#define USART1_RX_GPIO_PORT          GPIOB
#define USART1_RX_GPIO_CLK           RCC_AHB1Periph_GPIOB
#define USART1_RX_SOURCE             GPIO_PinSource7
#define USART1_RX_AF                 GPIO_AF_USART1
	
#define USART1_IRQn                  USART1_IRQn
/*#define USARTx_IRQHANDLER  			     USART1_IRQHandler*/

/*Usart 2*/
#define USART2_NAME                  USART2
#define USART2_ISAPB1                1
#define USART2_CLK                   RCC_APB1Periph_USART2
	
#define USART2_TX_PIN                GPIO_Pin_5
#define USART2_TX_GPIO_PORT          GPIOD
#define USART2_TX_GPIO_CLK           RCC_AHB1Periph_GPIOD
#define USART2_TX_SOURCE             GPIO_PinSource5
#define USART2_TX_AF                 GPIO_AF_USART2
	
#define USART2_RX_PIN                GPIO_Pin_6
#define USART2_RX_GPIO_PORT          GPIOD
#define USART2_RX_GPIO_CLK           RCC_AHB1Periph_GPIOD
#define USART2_RX_SOURCE             GPIO_PinSource6
#define USART2_RX_AF                 GPIO_AF_USART2
	
#define USART2_IRQn                  USART2_IRQn
//#define USARTx_IRQHANDLER  			     USART2_IRQHandler

/*Usart 6*/
#define USART6_NAME                  USART6
#define USART6_ISAPB1                0
#define USART6_CLK                   RCC_APB2Periph_USART6
	
#define USART6_TX_PIN                GPIO_Pin_6
#define USART6_TX_GPIO_PORT          GPIOC
#define USART6_TX_GPIO_CLK           RCC_AHB1Periph_GPIOC
#define USART6_TX_SOURCE             GPIO_PinSource6
#define USART6_TX_AF                 GPIO_AF_USART6
	
#define USART6_RX_PIN                GPIO_Pin_7
#define USART6_RX_GPIO_PORT          GPIOC
#define USART6_RX_GPIO_CLK           RCC_AHB1Periph_GPIOC
#define USART6_RX_SOURCE             GPIO_PinSource7
#define USART6_RX_AF                 GPIO_AF_USART6
	
#define USART6_IRQn                  USART6_IRQn
//#define USARTx_IRQHANDLER  			     USART6_IRQHandler

typedef struct
{
	USART_TypeDef * USARTx;
	GPIO_TypeDef * TX_Type;
	GPIO_TypeDef * RX_Type;
	uint32_t clock;
	uint32_t TX_clk;
	uint32_t RX_clk;
	
	uint16_t TX_pin;
	uint16_t RX_pin;
	
	uint8_t IsAPB1;
	uint8_t TX_source;
	uint8_t TX_AF;
	uint8_t RX_source;
	uint8_t RX_AF;
	uint8_t IRQn;
	uint8_t RX_STATE;
}USART_Para;

#define USART_1                   0
#define USART_2                   1
#define USART_6                   2
#define USART_NUM                 3

extern uint16_t UART1_ReceiveSize;
extern USART_Para usart_array[USART_NUM];

void USART_RXNE_Init(void);
void USART_Configuration(void);
void USART_NVIC_Config(void);

void USART1_Puts(char * str);
void debug(const char* fmt,...);

void MYUSART_ParaSet(void);
void MYUSART_Init(void);
void MYUSART_Send(uint8_t i, const char* fmt,...);

#endif  /*_USART_H*/
