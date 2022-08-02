/*
 * dsp_fir_taps21_bass.h
 */

#ifndef INC_DSP_FIR_TAPS21_BASS_H_
#define INC_DSP_FIR_TAPS21_BASS_H_

#include <arm_math.h>
#include <tone_control.h>

extern void init_dsp_fir_taps21_bass();
extern void process_dsp_fir_taps21_bass_left(float32_t srcLeft[], float32_t destLeft[], tone_intensity_level level);
extern void process_dsp_fir_taps21_bass_right(float32_t srcRight[], float32_t destRight[], tone_intensity_level level);


#endif /* INC_DSP_FIR_TAPS21_BASS_H_ */
