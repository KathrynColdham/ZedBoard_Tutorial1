
/********************************************************************************************
 * The provided code demonstrates how to use the GPIO driver to read the values of switches.
 * The output is in decimal.
 ********************************************************************************************/

/* Include Files */
#include "xparameters.h"
#include "xgpio.h"
#include "xstatus.h"
#include "xil_printf.h"
#include <stdio.h>

/* Definitions */
#define GPIO_DEVICE_ID  XPAR_AXI_GPIO_0_DEVICE_ID	/* GPIO device that switches are connected to */
#define SWITCH_CHANNEL 2						    /* GPIO port for switches. This corresponds to the channel coming out of the axi_gpio_0 in the block diagram that says sws_8bits*/
#define printf xil_printf							/* smaller, optimised printf */

XGpio Gpio;											/* GPIO Device driver instance */

int LEDInputExample(void)
{
	int Status;

	/* GPIO driver initialisation */
	Status = XGpio_Initialize(&Gpio, GPIO_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/*Set the data direction for the LEDs to input. */
	/*In the function below, 0x01 is for input (0x00 would be for input).*/
	XGpio_SetDataDirection(&Gpio, SWITCH_CHANNEL, 0x01);
	int output;
	output = XGpio_DiscreteRead(&Gpio, SWITCH_CHANNEL);
	printf("Switches that are switched up (in decimal): %d", output);
	return XST_SUCCESS; /* Should be unreachable */
}

/* Main function. */
int main(void){

	int Status;

	/* Execute the LED output. */
	Status = LEDInputExample();
	if (Status != XST_SUCCESS) {
		xil_printf("GPIO output to the LEDs failed!\r\n");
	}

	return 0;
}
