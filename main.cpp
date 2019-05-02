#include "mbed.h"

// Initialize a pins to perform analog input and digital output fucntions
AnalogIn   loudness(A0);
AnalogIn   lumin(A1);
DigitalOut dout(LED1);

int main(void)
{
    while (1) {
        // test the voltage on the initialized analog pin
        //  and if greater than 0.3 * VCC set the digital pin
        //  to a logic 1 otherwise a logic 0
        if(lumin > 0.3f) {
            dout = 1;
        } else {
            dout = 0;
        }
        
        // print the percentage and 16 bit normalized values
        printf("loudness: %3.3f%%", loudness.read()*100.0f);
        printf("    ");
        printf("light: %3.3f%%\r\n", lumin.read()*100.0f);
        wait(0.2f);
    }
}
