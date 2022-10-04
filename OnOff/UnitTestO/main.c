#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\user\Desktop\Scanned\PSE\FSM_LED\OnOff\fsm\fsmonoff.c"
#include "C:\Users\user\Desktop\Scanned\PSE\FSM_LED\OnOff\fsm\fsmonoff.h"

int main(){
    int state = STATE_OFF;
    int input = 0;
    int output = 0;
    int prev_state = STATE_OFF;
    int change_count = 0;

    int press_dur = 0;

    printf("Test Case 1\n");
    input = 1;
    output = 0;
    state = STATE_OFF;
    press_dur = 100;

    //printf("Input: %i, Duration: %i, State: %i, Output: %i, Prev: %i\n",input, press_dur, state, output,prev_state);
    printf("Initial State = %i, Input = %i for %i ms\n",state, input, press_dur);
    for (int j=0;j<press_dur;j++){
        fsm(input, &prev_state, &state, &change_count, &output);
    }
    printf("Expected result Final Output : LED_ON (1), Final State = Transition (3)\n");
    printf("Final Output: %i, Final State: %i\n",output,state);
    if(output==1 && state==3){
        printf("Test Succeded\n");
    }
    else{
        printf("Test Failed\n");
    }

    printf("\n");

    printf("Test Case 2\n");
    input = 1;
    output = 0;
    state = STATE_OFF;
    press_dur = 10000;

    //printf("Input: %i, Duration: %i, State: %i, Output: %i, Prev: %i\n",input, press_dur, state, output,prev_state);
    printf("Initial State = %i, Input = %i for %i ms\n",state, input, press_dur);
    for (int j=0;j<press_dur;j++){
        fsm(input, &prev_state, &state, &change_count, &output);
    }
    printf("Expected result Final Output : LED_ON (1), Final State = Transition (3)\n");
    printf("Final Output: %i, Final State: %i\n",output,state);
    if(output==1 && state==3){
        printf("Test Succeded\n");
    }
    else{
        printf("Test Failed\n");
    }

    printf("\n");

    printf("Test Case 3\n");
    input = 1;
    output = 0;
    state = STATE_OFF;
    press_dur = 100;

    //printf("Input: %i, Duration: %i, State: %i, Output: %i, Prev: %i\n",input, press_dur, state, output,prev_state);
    printf("Initial State = %i, Input = %i for %i ms and release\n",state, input, press_dur);
    for (int j=0;j<press_dur;j++){
        fsm(input, &prev_state, &state, &change_count, &output);
    }
    input = 0;
    fsm(input, &prev_state, &state, &change_count, &output);
    printf("Expected result Final Output : LED_ON (1), Final State = STATE_ON (1)\n");
    printf("Final Output: %i, Final State: %i\n",output,state);
    if(output==1 && state==1){
        printf("Test Succeded\n");
    }
    else{
        printf("Test Failed\n");
    }

    printf("\n");

    printf("Test Case 4\n");
    input = 1;
    output = 0;
    state = STATE_OFF;
    press_dur = 10000;

    //printf("Input: %i, Duration: %i, State: %i, Output: %i, Prev: %i\n",input, press_dur, state, output,prev_state);
    printf("Initial State = %i, Input = %i for %i ms and release\n",state, input, press_dur);
    for (int j=0;j<press_dur;j++){
        fsm(input, &prev_state, &state, &change_count, &output);
    }
    input = 0;
    fsm(input, &prev_state, &state, &change_count, &output);
    printf("Expected result Final Output : LED_ON (1), Final State = STATE_ON (1)\n");
    printf("Final Output: %i, Final State: %i\n",output,state);
    if(output==1 && state==1){
        printf("Test Succeded\n");
    }
    else{
        printf("Test Failed\n");
    }

    printf("\n");

        printf("Test Case 5\n");
    input = 0;
    output = 0;
    state = STATE_OFF;
    press_dur = 1000;

    //printf("Input: %i, Duration: %i, State: %i, Output: %i, Prev: %i\n",input, press_dur, state, output,prev_state);
    printf("Initial State = %i, Input = %i for %i ms\n",state, input, press_dur);
    for (int j=0;j<press_dur;j++){
        fsm(input, &prev_state, &state, &change_count, &output);
    }
    printf("Expected result Final Output : LED_OFF (0), Final State = STATE_OFF(0)\n");
    printf("Final Output: %i, Final State: %i\n",output,state);
    if(output==0 && state==0){
        printf("Test Succeded\n");
    }
    else{
        printf("Test Failed\n");
    }

    printf("\n");

    printf("Test Case 6\n");
    input = 1;
    output = 1;
    state = STATE_ON;
    press_dur = 100;

    //printf("Input: %i, Duration: %i, State: %i, Output: %i, Prev: %i\n",input, press_dur, state, output,prev_state);
    printf("Initial State = %i, Input = %i for %i ms and release\n",state, input, press_dur);
    for (int j=0;j<press_dur;j++){
        fsm(input, &prev_state, &state, &change_count, &output);
    }
    input = 0;
    fsm(input, &prev_state, &state, &change_count, &output);
    printf("Expected result Final Output : LED_ON (1), Final State = STATE_ON (1)\n");
    printf("Final Output: %i, Final State: %i\n",output,state);
    if(output==1 && state==1){
        printf("Test Succeded\n");
    }
    else{
        printf("Test Failed\n");
    }

    printf("\n");

    printf("Test Case 7\n");
    input = 1;
    output = 1;
    state = STATE_ON;
    press_dur = 10000;

    //printf("Input: %i, Duration: %i, State: %i, Output: %i, Prev: %i\n",input, press_dur, state, output,prev_state);
    printf("Initial State = %i, Input = %i for %i ms and release\n",state, input, press_dur);
    for (int j=0;j<press_dur;j++){
        fsm(input, &prev_state, &state, &change_count, &output);
    }
    input = 0;
    fsm(input, &prev_state, &state, &change_count, &output);
    printf("Expected result Final Output : LED_OFF (0), Final State = STATE_OFF (0)\n");
    printf("Final Output: %i, Final State: %i\n",output,state);
    if(output==0 && state==0){
        printf("Test Succeded\n");
    }
    else{
        printf("Test Failed\n");
    }

    printf("\n");

    printf("Test Case 8\n");
    input = 1;
    output = 1;
    state = STATE_ON;
    press_dur = 10000;

    //printf("Input: %i, Duration: %i, State: %i, Output: %i, Prev: %i\n",input, press_dur, state, output,prev_state);
    printf("Initial State = %i, Input = %i for %i ms\n",state, input, press_dur);
    for (int j=0;j<press_dur;j++){
        fsm(input, &prev_state, &state, &change_count, &output);
    }
    printf("Expected result Final Output : LED_OFF (0), Final State = TRANSITION (3)\n");
    printf("Final Output: %i, Final State: %i\n",output,state);
    if(output==0 && state==3){
        printf("Test Succeded\n");
    }
    else{
        printf("Test Failed\n");
    }

    printf("\n");

    printf("Test Case 9\n");
    input = 1;
    output = 1;
    state = STATE_ON;
    press_dur = 100;

    //printf("Input: %i, Duration: %i, State: %i, Output: %i, Prev: %i\n",input, press_dur, state, output,prev_state);
    printf("Initial State = %i, Input = %i for %i ms\n",state, input, press_dur);
    for (int j=0;j<press_dur;j++){
        fsm(input, &prev_state, &state, &change_count, &output);
    }
    printf("Expected result Final Output : LED_ON (1), Final State = CHANGE (2)\n");
    printf("Final Output: %i, Final State: %i\n",output,state);
    if(output==1 && state==2){
        printf("Test Succeded\n");
    }
    else{
        printf("Test Failed\n");
    }

    printf("\n");

    printf("Test Case 10\n");
    input = 1;
    output = 1;
    state = STATE_ON;
    press_dur = 100;

    //printf("Input: %i, Duration: %i, State: %i, Output: %i, Prev: %i\n",input, press_dur, state, output,prev_state);
    printf("Initial State = %i, Input = %i for %i ms and release\n",state, input, press_dur);
    for (int j=0;j<press_dur;j++){
        fsm(input, &prev_state, &state, &change_count, &output);
    }
    input = 0;
    fsm(input, &prev_state, &state, &change_count, &output);
    printf("Expected result Final Output : LED_ON (1), Final State = STATE_ON (1)\n");
    printf("Final Output: %i, Final State: %i\n",output,state);
    if(output==1 && state==1){
        printf("Test Succeded\n");
    }
    else{
        printf("Test Failed\n");
    }

    printf("\n");
}

