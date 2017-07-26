/* Includes ------------------------------------------------------------------*/
#include "Usart.h"
#include "msg_handler.h"
#include <stdarg.h>
#include <string.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define USART_INTERRUPT_PRIORITY   0
#define USART_INTERRUPT_SUB_PRI    3
#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t DEFAULT_BAUD_GSM = 115200;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
* Function Name  : USART_Configuration
* Description    : Configure Open_USART 
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void USART_Configuration(void)
{ 												
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure; 

  RCC_AHB1PeriphClockCmd(Open_USART_TX_GPIO_CLK,ENABLE);
  RCC_AHB1PeriphClockCmd(Open_USART_RX_GPIO_CLK,ENABLE);

  #ifdef	USART1_OPEN
  	RCC_APB2PeriphClockCmd(Open_USART_CLK,ENABLE);
  #else
  	RCC_APB1PeriphClockCmd(Open_USART_CLK,ENABLE);
  #endif	


  GPIO_PinAFConfig(Open_USART_TX_GPIO_PORT, Open_USART_TX_SOURCE, Open_USART_TX_AF);
  GPIO_PinAFConfig(Open_USART_RX_GPIO_PORT, Open_USART_RX_SOURCE, Open_USART_RX_AF);

  /*
  *  Open_USART_TX -> PA9 or PB6 , Open_USART_RX -PA10 or PB7
  */
  GPIO_InitStructure.GPIO_Pin = Open_USART_TX_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;

  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(Open_USART_TX_GPIO_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = Open_USART_RX_PIN;
  //GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  //GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(Open_USART_RX_GPIO_PORT, &GPIO_InitStructure);

/*
   		 USARTx configured as follow:
         - BaudRate = 115200 baud  
		 - Word Length = 8 Bits
         - One Stop Bit
         - No parity
         - Hardware flow control disabled (RTS and CTS signals)
         - Receive and transmit    
 */

  USART_InitStructure.USART_BaudRate = DEFAULT_BAUD_GSM;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(Open_USART, &USART_InitStructure);
  /* Enable the Open_USART Transmit interrupt: this interrupt is generated when the 
     Open_USART transmit data register is empty */
  //USART_ITConfig(Open_USART,USART_IT_RXNE,ENABLE);
	//USART_NVIC_Config();

  //USART_Cmd(Open_USART, ENABLE);
	//USART_ClearFlag(Open_USART, USART_FLAG_RXNE);
}

void USART_NVIC_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
  NVIC_InitStructure.NVIC_IRQChannel = Open_USART_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = USART_INTERRUPT_PRIORITY;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = USART_INTERRUPT_SUB_PRI;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	/* Enable the USARTx Interrupt */
	USART_ITConfig(Open_USART,USART_IT_RXNE,ENABLE);
	
	USART_Cmd(Open_USART, ENABLE);
	USART_ClearFlag(Open_USART, USART_FLAG_RXNE);
}

void USART_RXNE_Init(void)
{
	USART_Configuration();
	USART_NVIC_Config();
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
void USART1_Puts(char * str)
{
	while(*str)
	{
		USART_SendData(Open_USART, *str++);
		while(USART_GetFlagStatus(Open_USART, USART_FLAG_TXE) == RESET);
	}
}

void debug(const char* fmt,...)
{
  va_list ap;
  char string[65];
	memset(string, 0, 65);

  string[64]='\0';
  va_start(ap,fmt);
  vsprintf(string,fmt,ap);
  va_end(ap);
  USART1_Puts(string);
}
