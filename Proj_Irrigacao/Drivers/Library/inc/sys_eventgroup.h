/* USER CODE BEGIN Header */
/**
 * @file           : sys_eventgroup.h
 * @brief          :
 ******************************************************************************
 * @attention
 *
 * Author:
 * Date: 24/07/2022
 *
 * Description:
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYS_EVENTGROUP_H
#define __SYS_EVENTGROUP_H

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"

#include "serial.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define sys_eventgroupDEBUG


#define REQUEST_RTC		(1 << 0)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
EventGroupHandle_t xHandle_Event_Group;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void vSYSEVENTGROUP_CreateEventgroups(void);
/* USER CODE END PFP */


#endif /* __SYS_EVENTGROUP_H */

/*******************************END OF FILE************************************/
