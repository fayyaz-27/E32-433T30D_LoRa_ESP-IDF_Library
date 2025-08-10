// LoRa Module (E32-433T30D by EByte) Driver Code
// File Name: e32_lora_driver.h.c
// Author: Fayyaz Shaikh
// Email ID: fayyaz.shaikh24@spit.ac.in
// LinkedIn: https://www.linkedin.com/in/fayyaz-shaikh-7646312a3/ 


#ifndef E32_LORA_DRIVER_H
#define E32_LORA_DRIVER_H

esp_err_t e32_init(void);

esp_err_t e32_transmit(const char* data);

esp_err_t e32_receive(uint8_t *rx_data, size_t max_len);

esp_err_t e32_sleep_mode(void);

#endif