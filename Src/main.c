#include <string.h>
#include <math.h>
#include "main.h"
#include "main_functions.h"

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void StartDefaultTask(void const *argument);
void blink(void const *argument);

signed char prev_value = -1;

osThreadId defaultTaskHandle;
osThreadId blinkTaskHandle;

UART_HandleTypeDef UartHandle;

FATFS USBDISKFatFs;
FIL MyFile;
char USBDISKPath[4];
USBH_HandleTypeDef hUSB_Host;

typedef enum {
	DISCONNECTION_EVENT = 1,
	CONNECTION_EVENT,
} MSC_ApplicationTypeDef;

osMessageQId AppliEvent;

#define TOUCH_DOT_RADIUS 8
#define INPUT_IMAGE_SIZE 28
#define INPUT_BOX_THICKNESS 2
#define INPUT_IMAGE_SIZE_PIXEL 224
#define INPUT_BOX_TOP_MARGIN                                                   \
	((BSP_LCD_GetYSize() - INPUT_IMAGE_SIZE_PIXEL -                        \
	  2 * INPUT_BOX_THICKNESS) /                                           \
	 2)
#define INPUT_BOX_SIDE_MARGIN INPUT_BOX_TOP_MARGIN
#define INPUT_BOX_X_OUTER INPUT_BOX_SIDE_MARGIN
#define INPUT_BOX_X_INNER INPUT_BOX_SIDE_MARGIN + INPUT_BOX_THICKNESS
#define INPUT_BOX_Y_OUTER INPUT_BOX_SIDE_MARGIN
#define INPUT_BOX_Y_INNER INPUT_BOX_SIDE_MARGIN + INPUT_BOX_THICKNESS
#define INPUT_BOX_WIDTH (INPUT_IMAGE_SIZE_PIXEL + 2 * INPUT_BOX_THICKNESS)
#define RUN_BOX_WIDTH                                                          \
	(BSP_LCD_GetXSize() - INPUT_IMAGE_SIZE_PIXEL -                         \
	 3 * INPUT_BOX_TOP_MARGIN - 2 * INPUT_BOX_THICKNESS)
#define RUN_BOX_X                                                              \
	(INPUT_BOX_SIDE_MARGIN * 2 + INPUT_BOX_THICKNESS * 2 +                 \
	 INPUT_IMAGE_SIZE_PIXEL)
#define RUN_BOX_HEIGHT 40
#define RUN_BOX_Y (BSP_LCD_GetYSize() - 7 - (RUN_BOX_HEIGHT))

static TS_StateTypeDef TS_State;
static uint16_t TSInputImage[INPUT_IMAGE_SIZE_PIXEL][INPUT_IMAGE_SIZE_PIXEL] = {
	0
};
static uint8_t NNInputImage[INPUT_IMAGE_SIZE][INPUT_IMAGE_SIZE] = { 0 };
static const uint32_t image_size = INPUT_IMAGE_SIZE;
static const uint32_t image_size_pixel = INPUT_IMAGE_SIZE_PIXEL;

static void USBH_UserProcess(USBH_HandleTypeDef *phost, uint8_t id)
{
	switch (id) {
	case HOST_USER_SELECT_CONFIGURATION:
		break;
	case HOST_USER_DISCONNECTION:
		osMessagePut(AppliEvent, DISCONNECTION_EVENT, 0);
		f_mount(NULL, (TCHAR const *)"", 0);
		break;
	case HOST_USER_CLASS_ACTIVE:
		if (f_mount(&USBDISKFatFs, (TCHAR const *)USBDISKPath, 0) != FR_OK) {
			Error_Handler();
		} else
			osMessagePut(AppliEvent, CONNECTION_EVENT, 0);
		break;
	default:
		break;
	}
}

int FSInit(void)
{
	FRESULT res;

	if (USBH_Init(&hUSB_Host, USBH_UserProcess, 0) != USBH_OK) {
		printf("USB init failed\n\r");
		return -1;
	}

	if (USBH_RegisterClass(&hUSB_Host, USBH_MSC_CLASS) != USBH_OK) {
		printf("USB register class failed\n\r");
		return -1;
	}

	if (USBH_Start(&hUSB_Host) != USBH_OK) {
		printf("USB start failed\n\r");
		return -1;
	}
	
    if (FATFS_LinkDriver(&USBH_Driver, USBDISKPath) != 0)
		return -1;

	printf("FS init done\n\r");

	return 0;
}

