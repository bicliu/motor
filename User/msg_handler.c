/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "string.h"
#include <stdlib.h>
#include "Gpio.h"
#include "relay.h"
#include "motor.h"
#include "msg_handler.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
uint8_t USART_RX_BUF[BUF_SIZE];
uint8_t usart_rx_len = 0;
char cmd_buf[BUF_SIZE]; //copy the cmd
uint8_t USART_RX_STA=0;
uint8_t MYUSART_RX_BUF[USART_NUM][BUF_SIZE];
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

void cmd_process(void)
{
	char *p=NULL, *ptmp;
	uint8_t id = 0;
	uint8_t bit = 0;
	uint16_t value = 0;
	uint32_t i_postion = 0;
	uint16_t i_initsp = 0;
	uint16_t i_sp = 0;
	uint16_t i_spup = 0;
	/*uint8_t i_pulse = 0;
	uint8_t i_lmtp = 0;
	uint8_t i_lmtn = 0;
	uint8_t i_stop0 = 0;
	uint8_t i_stop1 = 0;
	uint8_t i_level = 0;*/
	//int num;
	//char dirc = 0;
	//debug("recive msg:%s\r\n", cmd_buf);
	p = strtok(cmd_buf, MSG_SPILT);
	//pfun = p;
	if(p)
	{
		if(0 == strcmp(p,"CMD_STOP"))//CMD_STOP#ID@XX
		{
			p = strtok(NULL, MSG_SPILT);
			if(p)//"ID@01"
			{
				id = (uint8_t)strtol((p+3), &ptmp,10);
				if(id > MOTOR_NUM && 0 == id)
				{
					debug("TIM%d is not exist!\r\n", id);
					//dma_debug("TIM%d is not exist!\r\n", id);
					return;
				}
				Motor_Stop((uint8_t)(id - 1));
				debug("TIM%d stop!\r\n", id);
				//dma_debug("TIM%d stop!\r\n", id);
				return;
			}
		}
		else if(0 == strcmp(p,"CMD_RUN"))//CMD_RUN#ID@XX#DESTI@XX#INITSP@XX#SP@XX@SPUP@XX@CLKW@XX
		{
			p = strtok(NULL, MSG_SPILT);
			if(p)//"ID@01"
			{
				id = (uint8_t)strtol((p+3), &ptmp,10);
				if(id > MOTOR_NUM && 0 == id)
				{
					debug("MOTOR%d is not exist!\r\n", id);
					//dma_debug("TIM%d is not exist!\r\n", id);
					return;
				}
				p = strtok(NULL, MSG_SPILT);
				if(p)//DESTI@XX
				{
					i_postion = (uint32_t)strtol((p+6), &ptmp,10);
					p = strtok(NULL, MSG_SPILT);
					if(p)//INITSP@XX
					{
						i_initsp = (uint16_t)strtol((p+7), &ptmp,10);
						p = strtok(NULL, MSG_SPILT);
						if(p)//SP@XX
						{
							i_sp = (uint16_t)strtol((p+3), &ptmp,10);
							p = strtok(NULL, MSG_SPILT);
							if(p)//SPUP@XX
							{
								i_spup = (uint16_t)strtol((p+5), &ptmp,10);
								p = strtok(NULL, MSG_SPILT);
								if(p)//CLKW@XX
								{
									bit = (uint8_t)strtol((p+5), &ptmp,10);
									Motor_set_clockwise((uint8_t)(id - 1), bit);
									Motor_set_setpNum((uint8_t)(id - 1), i_postion);
									Motor_setFrequency((uint8_t)(id - 1), i_initsp,i_sp,i_spup);
									Motor_Run((uint8_t)(id - 1));
									debug("Motor %d start!\r\n", id);
									//dma_debug("TIM%d start!\r\n", id);
									return;
								}
							}
						}
					}
				}
				//TIM_Config(timer_array[id - 1]);
				//Timer_Init(timer_array[id - 1]);
			}
		}
		else if(0 == strcmp(p,"TIM_SET"))//CMD_SET#ID@XX@PULSE@XX#LMTP@XX#LMTN@XX#STOP0@XX#STOP1@XX#LEVEL@XX
		{
			p = strtok(NULL, MSG_SPILT);
			if(p)//"ID@01"
			{
				id = (uint8_t)strtol((p+3), &ptmp,10);
				if(id > MOTOR_NUM && 0 == id)
				{
					debug("TIM%d is not exist!\r\n", id);
					//dma_debug("TIM%d is not exist!\r\n", id);
					return;
				}
				p = strtok(NULL, MSG_SPILT);
				if(p)//TIMES@10000
				{
					value = (uint16_t)strtol((p+6), &ptmp,10);
					//Timer_set_step_num((uint8_t)(id - 1), value);
					debug("Set TIM%d pwm times = %d\r\n", id, value);
					//dma_debug("Set TIM%d pwm times = %d\r\n", id, value);
					return;
				}
			}
		}
		else if(0 == strcmp(p,"CMD_RELAY"))//CMD_RELAY#ID@XX#BIT@XX
		{
			p = strtok(NULL, MSG_SPILT);
			if(p)//"ID@01"
			{
				id = (uint8_t)strtol((p+3), &ptmp,10);
				if(id > RELAY_NUM && 0 == id)
				{
					debug("RELAY%d is not exist!\r\n", id);
					//dma_debug("TIM%d is not exist!\r\n", id);
					return;
				}
				p = strtok(NULL, MSG_SPILT);
				if(p)//BIT@1
				{
					bit = (uint8_t)strtol((p+4), &ptmp,10);
					//Timer_set_step_num((uint8_t)(id - 1), value);
					Relay_writebit((uint8_t)(id - 1), bit);
					debug("Set Relay%d bit = %d\r\n", id, bit);
					//dma_debug("Set TIM%d pwm times = %d\r\n", id, value);
					return;
				}
			}
		}
	}
	//USART1_Puts(cmd_buf);
	debug("!unknow msg: ");
	debug_showbuf();
	//dma_debug("!unknow msg: %s\r\n",cmd_buf);
	return;
}

