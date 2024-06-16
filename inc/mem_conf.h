/**
  ******************************************************************************
  * File Name          : Target/mem_conf.h
  * Description        : This file provides code for the configuration
  *                      of the MEM instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MEM_CONF_H__
#define __MEM_CONF_H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx.h"
#include "stm32l0xx_nucleo_bus.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* BUS IO Instance handler */
extern  SPI_HandleTypeDef                   hspi2;

/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* Number of MEM instances */
#define MEM_INSTANCES_NBR                   1U

/* BUS IO Instance handlers */
#define hMEMSPI                             hspi2

/* BUS IO functions */
#define MEM_SPI_Init                        BSP_SPI2_Init
#define MEM_SPI_DeInit                      BSP_SPI2_DeInit
#define MEM_SPI_Recv                        BSP_SPI2_Recv
#define MEM_SPI_Send                        BSP_SPI2_Send
#define MEM_SPI_SendRecv                    BSP_SPI2_SendRecv
#define MEM_SPI_Send_DMA(td, ln)            BSP_ERROR_FEATURE_NOT_SUPPORTED
#define MEM_SPI_Recv_DMA(rd, ln)            BSP_ERROR_FEATURE_NOT_SUPPORTED
#define MEM_SPI_SendRecv_DMA(td, rd, ln)    BSP_ERROR_FEATURE_NOT_SUPPORTED

/* Memory Interface Mode */
#define MEM_INTERFACE_MODE                  MEM_INTERFACE_SPI_MODE

/* CS Pin mapping */
#define MEM_CS_GPIO_PORT                    GPIOB
#define MEM_CS_GPIO_PIN                     GPIO_PIN_6

/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* Chip Select macro definition */
#define MEM_CS_LOW()                        WRITE_REG(GPIOB->BRR, GPIO_PIN_6)
#define MEM_CS_HIGH()                       WRITE_REG(GPIOB->BSRR, GPIO_PIN_6)

/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif
#endif /* __MEM_CONF_H__ */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
