/* Includes ------------------------------------------------------------------*/
#include "Usart.h"
#include "msg_handler.h"
#include <stdarg.h>
#include <string.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define USART_INTERRUPT_PRIORITY   0
#define USART_INTERRUPT_SUB_PRI    3

#define MYUSART_SENDBUF_SIZE 1024
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
USART_Para usart_array[USART_NUM];

uint8_t myusart_txbuf_head[USART_NUM] = {0,0,0};
uint8_t myusart_txbuf_tail[USART_NUM] = {0,0,0};
char myusart_sendbuf[USART_NUM][MYUSART_SENDBUF_SIZE];
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void MYUSART_Puts(uint8_t i, char * str);
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
  //USART1_Puts(string);
	MYUSART_Puts(USART_1, string);
}

void MYUSART_ParaSet(void)
{
	/*usart 1*/
	usart_array[USART_1].USARTx = USART1_NAME;
	usart_array[USART_1].IsAPB1 = USART1_ISAPB1;
	usart_array[USART_1].clock = USART1_CLK;
	
	usart_array[USART_1].TX_pin = USART1_TX_PIN;
	usart_array[USART_1].TX_Type = USART1_TX_GPIO_PORT;
	usart_array[USART_1].TX_clk = USART1_TX_GPIO_CLK;
	usart_array[USART_1].TX_source = USART1_TX_SOURCE;
	usart_array[USART_1].TX_AF = USART1_TX_AF;
	
	usart_array[USART_1].RX_pin = USART1_RX_PIN;
	usart_array[USART_1].RX_Type = USART1_RX_GPIO_PORT;
	usart_array[USART_1].RX_clk = USART1_RX_GPIO_CLK;
	usart_array[USART_1].RX_source = USART1_RX_SOURCE;
	usart_array[USART_1].RX_AF = USART1_RX_AF;
	
	usart_array[USART_1].IRQn = USART1_IRQn;
	usart_array[USART_1].RX_STATE = 0;
	
	/*usart 2*/
	usart_array[USART_2].USARTx = USART2_NAME;
	usart_array[USART_2].IsAPB1 = USART2_ISAPB1;
	usart_array[USART_2].clock = USART2_CLK;
	
	usart_array[USART_2].TX_pin = USART2_TX_PIN;
	usart_array[USART_2].TX_Type = USART2_TX_GPIO_PORT;
	usart_array[USART_2].TX_clk = USART2_TX_GPIO_CLK;
	usart_array[USART_2].TX_source = USART2_TX_SOURCE;
	usart_array[USART_2].TX_AF = USART2_TX_AF;
	
	usart_array[USART_2].RX_pin = USART2_RX_PIN;
	usart_array[USART_2].RX_Type = USART2_RX_GPIO_PORT;
	usart_array[USART_2].RX_clk = USART2_RX_GPIO_CLK;
	usart_array[USART_2].RX_source = USART2_RX_SOURCE;
	usart_array[USART_2].RX_AF = USART2_RX_AF;
	
	usart_array[USART_2].IRQn = USART2_IRQn;
	usart_array[USART_2].RX_STATE = 0;
	
	/*usart 6*/
	usart_array[USART_6].USARTx = USART6_NAME;
	usart_array[USART_6].IsAPB1 = USART6_ISAPB1;
	usart_array[USART_6].clock = USART6_CLK;
	
	usart_array[USART_6].TX_pin = USART6_TX_PIN;
	usart_array[USART_6].TX_Type = USART6_TX_GPIO_PORT;
	usart_array[USART_6].TX_clk = USART6_TX_GPIO_CLK;
	usart_array[USART_6].TX_source = USART6_TX_SOURCE;
	usart_array[USART_6].TX_AF = USART6_TX_AF;
	
	usart_array[USART_6].RX_pin = USART6_RX_PIN;
	usart_array[USART_6].RX_Type = USART6_RX_GPIO_PORT;
	usart_array[USART_6].RX_clk = USART6_RX_GPIO_CLK;
	usart_array[USART_6].RX_source = USART6_RX_SOURCE;
	usart_array[USART_6].RX_AF = USART6_RX_AF;
	
	usart_array[USART_6].IRQn = USART6_IRQn;
	usart_array[USART_6].RX_STATE = 0;
}

