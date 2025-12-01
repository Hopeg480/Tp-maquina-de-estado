#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#include "driver.h"


static volatile bool flag_timer = false;
static volatile bool flag_button = false;


static volatile uint16_t tick_count = 0;


void systick_handler(void)
{
  
    if (Driver_GetButtonRaw())
    {
        tick_count++;

        if (tick_count >= 30)     
        {
            tick_count = 0;
            flag_timer = true;
        }
    }
    else
    {
      
        tick_count = 0;
    }
}


ISR(TIMER0_COMP_vect)
{
    systick_handler();
}


ISR(INT0_vect)
{
    flag_button = true;
}


void Driver_Init(void)
{
   
    DDRB |= (1<<PB0)|(1<<PB1)|(1<<PB2);
    PORTB &= ~((1<<PB0)|(1<<PB1)|(1<<PB2));

   
    DDRE &= ~(1<<PE0);
    PORTE |= (1<<PE0);

   
    EICRA |= (1<<ISC01);
    EIMSK |= (1<<INT0);

   
   TCCR0 = (1 << WGM01);                 
TCCR0 |= (1 << CS02) | (1 << CS00);
    OCR0 = 78;                                 
    TIMSK |= (1 << OCIE0);                     

    sei();
}


bool Driver_GetTimerFlag(void)
{
    return flag_timer;
}

void Driver_ResetTimer(void)
{
    flag_timer = false;
}

bool Driver_GetButtonFlag(void)
{
    return flag_button;
}

void Driver_ResetButton(void)
{
    flag_button = false;
}


bool Driver_GetButtonRaw(void)
{
    return !(PINE & (1<<PE0));  
}


void Driver_SetRGB(uint8_t r, uint8_t g, uint8_t b)
{
    PORTB = 0;
    if (r) PORTB |= (1<<PB0);
    if (g) PORTB |= (1<<PB1);
    if (b) PORTB |= (1<<PB2);
}