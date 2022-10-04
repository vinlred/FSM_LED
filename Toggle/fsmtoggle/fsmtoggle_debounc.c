#include <stdio.h>
#include <stdlib.h>
#include "fsmtoggle_debounce.h"

void fsm(int *state, int input, int *output, int *debounce){
    switch(*state)
    {
    case STATE_OFF:
        {
			*debounce += 1;
            if(input==1 && *debounce > 75){
                *state=STATE_ON;
                *output = 1;
				*debounce = 0;
            }
            break;
        }
    case STATE_ON:
        {
			*debounce += 1;
            if(input==1 && *debounce > 75){
                *state=STATE_OFF;
                *output = 0;
				*debounce = 0;
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


