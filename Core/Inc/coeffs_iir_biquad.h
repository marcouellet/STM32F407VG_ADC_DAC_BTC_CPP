/*
 * coeffs_iir_biquad.h
 */

#ifndef INC_COEFFS_IIR_BIQUAD_H_
#define INC_COEFFS_IIR_BIQUAD_H_

#include "arm_math.h"

#define COEFFS_IIR_BIQUAD_ORDER 4
#define COEFFS_IIR_BIQUAD_NUMSTAGES (COEFFS_IIR_BIQUAD_ORDER / 2)


  //left-channel, High-Pass, 1kHz, fs=96kHz, q=0.7
//  l_a0 = 0.9543457485325094f;
//  l_a1 = -1.9086914970650188f;
//  l_a2 = 0.9543457485325094f;
//  l_b1 = -1.9066459797557103f;
//  l_b2 = 0.9107370143743273f;

  //right-channel, Low-Pass, 1kHz, fs)96 kHz, q=0.7
//  r_a0 = 0.0010227586546542474f;
//  r_a1 = 0.002045517309308495f;
//  r_a2 = 0.0010227586546542474f;
//  r_b1 = -1.9066459797557103f;
//  r_b2 = 0.9107370143743273f;


//
// BASS
//

static float32_t coeffs_iir_biquad_bass_low_weak[5 * COEFFS_IIR_BIQUAD_NUMSTAGES] = { 1.0000000000f,
		-1.9169186492f, 1.0000000000f, 1.9314191302f, -0.9338812219f,
		1.0000000000f, -1.9829505952f, 1.0000000000f, 1.9737574359f,
		-0.9797267211f };

//static float32_t coeffs_iir_biquad_bass_low_weak[5 * COEFFS_IIR_BIQUAD_NUMSTAGES] = {  0.9543457485325094f,
//		-1.9086914970650188f, 0.9543457485325094f, -1.9066459797557103f, 0.9107370143743273f,
//		1.0000000000f, -1.9829505952f, 1.0000000000f, 1.9737574359f,
//		-0.9797267211f };

static float32_t coeffs_iir_biquad_bass_low_moderate[5 * COEFFS_IIR_BIQUAD_NUMSTAGES] = { 1.0000000000f,
		-1.9169186492f, 1.0000000000f, 1.9314191302f, -0.9338812219f,
		1.0000000000f, -1.9829505952f, 1.0000000000f, 1.9737574359f,
		-0.9797267211f };

static float32_t coeffs_iir_biquad_bass_low_strong[5 * COEFFS_IIR_BIQUAD_NUMSTAGES] = { 1.0000000000f,
		-1.9169186492f, 1.0000000000f, 1.9314191302f, -0.9338812219f,
		1.0000000000f, -1.9829505952f, 1.0000000000f, 1.9737574359f,
		-0.9797267211f };

static float32_t coeffs_iir_biquad_bass_neutral[5 * COEFFS_IIR_BIQUAD_NUMSTAGES] = { 1.0000000000f,
		-1.9169186492f, 1.0000000000f, 1.9314191302f, -0.9338812219f,
		1.0000000000f, -1.9829505952f, 1.0000000000f, 1.9737574359f,
		-0.9797267211f };

static float32_t coeffs_iir_biquad_bass_high_weak[5 * COEFFS_IIR_BIQUAD_NUMSTAGES] = { 1.0000000000f,
		-1.9169186492f, 1.0000000000f, 1.9314191302f, -0.9338812219f,
		1.0000000000f, -1.9829505952f, 1.0000000000f, 1.9737574359f,
		-0.9797267211f };

//static float32_t coeffs_iir_biquad_bass_high_weak[5 * COEFFS_IIR_BIQUAD_NUMSTAGES] = {  0.9543457485325094f,
//		-1.9086914970650188f, 0.9543457485325094f, -1.9066459797557103f, 0.9107370143743273f,
//		1.0000000000f, -1.9829505952f, 1.0000000000f, 1.9737574359f,
//		-0.9797267211f };

static float32_t coeffs_iir_biquad_bass_high_moderate[5 * COEFFS_IIR_BIQUAD_NUMSTAGES] = { 1.0000000000f,
		-1.9169186492f, 1.0000000000f, 1.9314191302f, -0.9338812219f,
		1.0000000000f, -1.9829505952f, 1.0000000000f, 1.9737574359f,
		-0.9797267211f };

static float32_t coeffs_iir_biquad_bass_high_strong[5 * COEFFS_IIR_BIQUAD_NUMSTAGES] = { 1.0000000000f,
		-1.9169186492f, 1.0000000000f, 1.9314191302f, -0.9338812219f,
		1.0000000000f, -1.9829505952f, 1.0000000000f, 1.9737574359f,
		-0.9797267211f };

//
// TREBLE
//

static float32_t coeffs_iir_biquad_treble_low_weak[5 * COEFFS_IIR_BIQUAD_NUMSTAGES] = { 1.0000000000f,
		-1.9169186492f, 1.0000000000f, 1.9314191302f, -0.9338812219f,
		1.0000000000f, -1.9829505952f, 1.0000000000f, 1.9737574359f,
		-0.9797267211f };

static float32_t coeffs_iir_biquad_treble_low_moderate[5 * COEFFS_IIR_BIQUAD_NUMSTAGES] = { 1.0000000000f,
		-1.9169186492f, 1.0000000000f, 1.9314191302f, -0.9338812219f,
		1.0000000000f, -1.9829505952f, 1.0000000000f, 1.9737574359f,
		-0.9797267211f };

static float32_t coeffs_iir_biquad_treble_low_strong[5 * COEFFS_IIR_BIQUAD_NUMSTAGES] = { 1.0000000000f,
		-1.9169186492f, 1.0000000000f, 1.9314191302f, -0.9338812219f,
		1.0000000000f, -1.9829505952f, 1.0000000000f, 1.9737574359f,
		-0.9797267211f };

static float32_t coeffs_iir_biquad_treble_neutral[5 * COEFFS_IIR_BIQUAD_NUMSTAGES] = { 1.0000000000f,
		-1.9169186492f, 1.0000000000f, 1.9314191302f, -0.9338812219f,
		1.0000000000f, -1.9829505952f, 1.0000000000f, 1.9737574359f,
		-0.9797267211f };

static float32_t coeffs_iir_biquad_treble_high_weak[5 * COEFFS_IIR_BIQUAD_NUMSTAGES] = { 1.0000000000f,
		-1.9169186492f, 1.0000000000f, 1.9314191302f, -0.9338812219f,
		1.0000000000f, -1.9829505952f, 1.0000000000f, 1.9737574359f,
		-0.9797267211f };

static float32_t coeffs_iir_biquad_treble_high_moderate[5 * COEFFS_IIR_BIQUAD_NUMSTAGES] = { 1.0000000000f,
		-1.9169186492f, 1.0000000000f, 1.9314191302f, -0.9338812219f,
		1.0000000000f, -1.9829505952f, 1.0000000000f, 1.9737574359f,
		-0.9797267211f };

static float32_t coeffs_iir_biquad_treble_high_strong[5 * COEFFS_IIR_BIQUAD_NUMSTAGES] = { 1.0000000000f,
		-1.9169186492f, 1.0000000000f, 1.9314191302f, -0.9338812219f,
		1.0000000000f, -1.9829505952f, 1.0000000000f, 1.9737574359f,
		-0.9797267211f };


#endif /* INC_COEFFS_IIR_BIQUAD_H_ */