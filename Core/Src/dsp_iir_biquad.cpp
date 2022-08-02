/*
 * dsp_iir_biquad.cpp
 */

#include <dsp_iir_biquad_bass.h>
#include <dsp_iir_biquad_treble.h>
#include <dsp_token.h>
#include <dsp_util.h>

void process_dsp_iir_biquad_bass_left(float32_t src[], float32_t dest[], int length) {

	process_dsp_iir_biquad_left_bass(src, dest, get_level(token_levels[token_bass]));
}

void process_dsp_iir_biquad_bass_right(float32_t src[], float32_t dest[], int length) {

	process_dsp_iir_biquad_right_bass(src, dest, get_level(token_levels[token_bass]));
}

void process_dsp_iir_biquad_treble_left(float32_t src[], float32_t dest[], int length) {

	process_dsp_iir_biquad_left_treble(src, dest, get_level(token_levels[token_treble]));
}

void process_dsp_iir_biquad_treble_right(float32_t src[], float32_t dest[], int length) {

	process_dsp_iir_biquad_right_treble(src, dest, get_level(token_levels[token_treble]));
}

void init_dsp_iir_biquad() {

	init_dsp_iir_biquad_bass();
	init_dsp_iir_biquad_treble();
}


