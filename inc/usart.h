#ifndef __USART_H
#define __USART_H

#include "stm32l0xx_hal.h"

namespace Drivers
{

    class Usart
    {
    public:
        Usart(UART_HandleTypeDef *huart);
        ~Usart();
        void TransmiBlocking(uint8_t *characterBufferToSend);

    private:
        UART_HandleTypeDef *UsartRef;
        void InitGpioUartPort(void);
    };
}

#endif /*__USART_H*/
