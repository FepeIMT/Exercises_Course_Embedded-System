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

/*
 * Write a program to add, subtract, multiply, and divide 2 operands using SVC handler and return the result to the
 * thread mode code and print the result. Thread mode code should pass 2 operands via the stack frame.
 *
 * Use the Next SVC numbers to decide the operation
 * 36	Addition
 * 37	Subtraction
 * 38	Multiplication
 * 39	Division
 */

#include <stdio.h>
#include <stdint.h>

/*Variable to see when the ISR SVC Handler esta activa */
int8_t SVC_Status = 0;

void SVC_Handler_c(uint32_t *pBaseStackFrame);

int32_t add_numbers(int32_t x, int32_t y)
{
	/*Variable to store the result of the add operation */
	int32_t res;

	/* Assign 36 like SVC number to add two numbers */
	__asm volatile("SVC #36");

	/* Store the value from register 0 to variable res */
	__asm volatile("MOV %0,R0": "=r"(res) ::);

	return res;

}

int32_t sub_numbers(int32_t x, int32_t y)
{
	int32_t res;

	/* Assign 37 like SVC number to substract two numbers */
	__asm volatile("SVC #37");

	/* Store the value from register 0 to variable res */
	__asm volatile("MOV %0, R0": "=r"(res) ::);

	return res;
}

int32_t mul_numbers(int32_t x, int32_t y)
{
	int32_t res;

	/* Assign 38 like SVC number to multiply two numbers */
	__asm volatile("SVC #38");

	/* Store the value from register 0 to variable res */
	__asm volatile("MOV %0, R0": "=r"(res)::);

	return res;
}

int32_t div_numbers(int32_t x, int32_t y)
{
	int32_t res;

	/* Assign 39 like SVC number to multiply two numbers */
	__asm volatile("SVC #39");

	/* Store the value from register 0 to variable res */
	__asm volatile("MOV %0, R0": "=r"(res)  ::);

	return res;
}


int main(void)
{
	int32_t res;


	res = add_numbers(40, -90);
	printf("The result of Add is %ld", res);

	res = sub_numbers(40, -90);
	printf("The result of Substraction is %ld", res);


	res = mul_numbers(40, -90);
	printf("The result of Multiplication is %ld", res);

	res = div_numbers(40, -90);
	printf("The result of division is %ld", res);



	for(;;);
}


/* Assembly naked function to access to the register values MSP and jump to SVC Handler C function  */
__attribute__( (naked) ) void SVC_Handler(void)
{

	/*Store the MSP Value in r0 */
	__asm ("MRS r0, MSP");

	/*Jump to SVC_Handler C function  */
	__asm ("B SVC_Handler_c");
}

void SVC_Handler_c(uint32_t *pBaseOfStackFrame)
{
	/*The status change to 1, only to see during debug */
	SVC_Status = 1;

	int32_t arg0, arg1, res;

	/*Assign the Return_addr */
	uint8_t *pReturn_addr = (uint8_t*)pBaseOfStackFrame[6];

	/*Compute the new Return_addr value */
	pReturn_addr -= 2;

	/*Get the svc number */
	uint8_t svc_number = *pReturn_addr;

	arg0 = pBaseOfStackFrame[0];
	arg1 = pBaseOfStackFrame[1];

	/*According with the value of SVC we have to make one operation */
	switch(svc_number)
	{
	case 36:
		res = arg0 + arg1;
		break;
	case 37:
		res = arg0 - arg1;
		break;
	case 38:
		res = arg0 * arg1;
		break;
	case 39:
		res = arg0 / arg1;
		break;
	default:
		printf("invalid svc code\n");
		break;
	}


	/*Store the res value */
	pBaseOfStackFrame[0] = res;

	SVC_Status = 0;

}

