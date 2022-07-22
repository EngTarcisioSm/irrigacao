/* USER CODE BEGIN Header */
/**
 * @file           : rtc.c
 * @brief          :
 ******************************************************************************
 * @attention
 *
 * Author:
 * Date: 21/07/2022
 *
 * Description:
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "rtc.h"

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private function ----------------------------------------------------------*/
/* USER CODE BEGIN FUNCTION */
void vRTC_CreateTaskLed(void) {

	HAL_UART_Transmit(&huart1, "LOG: Task LED_RTC inicializando\r\n", 33, 100);
	if ((xTaskCreate(vRTC_Task_Led, "LED_RTC", configMINIMAL_STACK_SIZE, NULL,
			1, NULL)) != pdTRUE) {
		HAL_UART_Transmit(&huart1, "ERROR: Task LED_RTC não Inicializada\r\n", 37, 100);
		while (1) {
			/**
			 * @author Task não foi criada, resetar o sistema
			 */
		}
	}
}
/* USER CODE END FUNCTION */

/* Tasks FreeRTOS ------------------------------------------------------------*/
/* USER CODE BEGIN TASKS FREERTOS */

/**
 * @brief Task responsavel por gerenciar o led que informa que o sistema RTC
 * esta desconfigurado.
 */
void vRTC_Task_Led(void *pvParameters) {

	for (;;) {
		HAL_GPIO_TogglePin(DOUT_LED_RTC_GPIO_Port, DOUT_LED_RTC_Pin);
		vTaskDelay(pdMS_TO_TICKS(RTC_DELAY_LED));
	}
}
/* USER CODE END TASKS FREERTOS */

#ifdef rtcDEBUG
/* DEBUG ---------------------------------------------------------------------*/
/* USER CODE DEBUG */

/* USER CODE END TASKS FREERTOS */

#endif
