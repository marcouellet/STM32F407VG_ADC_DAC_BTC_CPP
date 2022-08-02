/*
 * dsp_simple.cpp
 */

#include <dsp_simple.h>
#include <dsp_util.h>
#include <dsp_token.h>
#include <consts.h>

float32_t xm_bass = 0;
float32_t xm_treble = 0;

float32_t simplp (float32_t *x, float32_t *y,
               int length, float32_t xm1);

/* C function implementing the simplest low pass filter:
 *
 *      y(n) = x(n) + x(n-1)
 *
 */
float32_t simplp (float32_t *x, float32_t *y,
               int length, float32_t xm1)
{
  int n;
  y[0] = x[0] + xm1;
  for (n=1; n < length; n++) {
    y[n] =  x[n]  + x[n-1];
  }
  return x[length-1];
}

void process_dsp_invert_with_lpf(float32_t src[], float32_t lpf[], float32_t dest[], int length) {

	for ( int i = 0 ; i < length ; i++ )
	{
		dest[i] = src[i] - lpf[i];
	}
}

void process_dsp_simplp(float32_t src[], float32_t dest[], float32_t& xm) {
	xm = simplp(src, dest, SAMPLES_SRC_DEST, xm);
}

void process_dsp_simplp_bass(float32_t src[], float32_t dest[], int length) {

	if (token_levels[token_bass] > 20) {
		process_dsp_simplp(src, dest, xm_bass);
	} else {
		dsp_copy(src, dest, length);
	}
}
void process_dsp_simphp_treble(float32_t src[], float32_t dest[], int length) {

	float32_t lpfwork[length];

	if (token_levels[token_treble] > 20) {
		process_dsp_simplp(src, lpfwork, xm_treble);
		process_dsp_invert_with_lpf(src, lpfwork, dest, length);
	} else {
		dsp_copy(src, dest, length);
	}
}
