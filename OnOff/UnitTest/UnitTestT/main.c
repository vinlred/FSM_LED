#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\user\Desktop\Scanned\PSE\FSM_LED\Toggle\fsmtoggle\fsmtoggle.h"
#include "C:\Users\user\Desktop\Scanned\PSE\FSM_LED\Toggle\fsmtoggle\fsmtoggle.c"

int main(){
    int state = STATE_OFF;
    int input = 0;
    int output = 0;

    printf("Test Case 1\n");
    input = 1;
    output = 0;
    state = STATE_OFF;
    fsm(&state, input, &output);
    printf("Input = 1, Initial State = 0\n");
    printf("Expected result Final Output : 1, Final State = 1\n");
    printf("Final Output: %i, Final State: %i\n",output,state);
    if(output==1 && state==1){
        printf("Test Succeded\n");
    }
    else{
        printf("Test Failed\n");
    }

    printf("\n");

    printf("Test Case 2\n");
    input = 1;
    output = 1;
    state = STATE_ON;
    fsm(&state, input, &output);
    printf("Input = 1, Initial State = 1\n");
    printf("Expected result Final Output : 0, Final State = 0\n");
    printf("Final Output: %i, Final State: %i\n",output,state);
    if(output==0 && state==0){
        printf("Test Succeded\n");
    }
    else{
        printf("Test Failed\n");
    }

    printf("\n");

    printf("Test Case 3\n");
    input = 0;
    output = 0;
    state = STATE_OFF;
    fsm(&state, input, &output);
    printf("Input = 0, Initial State = 0\n");
    printf("Expected result Final Output : 0, Final State = 0\n");
    printf("Final Output: %i, Final State: %i\n",output,state);
    if(output==0 && state==0){
        printf("Test Succeded\n");
    }
    else{
        printf("Test Failed\n");
    }

    printf("\n");

    printf("Test Case 4\n");
    input = 0;
    output = 1;
    state = STATE_ON;
    fsm(&state, input, &output);
    printf("Input = 1, Initial State = 1\n");
    printf("Expected result Final Output : 1, Final State = 1\n");
    printf("Final Output: %i, Final State: %i\n",output,state);
    if(output==1 && state==1){
        printf("Test Succeded\n");
    }
    else{
        printf("Test Failed\n");
    }

    printf("\n");
}
