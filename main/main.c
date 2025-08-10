// LoRa Module (E32-433T30D by EByte) Driver Code
// File Name: main.c
// Author: Fayyaz Shaikh
// Email ID: fayyaz.shaikh24@spit.ac.in
// LinkedIn: https://www.linkedin.com/in/fayyaz-shaikh-7646312a3/ 

#include <stdio.h>
#include <string.h>
#include "esp_system.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "driver/uart.h"
#include "esp_macros.h"
#include "driver/gpio.h"
#include "e32_lora_driver.h"
#include <math.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

static const char *TAG_LORA = "E32 LoRa";

void app_main(){

    esp_err_t status_lora = e32_init();
     
    if (status_lora == ESP_OK){
        ESP_LOGI(TAG_LORA, "E32 LoRa Initialization Successful !");
    } 
    else {
        ESP_LOGE(TAG_LORA, "E32 LoRa Initialization Failed !");
    }

    vTaskDelay(pdMS_TO_TICKS(500));


    while(1){

    const char *message = "hi fayyaz from e32 LoRa !";
    status_lora = e32_transmit(message);
    if(status_lora == ESP_OK){
        ESP_LOGI(TAG_LORA, "E32 Data Sent");
    }
    else{
        ESP_LOGE(TAG_LORA, "E32 Data failed to send");
    }

    vTaskDelay(pdMS_TO_TICKS(2500));

    uint8_t rx_data[128];
    int len = 0;

    status_lora = e32_receive(rx_data, sizeof(rx_data));
    if (status_lora == ESP_OK){
        ESP_LOGI(TAG_LORA, "Data Received: %s", rx_data);
    }
    else {
        ESP_LOGI(TAG_LORA, "No Data Received: %d", status_lora);
    }
    // e32_sleep_mode();

        vTaskDelay(pdMS_TO_TICKS(5000));

    }

}