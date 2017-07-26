/****************************************Copyright (c)***************************************
**                                  
**-------------------------------------------------------------------------------------------
** File name:           relay.h
** Last modified Date:  2017-07-14
** Last Version:        V1.00
** Descriptions:        
**
**-------------------------------------------------------------------------------------------
** Created by:          LBC
** Last modified Date:  2017-07-14
** Last Version:        V1.00
** Descriptions:        
**
**-------------------------------------------------------------------------------------------
** Modified by:         
** Modified date:       
** Version:             
** Descriptions:        
**-------------------------------------------------------------------------------------------
********************************************************************************************/
#ifndef _RELAY_H_
#define _RELAY_H_

#define RELAY1      0
#define RELAY2      1
#define RELAY3      2
#define RELAY4      3
#define RELAY5      4
#define RELAY6      5
#define RELAY7      6
#define RELAY8      7
#define RELAY_NUM   8

extern Gpio_Info relay_array[RELAY_NUM];

void Relay_Init(void);
void Relay_setbit(uint8_t rid);
void Relay_resetbit(uint8_t rid);
void Relay_writebit(uint8_t rid, uint8_t bit);

#endif
