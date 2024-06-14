#ifndef __USART_H
#define __USART_H

#include "stm32l0xx_ll_usart.h"
#include "stm32l0xx_ll_gpio.h"

namespace HAL
{
    class Usart
    {
    public:
        Usart(GPIO_TypeDef *usartPort, USART_TypeDef *usart, uint32_t txPin, uint32_t rxPin);
        ~Usart();
        void TransmiBlocking(uint8_t *characterBufferToSend, uint8_t size);

    private:
        USART_TypeDef *UsartRef;
        void SendCharacter(uint8_t character);
    };
}

#endif /*__USART_H*/
