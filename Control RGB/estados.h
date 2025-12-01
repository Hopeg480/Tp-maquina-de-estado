#ifndef ESTADOS_H
#define ESTADOS_H

#include "driver.h"



typedef enum {
    EST_RED,
    EST_BLUE,
    EST_GREEN,
    EST_MIX1,
    EST_MIX2,
    EST_MIX3
} estado_t;



estado_t estado_rojo(void);
estado_t estado_azul(void);
estado_t estado_verde(void);
estado_t estado_mix1(void);
estado_t estado_mix2(void);
estado_t estado_mix3(void);

#endif 