#include <mbed.h>

const float Voc = 0.6;
const float Imax = 4;

DigitalOut myled(LED1);

AnalogIn D(PA_3); // Duty Cycle
AnalogOut V(PA_5); // Voltage
AnalogOut I(PA_4); // Current

// define the Serial object
Serial pc(USBTX, USBRX);

Timer t;

int main() {  
  float Vpv;
  float Ipv;
  float Iir=2;

  while(1) {
    //t.start();
    myled = 0;

    Vpv = (1-D)*Voc;

    // calculate Current
    if (Vpv <= Voc*0.7) {
      Ipv = Iir; // PV cell acts as current source until a certain point
    }
    else {
      Ipv = (Iir/(Voc*0.3))*(Voc - Vpv); // after that (in this simulation), I decreases linearly until it reaches 0 at 11 Volts
    }
    
    V=Vpv/Voc; // write normalized Voltage
    I=Ipv/Imax; // write normalized Current
    
    //pc.printf("time elapsed: %d us\r\n",static_cast<int>(t.read()*1000000));
    //t.reset();
  }
}
