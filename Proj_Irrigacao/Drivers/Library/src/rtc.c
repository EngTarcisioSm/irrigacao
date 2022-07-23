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

/**
 * @brief cria a task de aviso de rtc desconfigurado
 */
void vRTC_CreateTaskLed(void) {
	#ifdef DEBUG_ON
	vSERIAL_WriteMsg("LED_RTC", SERIAL_TASK_CREATING);
		#endif
	if ((xTaskCreate(vRTC_Task_Led, "LED_RTC", configMINIMAL_STACK_SIZE * 2,
			NULL, 1, NULL)) != pdTRUE) {
		#ifdef DEBUG_ON
		vSERIAL_WriteMsg("LED_RTC", SERIAL_TASK_ERROR);
		#endif
		while (1) {
			/**
			 * @author Task não foi criada, resetar o sistema
			 */
		}
	}
}

/**
 * @brief cria a task de obtenção de dados do RTC
 */
void vRTC_CreateTaskCheckRTC(void) {
	#ifdef DEBUG_ON
	vSERIAL_WriteMsg("CheckRTC", SERIAL_TASK_CREATING);
	#endif
	if ((xTaskCreate(vRTC_Task_CheckRTC, "CheckRTC", configMINIMAL_STACK_SIZE * 2,
			NULL, 1, NULL)) != pdTRUE) {
		#ifdef DEBUG_ON
		vSERIAL_WriteMsg("LED_RTC", SERIAL_TASK_ERROR);
		#endif
		while (1) {
			/**
			 * @author Task não foi criada, resetar o sistema
			 */
		}
	}
}

void vRTC_CreateTaskConfigRTC(void) {
	#ifdef DEBUG_ON
	vSERIAL_WriteMsg("ConfigRTC", SERIAL_TASK_CREATING);
	#endif
	if ((xTaskCreate(vRTC_Task_ConfigRTC, "CheckRTC", configMINIMAL_STACK_SIZE * 3,
			NULL, 1, NULL)) != pdTRUE) {
		#ifdef DEBUG_ON
		vSERIAL_WriteMsg("ConfigRTC", SERIAL_TASK_ERROR);
		#endif
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
#ifdef DEBUG_ON
	vSERIAL_WriteMsg("LED_RTC", SERIAL_LOG_TASK_STARTED);
#endif
	for (;;) {
		HAL_GPIO_TogglePin(DOUT_LED_RTC_GPIO_Port, DOUT_LED_RTC_Pin);
		vTaskDelay(pdMS_TO_TICKS(RTC_DELAY_LED));
	}
}

/**
 * @brief teste de obtenção dos dados do rtc
 */
void vRTC_Task_CheckRTC(void *pvParameters) {

	RTC_TimeTypeDef xReqTime;
	RTC_DateTypeDef xReqDate;
	xInfoRTC xRTC;
	xInfoRTC *pxRTC = &xRTC;

#ifdef DEBUG_ON
	vSERIAL_WriteMsg("CheckRTC", SERIAL_LOG_TASK_STARTED);
#endif
	for (;;) {
		/*EVENT GROUP DE SOLITICAÇÃO DE DATA DO SISTEMA*/
		xEventGroupWaitBits(xHandle_Event_Group, REQUEST_RTC, pdTRUE, pdTRUE, portMAX_DELAY);

		/*OBTENÇÃO DOS DADOS*/
		HAL_RTC_GetDate(&hrtc, &xReqDate, RTC_FORMAT_BIN);
		HAL_RTC_GetTime(&hrtc, &xReqTime, RTC_FORMAT_BIN);

		xRTC.ucSeconds = xReqTime.Seconds;
		xRTC.ucMinutes = xReqTime.Minutes;
		xRTC.ucHours = xReqTime.Hours;
		xRTC.ucDay = xReqDate.Date;
		xRTC.ucMonth = xReqDate.Month;
		xRTC.ucYear = xReqDate.Year;

		/*ESCREVE NA QUEUE INFORMAÇÃO DE TEMPO*/
		xQueueSend(xQueueRequestRTC, (void *)&pxRTC, portMAX_DELAY);

	}
}


/**
 * @brief task de checagem dos dados do rtc e configuracao do mesmo
 */
void vRTC_Task_ConfigRTC(void *pvParameters) {

	xInfoRTC *pxRTC;
	uint8_t ucAux00;

#ifdef DEBUG_ON
	vSERIAL_WriteMsg("ConfigRTC", SERIAL_LOG_TASK_STARTED);
#endif
	for(;;) {
		/**
		 * author: acorda task de checagem de tempo
		 */
		xEventGroupSetBits(xHandle_Event_Group, REQUEST_RTC);

		/**
		 * author: espera resposta da quest a respeito dos dados de tempo
		 */
		xQueueReceive(xQueueRequestRTC, &pxRTC, portMAX_DELAY);

		/**
		 * author: verifica se o ano do rtc esta configurado apropriadamente
		 * caso negativo indica que o sistema rtc ainda não foi configurado
		 * habilita a task de led informando que o sistema não foi configurado
		 */
		ucAux00 = pxRTC->ucYear;
		if(ucAux00 == 0x00) {
			vSERIAL_WriteMsg("Relogio nao configurado", SERIAL_WARNING);
			vRTC_CreateTaskLed();


			/*proximos passos*/




			/**
			 * @author: Ao final de toda a configuração deletar a quest
			 */
			vTaskDelete(NULL);
		} else {
			/**
			 * author: rtc esta configurado apropriadamente deve-se seguir para as proximas
			 * checagens antes de inicializar o sistema propriamente dito, chamando a proxima
			 * tarefa e deletando esta ao final
			 */



			/*proximos passos*/





			vTaskDelete(NULL);
		}
	}
}
/* USER CODE END TASKS FREERTOS */

#ifdef rtcDEBUG
/* DEBUG ---------------------------------------------------------------------*/
/* USER CODE DEBUG */

/* USER CODE END TASKS FREERTOS */

#endif
