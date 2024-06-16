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
        
        this->InitGpioUartPort();
        
        if (HAL_UART_Init(UsartRef) != HAL_OK)
        {
        }
    }

    void Usart::InitGpioUartPort()
    {   
        GPIO_InitTypeDef GPIO_InitStruct = {0};

        if (this->UsartRef->Instance == USART1)
        {
            /* USER CODE BEGIN USART1_MspInit 0 */

            /* USER CODE END USART1_MspInit 0 */
            /* Peripheral clock enable */
            __HAL_RCC_USART1_CLK_ENABLE();

            __HAL_RCC_GPIOA_CLK_ENABLE();
            /**USART1 GPIO Configuration
            PA9     ------> USART1_TX
            PA10     ------> USART1_RX
            */
            GPIO_InitStruct.Pin = GPIO_PIN_9 | GPIO_PIN_10;
            GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
            GPIO_InitStruct.Pull = GPIO_NOPULL;
            GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
            GPIO_InitStruct.Alternate = GPIO_AF4_USART1;
            HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

            /* USER CODE BEGIN USART1_MspInit 1 */

            /* USER CODE END USART1_MspInit 1 */
        }
        else if (this->UsartRef->Instance == USART2)
        {
            /* USER CODE BEGIN USART2_MspInit 0 */

            /* USER CODE END USART2_MspInit 0 */
            /* Peripheral clock enable */
            __HAL_RCC_USART2_CLK_ENABLE();

            __HAL_RCC_GPIOA_CLK_ENABLE();
            /**USART2 GPIO Configuration
            PA2     ------> USART2_TX
            PA3     ------> USART2_RX
            */
            GPIO_InitStruct.Pin = GPIO_PIN_2 | GPIO_PIN_3;
            GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
            GPIO_InitStruct.Pull = GPIO_NOPULL;
            GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
            GPIO_InitStruct.Alternate = GPIO_AF4_USART2;
            HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

            /* USER CODE BEGIN USART2_MspInit 1 */

            /* USER CODE END USART2_MspInit 1 */
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
