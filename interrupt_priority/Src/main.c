/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define IRQNO_TIMER2	28
#define IRQNO_I2C1		31

#include <stdint.h>
#include <stdio.h>

uint32_t *pNVIC_IPRBase = (uint32_t*)0xE000E400;
uint32_t *pNVIC_ISERBase = (uint32_t*)0xE000E100;
uint32_t *pNVIC_ISPRBase = (uint32_t*)0xE000E200;


void configure_priority_for_irqs(uint8_t irq_no)
{

}

int main(void)
{
	//1.- Lets Configure the priority for the peripherals
	configure_priority_for_irqs(IRQNO_TIMER2);
	configure_priority_for_irqs(IRQNO_I2C1);

	//2.- Set the interrupt pending bit in the NVIC PR


	//3. Enable the IRQs in NVIC ISER


	for(;;);
}


void TIM2_IRQHandler(void)
{
	printf("[TIM2_IRQHandler] \n");
}


void I2C1_EV_IRQHandler(void)
{
	printf("[I2C1_EV_IRQHandler] \n");
}



