#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\user\Desktop\Scanned\PSE\FSM_LED\Toggle\fsmtoggle\fsmtoggle.h"
#include "C:\Users\user\Desktop\Scanned\PSE\FSM_LED\Toggle\fsmtoggle\fsmtoggle.c"

int main(){
    int state = STATE_OFF;
    int input = 0;
    int output = 0;

    for(int i=0; i<10; i++){
        input = !input; // Alternating Input

        fsm(&state, input, &output);
        printf("Input: %i, State: %i, Output: %i\n",input, state, output);
    }
}
