#include "usart.h"
#include <cstring>

namespace Drivers
{
    Usart::Usart(UART_HandleTypeDef *huart)
    {
        this->UsartRef = huart;

        UsartRef->Instance = USART1;
        UsartRef->Init.BaudRate = 115200;
        UsartRef->Init.WordLength = UART_WORDLENGTH_8B;
        UsartRef->Init.StopBits = UART_STOPBITS_1;
        UsartRef->Init.Parity = UART_PARITY_NONE;
        UsartRef->Init.Mode = UART_MODE_TX;
        UsartRef->Init.HwFlowCtl = UART_HWCONTROL_NONE;
        UsartRef->Init.OverSampling = UART_OVERSAMPLING_16;
        UsartRef->Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;

        if (HAL_UART_Init(UsartRef) != HAL_OK)
        {
        }
    }

    void Usart::TransmiBlocking(uint8_t *characterBufferToSend)
    {
        HAL_UART_Transmit(UsartRef, (uint8_t *)characterBufferToSend, strlen((const char *)characterBufferToSend), HAL_MAX_DELAY);
    }

    Usart::~Usart()
    {
    }
}
