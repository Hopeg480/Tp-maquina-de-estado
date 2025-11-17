#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#include "avr_Gpio.h"
#include "avr_Timers.h"

typedef enum {
    S_RED,
    S_BLUE,
    S_GREEN,
    S_MIX1,
    S_MIX2,
    S_MIX3
} state_t;

volatile state_t state = S_RED;
volatile bool flag_next = false;
volatile uint16_t tick_counter = 0;
