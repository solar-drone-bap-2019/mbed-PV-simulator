#include "mbed.h"
#include "MPPT.h"

/*
Tracks the maximum power point for multiple solar arrays (solar cell groups).
*/

DigitalOut myled(LED1);

// Pins for tracking group 1
#define I1 PA_0 // Current sensor
#define V1 PA_1 // Voltage sensor
#define PWM1 PA_3 // Pulse width modulation output
#define D1 PA_4 // Duty Cycle


MPPT MPPT1(I1,V1,PWM1,D1); // Create Maximum Power Point Tracker 1


int main() {
    while(1) {
        myled = 1;

        MPPT1.PerturbObserve(); // Execute the P&O algorithm for tracking group 1

        //MPPT doesn't need to happen very fast    
        wait_ms(10); // Track the power point every 10 ms
    }
}