void MYUSART_Init(void)
{
	uint8_t i = 0;
	GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	for(i = 0; i < USART_NUM; i++)
	{
		RCC_AHB1PeriphClockCmd(usart_array[i].TX_clk,ENABLE);
		RCC_AHB1PeriphClockCmd(usart_array[i].RX_clk,ENABLE);
		if(usart_array[i].IsAPB1 == 0)
		{
			RCC_APB2PeriphClockCmd(usart_array[i].clock,ENABLE);
		}
		else
		{
			RCC_APB1PeriphClockCmd(usart_array[i].clock,ENABLE);
		}
		GPIO_PinAFConfig(usart_array[i].TX_Type, usart_array[i].TX_source, usart_array[i].TX_AF);
		GPIO_PinAFConfig(usart_array[i].RX_Type, usart_array[i].RX_source, usart_array[i].RX_AF);

		GPIO_InitStructure.GPIO_Pin = usart_array[i].TX_pin;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
		GPIO_Init(usart_array[i].TX_Type, &GPIO_InitStructure);

		GPIO_InitStructure.GPIO_Pin = usart_array[i].RX_pin;
		GPIO_Init(usart_array[i].RX_Type, &GPIO_InitStructure);

		USART_InitStructure.USART_BaudRate = DEFAULT_BAUD_GSM;
		USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		USART_InitStructure.USART_StopBits = USART_StopBits_1;
		USART_InitStructure.USART_Parity = USART_Parity_No;
		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
		USART_Init(usart_array[i].USARTx, &USART_InitStructure);
		
		//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
		NVIC_InitStructure.NVIC_IRQChannel = usart_array[i].IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = USART_INTERRUPT_PRIORITY;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = USART_INTERRUPT_SUB_PRI;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);
		
		/* Enable the USARTx Interrupt */
		USART_ITConfig(usart_array[i].USARTx,USART_IT_RXNE,ENABLE);
		
		USART_Cmd(usart_array[i].USARTx, ENABLE);
		USART_ClearFlag(usart_array[i].USARTx, USART_FLAG_RXNE);
	}
}

void MYUSART_IT_Handler(uint8_t i)
{
	u8 Res;
  if(USART_GetITStatus(usart_array[i].USARTx, USART_IT_RXNE) != RESET)
  {
		Res = USART_ReceiveData(usart_array[i].USARTx);
		if((usart_array[i].RX_STATE&0x80)==0)
		{
			if(usart_array[i].RX_STATE&0x40)
			{
				if(Res!=0x0a)
					usart_array[i].RX_STATE=0;
				else
					usart_array[i].RX_STATE|=0x80;
			}
			else
			{
				if(Res==0x0d)
					usart_array[i].RX_STATE|=0x40;
				else
				{
					MYUSART_RX_BUF[i][usart_array[i].RX_STATE&0X3F]=Res;
					usart_array[i].RX_STATE++;
					if(usart_array[i].RX_STATE>63)
						usart_array[i].RX_STATE=0;
				}
			}
		}
  }
}

void MYUSART_Puts(uint8_t i, char * str)
{
	while(*str)
	{
		USART_SendData(usart_array[i].USARTx, *str++);
		while(USART_GetFlagStatus(usart_array[i].USARTx, USART_FLAG_TXE) == RESET);
	}
}

void MYUSART_ToBuf(uint8_t i, char * str)
{
	uint8_t buftail = myusart_txbuf_tail[i];
	while(*str)
	{
		buftail++;
		if(buftail == (uint8_t)MYUSART_SENDBUF_SIZE)
			buftail = 0;
		
		if(buftail == myusart_txbuf_head[i])
			return;
		
		myusart_sendbuf[i][buftail] = *str++;
	}
	myusart_txbuf_tail[i] = buftail;
}

void MYUSART_Send(uint8_t i, const char* fmt,...)
{
  va_list ap;
  char string[65];
	memset(string, 0, 65);

  string[64]='\0';
  va_start(ap,fmt);
  vsprintf(string,fmt,ap);
  va_end(ap);
  //MYUSART_Puts(i, string);
	MYUSART_ToBuf(i, string);
}

void MYUSART_SendBuf(uint8_t i)
{
	char string[64];
	memset(string, 0, 64);
}