int TestFS(void)
{
	uint32_t byteswritten, bytesread;
	char *test_text = "This is the test text 1234";
	char read_text[50];

	if (f_mount(&USBDISKFatFs, (TCHAR const *)USBDISKPath, 0) != FR_OK) {
		printf("Could not mount USB\n\r");
		return -1;
	}


	if (f_open(&MyFile, "TEST.txt", FA_CREATE_ALWAYS | FA_WRITE) != FR_OK) {
		printf("Open file failed\n\r");
		return -1;
	}

	if (f_write(&MyFile, test_text, sizeof(test_text),
		    (void *)&byteswritten) != FR_OK ||
	    (byteswritten == 0)) {
		printf("Write to file failed \n\r");
		return -1;
	}

	f_close(&MyFile);

	printf("Wrote %lu bytes to file", byteswritten);

	if (f_open(&MyFile, "TEST.txt", FA_CREATE_ALWAYS | FA_WRITE) != FR_OK) {
		printf("Could not open file to read\n\r");
		return -1;
	}

	if (f_read(&MyFile, read_text, sizeof(read_text), (UINT *)&bytesread) !=
		    FR_OK ||
	    (bytesread == 0)) {
		printf("Could not read from file\n\r");
		return -1;
	}

	if (bytesread != byteswritten) {
		printf("Bytes read (%u) doesn't equal bytes written (%u)\n\r",
		       bytesread, byteswritten);
		return -1;
	}

	printf("Read %lu bytes from file", bytesread);

	return 0;
}

uint16_t AverageImageBlock(uint32_t block_size, uint32_t x, uint32_t y)
{
	uint32_t ret[3] = { 0 };

	for (int i = 0; i < block_size; i++)
		for (int j = 0; j < block_size; j++) {
			ret[0] += TSInputImage[y * block_size + i]
					      [x * block_size + j] &
				  0x1F;
			ret[1] += (TSInputImage[y * block_size + i]
					       [x * block_size + j] >>
				   5) &
				  0x3F;
			ret[2] += (TSInputImage[y * block_size + i]
					       [x * block_size + j] >>
				   11) &
				  0x1F;
		}

	return (((ret[0] / (block_size * block_size)) & 0x1F) |
		(((ret[1] / (block_size * block_size)) & 0x3F) << 5) |
		(((ret[2] / (block_size * block_size)) & 0x1F) << 11));
}

void PreprocessImage(void)
{
	uint8_t scale_factor = image_size_pixel / image_size;

	for (int y = 0; y < image_size; y++)
		for (int x = 0; x < image_size; x++) {
			NNInputImage[y][x] =
				AverageImageBlock(scale_factor, x, y);
		}
}

uint8_t ConvertHighColorToGS(uint16_t pixel)
{
	uint8_t r = pixel >> 11 & 0x1F;
	uint8_t g = pixel >> 5 & 0x3F;
	uint8_t b = pixel & 0x1F;
	uint8_t luminance = (r + g + b) / 3;
	uint8_t gs = luminance * (255 / 41.0);
	return gs;
}

#define SEND_HASH_IMAGE 0b1

static void SendImageUART(void *image, size_t pixel_size, size_t image_size,
			  char flags)
{
	char *buffer = (char *)pvPortMalloc((image_size + 3) * sizeof(char));
	memset(buffer, 0, (image_size + 3) * sizeof(char));
	printf("**********IMAGE START**********\n\r");
	for (int i = 0; i < image_size; i++) {
		buffer[0] = '|';
		for (int j = 0; j < image_size; j++)
			if (flags & 0b1)
				buffer[j + 1] = (*((char *)image +
						   (i * image_size + j) *
							   pixel_size) == 255) ?
							'.' :
							'#';
			else
				buffer[j + 1] = (*((char *)image +
						   (i * image_size + j) *
							   pixel_size) == 255) ?
							'.' :
							*((char *)image +
							  (i + image_size + j) *
								  pixel_size) %
									26 +
								65;
		buffer[image_size] = '|';
		printf("%s\n\r", buffer);
	}
	printf("**********IMAGE STOP**********\n\r");
	vPortFree(buffer);
}

static void DrawShrunkImage(int x, int y)
{
	BSP_LCD_Clear(LCD_COLOR_WHITE);
	for (int i = 0; i < INPUT_IMAGE_SIZE; i++)
		for (int j = 0; j < INPUT_IMAGE_SIZE; j++)
			BSP_LCD_DrawPixel(x + j, y + i, NNInputImage[i][j]);
}

