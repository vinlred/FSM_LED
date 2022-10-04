#ifndef FSMONOFF_H
#define FSMONOFF_H
#define STATE_OFF 0
#define STATE_ON 1
#define CHANGE 2
#define STATE_TRANS 3
#endif // FSMONOFF_H

void fsm(int input,int *prev_state,int *state,int *change_count,int *output);
