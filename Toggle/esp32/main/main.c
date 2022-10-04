#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "fsmtoggle.h"
#include "fsmtoggle.c"

#define GPIO_OUTPUT 4
#define GPIO_OUTPUT_PIN_SEL (1ULL<<GPIO_OUTPUT)
#define GPIO_INPUT_PB 5
#define GPIO_INPUT_PIN_SEL (1ULL<<GPIO_INPUT_PB)
#define DELAY_MS 150

const TickType_t xDelay = DELAY_MS / portTICK_PERIOD_MS;

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
	
	int state = 0;
	int output = 0;
	int input = 0;
	int debounce = 0;
	
	while(1){
		input = !(gpio_get_level(GPIO_INPUT_PB));
		fsm(&state, input, &output, &debounce);
		printf("Input: %i,Output: %i, State: %i\n", input,output,state);
		gpio_set_level(GPIO_OUTPUT, output);
	}
}