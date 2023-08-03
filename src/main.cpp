/* * * * * * * * * * * * * * * * * * * * *
*
*   LED Cube 4x4
*
*
*
*
*
*
* * * * * * * * * * * * * * * * * * * * */
#include <Arduino.h>

#include "util/shift_register_utils.h"

// define global constants to be used
const int SHIFT_REG_DATA_PIN = 19;
const int SHIFT_REG_CLOCK_PIN = 10;
const int SHIFT_REG_LATCH_OUTPUT_ENABLE_PIN = 18; // is output

int loopctr = 0;

void setup() {
    // initialize pins
    shift_reg::initialize_register_pins();
    
    // using as log
    Serial.begin(9600);

    Serial.println("---------------------");
    Serial.println("Starting LED Cube 4x4");
    Serial.println("---------------------");
    Serial.println(" ");

}

void loop() {
    
    char loopIterString[50];
    sprintf(loopIterString, "\t>Loop Iter: %d", loopctr);
    Serial.println(loopIterString);
    /*Not doing this dynamic*/
    // in the future, it will be a 2d array
    // row will be a state in time
    // each col is an X row
    // unless its the 0th shift 
    // reg which controls the z axis 

    // since we shift LSB to MSB
    // we want to make sure the top nibble
    // is set
    
    uint8_t state[2];
    state[0] = 0x10;
    state[1] = 0x10;


    shift_reg::send_bits( state, 2 );
    
    delay(10);
    
    shift_reg::enable_output();

    delay(1000);

}

