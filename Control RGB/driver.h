#ifndef DRIVER_H
#define DRIVER_H

#include <stdint.h>
#include <stdbool.h>

void Driver_Init(void);

void Driver_SetRGB(uint8_t r, uint8_t g, uint8_t b);

bool Driver_GetTimerFlag(void);
void Driver_ResetTimer(void);


bool Driver_GetButtonFlag(void);
void Driver_ResetButton(void);


bool Driver_GetButtonRaw(void);

#endif
