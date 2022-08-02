/*
 * dsp_main.h
 */

#ifndef INC_DSP_MAIN_H_
#define INC_DSP_MAIN_H_

#include "main.h"
#include <arm_math.h>

extern void init_dsp();
extern void process_dsp(float32_t srcLeft[], float32_t srcRight[], float32_t destLeft[], float32_t destRight[], int length);

#endif /* INC_DSP_MAIN_H_ */
