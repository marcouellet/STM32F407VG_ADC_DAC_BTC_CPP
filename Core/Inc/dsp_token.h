/*
 * dsp_token.h
 */

#ifndef INC_DSP_TOKEN_H_
#define INC_DSP_TOKEN_H_

#include <arm_math.h>

const int token_volume = 0;
const int token_bass = 1;
const int token_treble = 2;
const int token_balance = 3;
const int token_volume_max = 100;
const int token_balance_min = -50;
const int token_balance_equal = 0;
const int token_balance_max = 50;

const char TOKEN_VOLUME[] = "VOLUME";
const char TOKEN_BASS[] = "BASS";
const char TOKEN_TREBLE[] = "TREBLE";
const char TOKEN_BALANCE[] = "BALANCE";

extern int token_levels[4];

extern void get_token_value(char* str_token, uint16_t length, int* token, int* value);
extern int locate_token(char * buffer_start, int buffer_length, int* token_length);
extern void get_token_value(char* str_token, uint16_t length, int* token, int* value);
extern void process_token(int token, int value);
extern void process_token_updates(char buffer[]);

#endif /* INC_DSP_TOKEN_H_ */
