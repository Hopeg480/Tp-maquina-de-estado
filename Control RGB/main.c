#include "confi.h"


int main(int argc, char const *argv[])
{
    leds_init();
    button_init();
    timer_init();

    sei();

    update_leds(); // Estado inicial

    while(1)
    {
        if (flag_next) {
            flag_next = false;
            tick_counter = 0;

            next_state();
            update_leds();
        }
    }
}
