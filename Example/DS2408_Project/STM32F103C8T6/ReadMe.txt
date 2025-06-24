2025/06/24
==============================================================
專案說明
以雙線方式連接DS2408(請參閱Datasheet)，訊號線須外部上拉4.7K歐姆
於主程式中調用DS2408_Service()讀取GPIO端口狀態並顯示於USART1

※USART1使用DMA中斷非阻塞方式傳輸並映射於printf，可參考usart.c程式碼
※TIM2設置定時器，於建置HAL_Delay_us函數，可參考tim.c程式碼

==============================================================
DS2408驅動說明

位址：Project\User\lib\DS2408
bsp_ds2408：bsp底層GPIO控制
app_ds2408：app應用層驅動

文件說明
bsp_ds24085針對STM32F103C8T6設定，只需替換函數內容可於其他MCU使用
調用時只需呼叫app層即可(app_ds2408.h)

bool DS2408_Init(void);			// 初始化模組
bool DS2408_ReadROM(uint8_t *rom_buf);	// 獲取0x33 ROM 可顯示Serial Number
bool DS2408_ReadPIO(uint8_t *pio_status);	// 讀取I/O口狀態
void DS2408_Service(void);			// 啟動服務程式
==============================================================




