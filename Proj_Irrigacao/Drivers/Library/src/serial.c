/* USER CODE BEGIN Header */
/**
 * @file           : serial.c
 * @brief          :
 ******************************************************************************
 * @attention
 *
 * Author:
 * Date: 22/07/2022
 *
 * Description:
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "serial.h"

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

/**
 * @brief função de escrita na serial
 *
 * @param pucMsg ponteiro buffer da mensagem
 * @param ucSize quantidade de caracteres na mensagem
 * @param ucType tipo de mensagem a ser escrita
 * @note SERIAL_LOG: Mensagem de log
 * @note SERIAL_WARNING: Mensagem de Warning
 * @note SERIAL_ERROR: Mensagem de Erro
 * @note SERIAL_TASK_CREATING: Mensagem de Log de task sendo criada
 * @note SERIAL_TASK_CREATED: Mensagem de Log de task criada
 * @note SERIAL_TASK_ERROR: Erro na criação da task
 * @note SERIAL_LOG_DECIMAL: imprime valores numericos de tipo inteiro 
 * @note SERIAL_LOG_TASK_STARTED: task inicializada
 */
void vSERIAL_WriteMsg(void *pucMsg, xSerialTyeMessage_t xTypeMsg) {

	uint8_t ucBuffer[200];
	uint16_t usSize;

	memset(ucBuffer, 0x00, 200);
	switch (xTypeMsg) {
		case 0:
			sprintf(ucBuffer, "LOG: %s\r\n", (char*)pucMsg);
			break;
		case 1:
			sprintf(ucBuffer, "WARNING: %s\r\n", (char*)pucMsg);
			break;
		case 2:
			sprintf(ucBuffer, "ERROR: %s\r\n", (char*)pucMsg);
			break;
		case 3:
			sprintf(ucBuffer, "LOG: Task %s sendo criada...\r\n", (char*)pucMsg);
			break;
		case 4:
			sprintf(ucBuffer, "LOG: Task %s criada\r\n", (char*)pucMsg);
			break;
		case 5:
			sprintf(ucBuffer, "ERROR: Falha na criacao da Task %s\r\n", (char*)pucMsg);
			break;
		case 6:
			sprintf(ucBuffer, "LOG: %d\r\n", (uint32_t)pucMsg);
			break;
		case 7:
			sprintf(ucBuffer, "LOG: Task %s iniciada...\r\n", (char*)pucMsg);
			break;
		default:
			break;
	}
	usSize = strlen((char*)ucBuffer);
#ifdef SERIAL_STM32
	HAL_UART_Transmit(&huart1, ucBuffer, usSize, 100);
#endif

#ifdef SERIAL_ESP32

#endif
}
/* USER CODE END FUNCTION */

/* Tasks FreeRTOS ------------------------------------------------------------*/
/* USER CODE BEGIN TASKS FREERTOS */

/* USER CODE END TASKS FREERTOS */

#ifdef serialDEBUG
/* DEBUG ---------------------------------------------------------------------*/
/* USER CODE DEBUG */

/* USER CODE END TASKS FREERTOS */

#endif
