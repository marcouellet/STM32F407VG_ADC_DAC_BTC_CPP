/*
 * dsp_fir_bass_taps_21.c
 */

#include <coeffs_fir_taps21_bass.h>
#include <consts.h>
#include <dsp_fir_bass.h>
#include <tone_control.h>
#include <dsp_util.h>

arm_fir_instance_f32 arm_inst_bass_taps21_left;
arm_fir_instance_f32 arm_inst_bass_taps21_right;

float32_t bass_taps21_stateLeft[SAMPLES_SRC_DEST + COEFFS_FIR_BASS_TAPS_NUM - 1];
float32_t bass_taps21_stateRight[SAMPLES_SRC_DEST + COEFFS_FIR_BASS_TAPS_NUM - 1];

void init_dsp_fir_bass_taps21() {

	  arm_fir_init_f32(
			  &arm_inst_bass_taps21_left,
			  COEFFS_FIR_BASS_TAPS_NUM,
			  0,
			  &bass_taps21_stateLeft[0],
			  SAMPLES_SRC_DEST
	  );

	  arm_fir_init_f32(
			  &arm_inst_bass_taps21_right,
			  COEFFS_FIR_BASS_TAPS_NUM,
			  0,
			  &bass_taps21_stateRight[0],
			  SAMPLES_SRC_DEST
	  );
}

float32_t * get_dsp_fir_bass_taps21_coeffs_for_level(tone_intensity_level intensity_level) {

	float32_t * coeffs = NULL;

	switch (intensity_level) {

	case NONE:
		break;
	case LOW_STRONG:
		coeffs = coeffs_fir_bass_taps21_low_strong;
		break;
	case LOW_MODERATE:
		coeffs = coeffs_fir_bass_taps21_low_moderate;
		break;
	case LOW_WEAK:
		coeffs = coeffs_fir_bass_taps21_low_weak;
		break;
	case NEUTRAL:
		coeffs = coeffs_fir_bass_taps21_neutral;
		break;
	case HIGH_WEAK:
		coeffs = coeffs_fir_bass_taps21_high_weak;
		break;
	case HIGH_MODERATE:
		coeffs = coeffs_fir_bass_taps21_high_moderate;
		break;
	case HIGH_STRONG:
		coeffs = coeffs_fir_bass_taps21_high_strong;
		break;
	}

	return coeffs;
}


void process_dsp_fir_bass_taps21_left(float32_t srcLeft[], float32_t destLeft[], tone_intensity_level level) {

	if (level != NEUTRAL) {
		arm_inst_bass_taps21_left.pCoeffs =  get_dsp_fir_bass_taps21_coeffs_for_level(level);
		arm_fir_f32	(
				&arm_inst_bass_taps21_left,
				srcLeft,
				destLeft,
				SAMPLES_SRC_DEST
		);
	} else {
		dsp_copy(srcLeft, destLeft, SAMPLES_SRC_DEST);
	}
}

void process_dsp_fir_bass_taps21_right(float32_t srcRight[], float32_t destRight[], tone_intensity_level level) {

	if (level != NEUTRAL) {
		arm_inst_bass_taps21_right.pCoeffs = get_dsp_fir_bass_taps21_coeffs_for_level(level);
		arm_fir_f32	(
				&arm_inst_bass_taps21_right,
				srcRight,
				destRight,
				SAMPLES_SRC_DEST
		);
	} else {
		dsp_copy(srcRight, destRight, SAMPLES_SRC_DEST);
	}
}

