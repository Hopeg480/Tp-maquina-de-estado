#include "confi.h"

void systick_handler(void)
{
    tick_counter++;

    uint16_t limit = 30;     

    if (state >= S_MIX1)
        limit = 50;          

    if (tick_counter >= limit) {
        tick_counter = 0;
        flag_next = true;
    }
}


ISR(INT0_vect)
{
    flag_next = true;
}


void leds_init(void)
{
    GpioInitStructure_AVR cfg;
    cfg.port = avr_GPIO_B;
    cfg.modo = avr_GPIO_mode_Output;
    cfg.pines = avr_GPIO_PIN_0 | avr_GPIO_PIN_1 | avr_GPIO_PIN_2;
    init_gpio(cfg);
    avr_GPIOB_OUT = 0x00;
}


void update_leds(void)
{
    switch(state) {
        case S_RED:
            avr_GPIOB_OUT = avr_GPIO_PIN_0; // R
            break;

        case S_BLUE:
            avr_GPIOB_OUT = avr_GPIO_PIN_2; // A
            break;

        case S_GREEN:
            avr_GPIOB_OUT = avr_GPIO_PIN_1; // V
            break;

        case S_MIX1:
            avr_GPIOB_OUT = avr_GPIO_PIN_0 | avr_GPIO_PIN_2; // R + A
            break;

        case S_MIX2:
            avr_GPIOB_OUT = avr_GPIO_PIN_1 | avr_GPIO_PIN_2; // V + A
            break;

        case S_MIX3:
            avr_GPIOB_OUT = avr_GPIO_PIN_0 | avr_GPIO_PIN_1 | avr_GPIO_PIN_2; // R+V+A
            break;
    }
}

void next_state(void)
{
    switch(state) {
        case S_RED:   state = S_BLUE;  break;
        case S_BLUE:  state = S_GREEN; break;
        case S_GREEN: state = S_MIX1;  break;
        case S_MIX1:  state = S_MIX2;  break;
        case S_MIX2:  state = S_MIX3;  break;
        case S_MIX3:  state = S_RED;   break;
    }
}

void timer_init(void)
{
    SystickInitStructure_AVR tick;
    tick.timernumber = avr_TIM0;
    tick.time_ms = 100; 
    tick.avr_systick_handler = systick_handler;

    init_Systick_timer(tick);
}

void button_init(void)
{
    GpioInitStructure_AVR pin;
    pin.port = avr_GPIO_E;
    pin.modo = avr_GPIO_mode_Input;
    pin.pines = avr_GPIO_PIN_0;
    init_gpio(pin);
    avr_GPIOE_OUT |= avr_GPIO_PIN_0;
    EICRA |= (1<<ISC01);
    EICRA &= ~(1<<ISC00);
    EIMSK |= (1<<INT0);
}