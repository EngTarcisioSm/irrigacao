/* USER CODE BEGIN Header */
/**
 * @file           : rtc.h
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RTC_H
#define __RTC_H

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"

#include "serial.h"
#include "sys_eventgroups.h"
#include "sys_queues.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct InfoRTC_STUCT {
	uint8_t ucSeconds;
	uint8_t ucMinutes;
	uint8_t ucHours;
	uint8_t ucDay;
	uint8_t ucMonth;
	uint8_t ucYear;
}xInfoRTC;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define rtcDEBUG
#define RTC_DELAY_LED	500
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
extern RTC_HandleTypeDef hrtc;

extern EventGroupHandle_t xHandle_Event_Group;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void vRTC_CreateTaskLed(void);
void vRTC_CreateTaskCheckRTC(void);
void vRTC_CreateTaskConfigRTC(void);

void vRTC_Task_Led(void *pvParameters);
void vRTC_Task_CheckRTC(void *pvParameters);
void vRTC_Task_ConfigRTC(void *pvParameters);
/* USER CODE END PFP */


#endif /* __RTC_H */

/*******************************END OF FILE************************************/
