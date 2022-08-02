/*
 * dsp_filter.h
 */

#ifndef INC_DSP_FILTER_H_
#define INC_DSP_FILTER_H_

extern void init_dsp_filter();
extern void process_dsp_filter_bass_left(float32_t src[], float32_t dest[], int length);
extern void process_dsp_filter_bass_right(float32_t src[], float32_t dest[], int length);
extern void process_dsp_filter_treble_left(float32_t src[], float32_t dest[], int length);
extern void process_dsp_filter_treble_right(float32_t src[], float32_t dest[], int length);

#endif /* INC_DSP_FILTER_H_ */
