#include "bsp_ds2408.h"
#include "stm32f1xx_hal.h"  // 根據實際 MCU 調整
#include "tim.h"

#define DS2408_GPIO_PORT GPIOB
#define DS2408_GPIO_PIN  GPIO_PIN_8

void DS2408_GPIO_Init(void) {
  // 在 main.c 或 MX_GPIO_Init() 裡完成初始化
	DS2408_SetInputMode();
}

void DS2408_SetOutput(bool high) {
  HAL_GPIO_WritePin(DS2408_GPIO_PORT, DS2408_GPIO_PIN, high ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

bool DS2408_ReadInput(void) {
  return HAL_GPIO_ReadPin(DS2408_GPIO_PORT, DS2408_GPIO_PIN) == GPIO_PIN_SET;
}

void DS2408_SetInputMode(void) {
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = DS2408_GPIO_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(DS2408_GPIO_PORT, &GPIO_InitStruct);
}

void DS2408_SetOutputMode(void) {
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = DS2408_GPIO_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(DS2408_GPIO_PORT, &GPIO_InitStruct);
}

void DS2408_DelayUs(uint16_t us) {
	// 根據實際平台實作 microsecond delay
	HAL_Delay_us(us);
}
