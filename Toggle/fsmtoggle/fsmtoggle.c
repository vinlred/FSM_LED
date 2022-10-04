#include <stdio.h>
#include <stdlib.h>
#include "fsmtoggle.h"

void fsm(int *state, int input, int *output){
    switch(*state)
    {
    case STATE_OFF:
        {
            if(input==1){
                *state=STATE_ON;
                *output = 1;
            }
            break;
        }
    case STATE_ON:
        {
            if(input==1){
                *state=STATE_OFF;
                *output = 0;
            }
            break;
        }
    default:
        {
        break;
        }
    }
}
/*
int main(){
    int *state = STATE_OFF;
    int input = 1;
    int output;

    printf("%i\n",state);
    fsm(&state,input,output);
    printf("%i",state);
}*/


