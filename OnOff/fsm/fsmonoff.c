#include <stdio.h>
#include <stdlib.h>
#include "fsmonoff.h"

void fsm(int input,int prev_state,int *state,int *change_count,int *output){
	switch(*state)
{
	case STATE_ON:
	{
		*output = 1;
		if(input == 0){
		}
		else if(input == 1){
			*state = CHANGE;
			prev_state = STATE_ON;
			change_count = 0;
		}
		break;
	}
	case CHANGE:
	{
		*output = 1;
		if(change_count < 1000){
			if(input == 1){
				change_count += 1;
			}
			else{
				*state = STATE_ON;
			}
		}
		else{
			*state = STATE_TRANS;
			change_count = 0;
		}
		break;
	}
	case STATE_TRANS:
	{
		if(input == 0){
			if(prev_state == STATE_ON){
				*state = STATE_OFF;
			}
			else{
				*state = STATE_ON;
			}
		}
		break;
	}
	case STATE_OFF:
	{
		*output = 0;
		if(input == 1){
			*state = STATE_TRANS;
			prev_state = STATE_OFF;
			*output = 1;
		}
		break;
	}
	default:
	{
		break;
	}
}
				
			
		
		
	
	