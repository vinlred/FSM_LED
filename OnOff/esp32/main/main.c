#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "fsmonoff.h"
#include "fsmonoff.c"

#define GPIO_OUTPUT 4
#define GPIO_OUTPUT_PIN_SEL (1ULL<<GPIO_OUTPUT)
#define GPIO_INPUT_PB 5
#define GPIO_INPUT_PIN_SEL (1ULL<<GPIO_INPUT_PB)

const TickType_t xDelay = 10 / portTICK_PERIOD_MS; // Set Frekuensi 1/10 ms = 100 Hz

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
	
	int input = 0;
	int prev_state = 0;
	int state = 0;
	int output = 0;
	int change_count = 0;
	
	while(1){
		input = !(gpio_get_level(GPIO_INPUT_PB));
		fsm(input, &prev_state, &state, &change_count,&output);
		printf("Input: %i,Output: %i, State: %i\n", input,output,state);
		gpio_set_level(GPIO_OUTPUT, output);
		vTaskDelay(xDelay);
	}
}