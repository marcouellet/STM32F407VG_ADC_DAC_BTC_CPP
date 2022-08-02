/*
 * dsp_main.c
 */

#include <dsp_main.h>
#include <dsp_token.h>
#include <dsp_simple.h>
#include <dsp_filter.h>
#include <dsp_fir.h>
#include <dsp_iir_biquad.h>
#include <dsp_biquad.h>
#include "string.h"
#include "math.h"

void init_dsp() {

	init_dsp_filter();
	init_dsp_biquad();
	init_dsp_fir();
	init_dsp_iir_biquad();
}

void process_dsp_clear(float32_t dest[], int length) {

	memset(dest, -1, length*sizeof(float32_t));
}

void process_dsp_with_factor(float32_t src[], float32_t dest[], int length, float factor) {

	float32_t srcval, dstval;

	for ( int i = 0 ; i < length ; i++ )
	{
		srcval = src[i]; // unsigned int and float does not work
		dstval = srcval * factor;
		dest[i] = dstval;
	}
}

//
// PROCESS BALANCE FILTERING
//

void process_dsp_balance_left(float32_t src[], float32_t dest[], int length) {

	float32_t balance_factor = 1;
	if (token_levels[token_balance] > 0) {
		balance_factor = 1 - (float)token_levels[token_balance] / token_balance_max;
	}

	process_dsp_with_factor(src, dest, length, balance_factor);
}

void process_dsp_balance_right(float32_t src[], float32_t dest[], int length) {

	float32_t balance_factor = 1;
	if (token_levels[token_balance] < 0) {
		balance_factor = 1 - (float)token_levels[token_balance] / token_balance_min;
	}

	process_dsp_with_factor(src, dest, length, balance_factor);
}

//
// PROCESS VOLUME FILTERING
//

void process_dsp_volume(float32_t src[], float32_t dest[], int length) {

	float32_t vol_factor = (float32_t)token_levels[token_volume] / token_volume_max;

	process_dsp_with_factor(src, dest, length, vol_factor);
}

//
// PROCESS DSP TONE CONTROL
//

void process_dsp_left(float32_t srcLeft[], float32_t destLeft[], int length) {

	float32_t wrkBuf[length];
	float32_t wrkBuf2[length];

	if (token_levels[token_balance] < token_balance_max && token_levels[token_volume] > 0) {
		//process_dsp_fir_bass_left(srcLeft, wrkBuf2, length);
		//process_dsp_simplp_bass(srcLeft, wrkBuf, length);
		//process_dsp_filter_bass_left(srcLeft, wrkBuf2, length);
		//process_dsp_biquad_bass_left(srcLeft, wrkBuf, length);
		process_dsp_iir_biquad_bass_left(srcLeft, wrkBuf, length);
		//process_dsp_fir_treble_left(wrkBuf, wrkBuf2, length);
		//process_dsp_simphp_treble(wrkBuf, wrkBuf2, length);
		//process_dsp_filter_treble_left(wrkBuf, wrkBuf2, length);
		//process_dsp_biquad_treble_left(wrkBuf, wrkBuf2, length);
		process_dsp_iir_biquad_treble_left(wrkBuf, wrkBuf2, length);
		process_dsp_balance_left(wrkBuf2, wrkBuf, length);
		process_dsp_volume(wrkBuf, destLeft, length);
	} else {
		process_dsp_clear(destLeft, length);
	}
}

void process_dsp_right(float32_t srcRight[], float32_t destRight[], int length) {

	float32_t wrkBuf[length];
	float32_t wrkBuf2[length];

	if (token_levels[token_balance] > token_balance_min && token_levels[token_volume] > 0) {
		//process_dsp_fir_bass_right(srcRight, wrkBuf2, length);
		//process_dsp_simplp_bass(srcRight, wrkBuf, length);
		//process_dsp_filter_bass_right(srcRight, wrkBuf2, length);
		//process_dsp_biquad_bass_right(srcRight, wrkBuf, length);
		process_dsp_iir_biquad_bass_right(srcRight, wrkBuf, length);
		//process_dsp_fir_treble_right(wrkBuf, wrkBuf2, length);
		//process_dsp_simphp_treble(wrkBuf, wrkBuf2, length);
		//process_dsp_filter_treble_right(wrkBuf, wrkBuf2, length);
		//process_dsp_biquad_treble_right(wrkBuf, wrkBuf2, length);
		process_dsp_iir_biquad_treble_right(wrkBuf, wrkBuf2, length);
		process_dsp_balance_right(wrkBuf2, wrkBuf, length);
		process_dsp_volume(wrkBuf, destRight, length);
	} else {
		process_dsp_clear(destRight, length);
	}
}

void process_dsp(float32_t srcLeft[], float32_t srcRight[], float32_t destLeft[], float32_t destRight[], int length) {

	process_dsp_left(srcLeft, destLeft, length);
	process_dsp_right(srcRight, destRight, length);
}