void debug_showbuf(void)
{
	u8 i;
	for(i = 0; i < BUF_SIZE; i++)
	{
		debug("%c", cmd_buf[i]);
	}
	debug("\r\n");
}

void msg_receive(void)
{
	u8 t;
	u8 len;	
	if(USART_RX_STA/*usart_array[USART_1].RX_STATE*/&0x80)
	{					   
		len=USART_RX_STA/*usart_array[USART_1].RX_STATE*/&0x3f;//get receive data length
		memset(cmd_buf, 0, BUF_SIZE);
		
		for(t=0;t<len;t++) //for USART_RX_BUF may not be string
		{
			cmd_buf[t] = (uint8_t)USART_RX_BUF[t];
		}
		//DEBUG("\ninput : %s",cmd_buf);
		USART_RX_STA/*usart_array[USART_1].RX_STATE*/=0;
		cmd_process();
		//LED1_OFF;
	}
}

/*void msg_dmarx(uint16_t len)
{
	u8 t;
	memset(cmd_buf, 0, BUF_SIZE);
	for(t=0;t<len;t++) //for USART_RX_BUF may not be string
	{
		cmd_buf[t] = (uint8_t)USART_RX_BUF[t];
	}
	cmd_process();
}*/

void MYMSG_receive(void)
{
	u8 t;
	u8 len;	
	uint8_t i = 0;
	for(i = 0; i < USART_NUM; i++)
	{
		if(usart_array[i].RX_STATE&0x80)
		{					   
			len=usart_array[i].RX_STATE&0x3f;//get receive data length
			memset(cmd_buf, 0, BUF_SIZE);
		
			for(t=0;t<len;t++) //for USART_RX_BUF may not be string
			{
				cmd_buf[t] = (uint8_t)MYUSART_RX_BUF[i][t];
			}
			//DEBUG("\ninput : %s",cmd_buf);
			usart_array[i].RX_STATE=0;
			cmd_process();
		}
	}
}
