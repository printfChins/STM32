#ifndef BSP_DS2408_H
#define BSP_DS2408_H

#include <stdint.h>
#include <stdbool.h>

void DS2408_GPIO_Init(void);
void DS2408_SetOutput(bool high);
bool DS2408_ReadInput(void);
void DS2408_SetInputMode(void);
void DS2408_SetOutputMode(void);
void DS2408_DelayUs(uint16_t us);

#endif
