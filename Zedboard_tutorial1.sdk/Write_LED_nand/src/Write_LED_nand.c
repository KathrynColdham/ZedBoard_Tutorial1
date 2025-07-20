
/********************************************************************************************
 * This code reads the switches that are flipped up. It treats the first 4 switches as a decimal
 *number and the second 4 switches as another decimal number. If there are any switches flipped
 *up in a section, that section is given a value "true." If no switches are flipped up, then the
 *section is given a value "false". The two sections are then put through a nand gate, and if the
 *resulting value is true, one LED will light up. If the resulting value is false, no LEDs will
 *light up.
 ********************************************************************************************/

/* Include Files */
#include "xparameters.h"
#include "xgpio.h"
#include "xstatus.h"
#include "xil_printf.h"
#include <stdio.h>
#include <stdbool.h>

/* Definitions */
#define GPIO_DEVICE_ID  XPAR_AXI_GPIO_0_DEVICE_ID	/* GPIO device that switches are connected to */
/*Set GPIO ports for switches and LEDS. We think that this corresponds to the channel coming out of the axi_gpio_0 in the block diagram that says sws_8bits and leds_8bits*/
#define LED_CHANNEL 1
#define SWITCH_CHANNEL 2
#define printf xil_printf							/* smaller, optimised printf */

XGpio Gpio;											/* GPIO Device driver instance */


int SwitchIn_LEDOut(void)
{
	int InputStatus;

	/* GPIO driver initialisation */
	InputStatus = XGpio_Initialize(&Gpio, GPIO_DEVICE_ID);


	/*Set the data direction for the switches to input. */
	/*In the function below, 0x01 is for input (0x00 would be for output).*/
	XGpio_SetDataDirection(&Gpio, SWITCH_CHANNEL, 0x01);
	int input;
	input = XGpio_DiscreteRead(&Gpio, SWITCH_CHANNEL);
	printf("\n The hexadecimal switch configuration (for up switches) is: 0x%x. ", input);


	/*Input is in decimal, so let's convert it into hexadecimal:*/
	int quotient = input;
	int hexadecimalNumber[2];
	int temp = (quotient % 16);
	hexadecimalNumber[1] = temp;
	quotient = quotient / 16;
	temp = quotient % 16;
	hexadecimalNumber[0] = temp;

	int digit1 = hexadecimalNumber[0];
	int digit2 = hexadecimalNumber[1];
	printf("Digit 1 is %d and Digit 2 is %d. ", digit1, digit2);


	bool section1;
	bool section2;

	if(digit1 == 0){section1 = false;}
	else{section1 = true;}
	printf("Section 1: %d", section1);

	if(digit2 == 0){section2 = false;}
	else{section2 = true;}
	printf("\nSection 2: %d", section2);


	int and = (section1*section2);
	int nand;

	if(and == 1){nand = 0;}
	else{nand = 1;}

	printf("\nSection 1 AND section 2 gives: %d", nand);


	int OutputStatus;

	printf("The LED configuration is: %d. ", nand);

	/* GPIO driver initialisation */
	OutputStatus = XGpio_Initialize(&Gpio, GPIO_DEVICE_ID);
	if ((InputStatus & OutputStatus) != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/*Set the data direction for the LEDs to output. */
	/*In the function below, 0x00 does this.*/
	XGpio_SetDataDirection(&Gpio, LED_CHANNEL, 0x00);
	XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, nand);
	return XST_SUCCESS; /* Should be unreachable */
}


/* Main function. */
int main(void){

	int Status;


	/* Execute the switch input. */
	Status = SwitchIn_LEDOut();
	if (Status != XST_SUCCESS) {
		xil_printf("Failed!\r\n");
	}



	return 0;

}








