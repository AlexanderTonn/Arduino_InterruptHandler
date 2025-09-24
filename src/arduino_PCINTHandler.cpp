#include "arduino_PCINTHandler.hpp"

Arduino_PCINTHandler::counters Arduino_PCINTHandler::mData = {0};

/**
 * @brief Setup the Mega 2560 pin change interrupt handler
 * 
 */
auto Arduino_PCINTHandler::setupMEGA2560() -> void
{
    switch (mPcintGroup)
    {
    case PCINT_GROUP_0:
        mega2560_group0();
        PCICR |= (1 << PCIE0); // set pin change interrupt for pins PCINT[7:0]

        break;
    case PCINT_GROUP_1:
        mega2560_group1();
        break;

    case PCINT_GROUP_2:
        mega2560_group2();
        break;
    default:
        mErrorCode = ERROR_CODES::INVALID_PCINT_GROUP;
        break;
    }
}
/**
 * @brief Setup the Mega 2560 pin change interrupt for group 0
 * 
 */
auto Arduino_PCINTHandler::mega2560_group0() -> void
{
    switch (mSinglePin)
    {
    case 53:
        DDRB &= ~(1 << PINB0);   // Set as input
        PORTB |= (1 << PINB0);   // Enable pull-up resistor
        PCMSK0 |= (1 << PCINT0); // set pin change interrupt for pin 53 (PCINT0)
        break;
    case 52:
        DDRB &= ~(1 << PINB1);
        PORTB |= (1 << PINB1);
        PCMSK0 |= (1 << PCINT1);
        break;
    case 51:
        DDRB &= ~(1 << PINB2);
        PORTB |= (1 << PINB2);
        PCMSK0 |= (1 << PCINT2);
        break;
    case 50:
        DDRB &= ~(1 << PINB3);
        PORTB |= (1 << PINB3);
        PCMSK0 |= (1 << PCINT3);
        break;
    case 13:
        DDRB &= ~(1 << PINB7);
        PORTB |= (1 << PINB7);
        PCMSK0 |= (1 << PCINT7);
        break;
    case 12:
        DDRB &= ~(1 << PINB6);
        PORTB |= (1 << PINB6);
        PCMSK0 |= (1 << PCINT6);
        break;
    case 11:
        DDRB &= ~(1 << PINB5);
        PORTB |= (1 << PINB5);
        PCMSK0 |= (1 << PCINT5);
        break;
    case 10:
        DDRB &= ~(1 << PINB4);
        PORTB |= (1 << PINB4);
        PCMSK0 |= (1 << PCINT4);
        break;

    case ALL_PINS:
        DDRB &= ~(1 << PINB0 | 1 << PINB1 | 1 << PINB2 | 1 << PINB3 | 1 << PINB4 | 1 << PINB5 | 1 << PINB6 | 1 << PINB7);
        PORTB |= (1 << PINB0 | 1 << PINB1 | 1 << PINB2 | 1 << PINB3 | 1 << PINB4 | 1 << PINB5 | 1 << PINB6 | 1 << PINB7);
        PCMSK0 |= (1 << PCINT0) | (1 << PCINT1) | (1 << PCINT2) | (1 << PCINT3) | (1 << PCINT4) | (1 << PCINT5) | (1 << PCINT6) | (1 << PCINT7);
        break;

    default:
        mErrorCode = ERROR_CODES::INVALID_PIN;
        break;
    }

}
/**
 * @brief Setup the Mega 2560 pin change interrupt for group 1
 * 
 */
auto Arduino_PCINTHandler::mega2560_group1() -> void
{
    switch (mSinglePin)
    {
    case 15:
        DDRB &= ~(1 << PINF0);   // Set as input
        PORTB |= (1 << PINF1);   // Enable pull-up resistor
        PCMSK1 |= (1 << PCINT8); // set pin change interrupt for pin 15 (PCINT9)
        break;
    case 14:
        DDRB &= ~(1 << PINF1);
        PORTB |= (1 << PINF1);
        PCMSK1 |= (1 << PCINT9);
        break;

    case ALL_PINS:
        DDRB &= ~(1 << PINF1 | 1 << PINF0);
        PORTB |= (1 << PINF1 | 1 << PINF0);
        PCMSK1 |= (1 << PCINT8 | 1 << PCINT9);
        break;

    default:
        mErrorCode = ERROR_CODES::INVALID_PIN;
        break;
    }
}
/**
 * @brief Setup the Mega 2560 pin change interrupt for group 2
 * 
 */
