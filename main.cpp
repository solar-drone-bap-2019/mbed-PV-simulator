#include <mbed.h>

const float Vbat = 11.1;
const float Imax = 1;

DigitalOut myled(LED1);

AnalogIn D(PA_6); // Duty Cycle
AnalogOut V(PA_4); // Voltage
AnalogOut I(PA_5); // Current

int main() {
  // put your setup code here, to run once:
  float Vpv;
  float Ipv;

  while(1) {
    
    myled = 1;
    
    // put your main code here, to run repeatedly:

    Vpv = (1-D)*Vbat;

    // calculate Current
    if (Vpv > 9) {
      Ipv = 0.6; // PV cell acts as current source until a certain point
    }
    else {
      Ipv = 3.3-0.3*Vpv; // after that (in this simulation), I decreases linearly until it reaches 0 at 11 Volts
    }
    
    V=Vpv/Vbat; // write normalized Voltage
    I=Ipv/Imax; // write normalized Current
    
  }
}
