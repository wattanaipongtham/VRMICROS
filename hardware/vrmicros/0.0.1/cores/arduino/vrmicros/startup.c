/**Build:
main.o :  arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 main.c -o main.o
stm32f411_startup.o : arm-none-eabi-gcc -c -mcpu=cortex-m3 -mthumb -std=gnu11 -Wl,-start-group startup.c -o startup.o
stm32_blink.elf : arm-none-eabi-gcc -nostdlib -T ldscript.ld *.o -o stm32_blink.elf -Wl,-Map=stm32_blink.map

Load:

openocd -f board/st_nucleo_f4.cfg
**/

#include <stdint.h>
int test_dfl = 0;

extern uint32_t _estack;
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

void Error_Handler(void);
void Reset_Handler(void);
int main(void);

void NMI_Handler 						    (void)__attribute__((weak,alias("Default_Handler")));
void HardFault_Handler                      (void)__attribute__((weak,alias("Default_Handler")));
void MemManage_Handler                      (void)__attribute__((weak,alias("Default_Handler")));
void BusFault_Handler                       (void)__attribute__((weak,alias("Default_Handler")));
void UsageFault_Handler                     (void)__attribute__((weak,alias("Default_Handler")));
void SVC_Handler                            (void)__attribute__((weak,alias("Default_Handler")));
void DebugMon_Handler                       (void)__attribute__((weak,alias("Default_Handler")));
void PendSV_Handler                         (void)__attribute__((weak,alias("Default_Handler")));
void SysTick_Handler                        (void)__attribute__((weak,alias("Default_Handler")));
void WWDG_IRQHandler           	            (void)__attribute__((weak,alias("Default_Handler")));
void PVD_IRQHandler            	            (void)__attribute__((weak,alias("Default_Handler")));
void TAMPER_IRQHandler         	            (void)__attribute__((weak,alias("Default_Handler")));
void RTC_IRQHandler            	            (void)__attribute__((weak,alias("Default_Handler")));
void FLASH_IRQHandler          	            (void)__attribute__((weak,alias("Default_Handler")));
void RCC_IRQHandler            	            (void)__attribute__((weak,alias("Default_Handler")));
void EXTI0_IRQHandler          	            (void)__attribute__((weak,alias("Default_Handler")));
void EXTI1_IRQHandler          	            (void)__attribute__((weak,alias("Default_Handler")));
void EXTI2_IRQHandler          	            (void)__attribute__((weak,alias("Default_Handler")));
void EXTI3_IRQHandler          	            (void)__attribute__((weak,alias("Default_Handler")));
void EXTI4_IRQHandler          	            (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_Channel1_IRQHandler  	            (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_Channel2_IRQHandler  	            (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_Channel3_IRQHandler  	            (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_Channel4_IRQHandler  	            (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_Channel5_IRQHandler  	            (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_Channel6_IRQHandler  	            (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_Channel7_IRQHandler  	            (void)__attribute__((weak,alias("Default_Handler")));
void ADC1_2_IRQHandler         	            (void)__attribute__((weak,alias("Default_Handler")));
void USB_HP_CAN1_TX_IRQHandler  	            (void)__attribute__((weak,alias("Default_Handler")));
void USB_LP_CAN1_RX0_IRQHandler 	            (void)__attribute__((weak,alias("Default_Handler")));
void CAN1_RX1_IRQHandler        	            (void)__attribute__((weak,alias("Default_Handler")));
void CAN1_SCE_IRQHandler        	            (void)__attribute__((weak,alias("Default_Handler")));
void EXTI9_5_IRQHandler        	            (void)__attribute__((weak,alias("Default_Handler")));
void TIM1_BRK_IRQHandler       	            (void)__attribute__((weak,alias("Default_Handler")));
void TIM1_UP_IRQHandler        	            (void)__attribute__((weak,alias("Default_Handler")));
void TIM1_TRG_COM_IRQHandler   	            (void)__attribute__((weak,alias("Default_Handler")));
void TIM1_CC_IRQHandler        	            (void)__attribute__((weak,alias("Default_Handler")));
void TIM2_IRQHandler           	            (void)__attribute__((weak,alias("Default_Handler")));
void TIM3_IRQHandler           	            (void)__attribute__((weak,alias("Default_Handler")));
void TIM4_IRQHandler           	            (void)__attribute__((weak,alias("Default_Handler")));
void I2C1_EV_IRQHandler        	            (void)__attribute__((weak,alias("Default_Handler")));
void I2C1_ER_IRQHandler        	            (void)__attribute__((weak,alias("Default_Handler")));
void I2C2_EV_IRQHandler        	            (void)__attribute__((weak,alias("Default_Handler")));
void I2C2_ER_IRQHandler        	            (void)__attribute__((weak,alias("Default_Handler")));
void SPI1_IRQHandler           	            (void)__attribute__((weak,alias("Default_Handler")));
void SPI2_IRQHandler           	            (void)__attribute__((weak,alias("Default_Handler")));
void USART1_IRQHandler         	            (void)__attribute__((weak,alias("Default_Handler")));
void USART2_IRQHandler         	            (void)__attribute__((weak,alias("Default_Handler")));
void USART3_IRQHandler         	            (void)__attribute__((weak,alias("Default_Handler")));
void EXTI15_10_IRQHandler      	            (void)__attribute__((weak,alias("Default_Handler")));
void RTC_Alarm_IRQHandler       	            (void)__attribute__((weak,alias("Default_Handler")));
void USBWakeUp_IRQHandler       	            (void)__attribute__((weak,alias("Default_Handler")));
void BootRAM       	            (void)__attribute__((weak,alias("Default_Handler")));

uint32_t vector_tbl[] __attribute__((section(".isr_vector_tbl")))={
	
	(uint32_t)&_estack,
	(uint32_t)&Reset_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&HardFault_Handler,
	(uint32_t)&MemManage_Handler,
	(uint32_t)&BusFault_Handler,
	(uint32_t)&UsageFault_Handler,
	0,
	0,
	0,
	0,
	(uint32_t)&SVC_Handler,
	(uint32_t)&DebugMon_Handler,
	0,
	(uint32_t)&PendSV_Handler,
	(uint32_t)&SysTick_Handler,
	(uint32_t)&WWDG_IRQHandler,          
	(uint32_t)&PVD_IRQHandler,          
	(uint32_t)&TAMPER_IRQHandler,         
	(uint32_t)&RTC_IRQHandler,            
	(uint32_t)&FLASH_IRQHandler,          
	(uint32_t)&RCC_IRQHandler,            
	(uint32_t)&EXTI0_IRQHandler,          
	(uint32_t)&EXTI1_IRQHandler,          
	(uint32_t)&EXTI2_IRQHandler,          
	(uint32_t)&EXTI3_IRQHandler,          
	(uint32_t)&EXTI4_IRQHandler,          
	(uint32_t)&DMA1_Channel1_IRQHandler,  
	(uint32_t)&DMA1_Channel2_IRQHandler,  
	(uint32_t)&DMA1_Channel3_IRQHandler,  
	(uint32_t)&DMA1_Channel4_IRQHandler,  
	(uint32_t)&DMA1_Channel5_IRQHandler,  
	(uint32_t)&DMA1_Channel6_IRQHandler,  
	(uint32_t)&DMA1_Channel7_IRQHandler,  
	(uint32_t)&ADC1_2_IRQHandler,         
	(uint32_t)&USB_HP_CAN1_TX_IRQHandler,  
	(uint32_t)&USB_LP_CAN1_RX0_IRQHandler, 
	(uint32_t)&CAN1_RX1_IRQHandler,        
	(uint32_t)&CAN1_SCE_IRQHandler,        
	(uint32_t)&EXTI9_5_IRQHandler,        
	(uint32_t)&TIM1_BRK_IRQHandler,       
	(uint32_t)&TIM1_UP_IRQHandler,       
	(uint32_t)&TIM1_TRG_COM_IRQHandler,   
	(uint32_t)&TIM1_CC_IRQHandler,        
	(uint32_t)&TIM2_IRQHandler,           
	(uint32_t)&TIM3_IRQHandler,           
	(uint32_t)&TIM4_IRQHandler,           
	(uint32_t)&I2C1_EV_IRQHandler,        
	(uint32_t)&I2C1_ER_IRQHandler,        
	(uint32_t)&I2C2_EV_IRQHandler,        
	(uint32_t)&I2C2_ER_IRQHandler,        
	(uint32_t)&SPI1_IRQHandler,           
	(uint32_t)&SPI2_IRQHandler,           
	(uint32_t)&USART1_IRQHandler,         
	(uint32_t)&USART2_IRQHandler,         
	(uint32_t)&USART3_IRQHandler,         
	(uint32_t)&EXTI15_10_IRQHandler,      
	(uint32_t)&RTC_Alarm_IRQHandler,
	(uint32_t)&USBWakeUp_IRQHandler,       
	0,
	0,
	0,
	0,
	0,
	0,
	0,             
	(uint32_t)&BootRAM
};


void Default_Handler(void)
{
	while(1)
	{
		//Do nothing...
		test_dfl = 1;
	}
}




/*Entry point*/
void Reset_Handler(void)
{
	uint32_t data_mem_size =  (uint32_t)&_edata - (uint32_t)&_sdata;
	uint32_t bss_mem_size  =   (uint32_t)&_ebss - (uint32_t)&_sbss;
	
	uint32_t *p_src_mem =  (uint32_t *)&_etext;
	uint32_t *p_dest_mem = (uint32_t *)&_sdata;
	
	for(uint32_t i = 0; i < data_mem_size; i++  )
	{
		/*Copy data section from FLASH to SRAM*/
		
		 *p_dest_mem++ = *p_src_mem++;
	}
	p_dest_mem =  (uint32_t *)&_sbss;
	
	for(uint32_t i = 0; i < bss_mem_size; i++)
	{
		 /*Set bss section to zero*/  
		*p_dest_mem++ = 0;
	}
	
	
	main();
}

void Error_Handler(void)
{
  while (1)
  {
    
  }
}