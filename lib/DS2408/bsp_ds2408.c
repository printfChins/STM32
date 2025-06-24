#include "bsp_ds2408.h"
#include "stm32f1xx_hal.h"  // 根據實際 MCU 調整
#include "tim.h"			// 根據實際函式庫調整

//Using 4.7K Pull-up resistors
#define DS2408_GPIO_PORT GPIO?			//GPIO Port	Setting
#define DS2408_GPIO_PIN  GPIO_PIN_?		//GPIO Pin Setting

void DS2408_GPIO_Init(void) {
	DS2408_SetInputMode();
}

void DS2408_SetOutput(bool high) {
  //GPIO Write Set
  //HAL_GPIO_WritePin(DS2408_GPIO_PORT, DS2408_GPIO_PIN, high ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

bool DS2408_ReadInput(void) {
  //GPIO Read
  //return HAL_GPIO_ReadPin(DS2408_GPIO_PORT, DS2408_GPIO_PIN) == GPIO_PIN_SET;
}

void DS2408_SetInputMode(void) {
	//Setting GPIO Input Mode
	/*
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = DS2408_GPIO_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(DS2408_GPIO_PORT, &GPIO_InitStruct);
	*/
}

void DS2408_SetOutputMode(void) {
	//Setting GPIO Output Mode, Output Open Drain
	/*
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = DS2408_GPIO_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(DS2408_GPIO_PORT, &GPIO_InitStruct);
	*/
}

void DS2408_DelayUs(uint16_t us) {
	// Microsecond delay
	/*
	HAL_Delay_us(us);
	*/
}
