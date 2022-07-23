/* USER CODE BEGIN Header */
/**
 * @file           : sys_eventgroups.c
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
#include "sys_eventgroups.h"

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
void vSYSEVENTGROUPS_CreateEventgroups(void){
#ifdef DEBUG_ON
	vSERIAL_WriteMsg("Event_Group criado", SERIAL_LOG);
#endif
	xHandle_Event_Group = xEventGroupCreate();
}
/* USER CODE END FUNCTION */

/* Tasks FreeRTOS ------------------------------------------------------------*/
/* USER CODE BEGIN TASKS FREERTOS */

/* USER CODE END TASKS FREERTOS */

#ifdef sys_eventgroupsDEBUG
/* DEBUG ---------------------------------------------------------------------*/
/* USER CODE DEBUG */

/* USER CODE END TASKS FREERTOS */

#endif
