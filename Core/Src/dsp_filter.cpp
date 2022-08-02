/*
 * dsp_filter.cpp
 */

#include <filter.hpp>
#include <arm_math.h>
#include <tone_control.h>
#include <dsp_util.h>
#include <dsp_token.h>

tone_intensity_level bass_filter_intensity_level = NONE;
tone_intensity_level treble_filter_intensity_level = NONE;

Filter* bass_filter_left = NULL;
Filter* bass_filter_right = NULL;
Filter* treble_filter_left = NULL;
Filter* treble_filter_right = NULL;

void process_dsp_filter(Filter* pfilter, float32_t src[], float32_t dest[], int length) {

	if (pfilter != NULL) {

		for ( int i = 0 ; i < length ; i++ )
		{
			dest[i] = pfilter->do_sample(src[i]);
		}

	} else {
		dsp_copy(src, dest, length);
	}
}

Filter* get_dsp_filter_for_level(tone_intensity_level intensity_level) {

	Filter* filter = NULL;

	switch (intensity_level) {

	case NONE:
		break;
	case LOW_STRONG:
		filter = new Filter(LPF, 61, 48, -12.0);
		break;
	case LOW_MODERATE:
		filter = new Filter(LPF, 61, 48, -9.0);
		break;
	case LOW_WEAK:
		filter = new Filter(LPF, 61, 48, -6.0);
		break;
	case NEUTRAL:
		filter = new Filter(LPF, 61, 48, 1.0);
		break;
	case HIGH_WEAK:
		filter = new Filter(LPF, 61, 48, 6.0);
		break;
	case HIGH_MODERATE:
		filter = new Filter(LPF, 61, 48, 9.0);
		break;
	case HIGH_STRONG:
		filter = new Filter(LPF, 61, 48, 12.0);
		break;
	}

	return filter;
}

void set_dsp_filter_bass_for_level(tone_intensity_level intensity_level) {

	if (bass_filter_intensity_level != intensity_level) {

		bass_filter_intensity_level = intensity_level;

		if (bass_filter_left != NULL)
			delete bass_filter_left;
		if (bass_filter_right != NULL)
			delete bass_filter_right;
		bass_filter_left = bass_filter_right = get_dsp_filter_for_level(bass_filter_intensity_level);
	}
}

void set_dsp_filter_treble_for_level(tone_intensity_level intensity_level) {

	if (treble_filter_intensity_level != intensity_level) {

		treble_filter_intensity_level = intensity_level;

		if (treble_filter_left != NULL)
			delete treble_filter_left;
		if (treble_filter_right != NULL)
			delete treble_filter_right;
		treble_filter_left = treble_filter_right = get_dsp_filter_for_level(treble_filter_intensity_level);
	}
}

void process_dsp_filter_bass_left(float32_t src[], float32_t dest[], int length) {

	set_dsp_filter_bass_for_level(get_level(token_levels[token_bass]));
	process_dsp_filter(bass_filter_left, src, dest, length);
}

void process_dsp_filter_bass_right(float32_t src[], float32_t dest[], int length) {

	set_dsp_filter_bass_for_level(get_level(token_levels[token_bass]));
	process_dsp_filter(bass_filter_right, src, dest, length);
}

void process_dsp_filter_treble_left(float32_t src[], float32_t dest[], int length) {

	set_dsp_filter_bass_for_level(get_level(token_levels[token_treble]));
	process_dsp_filter(treble_filter_left, src, dest, length);
}

void process_dsp_filter_treble_right(float32_t src[], float32_t dest[], int length) {

	set_dsp_filter_bass_for_level(get_level(token_levels[token_treble]));
	process_dsp_filter(treble_filter_right, src, dest, length);
}

void init_dsp_filter() {

	set_dsp_filter_bass_for_level(NEUTRAL);
	set_dsp_filter_treble_for_level(NEUTRAL);
}

