/* USER CODE BEGIN Header */
/**
 * @file           : serial.h
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SERIAL_H
#define __SERIAL_H

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main.h"
#include "string.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum {
	SERIAL_LOG = 0,
	SERIAL_WARNING = 1,
	SERIAL_ERROR = 2,
	SERIAL_TASK_CREATING = 3,
	SERIAL_TASK_CREATED = 4,
	SERIAL_TASK_ERROR = 5,
	SERIAL_LOG_DECIMAL = 6,
	SERIAL_LOG_TASK_STARTED = 7,
}xSerialTyeMessage_t;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define serialDEBUG
#define SERIAL_STM32

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
extern UART_HandleTypeDef huart1;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void vSERIAL_WriteMsg(void *pucMsg, xSerialTyeMessage_t xTypeMsg);
/* USER CODE END PFP */


#endif /* __SERIAL_H */

/*******************************END OF FILE************************************/