auto Arduino_PCINTHandler::mega2560_group2() -> void
{
    switch (mSinglePin)
    {
    case A8:
        DDRB &= ~(1 << PINK0);    // Set as input
        PORTB |= 1 << PINK0;      // Enable pull-up resistor
        PCMSK2 |= (1 << PCINT16); // set pin change interrupt for pin 15 (PCINT9)
        break;
    case A9:
        DDRB &= ~1 << PINK1;
        PORTB |= 1 << PINK1;
        PCMSK2 |= (1 << PCINT17);
        break;
    case A10:
        DDRB &= ~(1 << PINK2);
        PORTB |= 1 << PINK2;
        PCMSK2 |= (1 << PCINT18);
        break;
    case A11:
        DDRB &= ~(1 << PINK3);
        PORTB |= 1 << PINK3;
        PCMSK2 |= (1 << PCINT19);
        break;
    case A12:
        DDRB &= ~(1 << PINK4);
        PORTB |= 1 << PINK4;
        PCMSK2 |= (1 << PCINT20);
        break;
    case A13:
        DDRB &= ~(1 << PINK5);
        PORTB |= 1 << PINK5;
        PCMSK2 |= (1 << PCINT21);
        break;
    case A14:
        DDRB &= ~(1 << PINK6);
        PORTB |= 1 << PINK6;
        PCMSK2 |= (1 << PCINT22);
        break;
    case A15:
        DDRB &= ~(1 << PINK7);
        PORTB |= 1 << PINK7;
        PCMSK2 |= (1 << PCINT23);
        break;
    case ALL_PINS:
        DDRB &= ~(PINK0 | 1 << PINK1 | 1 << PINK2 | 1 << PINK3 | 1 << PINK4 | 1 << PINK5 | 1 << PINK6 | 1 << PINK7);
        PORTB |= (PINK0 | 1 << PINK1 | 1 << PINK2 | 1 << PINK3 | 1 << PINK4 | 1 << PINK5 | 1 << PINK6 | 1 << PINK7);
        PCMSK2 |= (1 << PCINT16 | 1 << PCINT17 | 1 << PCINT18 | 1 << PCINT19 | 1 << PCINT20 | 1 << PCINT21 | 1 << PCINT22 | 1 << PCINT23);
        break;

    default:
        break;
    }
}

/**
 * @brief Start a critical section by disabling interrupts.
 * 
 */
auto Arduino_PCINTHandler::startCriticalSection() -> void 
{ 
    if(critSectionActive)
        return;
    
    critSectionActive = true;
    
    switch (mPcintGroup)
    {
    #if defined (ARDUINO_AVR_MEGA2560)
    case PCINT_GROUP_0:
        PCICR &= ~(1 << PCIE0); 
        break;
    case PCINT_GROUP_1:
        PCICR &= ~(1 << PCIE1); 
        break;
    case PCINT_GROUP_2:
        PCICR &= ~(1 << PCIE2);
        break;
    #endif
    default:
        break;
    }
}
/**
 * @brief Restore the previous interrupt state, ending the critical section.
 * 
 */
auto Arduino_PCINTHandler::endCriticalSection() -> void 
{ 
    if (!critSectionActive)
    {
        return;
    }
        
    
        switch (mPcintGroup)
    {
    #if defined (ARDUINO_AVR_MEGA2560)
    case PCINT_GROUP_0:
        PCICR |= (1 << PCIE0); 
        break;
    case PCINT_GROUP_1:
        PCICR |= (1 << PCIE1);
        break;
    case PCINT_GROUP_2:
        PCICR |= (1 << PCIE2); 
        break;
    #endif
    default:
        break;
    }
}

