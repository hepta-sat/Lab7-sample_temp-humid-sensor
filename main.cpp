#include "mbed.h"
#include "Dht11.h"
 
Serial pc(USBTX, USBRX);
Dht11 sensor(p15);
int temp,humid;

int main() {
     while(1){
        sensor.read();
        temp = sensor.getFahrenheit();
        humid = sensor.getHumidity();
        temp = (temp - 32.0)/1.80;    // Fahrenheit --> Celsius
        pc.printf("T: %d, H: %d\r\n", temp, humid);
        wait(1.0);
    }
}