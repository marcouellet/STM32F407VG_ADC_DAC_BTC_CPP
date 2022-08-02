/*
 * dsp_simple.h
 */

#ifndef INC_DSP_SIMPLE_H_
#define INC_DSP_SIMPLE_H_

#include <arm_math.h>

/* C function implementing the simplest low pass filter
 */

extern void process_dsp_simplp_bass(float32_t src[], float32_t dest[], int length);
extern void process_dsp_simphp_treble(float32_t src[], float32_t dest[], int length);

#endif /* INC_DSP_SIMPLE_H_ */
