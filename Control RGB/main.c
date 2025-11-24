#include "estados.h"
#include "driver.h"

int main(void)
{
    Driver_Init();

    estado_t estado_actual = EST_RED;

    while(1)
    {
        switch(estado_actual)
        {
            case EST_RED:   estado_actual = estado_rojo();  break;
            case EST_BLUE:  estado_actual = estado_azul();  break;
            case EST_GREEN: estado_actual = estado_verde(); break;
            case EST_MIX1:  estado_actual = estado_mix1();  break;
            case EST_MIX2:  estado_actual = estado_mix2();  break;
            case EST_MIX3:  estado_actual = estado_mix3();  break;
        }
    }
}