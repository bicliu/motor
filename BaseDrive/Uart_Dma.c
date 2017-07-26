/* Includes ------------------------------------------------------------------*/
#include "Uart_Dma.h"
#include "msg_handler.h"
#include <stdarg.h>
#include <string.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t DEFAULT_BAUD = 115200;
uint8_t SendBuff[BUF_SIZE];
uint16_t UART1_ReceiveSize;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


void uart_init(void)
{  
    GPIO_InitTypeDef GPIO_InitStructure;  
    USART_InitTypeDef USART_InitStructure;  
    NVIC_InitTypeDef NVIC_InitStructure;  
    DMA_InitTypeDef  DMA_InitStructure;  
  
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2,ENABLE);
  
    GPIO_PinAFConfig(GPIOB,GPIO_PinSource6,GPIO_AF_USART1);
    GPIO_PinAFConfig(GPIOB,GPIO_PinSource7,GPIO_AF_USART1);
  
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOB,&GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
		GPIO_Init(GPIOB,&GPIO_InitStructure);
  
    USART_InitStructure.USART_BaudRate = DEFAULT_BAUD;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART1, &USART_InitStructure);
  
    USART_Cmd(USART1, ENABLE);
  
    //USART_ClearFlag(USART1, USART_FLAG_TC);  
      
    USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);
  
    //Usart1 NVIC
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
  
    USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);
    USART_DMACmd(USART1,USART_DMAReq_Rx,ENABLE);
  
  
    //****************************UART1 tx
    DMA_DeInit(DMA2_Stream7);  
    while (DMA_GetCmdStatus(DMA2_Stream7) != DISABLE);
    /* DMA Stream */  
    DMA_InitStructure.DMA_Channel = DMA_Channel_4;
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)&USART1->DR;
    DMA_InitStructure.DMA_Memory0BaseAddr = (u32)SendBuff;
    DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
    DMA_InitStructure.DMA_BufferSize = BUF_SIZE;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;           
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;  
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
    DMA_Init(DMA2_Stream7, &DMA_InitStructure);
    //DMA NVIC    
    NVIC_InitStructure.NVIC_IRQChannel = DMA2_Stream7_IRQn;    
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;    
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;    
    NVIC_Init(&NVIC_InitStructure);    
    DMA_ITConfig(DMA2_Stream7,DMA_IT_TC,ENABLE);  
  
    //****************************UART1 RX
    DMA_DeInit(DMA2_Stream5);  
    while (DMA_GetCmdStatus(DMA2_Stream5) != DISABLE);
    /* DMA Stream */  
    DMA_InitStructure.DMA_Channel = DMA_Channel_4;
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)&USART1->DR;
    DMA_InitStructure.DMA_Memory0BaseAddr = (u32)USART_RX_BUF;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory; 
    DMA_InitStructure.DMA_BufferSize = BUF_SIZE;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;           
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;  
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
    DMA_Init(DMA2_Stream5, &DMA_InitStructure);
    //DMA NVIC    
    NVIC_InitStructure.NVIC_IRQChannel = DMA2_Stream5_IRQn;    
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;    
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;    
    NVIC_Init(&NVIC_InitStructure);    
    DMA_Cmd(DMA2_Stream5, ENABLE);
      
    DMA_ITConfig(DMA2_Stream5,DMA_IT_TC,ENABLE);  
      
}

void DmaSendDataProc(DMA_Stream_TypeDef *DMA_Streamx,u16 ndtr)  
{
	DMA_Cmd(DMA_Streamx, DISABLE);
	while (DMA_GetCmdStatus(DMA_Streamx) != DISABLE)
	{
	}
	DMA_SetCurrDataCounter(DMA_Streamx,ndtr);
	DMA_Cmd(DMA_Streamx, ENABLE);
}

void SendBytesInfoProc(u8* pSendInfo, u16 nSendCount)  
{
	u16 i = 0;
	u8 *pBuf = NULL;
	
	pBuf = SendBuff;
	
	for (i=0; i<nSendCount; i++)
	{
		*pBuf++ = pSendInfo[i];
	}
	
	DmaSendDataProc(DMA2_Stream7,nSendCount);
}

void dma_debug(const char* fmt,...)
{
  va_list ap;
  char string[65];
	memset(string, 0, 65);

  string[64]='\0';
  va_start(ap,fmt);
  vsprintf(string,fmt,ap);
  va_end(ap);
  SendBytesInfoProc((u8 *)string,strlen(string));
}

void DMA2_Stream7_IRQHandler(void)  
{
	if(DMA_GetFlagStatus(DMA2_Stream7,DMA_FLAG_TCIF7)!=RESET)
	{
		DMA_ClearFlag(DMA2_Stream7,DMA_FLAG_TCIF7);
	}  
}


void DMA2_Stream5_IRQHandler(void)  
{
	if(DMA_GetFlagStatus(DMA2_Stream5,DMA_FLAG_TCIF5)!=RESET)
	{
		DMA_Cmd(DMA2_Stream5, DISABLE);
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
}
