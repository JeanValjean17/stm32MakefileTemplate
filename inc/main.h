#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l0xx_ll_crs.h"
#include "stm32l0xx_ll_rcc.h"
#include "stm32l0xx_ll_bus.h"
#include "stm32l0xx_ll_system.h"
#include "stm32l0xx_ll_exti.h"
#include "stm32l0xx_ll_cortex.h"
#include "stm32l0xx_ll_utils.h"
#include "stm32l0xx_ll_pwr.h"
#include "stm32l0xx_ll_dma.h"
#include "stm32l0xx_ll_usart.h"
#include "stm32l0xx_ll_gpio.h"

#define LD2_Pin LL_GPIO_PIN_5
#define LD2_GPIO_Port GPIOA

void SystemClock_Config(void);
void SysTickSetup(void);
void ActivateClocks(void);
void Error_Handler(void);
void MX_GPIO_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
