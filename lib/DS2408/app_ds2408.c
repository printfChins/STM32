#include "app_ds2408.h"
#include "bsp_ds2408.h"
#include "usart.h"

#define PRINT_SERIAL_NUMBER		0		// 0:Disable, 1:Enable
#define PRINT_STYLE						1		// 0:HEX, 		1:BINARY

bool DS2408_ResetPulse(void) {
	DS2408_SetOutputMode();
	DS2408_SetOutput(0);
	DS2408_DelayUs(480);
	DS2408_SetInputMode();
	DS2408_DelayUs(70);
	bool presence = !DS2408_ReadInput();
	DS2408_DelayUs(410);
	return presence;
}

void DS2408_WriteBit(uint8_t bit) {
	DS2408_SetOutputMode();
	DS2408_SetOutput(0);
	DS2408_DelayUs(bit ? 6 : 60);
	if (bit) DS2408_SetInputMode();
	DS2408_DelayUs(bit ? 64 : 10);
	DS2408_SetInputMode();
}

uint8_t DS2408_ReadBit(void) {
	uint8_t bit = 0;
	DS2408_SetOutputMode();
	DS2408_SetOutput(0);
	DS2408_DelayUs(6);
	DS2408_SetInputMode();
	DS2408_DelayUs(9);
	bit = DS2408_ReadInput();
	DS2408_DelayUs(55);
	return bit;
}

void DS2408_WriteByte(uint8_t byte) {
	for (int i = 0; i < 8; i++) {
			DS2408_WriteBit(byte & 0x01);
			byte >>= 1;
	}
}

uint8_t DS2408_ReadByte(void) {
	uint8_t byte = 0;
	for (int i = 0; i < 8; i++)
			byte |= (DS2408_ReadBit() << i);
	return byte;
}

bool DS2408_ReadPIO(uint8_t *pio_status) {
	if (!DS2408_ResetPulse()) return false;

	DS2408_WriteByte(0xCC);  // Skip ROM
	DS2408_WriteByte(0xF5);  // Read PIO Registers
	DS2408_WriteByte(0xF0);  // Address LSB
	DS2408_WriteByte(0xFF);  // Address MSB

	*pio_status = DS2408_ReadByte();
	DS2408_ReadByte(); // CRC 忽略
	return true;
}

bool DS2408_Init(void) {
	DS2408_GPIO_Init();
	return DS2408_ResetPulse();
}

bool DS2408_ReadROM(uint8_t *rom_buf) {
	if (!DS2408_ResetPulse()) return false;

	DS2408_WriteByte(0x33);  // Read ROM command

	for (int i = 0; i < 8; i++)
			rom_buf[i] = DS2408_ReadByte();
	
	return true;
}

void DS2408_Service(void) {
#if PRINT_SERIAL_NUMBER
	uint8_t rom[8];
	if (DS2408_ReadROM(rom)) {
			printf("DS2408 ROM ID: ");
			for (int i = 0; i < 8; i++) {
					printf("%02X", rom[i]);
			}
			printf("\r\n");

			// 額外解析 family code 與序號
			printf("Family Code: 0x%02X\r\n", rom[0]);
			printf("Serial Number: ");
			for (int i = 6; i >= 1; i--) {
					printf("%02X", rom[i]);  				// 注意：DS 是低位在前，需反向
			}
			printf("\r\nCRC: 0x%02X\r\n", rom[7]);
	} else {
			printf("Failed to read DS2408 ROM ID\r\n");
	}
#endif
	uint8_t pio;
	if (DS2408_ReadPIO(&pio)) {
		// 二進制顯示	
#if PRINT_STYLE
		printf("PIO status: ");
		for(int i=128;i;i>>=1)printf(i&pio?"1":"0");
		printf("\r\n");
#else
		// 十六進制顯示	
		printf("PIO status: 0x%02X\r\n\r\n", pio);
#endif
	} else {
			printf("Failed to read PIO\r\n\r\n");
	}
}
