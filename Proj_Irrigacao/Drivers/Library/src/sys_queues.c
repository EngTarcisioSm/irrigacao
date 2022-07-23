/* USER CODE BEGIN Header */
/**
 * @file           : sys_queues.c
 * @brief          :
 ******************************************************************************
 * @attention
 *
 * Author:
 * Date: 23/07/2022
 *
 * Description:
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "sys_queues.h"

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
void vSYSQUEUES_CreateQueueRTCRequest(void) {

	vSERIAL_WriteMsg("QUEUE RequestRTC sendo criada", SERIAL_LOG);
	if ((xQueueRequestRTC = xQueueCreate(1, sizeof(xInfoRTC*))) == NULL) {
		vSERIAL_WriteMsg("QUEUE RequestRTC não criada", SERIAL_ERROR);
		while(1);
	}
}
/* USER CODE END FUNCTION */

/* Tasks FreeRTOS ------------------------------------------------------------*/
/* USER CODE BEGIN TASKS FREERTOS */

/* USER CODE END TASKS FREERTOS */

#ifdef sys_queuesDEBUG
/* DEBUG ---------------------------------------------------------------------*/
/* USER CODE DEBUG */

/* USER CODE END TASKS FREERTOS */

#endif
