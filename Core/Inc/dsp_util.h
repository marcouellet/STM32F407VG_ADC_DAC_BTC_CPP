/*
 * dsp_util.h
 */

#ifndef INC_DSP_UTIL_H_
#define INC_DSP_UTIL_H_

#include <arm_math.h>

extern uint8_t string_compare(const char array1[], const char array2[], uint16_t length);
extern int char2int (const char *array, size_t n);
extern char* int2char(const int value, char* result);
extern void dsp_copy(float32_t src[], float32_t dest[], int length);

#endif /* INC_DSP_UTIL_H_ */