auto Arduino_PCINTHandler::resetCounter(uint8_t pin) -> void 
{
    startCriticalSection();
    
    switch(mPcintGroup)
    {
        case PCINT_GROUP_0:
            switch(pin)
            {
                case 53:
                    mData.grp0.count53 = 0;
                    break;
                case 52:
                    mData.grp0.count52 = 0;
                    break;
                case 51:
                    mData.grp0.count51 = 0;
                    break;
                case 50:
                    mData.grp0.count50 = 0;
                    break;
                case 13:
                    mData.grp0.count13 = 0;
                    break;
                case 12:
                    mData.grp0.count12 = 0;
                    break;
                case 11:
                    mData.grp0.count11 = 0;
                    break;
                case 10:
                    mData.grp0.count10 = 0;
                    break;
                case ALL_PINS:
                    mData.grp0.count53 = 0;
                    mData.grp0.count52 = 0;
                    mData.grp0.count51 = 0;
                    mData.grp0.count50 = 0;
                    mData.grp0.count13 = 0;
                    mData.grp0.count12 = 0;
                    mData.grp0.count11 = 0;
                    mData.grp0.count10 = 0;
                    break;
                default:
                    break; // Invalid pin for this group
            }
            case PCINT_GROUP_1:
            switch(pin)
            {
                case 15:
                    mData.grp1.count15 = 0;
                    break;
                case 14:
                    mData.grp1.count14 = 0;
                    break;
                case ALL_PINS:
                    mData.grp1.count15 = 0;
                    mData.grp1.count14 = 0;
                    break;
                default:
                    break; // Invalid pin for this group
            }
            case PCINT_GROUP_2:
            switch(pin)
            {
                case A8:
                    mData.grp2.countA8 = 0;
                    break;
                case A9:
                    mData.grp2.countA9 = 0;
                    break;
                case A10:
                    mData.grp2.countA10 = 0;
                    break;
                case A11:
                    mData.grp2.countA11 = 0;
                    break;
                case A12:
                    mData.grp2.countA12 = 0;
                    break;
                case A13:
                    mData.grp2.countA13 = 0;
                    break;
                case A14:
                    mData.grp2.countA14 = 0;
                    break;
                case A15:
                    mData.grp2.countA15 = 0;
                    break;
                case ALL_PINS:
                    mData.grp2.countA8 = 0;
                    mData.grp2.countA9 = 0;
                    mData.grp2.countA10 = 0;
                    mData.grp2.countA11 = 0;
                    mData.grp2.countA12 = 0;
                    mData.grp2.countA13 = 0;
                    mData.grp2.countA14 = 0;
                    mData.grp2.countA15 = 0;
                    break;
                default:
                    break; // Invalid pin for this group
            }

            break;
    }

    endCriticalSection();
}
auto Arduino_PCINTHandler::getCounter(uint8_t pin) -> uint32_t
{
    switch(mPcintGroup)
    {
        case PCINT_GROUP_0:
            switch(pin)
            {
                case 53:
                    return mData.grp0.count53;
                case 52:
                    return mData.grp0.count52;
                case 51:
                    return mData.grp0.count51;
                case 50:
                    return mData.grp0.count50;
                case 13:
                    return mData.grp0.count13;
                case 12:
                    return mData.grp0.count12;
                case 11:
                    return mData.grp0.count11;
                case 10:
                    return mData.grp0.count10;
                default:
                    return 0; // Invalid pin for this group
            }
        case PCINT_GROUP_1:
            switch(pin)
            {
                case 15:
                    return mData.grp1.count15;
                case 14:
                    return mData.grp1.count14;
                default:
                    return 0; // Invalid pin for this group
            }
        case PCINT_GROUP_2:
            switch(pin)
            {
                case A8:
                    return mData.grp2.countA8;
                case A9:
                    return mData.grp2.countA9;
                case A10:
                    return mData.grp2.countA10;
                case A11:
                    return mData.grp2.countA11;
                case A12:
                    return mData.grp2.countA12;
                case A13:
                    return mData.grp2.countA13;
                case A14:
                    return mData.grp2.countA14;
                case A15:
                    return mData.grp2.countA15;
                default:
                    return 0; // Invalid pin for this group
            }
    }
}
#if defined(ARDUINO_AVR_MEGA2560)

ISR(PCINT0_vect)
{
    Arduino_PCINTHandler::mega2560_group0_int();
}

ISR(PCINT1_vect)
{
    Arduino_PCINTHandler::mega2560_group1_int();
}

ISR(PCINT2_vect)
{
    Arduino_PCINTHandler::mega2560_group2_int();
}

auto Arduino_PCINTHandler::mega2560_group0_int() -> void
{
    static uint8_t lastPinB = 0;
    static uint8_t currentMask = PCMSK0; // Set this to the mask you want, or provide a setter

    uint8_t now = PINB;
    uint8_t chngd = (now ^ lastPinB) & currentMask;

    uint8_t rised = chngd & now;
    lastPinB = now;

    if (rised & (1 << PINB0)) // Pin 53
        ++mData.grp0.count53;

    if (rised & (1 << PINB1)) // Pin 52
        ++mData.grp0.count52;

    if (rised & (1 << PINB2)) // Pin 51
        ++mData.grp0.count51;

    if (rised & (1 << PINB3)) // Pin 50
        ++mData.grp0.count50;

    if (rised & (1 << PINB4)) // Pin 10
        ++mData.grp0.count10;

    if (rised & (1 << PINB5)) // Pin 11
        ++mData.grp0.count11;

    if (rised & (1 << PINB6)) // Pin 12
        ++mData.grp0.count12;

    if (rised & (1 << PINB7)) // Pin 13
        ++mData.grp0.count13;
}

auto Arduino_PCINTHandler::mega2560_group1_int() -> void
{
    // Handle pin change interrupt for group 1 (PCINT[14:8])
    // User code to handle the interrupt can be added here
}

auto Arduino_PCINTHandler::mega2560_group2_int() -> void
{
    // Handle pin change interrupt for group 2 (PCINT[23:16])
    // User code to handle the interrupt can be added here
}

#endif