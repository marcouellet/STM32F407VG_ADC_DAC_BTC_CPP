/*
 * dsp_fir.cpp
 */

#include <dsp_fir_bass.h>
#include <dsp_fir_treble.h>
#include <dsp_token.h>
#include <dsp_util.h>
#include <tone_control.h>

void process_dsp_fir_bass_left(float32_t src[], float32_t dest[], int length) {

	process_dsp_fir_bass_left(src, dest, get_level(token_levels[token_bass]));
}

void process_dsp_fir_bass_right(float32_t src[], float32_t dest[], int length) {

	process_dsp_fir_bass_right(src, dest, get_level(token_levels[token_bass]));
}

void process_dsp_fir_treble_left(float32_t src[], float32_t dest[], int length) {

	process_dsp_fir_treble_left(src, dest, get_level(token_levels[token_treble]));
}

void process_dsp_fir_treble_right(float32_t src[], float32_t dest[], int length) {

	process_dsp_fir_treble_right(src, dest, get_level(token_levels[token_treble]));
}

void init_dsp_fir() {

	init_dsp_fir_bass();
	init_dsp_fir_treble();
}


