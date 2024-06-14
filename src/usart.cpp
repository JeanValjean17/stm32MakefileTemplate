#include "usart.h"

namespace HAL
{
    Usart::Usart(GPIO_TypeDef *usartPort, USART_TypeDef *usart, uint32_t txPin, uint32_t rxPin)
    {
        this->UsartRef = usart;

        LL_USART_InitTypeDef USART_InitStruct = {0};

        LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

        /* Peripheral clock enable */

        /**USART2 GPIO Configuration
        PA2   ------> USART2_TX
        PA3   ------> USART2_RX
        */
        GPIO_InitStruct.Pin = txPin;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
        GPIO_InitStruct.Alternate = LL_GPIO_AF_4;
        LL_GPIO_Init(usartPort, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = rxPin;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
        GPIO_InitStruct.Alternate = LL_GPIO_AF_4;
        LL_GPIO_Init(usartPort, &GPIO_InitStruct);

        /* USER CODE BEGIN USART2_Init 1 */

        /* USER CODE END USART2_Init 1 */
        USART_InitStruct.BaudRate = 115200;
        USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
        USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
        USART_InitStruct.Parity = LL_USART_PARITY_NONE;
        USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
        USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
        USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;
        LL_USART_Init(this->UsartRef, &USART_InitStruct);
        LL_USART_ConfigAsyncMode(this->UsartRef);
        LL_USART_Enable(this->UsartRef);
    }

    void Usart::TransmiBlocking(uint8_t *characterBufferToSend, uint8_t size)
    {
        LL_USART_EnableDirectionTx(this->UsartRef);

        int dataIdx = 0;

        while (dataIdx < size)
        {
            if (LL_USART_IsActiveFlag_TC(this->UsartRef))
            {
                LL_USART_TransmitData8(this->UsartRef, characterBufferToSend[dataIdx++]);
                dataIdx++;
            }            
        }
    }


    Usart::~Usart()
    {
    }

}
