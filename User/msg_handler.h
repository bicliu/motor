#ifndef _MSG_HANDLER_H_
#define _MSG_HANDLER_H_

#include "Usart.h"

#define BUF_SIZE 64
#define MSG_SPILT "#"
#define MSG_PARAMETER	"@"

extern uint8_t USART_RX_BUF[BUF_SIZE];
extern uint8_t usart_rx_len;
extern u8 USART_RX_STA;
extern uint8_t MYUSART_RX_BUF[USART_NUM][BUF_SIZE];

void msg_receive(void);
void debug_showbuf(void);
void MYMSG_receive(void);

#endif
