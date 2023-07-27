/* * * * * * * * * * * * * * * * * * * * *
*
*
*
*
*
*
*
*
* * * * * * * * * * * * * * * * * * * * */
#include <Arduino.h>

#include "util/shift_register_utils.cpp"

// define global constants to be used
const int SHIFT_REG_DATA_PIN = 19;
const int SHIFT_REG_CLOCK_PIN = 10;
const int SHIFT_REG_LATCH_OUTPUT_ENABLE_PIN = 18; // is output

void setup()
{
    // initialize pins
    shift_reg::intiialize_register_pins();
    
    // using as log
    Serial.begin(9600);
}

void loop()
{

    Serial.println("Hello world!");
    delay(1000);
}

