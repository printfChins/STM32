#ifndef APP_DS2408_H
#define APP_DS2408_H

#include <stdint.h>
#include <stdbool.h>

bool DS2408_ResetPulse(void);
void DS2408_WriteBit(uint8_t bit);
uint8_t DS2408_ReadBit(void);
void DS2408_WriteByte(uint8_t byte);
uint8_t DS2408_ReadByte(void);


bool DS2408_Init(void);
bool DS2408_ReadROM(uint8_t *rom_buf);
bool DS2408_ReadPIO(uint8_t *pio_status);
void DS2408_Service(void);

#endif