static void SaveInputImage(void)
{
	volatile int margin = INPUT_BOX_Y_INNER;
	TSInputImage[0][0] = 1;
	for (int y = 0; y < image_size_pixel; y++) {
		for (int x = 0; x < image_size_pixel; x++) {
			TSInputImage[y][x] = ConvertHighColorToGS(
				BSP_LCD_ReadPixel(x + margin, y + margin));
		}
	}

	/** SendImageUART((void *)TSInputImage, sizeof(uint16_t), */
	/**           INPUT_IMAGE_SIZE_PIXEL); */

	PreprocessImage();

	DrawShrunkImage(BSP_LCD_GetXSize() / 2 - INPUT_IMAGE_SIZE / 2,
			BSP_LCD_GetYSize() / 2 - INPUT_IMAGE_SIZE / 2);
	BSP_LCD_DisplayStringAt(BSP_LCD_GetXSize() / 4,
				BSP_LCD_GetYSize() / 2 - 40,
				(uint8_t *)"RUNNING", LEFT_MODE);

	SendImageUART((void *)NNInputImage, sizeof(char), INPUT_IMAGE_SIZE, 0);
}

uint8_t RunButtonPressed(uint32_t x, uint32_t y)
{
	if ((x >= RUN_BOX_X) && (x <= (RUN_BOX_X + RUN_BOX_WIDTH)) &&
	    (y >= RUN_BOX_Y) && (y <= (RUN_BOX_Y + RUN_BOX_HEIGHT)))
		return 1;

	return 0;
}

uint8_t DrawInBox(uint32_t x, uint32_t y, uint32_t dot_radius)
{
	if ((x < (INPUT_BOX_X_INNER + dot_radius)) ||
	    (x > (INPUT_BOX_X_INNER + INPUT_IMAGE_SIZE_PIXEL - dot_radius))) {
		return 0;
	}
	if ((y < (INPUT_BOX_Y_INNER + dot_radius)) ||
	    (y > (INPUT_BOX_Y_INNER + INPUT_IMAGE_SIZE_PIXEL - dot_radius))) {
		return 0;
	}

	return 1;
}

void DrawInputScreen(void)
{
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_Clear(LCD_COLOR_WHITE);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_FillRect(INPUT_BOX_X_OUTER, INPUT_BOX_Y_OUTER, INPUT_BOX_WIDTH,
			 INPUT_BOX_WIDTH);
	BSP_LCD_FillRect(RUN_BOX_X, RUN_BOX_Y, RUN_BOX_WIDTH, RUN_BOX_HEIGHT);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_FillRect(INPUT_BOX_X_INNER, INPUT_BOX_Y_INNER,
			 INPUT_IMAGE_SIZE_PIXEL, INPUT_IMAGE_SIZE_PIXEL);
	BSP_LCD_FillRect(RUN_BOX_X + INPUT_BOX_THICKNESS,
			 RUN_BOX_Y + INPUT_BOX_THICKNESS,
			 RUN_BOX_WIDTH - 2 * INPUT_BOX_THICKNESS,
			 RUN_BOX_HEIGHT - 2 * INPUT_BOX_THICKNESS);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_DisplayStringAt(RUN_BOX_X + 20, RUN_BOX_Y + 12,
				(uint8_t *)"RUN", LEFT_MODE);
	if (prev_value != -1) {
		BSP_LCD_DisplayStringAt(
			INPUT_BOX_X_OUTER + INPUT_BOX_WIDTH + 10,
			INPUT_BOX_Y_OUTER, (uint8_t *)"RESULT", LEFT_MODE);
		char buf[2];
		sprintf(buf, "%c", prev_value);
		BSP_LCD_DisplayStringAt(
			INPUT_BOX_X_OUTER + INPUT_BOX_WIDTH + 35,
			INPUT_BOX_Y_OUTER + 15, (uint8_t *)buf, LEFT_MODE);
	}
}

char determine_char(float *out_array)
{
	int index = 0;
	float max_val = out_array[index];

	for (int i = 1; i < 10; i++)
		if (out_array[i] > max_val) {
			index = i;
			max_val = out_array[i];
		}

	return (char)index + 48;
}

void printPercentages(float *output_array)
{
	char buff[10] = { 0 };
	for (int i = 0; i < 11; i++) {
		sprintf(buff, "%d: %d%%", i, (int)round(output_array[i] * 100));
		BSP_LCD_DisplayStringAt(INPUT_BOX_X_OUTER + INPUT_BOX_WIDTH + 5,
					INPUT_BOX_Y_OUTER + 35 + i * 13,
					(uint8_t *)buff, LEFT_MODE);
	}
}

void DrawTouchInput(void)
{
	static const uint32_t dot_radius = TOUCH_DOT_RADIUS;
	static uint32_t x = 0, y = 0;
	float *output_array;

	BSP_TS_GetState(&TS_State);

	if (TS_State.TouchDetected) {
		x = TS_State.x;
		y = TS_State.y;

		if (DrawInBox(x, y, dot_radius)) {
			BSP_LCD_FillCircle(x, y, dot_radius);
		} else if (RunButtonPressed(x, y)) {
			printf("Save image\n\r");
			SaveInputImage();
			output_array =
				loop((uint8_t *)NNInputImage,
				     INPUT_IMAGE_SIZE * INPUT_IMAGE_SIZE);
			prev_value = determine_char(output_array);
			DrawInputScreen();
			printPercentages(output_array);
		}
	}
}

