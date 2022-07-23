/* USER CODE BEGIN Header */
/**
 * @file           : sys_queues.h
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYS_QUEUES_H
#define __SYS_QUEUES_H

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include "rtc.h"
#include "serial.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define sys_queuesDEBUG

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
QueueHandle_t xQueueRequestRTC;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void vSYSQUEUES_CreateQueueRTCRequest(void);
/* USER CODE END PFP */


#endif /* __SYS_QUEUES_H */

/*******************************END OF FILE************************************/
