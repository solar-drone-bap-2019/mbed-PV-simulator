#include <mbed.h>

const float Vbat = 11;
const float Imax = 1;

DigitalOut myled(LED1);

AnalogIn D(PA_3); // Duty Cycle
AnalogOut V(PA_5); // Voltage
AnalogOut I(PA_4); // Current

int main() {
  // put your setup code here, to run once:
  float Vpv;
  float Ipv;
  float Iir=0.6;

  while(1) {
    myled = 0;
    
    // Use for simulating change in Solar Irradiance:
    /*
    if (Iir >= 0.6) {
          Iir = 0.2;
      }
    else {
          Iir = Iir+0.000001;
    } 
    */

    Vpv = (1-D)*Vbat;

    // calculate Current
    if (Vpv <= 15*Iir) {
      Ipv = Iir; // PV cell acts as current source until a certain point
    }
    else {
      Ipv = (Iir/(Vbat-15*Iir))*(Vbat - Vpv); // after that (in this simulation), I decreases linearly until it reaches 0 at 11 Volts
    }
    
    V=Vpv/Vbat; // write normalized Voltage
    I=Ipv/Imax; // write normalized Current
    
  }
}