/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
void StartDefaultTask(void const *argument)
{
	DrawInputScreen();

	printf("Started\n\r");
	setup();
	for (;;) {
		DrawTouchInput();
		HAL_Delay(1);
	}
}

void blink(void const *argument)
{
	int count = 0;

	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);

	for (;;) {
		count %= 10;

		switch (count++) {
		case 0:
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin,
					  GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin,
					  GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin,
					  GPIO_PIN_SET);
			break;
		case 5:
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin,
					  GPIO_PIN_RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin,
					  GPIO_PIN_RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin,
					  GPIO_PIN_RESET);
			break;
		default:
			break;
		}

		HAL_Delay(100);
	}
}

int main(void)
{
	int ret;

	HAL_Init();
	SystemClock_Config();

	UartHandle.Instance = USARTx;
	UartHandle.Init.BaudRate = 9600;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits = UART_STOPBITS_1;
	UartHandle.Init.Parity = UART_PARITY_ODD;
	UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode = UART_MODE_TX_RX;
	UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;

	if (HAL_UART_Init(&UartHandle) != HAL_OK) {
		/* Initialization Error */
		Error_Handler();
	}

	printf("UART online\n\r");

	BSP_LCD_Init();
	BSP_LCD_DisplayOn();
	BSP_LCD_Clear(LCD_COLOR_WHITE);
	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());

	/* Initialize all configured peripherals */
	MX_GPIO_Init();

	if ((ret = FSInit()))
		printf("FS init failed %d\n\r", ret);

	if (TestFS())
		printf("Test FS failed\n\r");

	/** osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 1000); */
	/** defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL); */

	osThreadDef(blinkTaskHandle, blink, osPriorityNormal, 0, 256);
	blinkTaskHandle = osThreadCreate(osThread(blinkTaskHandle), NULL);

	osMessageQDef(osqueue, 1, uint16_t);
	AppliEvent = osMessageCreate(osMessageQ(osqueue), NULL);

	/* Start scheduler */
	osKernelStart();

	while (1) {
	}
}

void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Configure the main internal regulator output voltage 
           *   */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
	/** Initializes the CPU, AHB and APB busses clocks 
               *   */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 168;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 7;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB busses clocks 
                                   *   */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK |
				      RCC_CLOCKTYPE_SYSCLK |
				      RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) !=
	    HAL_OK) {
		Error_Handler();
	}
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOG, LED2_Pin | LED1_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pins : FSMC_NE1_Pin FSMC_NWAIT_Pin D2_Pin FSMC_NWE_Pin 
                           D3_Pin FSMC_NOE_Pin FSMC_CLK_Pin D1_Pin 
                           D0_Pin A18_Pin A17_Pin A16_Pin 
                           D15_Pin D14_Pin D13_Pin */
	GPIO_InitStruct.Pin = FSMC_NE1_Pin | FSMC_NWAIT_Pin | D2_Pin |
			      FSMC_NWE_Pin | D3_Pin | FSMC_NOE_Pin |
			      FSMC_CLK_Pin | D1_Pin | D0_Pin | A18_Pin |
			      A17_Pin | A16_Pin | D15_Pin | D14_Pin | D13_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF12_FSMC;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	/*Configure GPIO pin : FSMC_NL_Pin */
	GPIO_InitStruct.Pin = FSMC_NL_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF12_FSMC;
	HAL_GPIO_Init(FSMC_NL_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pin : User_Button_Pin */
	GPIO_InitStruct.Pin = User_Button_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(User_Button_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : LED2_Pin LED1_Pin */
	GPIO_InitStruct.Pin = LED2_Pin | LED1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

	/*Configure GPIO pins : FSMC_NE3_Pin FSMC_NE2_Pin A15_Pin A14_Pin 
                           A13_Pin A12_Pin A11_Pin A10_Pin */
	GPIO_InitStruct.Pin = FSMC_NE3_Pin | FSMC_NE2_Pin | A15_Pin | A14_Pin |
			      A13_Pin | A12_Pin | A11_Pin | A10_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF12_FSMC;
	HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

	/*Configure GPIO pin : LED3_Pin */
	GPIO_InitStruct.Pin = LED3_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LED3_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pin : LED4_Pin */
	GPIO_InitStruct.Pin = LED4_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LED4_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pin : SW1_Pin */
	GPIO_InitStruct.Pin = SW1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(SW1_GPIO_Port, &GPIO_InitStruct);
}

void Error_Handler(void)
{
	while (1) {
	}
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
}
#endif /* USE_FULL_ASSERT */
