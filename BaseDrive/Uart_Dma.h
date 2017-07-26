#ifndef _UART_DMA_H_
#define _UART_DMA_H_
#include "stm32f4xx.h"
#include <stdio.h>

#define Open_USART_CLK                 RCC_APB2Periph_USART1
#define Open_USART_GPIO_CLK            RCC_AHB1Periph_GPIOB
#define Open_USART_DMA_CLK             RCC_AHB1Periph_DMA2

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

void uart_init(void);
void dma_debug(const char* fmt,...);

#endif  /*_UART_DMA_H_*/
