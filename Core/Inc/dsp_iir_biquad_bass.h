/*
 * dsp_iit_biquad_bass.h
 */

#ifndef INC_DSP_IIR_BIQUAD_BASS_H_
#define INC_DSP_IIR_BIQUAD_BASS_H_

#include <arm_math.h>
#include <tone_control.h>

extern void init_dsp_iir_biquad_bass();
extern void process_dsp_iir_biquad_left_bass(float32_t srcLeft[], float32_t destLeft[], tone_intensity_level intensity_level);
extern void process_dsp_iir_biquad_right_bass(float32_t srcLeft[], float32_t destLeft[], tone_intensity_level intensity_level);
#endif /* INC_DSP_IIR_BIQUAD_BASS_H_ */
