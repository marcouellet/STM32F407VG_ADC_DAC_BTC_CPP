/*
 * coeffs_fir_taps21_treble.h
 */

#ifndef INC_COEFFS_FIR_TAPS21_TREBLE_H_
#define INC_COEFFS_FIR_TAPS21_TREBLE_H_

#include "arm_math.h"

#define FILTER_FIR_TREBLE_TAPS_NUM 21

static float32_t coeffs_fir_treble_taps21_low_weak[FILTER_FIR_TREBLE_TAPS_NUM] = {
//		-0.0041290019, 0.0014288781, -0.00086025306, -0.0030580537, -0.0060144522, -0.0091673458,
//		-0.012214567, -0.015273020, -0.016923209, -0.016154428, 1.1847686, -0.016154428,
//		-0.016923209, -0.015273020, -0.012214567, -0.0091673458, -0.0060144522, -0.0030580537,
//		-0.00086025306, 0.0014288781, -0.0041290019
		// cutoff 384 hz : fir1(20, .008, "high")
		-5.5763e-04,  -7.1567e-04,  -1.1734e-03,  -1.8872e-03,  -2.7877e-03,  -3.7871e-03,  -4.7875e-03,  -5.6907e-03,  -6.4079e-03,
		-6.8686e-03,   9.9353e-01,  -6.8686e-03,  -6.4079e-03,  -5.6907e-03,  -4.7875e-03,  -3.7871e-03,  -2.7877e-03,  -1.8872e-03,
		 -1.1734e-03,  -7.1567e-04,  -5.5763e-04
};

static float32_t coeffs_fir_treble_taps21_low_moderate[FILTER_FIR_TREBLE_TAPS_NUM] = {
//		-0.010361371, 0.0034762743, -0.0022150752, -0.0075974994, -0.014864569, -0.022859104,
//		-0.030370802, -0.037709263, -0.043158904, -0.044643463, 1.4556588, -0.044643463,
//		-0.043158904, -0.037709263, -0.030370802, -0.022859104, -0.014864569, -0.0075974994,
//		-0.0022150752, 0.0034762743, -0.010361371
		// cutoff 600 hz : fir1(20, .0125, "high")
		-9.0241e-04,  -1.1613e-03,  -1.9087e-03,  -3.0761e-03,  -4.5523e-03,  -6.1938e-03,  -7.8399e-03,  -9.3282e-03,  -1.0511e-02,
		-1.1272e-02,   9.8937e-01,  -1.1272e-02,  -1.0511e-02,  -9.3282e-03,  -7.8399e-03,  -6.1938e-03,  -4.5523e-03,  -3.0761e-03,
		-1.9087e-03,  -1.1613e-03,  -9.0241e-04
};

static float32_t coeffs_fir_treble_taps21_low_strong[FILTER_FIR_TREBLE_TAPS_NUM] = {
//		-0.021432325, 0.0059782627, -0.0058250577, -0.016900184, -0.031221045, -0.046705188,
//		-0.060352228, -0.072906659, -0.083887530, -0.090358378, 1.9078762, -0.090358378,
//		-0.083887530, -0.072906659, -0.060352228, -0.046705188, -0.031221045, -0.016900184,
//		-0.0058250577, 0.0059782627, -0.021432325

		// cutoff 1008 hz : fir1(20, .021, "high")
		 -1.5003e-03,  -1.9474e-03,  -3.2253e-03,  -5.2332e-03,  -7.7896e-03,  -1.0651e-02,  -1.3535e-02,  -1.6154e-02,  -1.8243e-02,
		 -1.9589e-02,   9.8144e-01,  -1.9589e-02,  -1.8243e-02,  -1.6154e-02,  -1.3535e-02,  -1.0651e-02,  -7.7896e-03,  -5.2332e-03,
		 -3.2253e-03,  -1.9474e-03,  -1.5003e-03
};

