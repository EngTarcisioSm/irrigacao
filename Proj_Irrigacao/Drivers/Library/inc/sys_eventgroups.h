/* USER CODE BEGIN Header */
/**
 * @file           : sys_eventgroups.h
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
#ifndef __SYS_EVENTGROUPS_H
#define __SYS_EVENTGROUPS_H

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
//#define sys_eventgroupsDEBUG

#define REQUEST_RTC		(1 << 0)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
static EventGroupHandle_t xHandle_Event_Group;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void vSYSEVENTGROUPS_CreateEventgroups(void);
/* USER CODE END PFP */


#endif /* __SYS_EVENTGROUPS_H */

/*******************************END OF FILE************************************/
