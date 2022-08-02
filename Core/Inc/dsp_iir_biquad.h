/*
 * dsp_iir_biquad.h
 */

#ifndef INC_DSP_IIR_BIQUAD_H_
#define INC_DSP_IIR_BIQUAD_H_

extern void init_dsp_iir_biquad();
extern void process_dsp_iir_biquad_bass_left(float32_t src[], float32_t dest[], int length);
extern void process_dsp_iir_biquad_bass_right(float32_t src[], float32_t dest[], int length);
extern void process_dsp_iir_biquad_treble_left(float32_t src[], float32_t dest[], int length);
extern void process_dsp_iir_biquad_treble_right(float32_t src[], float32_t dest[], int length);

#endif /* INC_DSP_IIR_BIQUAD_H_ */
