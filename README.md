# PROJETO REPETIDOR 

## 24 07 2022
- Criada a task  de requisição de dados de rtc para o usuário 
    - A task é criada a partir do momento em que é verificado que o rtc esta desconfigurado 
    - A task ainda esta no esqueleto faltando criar sua lógica 
    - vRTC_Task_RequestUserRTC
- Aparentemente é possivel alocar o eventgroup em outro arquivo C, desde que o handle não seja alocado com o tipo static 

## 23 07 2022
- 3 PROBLEMAS: 
    - o EVENTGROUP esta travando a task de configuração do rtc verificar possivel solução movendo o event groupara pa propria biblioteca do rtc
- 2 Criada bibliotecas de 
    - eventgroup
    - queue
- 1 Biblioteca serial para mensagens de sistema criada

## 22 07 2022
- Fluxograma de configuração do RTC e Alarme 
- Habilitação do RTC
- Criada função que avisa rtc desconfigurado via led(toggle)
    - Validado
- Inicio da biblioteca serial

## 21 07 2022
- Criação do fluxograma de trabalho;
- Criação do projeto stm32cubeIDE;