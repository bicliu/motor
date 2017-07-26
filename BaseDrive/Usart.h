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

extern uint16_t UART1_ReceiveSize;

void USART_RXNE_Init(void);
void USART_Configuration(void);
void USART_NVIC_Config(void);

void USART1_Puts(char * str);
void debug(const char* fmt,...);

#endif  /*_USART_H*/
