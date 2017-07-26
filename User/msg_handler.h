#ifndef _MSG_HANDLER_H_
#define _MSG_HANDLER_H_

#define BUF_SIZE 64
#define MSG_SPILT "#"
#define MSG_PARAMETER	"@"

extern uint8_t USART_RX_BUF[BUF_SIZE];
extern uint8_t usart_rx_len;
extern u8 USART_RX_STA;

void msg_receive(void);
void msg_dmarx(uint16_t len);
void debug_showbuf(void);

#endif
