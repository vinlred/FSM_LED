#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\user\Desktop\Scanned\PSE\FSM_LED\OnOff\fsm\fsmonoff.c"
#include "C:\Users\user\Desktop\Scanned\PSE\FSM_LED\OnOff\fsm\fsmonoff.h"

int main(){
    int state = STATE_OFF;
    int input = 1;
    int output = 0;
    int prev_state = STATE_OFF;
    int change_count = 0;

    int test_case[20] = {100, 100, 100, 100, 750, 750, 750, 750, 1500, 1500, 1500, 1500, 3000, 3000, 3000, 3000, 5000, 5000, 5000, 5000};

    printf("Initial State = 0\n");
    for(int i=0; i<20; i++){
        for (int j=0;j<test_case[i];j++){
            fsm(input, &prev_state, &state, &change_count, &output);
        }
        printf("Input: %i, Duration: %i, State: %i, Output: %i, Prev: %i\n",input, test_case[i], state, output,prev_state);
        input = !input;
    }
    printf("Finish");
    return 0;
}

