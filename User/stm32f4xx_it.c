/**
  ******************************************************************************
  * @file    GPIO/IOToggle/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    13-April-2012
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
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
#include "stm32f4xx_it.h"
#include "Tim.h"
#include "Usart.h"
#include "msg_handler.h"
#include "MyTimer.h"
#include "Gpio.h"
#include "Tim_pwm.h"
/** @addtogroup STM32F4xx_StdPeriph_Examples
  * @{
  */

/** @addtogroup IOToggle
  * @{
  */ 

extern void MYUSART_IT_Handler(uint8_t i);
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/
void USART1_IRQHandler(void)
{
	MYUSART_IT_Handler(USART_1);
}/**/

void USART2_IRQHandler(void)
{
	MYUSART_IT_Handler(USART_2);
}

void USART6_IRQHandler(void)
{
	MYUSART_IT_Handler(USART_6);
}

/*void USARTx_IRQHANDLER(void)
{
#if 1
	u8 Res;
  if(USART_GetITStatus(Open_USART, USART_IT_RXNE) != RESET)
  {
		Res = USART_ReceiveData(Open_USART);
		if((USART_RX_STA&0x80)==0)
		{
			if(USART_RX_STA&0x40)
			{
				if(Res!=0x0a)
				{
					USART_RX_STA=0;
					LED1_OFF;
				}
				else
				{
					USART_RX_STA|=0x80;
					LED1_ON;
				}
			}
			else
			{
				if(Res==0x0d)
				{
					USART_RX_STA|=0x40;
				}
				else
				{
					USART_RX_BUF[USART_RX_STA&0X3F]=Res;
					USART_RX_STA++;
					if(USART_RX_STA>63)
					{
						USART_RX_STA=0;
						LED1_OFF;
					}
				}
			}
		}
  }
#else
	u16 data;  
  if(USART_GetITStatus(USART1,USART_IT_IDLE) != RESET)  
  {  
     DMA_Cmd(DMA2_Stream5, DISABLE);
  
     data = USART1->SR;  
     data = USART1->DR;  
          
     UART1_ReceiveSize =BUF_SIZE - DMA_GetCurrDataCounter(DMA2_Stream5);  
     if(UART1_ReceiveSize !=0)  
     {  
        //OSSemPost(DMAReceiveSize_Sem);
			 msg_dmarx(UART1_ReceiveSize);
     }  
     DMA_ClearFlag(DMA2_Stream5,DMA_FLAG_TCIF5 | DMA_FLAG_FEIF5 | DMA_FLAG_DMEIF5 | DMA_FLAG_TEIF5 | DMA_FLAG_HTIF5);
     DMA_SetCurrDataCounter(DMA2_Stream5, BUF_SIZE);  
     DMA_Cmd(DMA2_Stream5, ENABLE);
	}
#endif
}*/

/**
  * @brief  TIM1 CC IT Handler.
  * @param  None
  * @retval None
  */
void TIM1_CC_IRQHandler(void)
{
	TIM_IT_Handler(TIMER1);
}

/**
  * @brief  TIM2 CC IT Handler.
  * @param  None
  * @retval None
  */
void TIM2_IRQHandler(void)
{
	TIM_IT_Handler(TIMER2);
}

void TIM3_IRQHandler(void)
{
	TIM_IT_Handler(TIMER3);
}

void TIM4_IRQHandler(void)
{
	TIM_IT_Handler(TIMER4);
}

void TIM5_IRQHandler(void)
{
	TIM_IT_Handler(TIMER5);
}

void TIM6_DAC_IRQHandler(void)
{
	MyTimer_IT_Handler();
}

void TIM7_IRQHandler(void)
{
	MyTimer7_IT_Handler();
}

void TIM8_CC_IRQHandler(void)
{
	TIM_IT_Handler(TIMER8);
}

void TIM1_BRK_TIM9_IRQHandler(void)
{
	TIM_IT_Handler(TIMER9);
}

void TIM1_UP_TIM10_IRQHandler(void)
{
	TIM_IT_Handler(TIMER10);
}

void TIM1_TRG_COM_TIM11_IRQHandler(void)
{
	TIM_IT_Handler(TIMER11);
}

void TIM8_BRK_TIM12_IRQHandler(void)
{
	TIM_IT_Handler(TIMER12);
}

void TIM8_UP_TIM13_IRQHandler(void)
{
	TIM_IT_Handler(TIMER13);
}

void TIM8_TRG_COM_TIM14_IRQHandler(void)
{
	TIM_IT_Handler(TIMER14);
}

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */

//void TIM3_IRQHandler(void)
//{
//    TIM3_IRQ();
//}
/*void TIM13_IRQHandler(void)
{
	static int i = 0;
	i++;
	if(i > 20)
	{
		TIM_Cmd(TIM13, DISABLE);
	}
}*/
/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
