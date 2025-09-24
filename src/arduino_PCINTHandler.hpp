#ifndef ARDUINO_PCINT_HANDLER_HPP
#define ARDUINO_PCINT_HANDLER_HPP

#include <Arduino.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/atomic.h>

class Arduino_PCINTHandler {
public:
    #define PCINT_GROUP_0 0
    #define PCINT_GROUP_1 1
    #define PCINT_GROUP_2 2
    #define ALL_PINS 255

// Internal setup functions for setting the corresponding pins
private: 
    uint8_t mPcintGroup; // PCINT group (0, 1, 2)
    uint8_t mSinglePin; // Only single pin or all pins in the group
    bool critSectionActive = false; //checkbit whether critical section is active
    // return true if sei register is active 
    auto isSEI() -> bool {return (SREG &(1<<SREG_I)) !=0; }
    auto startCriticalSection() -> void ;
    auto endCriticalSection() -> void ;

    #if defined(ARDUINO_AVR_MEGA2560)
        auto setupMEGA2560() -> void;
        auto mega2560_group0() -> void ;
        auto mega2560_group1() -> void ;
        auto mega2560_group2() -> void ;
    #elif
        #error "This board is currently not supported. Please create a feature request."
    #endif

public: 


    Arduino_PCINTHandler(uint8_t pcintGroup, uint8_t singlePin) : mPcintGroup(pcintGroup), mSinglePin(singlePin) 
    {
        // Disable interrupts during setup
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) 
        {
        #if defined(ARDUINO_AVR_MEGA2560)
            setupMEGA2560();
        #endif
        };

        // Enable Pin Change Interrupts
        if(mErrorCode == ERROR_CODES::IS_RDY && !isSEI())
        {
            sei();
            return;
        }// Restore previous interrupt state
        
    };

    auto resetCounter(uint8_t pin) -> void;
    auto getCounter(uint8_t pin) -> uint32_t;


    #if defined(ARDUINO_AVR_MEGA2560)
        static auto mega2560_group0_int() -> void ;
        static auto mega2560_group1_int() -> void ;
        static auto mega2560_group2_int() -> void ;
    #endif 

    private:

    #if defined(ARDUINO_AVR_MEGA2560)
        //friend void PCINT0_vect(void);
        //friend void PCINT1_vect(void);
        //friend void PCINT2_vect(void);
        
        static struct counters{
            struct group0{
                volatile  uint32_t count50;
                volatile  uint32_t count51;
                volatile  uint32_t count52;
                volatile  uint32_t count53;
                volatile  uint32_t count10;
                volatile  uint32_t count11;
                volatile  uint32_t count12;
                volatile  uint32_t count13;
            }grp0;
            struct group1{
                volatile  uint32_t count14;
                volatile  uint32_t count15;
            }grp1;
            struct group2{
                volatile  uint32_t countA8;
                volatile  uint32_t countA9;
                volatile  uint32_t countA10;
                volatile  uint32_t countA11;
                volatile  uint32_t countA12;
                volatile  uint32_t countA13;
                volatile  uint32_t countA14;
                volatile  uint32_t countA15;
            }grp2;
        }mData;

    #endif

private:

    enum class ERROR_CODES {
        NO_ERROR = 0,
        IS_RDY = 1,
        INVALID_PCINT_GROUP = -1,
        INVALID_PIN = -2
    } mErrorCode;

    


};

#endif // ARDUINO_PCINT_HANDLER_HPP