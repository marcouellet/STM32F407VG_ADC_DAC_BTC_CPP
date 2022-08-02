/*
 * dsp_fir_bass.c
 */

#include <consts.h>
#include <dsp_fir_bass.h>
#include <coeffs_fir_bass.h>
#include <dsp_util.h>

arm_fir_instance_f32 arm_inst_bass_left;
arm_fir_instance_f32 arm_inst_bass_right;

float32_t bass_stateLeft[SAMPLES_SRC_DEST + COEFFS_FIR_BASS_TAPS_NUM - 1];
float32_t bass_stateRight[SAMPLES_SRC_DEST + COEFFS_FIR_BASS_TAPS_NUM - 1];

void init_dsp_fir_bass() {

	  arm_fir_init_f32(
			  &arm_inst_bass_left,
			  COEFFS_FIR_BASS_TAPS_NUM,
			  0,
			  &bass_stateLeft[0],
			  SAMPLES_SRC_DEST
	  );

	  arm_fir_init_f32(
			  &arm_inst_bass_right,
			  COEFFS_FIR_BASS_TAPS_NUM,
			  0,
			  &bass_stateRight[0],
			  SAMPLES_SRC_DEST
	  );
}

float32_t * get_dsp_fir_bass_coeffs_for_level(tone_intensity_level intensity_level) {

	float32_t * coeffs = NULL;

	switch (intensity_level) {

	case NONE:
		break;
	case LOW_STRONG:
		coeffs = coeffs_fir_bass_low_strong;
		break;
	case LOW_MODERATE:
		coeffs = coeffs_fir_bass_low_moderate;
		break;
	case LOW_WEAK:
		coeffs = coeffs_fir_bass_low_weak;
		break;
	case NEUTRAL:
		coeffs = coeffs_fir_bass_neutral;
		break;
	case HIGH_WEAK:
		coeffs = coeffs_fir_bass_high_weak;
		break;
	case HIGH_MODERATE:
		coeffs = coeffs_fir_bass_high_moderate;
		break;
	case HIGH_STRONG:
		coeffs = coeffs_fir_bass_high_strong;
		break;
	}

	return coeffs;
}

void process_dsp_fir_bass_left(float32_t srcLeft[], float32_t destLeft[], tone_intensity_level level) {

	if (level != NEUTRAL) {
		arm_inst_bass_left.pCoeffs = get_dsp_fir_bass_coeffs_for_level(level);
		arm_fir_f32	(
				&arm_inst_bass_left,
				srcLeft,
				destLeft,
				SAMPLES_SRC_DEST
		);
	} else {
		dsp_copy(srcLeft, destLeft, SAMPLES_SRC_DEST);
	}
}

void process_dsp_fir_bass_right(float32_t srcRight[], float32_t destRight[], tone_intensity_level level) {

	if (level != NEUTRAL) {
		arm_inst_bass_right.pCoeffs = get_dsp_fir_bass_coeffs_for_level(level);
		arm_fir_f32	(
				&arm_inst_bass_left,
				srcRight,
				destRight,
				SAMPLES_SRC_DEST
		);
	} else {
		dsp_copy(srcRight, destRight, SAMPLES_SRC_DEST);
	}
}

