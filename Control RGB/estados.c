#include "estados.h"
#include "driver.h"

estado_t estado_rojo(void)
{
    Driver_SetRGB(1,0,0);

    if (Driver_GetButtonFlag()) {
        Driver_ResetButton();
        return EST_BLUE;
    }

    if (Driver_GetTimerFlag()) {
        Driver_ResetTimer();
        return EST_BLUE;
    }

    return EST_RED;
}

estado_t estado_azul(void)
{
    Driver_SetRGB(0,0,1);

    if (Driver_GetButtonFlag()) {
        Driver_ResetButton();
        return EST_GREEN;
    }

    if (Driver_GetTimerFlag()) {
        Driver_ResetTimer();
        return EST_GREEN;
    }

    return EST_BLUE;
}

estado_t estado_verde(void)
{
    Driver_SetRGB(0,1,0);

    if (Driver_GetButtonFlag()) {
        Driver_ResetButton();
        return EST_MIX1;
    }

    if (Driver_GetTimerFlag()) {
        Driver_ResetTimer();
        return EST_MIX1;
    }

    return EST_GREEN;
}

estado_t estado_mix1(void)
{
    Driver_SetRGB(1, 0, 1); 

    if (Driver_GetButtonFlag()) {
        Driver_ResetButton();
        return EST_MIX2;
    }
    if (Driver_GetTimerFlag()) {
        Driver_ResetTimer();
        return EST_MIX2;
    }
    return EST_MIX1;
}

estado_t estado_mix2(void)
{
    Driver_SetRGB(0, 1, 1); 

    if (Driver_GetButtonFlag()) {
        Driver_ResetButton();
        return EST_MIX3;
    }
    if (Driver_GetTimerFlag()) {
        Driver_ResetTimer();
        return EST_MIX3;
    }
    return EST_MIX2;
}

estado_t estado_mix3(void)
{
    Driver_SetRGB(1, 1, 1); 

    if (Driver_GetButtonFlag()) {
        Driver_ResetButton();
        return EST_RED;
    }
    if (Driver_GetTimerFlag()) {
        Driver_ResetTimer();
        return EST_RED;
    }
    return EST_MIX3;
}
