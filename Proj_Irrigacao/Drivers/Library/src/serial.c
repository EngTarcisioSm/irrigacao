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
 */
void vSERIAL_WriteMsg(uint8_t *pucMsg, uint8_t ucSize, xSerialTyeMessage_t xTypeMsg) {

	uint8_t ucBuffer[200];

	switch (xTypeMsg) {
		case 0:
			sprintf(ucBuffer, "LOG: %s", pucMsg);
			break;
		case 1:
			sprintf(ucBuffer, "WARN: %s", pucMsg);
			break;
		case 2:
			sprintf(ucBuffer, "ERROR: %s", pucMsg);
			break;
		case 3:
			sprintf(ucBuffer, "%s", pucMsg);
			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		default:
			break;
	}
#ifdef SERIAL_STM32

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
