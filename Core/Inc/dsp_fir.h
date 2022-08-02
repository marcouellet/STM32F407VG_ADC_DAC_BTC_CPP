/*
 * dsp_fir.h
 */

#ifndef INC_DSP_FIR_H_
#define INC_DSP_FIR_H_

extern void init_dsp_fir();
extern void process_dsp_fir_bass_left(float32_t src[], float32_t dest[], int length);
extern void process_dsp_fir_bass_right(float32_t src[], float32_t dest[], int length);
extern void process_dsp_fir_treble_left(float32_t src[], float32_t dest[], int length);
extern void process_dsp_fir_treble_right(float32_t src[], float32_t dest[], int length);

#endif /* INC_DSP_FIR_H_ */
