/******************************************************************
**	  ���������壨V1.0��
**	  Gpio�����ļ�
**
**	  ��    ̳��bbs.openmcu.com
**	  ��    ����www.openmcu.com
**	  ��    �䣺support@openmcu.com
**
**    ��    ����V1.0
**	  ��    �ߣ�FXL
**	  �������:	2012.7.20
********************************************************************/
#include "Gpio.h"

Gpio_Info led_array[KEY_NUMBER]={
    {LED1_RCC,LED1_GPIO,LED1_GPIO_PIN},
    {LED2_RCC,LED2_GPIO,LED2_GPIO_PIN},
    {LED3_RCC,LED3_GPIO,LED3_GPIO_PIN}
};

uint8_t LED1_FLASHING = 0;
uint8_t LED2_FLASHING = 0;
uint8_t LED3_FLASHING = 0;

void LEDGpio_Init(void)
{
    uint8_t i;
    GPIO_InitTypeDef  GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

    for(i=0;i<KEY_NUMBER;i++)
    {
        RCC_AHB1PeriphClockCmd( led_array[i].rcc , ENABLE);
        GPIO_InitStructure.GPIO_Pin = led_array[i].pin;
        GPIO_Init(led_array[i].gpio, &GPIO_InitStructure);
    }
		LED1_OFF;
		LED2_OFF;
		LED3_OFF;
}

void Delay(vu32 nCount)
{
	for(; nCount != 0; nCount--);
}

void LED1_Flashing(void)
{
	//GPIO_SetBits(GPIOH,GPIO_Pin_13);
	LED1_ON;
    Delay(0xfffff);
    //GPIO_ResetBits(GPIOH,GPIO_Pin_13);
	LED1_OFF;
    Delay(0xfffff);
}

void LED_Change(uint8_t id)
{
	if(id >= KEY_NUMBER)
	{
		return;
	}
	if(GPIO_ReadOutputDataBit(led_array[id].gpio, led_array[id].pin) == (uint8_t)Bit_RESET)
	{
		GPIO_SetBits(led_array[id].gpio, led_array[id].pin);
	}
	else
	{
		GPIO_ResetBits(led_array[id].gpio, led_array[id].pin);
	}
}

void LED_SetFlashing(uint8_t id, uint8_t bit)
{
	switch(id)
	{
		case LED1:
			LED1_FLASHING = bit;
			break;
		case LED2:
			LED2_FLASHING = bit;
			break;
		case LED3:
			LED3_FLASHING = bit;
			break;
		default:
			return;
	}
}

void LED_Flashing(void)
{
	if(LED1_FLASHING != 0)
	{
		LED_Change(LED1);
	}
	if(LED2_FLASHING != 0)
	{
		LED_Change(LED2);
	}
	if(LED3_FLASHING != 0)
	{
		LED_Change(LED3);
	}
}

void Gpio_Writebit(Gpio_Info t_gpio, BitAction BitVal)
{
	GPIO_WriteBit(t_gpio.gpio,t_gpio.pin, BitVal);
}

uint8_t Gpio_ReadBit(Gpio_Info t_gpio)
{
	return GPIO_ReadInputDataBit(t_gpio.gpio, t_gpio.pin);
}

void Gpio_out_Init(Gpio_Info t_gpio)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

    RCC_AHB1PeriphClockCmd( t_gpio.rcc , ENABLE);
    GPIO_InitStructure.GPIO_Pin = t_gpio.pin;
    GPIO_Init(t_gpio.gpio, &GPIO_InitStructure);
}

void Gpio_IN_Init(Gpio_Info t_gpio)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

    RCC_AHB1PeriphClockCmd( t_gpio.rcc , ENABLE);
    GPIO_InitStructure.GPIO_Pin = t_gpio.pin;
    GPIO_Init(t_gpio.gpio, &GPIO_InitStructure);
}
