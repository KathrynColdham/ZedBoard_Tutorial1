
 
/********************************************************************************************
 * This file contains an example of using the GPIO driver to provide communication between
 * the Zynq Processing System (PS) and the AXI GPIO block implemented in the Zynq Programmable
 * Logic (PL). The AXI GPIO is connected to the LEDs on the ZedBoard.
 *
 * The provided code demonstrates how to use the GPIO driver to write to the memory mapped AXI
 * GPIO block, which in turn controls the LEDs.
 ********************************************************************************************/

/* Include Files */
#include "xparameters.h"
#include "xgpio.h"
#include "xstatus.h"
#include "xil_printf.h"
#include <stdio.h>

/* Definitions */
#define GPIO_DEVICE_ID  XPAR_AXI_GPIO_0_DEVICE_ID	/* GPIO device that LEDs are connected to */
#define LED 0xC3						        /* Initial LED value - XX0000XX */  //0xC3
#define LED_DELAY 10000000							/* Software delay length */
#define LED_CHANNEL 1								/* GPIO port for LEDs */
#define printf xil_printf							/* smaller, optimised printf */

XGpio Gpio;											/* GPIO Device driver instance */

int LEDOutputExample(void)
{

	int number;
	printf("Enter the LED number that you want to turn on: ");
	scanf("%x", &number);
	printf("You entered: %x", number);

	int Status;
	int led = LED; /* Hold current LED value. Initialise to LED definition */

	led = number;
	printf("The LED configuration is:%x", led);

	/* GPIO driver initialisation */
	Status = XGpio_Initialize(&Gpio, GPIO_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/*Set the direction for the LEDs to output. */
	XGpio_SetDataDirection(&Gpio, LED_CHANNEL, 0x00);
	XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, led);
	return XST_SUCCESS; /* Should be unreachable */
}

/* Main function. */
int main(void){

	int Status;

	/* Execute the LED output. */
	Status = LEDOutputExample();
	if (Status != XST_SUCCESS) {
		xil_printf("GPIO output to the LEDs failed!\r\n");
	}

	return 0;
}

