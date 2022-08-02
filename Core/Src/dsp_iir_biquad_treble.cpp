/*
 * dsp_iir_biquad_treble.cpp
 */

#include <coeffs_iir_biquad.h>
#include <consts.h>
#include <tone_control.h>
#include <dsp_iir_biquad_treble.h>
#include <dsp_util.h>

arm_biquad_cascade_df2T_instance_f32 arm_inst_iir_biquad_treble_left;
arm_biquad_cascade_df2T_instance_f32 arm_inst_iir_biquad_treble_right;

float32_t iir_biquad_treble_stateLeft[COEFFS_IIR_BIQUAD_ORDER];
float32_t  iir_biquad_treble_stateRight[COEFFS_IIR_BIQUAD_ORDER];

void init_dsp_iir_biquad_treble() {

	arm_biquad_cascade_df2T_init_f32(
			  &arm_inst_iir_biquad_treble_left,
			  COEFFS_IIR_BIQUAD_NUMSTAGES,
			  0,
			  &iir_biquad_treble_stateLeft[0]
	  );

	arm_biquad_cascade_df2T_init_f32(
			  &arm_inst_iir_biquad_treble_right,
			  COEFFS_IIR_BIQUAD_NUMSTAGES,
			  0,
			  &iir_biquad_treble_stateRight[0]
	  );
}

float32_t * get_dsp_iir_biquad_treble_coeffs_for_level(tone_intensity_level intensity_level) {

	float32_t * coeffs = NULL;

	switch (intensity_level) {

	case NONE:
		break;
	case LOW_STRONG:
		coeffs = coeffs_iir_biquad_treble_low_strong;
		break;
	case LOW_MODERATE:
		coeffs = coeffs_iir_biquad_treble_low_moderate;
		break;
	case LOW_WEAK:
		coeffs = coeffs_iir_biquad_treble_low_weak;
		break;
	case NEUTRAL:
		coeffs = coeffs_iir_biquad_treble_neutral;
		break;
	case HIGH_WEAK:
		coeffs = coeffs_iir_biquad_treble_high_weak;
		break;
	case HIGH_MODERATE:
		coeffs = coeffs_iir_biquad_treble_high_moderate;
		break;
	case HIGH_STRONG:
		coeffs = coeffs_iir_biquad_treble_high_strong;
		break;
	}

	return coeffs;
}
void process_dsp_iir_biquad_left_treble(float32_t srcLeft[], float32_t destLeft[], tone_intensity_level level) {

	if (level != NEUTRAL) {
		arm_inst_iir_biquad_treble_left.pCoeffs = get_dsp_iir_biquad_treble_coeffs_for_level(level);
		arm_biquad_cascade_df2T_f32	(
				&arm_inst_iir_biquad_treble_left,
				srcLeft,
				destLeft,
				SAMPLES_SRC_DEST
		);
	} else {
		dsp_copy(srcLeft, destLeft, SAMPLES_SRC_DEST);
	}
}

void process_dsp_iir_biquad_right_treble(float32_t srcRight[], float32_t destRight[], tone_intensity_level level) {

	if (level != NEUTRAL) {
		arm_inst_iir_biquad_treble_right.pCoeffs = get_dsp_iir_biquad_treble_coeffs_for_level(level);
		arm_biquad_cascade_df2T_f32	(
				&arm_inst_iir_biquad_treble_right,
				srcRight,
				destRight,
				SAMPLES_SRC_DEST
		);
	} else {
		dsp_copy(srcRight, destRight, SAMPLES_SRC_DEST);
	}
}
