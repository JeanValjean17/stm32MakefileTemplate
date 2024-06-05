#include "main.h"



uint32_t volatile sum = 0;




void SetupClock(void) 
{


    //We want to use External oscillator and PLL
    RCC->CIER |= RCC_CIER_HSERDYIE | RCC_CIER_PLLRDYIE;

    RCC->CR |= RCC_CR_CSSHSEON | RCC_CR_HSEON; 

    while ((RCC->CR & RCC_CR_HSERDY) == 0);

    FLASH->ACR |= FLASH_ACR_LATENCY;

    RCC->CFGR |= RCC_CFGR_PLLDIV2 | RCC_CFGR_PLLMUL8 | RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PPRE2_0 | RCC_CFGR_PPRE1_0 | RCC_CFGR_HPRE_0;

    RCC->CR |= RCC_CR_PLLON;

    while ((RCC->CR & RCC_CR_PLLRDY) == 0);

    RCC->CFGR |= RCC_CFGR_SW_PLL;

    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

}




void SysTick_Handler(void)
{
    
    
}

void WWDG_IRQHandler(void)
{
    
}

int main(void)
{
    
    SetupClock();
    SysTick_Config(2000);
    
    while(1)
    {
        
    }
    return 0;
}
