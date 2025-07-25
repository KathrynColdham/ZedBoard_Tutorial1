# ZedBoard_Tutorial1

## LEDs and switches

* [Read_Switches.c](https://github.com/KathrynColdham/ZedBoard_Tutorial1/blob/548563cc62d26386e387b62873c570deb1cfc870/Zedboard_tutorial1.sdk/Read_Switches/src/Read_Switches.c) = reads which switches were on and prints the result on the terminal
  
* [Write_LEDS.c](https://github.com/KathrynColdham/ZedBoard_Tutorial1/blob/548563cc62d26386e387b62873c570deb1cfc870/Zedboard_tutorial1.sdk/Write_LED/src/Write_LED.c) = writes to the LEDs so, when the user uses the command line to specify which LED configuration they want turned on, these LEDs would light up.

* [ReadSwitch_WriteLED.c](https://github.com/KathrynColdham/ZedBoard_Tutorial1/blob/548563cc62d26386e387b62873c570deb1cfc870/Zedboard_tutorial1.sdk/ReadSwitch_WriteLED/src/ReadSwitch_WriteLED.c) = reads the switch configuration that was turned on and then lights up the corresponding LEDs

* [Write_LED_Addition.c](https://github.com/KathrynColdham/ZedBoard_Tutorial1/blob/09159f07987775ab375a9417b9294fe29ea94c9f/Zedboard_tutorial1.sdk/Write_LED_Addition/src/Write_LED_Addition.c) = reads the switch configuration that is on in hexadecimal format, computes the addition and displays the result using the LEDs in binary format

* [Write_LED_Multiplication.c](https://github.com/KathrynColdham/ZedBoard_Tutorial1/blob/548563cc62d26386e387b62873c570deb1cfc870/Zedboard_tutorial1.sdk/Write_LED_Multiplication/src/Write_LED_Multiplication.c) = reads the switch configuration that is on in hexadecimal
format, computes the multiplication and displays the result using the LEDs in binary
format

* [Write_LED_and.c](https://github.com/KathrynColdham/ZedBoard_Tutorial1/blob/548563cc62d26386e387b62873c570deb1cfc870/Zedboard_tutorial1.sdk/Write_LED_and/src/Write_LED_and.c) = reads the switches that are flipped up. It treats the first 4 switches
as a decimal number and the second 4 switches as another decimal number. If there
are any switches flipped up in a section, that section is given a value "true." If no
switches are flipped up, then the section is given a value "false". The two sections
are then put through an and gate, and if the resulting value is true, one LED will light
up. If the resulting value is false, no LEDs will light up.

* [Write_LED_nand.c ](https://github.com/KathrynColdham/ZedBoard_Tutorial1/tree/548563cc62d26386e387b62873c570deb1cfc870/Zedboard_tutorial1.sdk/Write_LED_nand/src)= same as above but with a nand gate
  
* [Write_LED_nor.c ](https://github.com/KathrynColdham/ZedBoard_Tutorial1/tree/548563cc62d26386e387b62873c570deb1cfc870/Zedboard_tutorial1.sdk/Write_LED_nor/src)= same as above but with a nor gate
  
* [Write_LED_or.c](https://github.com/KathrynColdham/ZedBoard_Tutorial1/tree/548563cc62d26386e387b62873c570deb1cfc870/Zedboard_tutorial1.sdk/Write_LED_or/src) = same as above but with an or gate
  
  
## Coincidence unit work

*4inputs_with_ANDgate.c = computes the output for 4 inputs going into an AND gate.

*veto_driver_OR_gate.c = computes the OR gate output when inputs from the veto and
driver are used
