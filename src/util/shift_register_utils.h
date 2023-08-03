/* * * * * * * * * * * * * * * * * * * * 
*
*  Namespace shift_reg
*
* Collection of functions to simplify the use of 
* 959 shift registers
*
* * * * * * * * * * * * * * * * * * * * */
#include <Arduino.h>

// Reference global consts defined in main.cpp
extern const int SHIFT_REG_DATA_PIN;
extern const int SHIFT_REG_CLOCK_PIN;
extern const int SHIFT_REG_LATCH_OUTPUT_ENABLE_PIN;

namespace shift_reg{

    void initialize_register_pins(){
        pinMode(SHIFT_REG_DATA_PIN, OUTPUT);
        pinMode(SHIFT_REG_CLOCK_PIN, OUTPUT);
        pinMode(SHIFT_REG_LATCH_OUTPUT_ENABLE_PIN, OUTPUT);
    }
    
    void enable_output(){
        digitalWrite(SHIFT_REG_LATCH_OUTPUT_ENABLE_PIN, HIGH);    
    }

    void enable_input(){
        digitalWrite(SHIFT_REG_LATCH_OUTPUT_ENABLE_PIN, LOW);    
    }
    
    /*we shift LSB first towards MSB*/
    void shift_out_byte(uint8_t byteOut ){
        
        for (int i = 0; i < 8; i++){
            
            digitalWrite(SHIFT_REG_CLOCK_PIN, LOW);
            
            if ( byteOut & (1 << i) ) {
                digitalWrite(SHIFT_REG_DATA_PIN, HIGH);
            } else {
                digitalWrite(SHIFT_REG_DATA_PIN, LOW);
            }

            digitalWrite(SHIFT_REG_CLOCK_PIN, HIGH);
            digitalWrite(SHIFT_REG_DATA_PIN, LOW);

        }

    }
    
    void send_bits(uint8_t* vals_to_shift, int len){
        
        // Latch low to allow transmission
        enable_input();

        for ( int i = 0; i < len; i++ ) {
            shift_out_byte( vals_to_shift[i] );
        }


    }

}