#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define GPIO_OUTPUT 4
#define GPIO_OUTPUT_PIN_SEL (1ULL<<GPIO_OUTPUT)
#define GPIO_INPUT_PB 5
#define GPIO_INPUT_PIN_SEL (1ULL<<GPIO_INPUT_PB)
#define DELAY_MS 150

const TickType_t xDelay = DELAY_MS / portTICK_PERIOD_MS;

int state = 0;

void app_main(){
	gpio_config_t io_conf;
	io_conf.intr_type = 0;
	io_conf.mode = GPIO_MODE_OUTPUT;
	io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
	io_conf.pull_down_en = 0;
	io_conf.pull_up_en = 0;
	gpio_config(&io_conf);
	io_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
	io_conf.mode = GPIO_MODE_INPUT; // mode input
	io_conf.pull_up_en = 1; // menggunakan pull up
	gpio_config(&io_conf);
	
	uint8_t prev_state = 0;
	
	while(1){
		if (gpio_get_level(GPIO_INPUT_PB) == 0) {
			vTaskDelay(xDelay);
			prev_state = !prev_state;
			
			gpio_set_level(GPIO_OUTPUT, prev_state);
			vTaskDelay(xDelay);
		}
		/*else{
			prev_state = !prev_state;
			gpio_set_level(GPIO_OUTPUT, prev_state);
			vTaskDelay(xDelay);
		}*/
	}
}