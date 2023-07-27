/* * * * * * * * * * * * * * * * * * * * 
*
*  Namespace
*
*
*
*
* * * * * * * * * * * * * * * * * * * * */
#include <Arduino.h>

// Reference global consts defined in main.cpp
extern const int SHIFT_REG_DATA_PIN;
extern const int SHIFT_REG_CLOCK_PIN;
extern const int SHIFT_REG_LATCH_OUTPUT_ENABLE_PIN;

namespace shift_reg{

    bool intiialize_register_pins(){
        pinMode(SHIFT_REG_DATA_PIN, OUTPUT);
        pinMode(SHIFT_REG_CLOCK_PIN, OUTPUT);
        pinMode(SHIFT_REG_LATCH_OUTPUT_ENABLE_PIN, OUTPUT);
    }
    
    bool send_bits(char val_to_shift){
        
        // Latch low to allow transmission
        digitalWrite(SHIFT_REG_LATCH_OUTPUT_ENABLE_PIN, LOW);

        //TODO: look up arduino impl where you manually do clock, 
        //      seems interesting


    }

    bool enable_output(){

    }

    
}