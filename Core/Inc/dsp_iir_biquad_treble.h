/*
 * dsp_iir_biquad_treble.h
 */

#ifndef INC_DSP_IIR_BIQUAD_TREBLE_H_
#define INC_DSP_IIR_BIQUAD_TREBLE_H_

#include <arm_math.h>
#include <tone_control.h>

extern void init_dsp_iir_biquad_treble();
extern void process_dsp_iir_biquad_left_treble(float32_t srcLeft[], float32_t destLeft[], tone_intensity_level intensity_level);
extern void process_dsp_iir_biquad_right_treble(float32_t srcLeft[], float32_t destLeft[], tone_intensity_level intensity_level);

#endif /* INC_DSP_IIR_BIQUAD_TREBLE_H_ */
