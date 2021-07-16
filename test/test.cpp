/*
  Library for the Sensirion SGP40 Indoor Air Quality Sensor
  By: Paul Clark
  SparkFun Electronics
  Date: December 5th, 2020
  License: please see LICENSE.md for details
  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/17729
*/

#include "mbed.h"
#include "SparkFun_SGP40_Arduino_Library.h" // Click here to get the library: http://librarymanager/All#SparkFun_SGP40

I2C i2c(I2C_SDA , I2C_SCL );

SGP40 mySensor; //create an object of the SGP40 class

int main() {

  printf("SGP40 Example\n");

  mySensor.enableDebugging(); // Uncomment this line to print useful debug messages to Serial

  //Initialize sensor
  if (mySensor.begin(i2c) == false) {
    printf("SGP40 not detected. Check connections. Freezing...\n");
    while (1)
      ; // Do nothing more
  }

  while(true) {
    //Get the VOC Index using the default RH (50%) and T (25C)
    printf("VOC Index is: %d\n", mySensor.getVOCindex());
    thread_sleep_for(1000); //Wait 1 second - the Sensirion VOC algorithm expects a sample rate of 1Hz
  }
}