static float32_t coeffs_fir_treble_taps21_neutral[FILTER_FIR_TREBLE_TAPS_NUM] = {
//		-0.021432325, 0.0059782627, -0.0058250577, -0.016900184, -0.031221045, -0.046705188,
//		-0.060352228, -0.072906659, -0.083887530, -0.090358378, 1.9078762, -0.090358378,
//		-0.083887530, -0.072906659, -0.060352228, -0.046705188, -0.031221045, -0.016900184,
//		-0.0058250577, 0.0059782627, -0.021432325

		// cutoff 1008 hz : fir1(20, .021, "high")
		 -1.5003e-03,  -1.9474e-03,  -3.2253e-03,  -5.2332e-03,  -7.7896e-03,  -1.0651e-02,  -1.3535e-02,  -1.6154e-02,  -1.8243e-02,
		 -1.9589e-02,   9.8144e-01,  -1.9589e-02,  -1.8243e-02,  -1.6154e-02,  -1.3535e-02,  -1.0651e-02,  -7.7896e-03,  -5.2332e-03,
		 -3.2253e-03,  -1.9474e-03,  -1.5003e-03
};

static float32_t coeffs_fir_treble_taps21_high_weak[FILTER_FIR_TREBLE_TAPS_NUM] = {
//		-0.0041290019, 0.0014288781, -0.00086025306, -0.0030580537, -0.0060144522, -0.0091673458,
//		-0.012214567, -0.015273020, -0.016923209, -0.016154428, 1.1847686, -0.016154428,
//		-0.016923209, -0.015273020, -0.012214567, -0.0091673458, -0.0060144522, -0.0030580537,
//		-0.00086025306, 0.0014288781, -0.0041290019
		// cutoff 384 hz : fir1(20, .008, "high")
		-5.5763e-04,  -7.1567e-04,  -1.1734e-03,  -1.8872e-03,  -2.7877e-03,  -3.7871e-03,  -4.7875e-03,  -5.6907e-03,  -6.4079e-03,
		-6.8686e-03,   9.9353e-01,  -6.8686e-03,  -6.4079e-03,  -5.6907e-03,  -4.7875e-03,  -3.7871e-03,  -2.7877e-03,  -1.8872e-03,
		 -1.1734e-03,  -7.1567e-04,  -5.5763e-04
};

static float32_t coeffs_fir_treble_taps21_high_moderate[FILTER_FIR_TREBLE_TAPS_NUM] = {
//		-0.010361371, 0.0034762743, -0.0022150752, -0.0075974994, -0.014864569, -0.022859104,
//		-0.030370802, -0.037709263, -0.043158904, -0.044643463, 1.4556588, -0.044643463,
//		-0.043158904, -0.037709263, -0.030370802, -0.022859104, -0.014864569, -0.0075974994,
//		-0.0022150752, 0.0034762743, -0.010361371
		// cutoff 600 hz : fir1(20, .0125, "high")
		-9.0241e-04,  -1.1613e-03,  -1.9087e-03,  -3.0761e-03,  -4.5523e-03,  -6.1938e-03,  -7.8399e-03,  -9.3282e-03,  -1.0511e-02,
		-1.1272e-02,   9.8937e-01,  -1.1272e-02,  -1.0511e-02,  -9.3282e-03,  -7.8399e-03,  -6.1938e-03,  -4.5523e-03,  -3.0761e-03,
		-1.9087e-03,  -1.1613e-03,  -9.0241e-04
};

static float32_t coeffs_fir_treble_taps21_high_strong[FILTER_FIR_TREBLE_TAPS_NUM] = {
//		-0.021432325, 0.0059782627, -0.0058250577, -0.016900184, -0.031221045, -0.046705188,
//		-0.060352228, -0.072906659, -0.083887530, -0.090358378, 1.9078762, -0.090358378,
//		-0.083887530, -0.072906659, -0.060352228, -0.046705188, -0.031221045, -0.016900184,
//		-0.0058250577, 0.0059782627, -0.021432325

		// cutoff 1008 hz : fir1(20, .021, "high")
		 -1.5003e-03,  -1.9474e-03,  -3.2253e-03,  -5.2332e-03,  -7.7896e-03,  -1.0651e-02,  -1.3535e-02,  -1.6154e-02,  -1.8243e-02,
		 -1.9589e-02,   9.8144e-01,  -1.9589e-02,  -1.8243e-02,  -1.6154e-02,  -1.3535e-02,  -1.0651e-02,  -7.7896e-03,  -5.2332e-03,
		 -3.2253e-03,  -1.9474e-03,  -1.5003e-03
};

#endif /* INC_COEFFS_FIR_TAPS21_TREBLE_H_ */