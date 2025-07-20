
/********************************************************************************************
 * Code modified from example in Zynq Book Tutorials. It is used to light up LEDs on the
 * ZedBoard.
 *
 * This code asks the user for an decimal input of what LED they want to turn on.
 * The corresponding LED will then light up.
 ********************************************************************************************/

/* Include Files */
#include "xparameters.h"
#include "xgpio.h"
#include "xstatus.h"
#include "xil_printf.h"
#include <stdio.h>

/* Definitions */
#define GPIO_DEVICE_ID  XPAR_AXI_GPIO_0_DEVICE_ID	/* GPIO device that LEDs are connected to */
#define LED_CHANNEL 1						        /* GPIO port for LEDs. We think that this corresponds to the channel coming out of the axi_gpio_0 in the block diagram that says leds_8bits*/
#define printf xil_printf						    /* smaller, optimised printf */

XGpio Gpio;										    /* GPIO Device driver instance */

int LEDOutputExample(void)
{

	int number;
	printf("Enter the LED number in decimal that you want to turn on: ");
	scanf("%x", &number);
	printf("You entered: %d", number);

	int Status;

	printf("The LED configuration in decimal is: %d", number);

	/* GPIO driver initialisation */
	Status = XGpio_Initialize(&Gpio, GPIO_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/*Set the data direction for the LEDs to output. */
	/* In the function below, 0x00 is for output (0x01 would be for input.) */
	XGpio_SetDataDirection(&Gpio, LED_CHANNEL, 0x00);
	XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, number);
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
