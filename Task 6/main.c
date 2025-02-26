#include <ch32v00x.h>
#include <debug.h>

#define LED1_GPIO_PORT GPIOC
#define LED2_GPIO_PORT GPIOC
#define LED3_GPIO_PORT GPIOC
#define LED4_GPIO_PORT GPIOC

#define LED1_GPIO_PIN GPIO_Pin_3
#define LED2_GPIO_PIN GPIO_Pin_4
#define LED3_GPIO_PIN GPIO_Pin_5
#define LED4_GPIO_PIN GPIO_Pin_6

#define BLINKY_CLOCK_ENABLE RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE)

void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void Delay_Init(void);
void Delay_Ms(uint32_t n);

void Fade_LED(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    for (int i = 0; i < 10; i++)
    {
        GPIO_WriteBit(GPIOx, GPIO_Pin, Bit_SET);
        Delay_Ms(i * 20);
        GPIO_WriteBit(GPIOx, GPIO_Pin, Bit_RESET);
        Delay_Ms(200 - i * 20);
    }
    for (int i = 10; i > 0; i--)
    {
        GPIO_WriteBit(GPIOx, GPIO_Pin, Bit_SET);
        Delay_Ms(i * 20);
        GPIO_WriteBit(GPIOx, GPIO_Pin, Bit_RESET);
        Delay_Ms(200 - i * 20);
    }
}

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();

    GPIO_InitTypeDef GPIO_InitStructure = {0};
    BLINKY_CLOCK_ENABLE;
    GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN | LED2_GPIO_PIN | LED3_GPIO_PIN | LED4_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    while (1)
    {
        // Forward fading sequence
        Fade_LED(LED1_GPIO_PORT, LED1_GPIO_PIN);
        Fade_LED(LED2_GPIO_PORT, LED2_GPIO_PIN);
        Fade_LED(LED3_GPIO_PORT, LED3_GPIO_PIN);
        Fade_LED(LED4_GPIO_PORT, LED4_GPIO_PIN);

        // Reverse fading sequence
        Fade_LED(LED4_GPIO_PORT, LED4_GPIO_PIN);
        Fade_LED(LED3_GPIO_PORT, LED3_GPIO_PIN);
        Fade_LED(LED2_GPIO_PORT, LED2_GPIO_PIN);
        Fade_LED(LED1_GPIO_PORT, LED1_GPIO_PIN);
    }
}

void NMI_Handler(void) {}
void HardFault_Handler(void)
{
    while (1)
    {
    }
}
