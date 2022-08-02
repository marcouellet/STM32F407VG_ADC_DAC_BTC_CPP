/*
 * dsp_biquad.cpp
 */

#include <biquad.hpp>
#include <arm_math.h>
#include <tone_control.h>
#include <dsp_util.h>
#include <dsp_token.h>

tone_intensity_level bass_biquad_intensity_level = NONE;
tone_intensity_level treble_biquad_intensity_level = NONE;

Biquad* bass_biquad_left = NULL;
Biquad* bass_biquad_right = NULL;
Biquad* treble_biquad_left = NULL;
Biquad* treble_biquad_right = NULL;

void process_dsp_biquad(Biquad* pbiquad, float32_t src[], float32_t dest[], int length) {

	if (pbiquad != NULL) {

		for ( int i = 0 ; i < length ; i++ )
		{
			dest[i] = pbiquad->process(src[i]);
		}

	} else {
		dsp_copy(src, dest, length);
	}
}

Biquad* get_biquad_for_level(tone_intensity_level intensity_level) {

	Biquad* biquad = NULL;

	switch (intensity_level) {

	case NONE:
		break;
	case LOW_STRONG:
		biquad = new Biquad(bq_type_lowshelf, .0208, 1, -9.0);
		break;
	case LOW_MODERATE:
		biquad = new Biquad(bq_type_lowshelf, .0208, 1, -6.0);
		break;
	case LOW_WEAK:
		biquad = new Biquad(bq_type_lowshelf, .0208, 1, -3.0);
		break;
	case NEUTRAL:
		biquad = new Biquad(bq_type_lowshelf, .0208, 1, 0.0);
		break;
	case HIGH_WEAK:
		//	return new Biquad(bq_type_lowshelf, .021, 1, 3.0);
		biquad = new Biquad(bq_type_lowshelf, .0208, 1, 3.0);
		break;
	case HIGH_MODERATE:
		biquad = new Biquad(bq_type_lowshelf, .0208, 1, 6.0);
		break;
	case HIGH_STRONG:
		biquad = new Biquad(bq_type_lowshelf, .0208, 1, 9.0);
		break;
	}

	return biquad;
}


void set_dsp_biquad_bass_for_level(tone_intensity_level intensity_level) {

	if (bass_biquad_intensity_level != intensity_level) {

		bass_biquad_intensity_level = intensity_level;

		if (bass_biquad_left != NULL)
			delete bass_biquad_left;
		if (bass_biquad_right != NULL)
			delete bass_biquad_right;

		bass_biquad_left = bass_biquad_right = get_biquad_for_level(bass_biquad_intensity_level);
	}
}

void set_dsp_biquad_treble_for_level(tone_intensity_level intensity_level) {

	if (treble_biquad_intensity_level != intensity_level) {

		treble_biquad_intensity_level = intensity_level;

		if (treble_biquad_left != NULL)
			delete treble_biquad_left;
		if (treble_biquad_right != NULL)
			delete treble_biquad_right;

		treble_biquad_left = treble_biquad_right = get_biquad_for_level(treble_biquad_intensity_level);;
	}
}

void process_dsp_biquad_bass_left(float32_t src[], float32_t dest[], int length) {

	set_dsp_biquad_bass_for_level(get_level(token_levels[token_bass]));
	process_dsp_biquad(bass_biquad_left, src, dest, length);
}

void process_dsp_biquad_bass_right(float32_t src[], float32_t dest[], int length) {

	set_dsp_biquad_bass_for_level(get_level(token_levels[token_bass]));
	process_dsp_biquad(bass_biquad_right, src, dest, length);
}

void process_dsp_biquad_treble_left(float32_t src[], float32_t dest[], int length) {

	set_dsp_biquad_treble_for_level(get_level(token_levels[token_treble]));
	process_dsp_biquad(treble_biquad_left, src, dest, length);
}

void process_dsp_biquad_treble_right(float32_t src[], float32_t dest[], int length) {

	set_dsp_biquad_treble_for_level(get_level(token_levels[token_treble]));
	process_dsp_biquad(treble_biquad_right, src, dest, length);
}

void init_dsp_biquad() {

	set_dsp_biquad_bass_for_level(NEUTRAL);
	set_dsp_biquad_treble_for_level(NEUTRAL);
}
