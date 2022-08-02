/*
 * dsp_shelving.h
 */

#ifndef INC_DSP_SHELVING_H_
#define INC_DSP_SHELVING_H_

typedef enum {BASE, TREBLE} shelving_type;

//
// Derive coefficients for a shelving filter with a given amplitude and
// cutoff frequency.  All coefficients are calculated as described in
// Zolzer's DAFX book (p. 50 -55).
//
// Usage:     shelving(float32_t gain, float32_t fc, float32_t fs, float32_t q, shelving_type type, float32_t a_coeffs[], float32_t b_coeffs[]);
//
//            gain is the logarithmic gain (in dB)
//            fc is the center frequency
//            fs is the sampling rate
//            q adjusts the slope be replacing the sqrt(2) term
//            type is a character string defining filter type
//                 Choices are: BASE or TREBLE
//

#endif /* INC_DSP_SHELVING_H_ */
