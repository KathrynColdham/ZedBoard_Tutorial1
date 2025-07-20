#include <stdio.h>
#include "platform.h"
#include "Xil_io.h"
// xil_io.h contains the interface for the general I/O component, which
// encapsulates the I/O functions for the processors that do not
// require any special I/O handling.


void delay() // function meant to take up time and delay
{
       int i;
       for(i=0;i<10000000;i++);
       }

int main()
{
    init_platform();
    unsigned char counter;
    while(1) // infinite loop
    {
       // write the value of the counter to address 0x41200000
       // this is the offset address of the AXI GPIO
       Xil_Out32(0x41200000,counter);
       counter++;
       delay();
    }
    cleanup_platform();
    return 0;
}
