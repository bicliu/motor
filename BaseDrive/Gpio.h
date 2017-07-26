#ifndef _GPIO_H_
#define _GIPO_H_

#define LED1               0
#define LED2               1
#define LED3               2
#define KEY_NUMBER         3
#define LED_FLASHING_OFF   0
#define LED_FLASHING_ON    1

#define LED1_RCC           RCC_AHB1Periph_GPIOH
#define LED1_GPIO          GPIOH
#define LED1_GPIO_PIN      GPIO_Pin_13
#define LED1_ONOFF(x)      GPIO_WriteBit(GPIOH,GPIO_Pin_13,x);
#define LED1_ON            GPIO_ResetBits(GPIOH,GPIO_Pin_13);
#define LED1_OFF           GPIO_SetBits(GPIOH,GPIO_Pin_13);

#define LED2_RCC           RCC_AHB1Periph_GPIOH
#define LED2_GPIO          GPIOH
#define LED2_GPIO_PIN      GPIO_Pin_14
#define LED2_ONOFF(x)      GPIO_WriteBit(GPIOH,GPIO_Pin_14,x);
#define LED2_ON            GPIO_ResetBits(GPIOH,GPIO_Pin_14);
#define LED2_OFF           GPIO_SetBits(GPIOH,GPIO_Pin_14);

#define LED3_RCC           RCC_AHB1Periph_GPIOH
#define LED3_GPIO          GPIOH
#define LED3_GPIO_PIN      GPIO_Pin_15
#define LED3_ONOFF(x)      GPIO_WriteBit(GPIOH,GPIO_Pin_15,x);
#define LED3_ON            GPIO_ResetBits(GPIOH,GPIO_Pin_15);
#define LED3_OFF           GPIO_SetBits(GPIOH,GPIO_Pin_15);

#define OUT_NUM 8

typedef struct{
    uint32_t     rcc;
    GPIO_TypeDef *gpio;
    uint16_t     pin;
}Gpio_Info;

//extern Gpio_Info out_array[OUT_NUM];
//extern Gpio_Info LMTBIT_array[2];

void LEDGpio_Init(void);
void LED1_Flashing(void);
//void LED_Change(uint8_t id);
void LED_SetFlashing(uint8_t id, uint8_t bit);
void LED_Flashing(void);

/*void Gpio_Init(Gpio_Info t_gpio);*/
void Gpio_out_Init(Gpio_Info t_gpio);
void Gpio_IN_Init(Gpio_Info t_gpio);
void Gpio_Writebit(Gpio_Info t_gpio, BitAction BitVal);
uint8_t Gpio_ReadBit(Gpio_Info t_gpio);

#endif
