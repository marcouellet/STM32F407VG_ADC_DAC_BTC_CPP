/*
 * dsp_shelving.cpp
 */

#include <dsp_shelving.h>
#include <arm_math.h>
#include <math.h>

int shelving(float32_t gain, float32_t fc, float32_t fs, float32_t q, shelving_type type, float32_t a_coeffs[], float32_t b_coeffs[]) {

	float32_t b0, b1, b2, a0, a1, a2, k, v0, root2;

//	K = tan((pi * fc)/fs);
//	V0 = 10^(G/20);
//	root2 = 1/Q; %sqrt(2)
//
//	%Invert gain if a cut
//	if(V0 < 1)
//	    V0 = 1/V0;
//	end

	k = tan((M_PI * fc) / fs);
	v0 = pow(10.0, gain / 10.0);
	root2 = 1.0 / q; // q; // sqrt(2)

	// Invert gain if a cut
	if (v0 < 1) {
		v0 = 1 / v0;
	}

	//
	//    BASE BOOST
	//
	if ( gain > 0 && type == BASE) {

		//	    b0 = (1 + sqrt(V0)*root2*K + V0*K^2) / (1 + root2*K + K^2);
		//	    b1 =             (2 * (V0*K^2 - 1) ) / (1 + root2*K + K^2);
		//	    b2 = (1 - sqrt(V0)*root2*K + V0*K^2) / (1 + root2*K + K^2);
		//	    a1 =                (2 * (K^2 - 1) ) / (1 + root2*K + K^2);
		//	    a2 =             (1 - root2*K + K^2) / (1 + root2*K + K^2);

		b0 = (1 + sqrt(v0) * root2*k + v0*pow(k,2)) / (1 + root2*k + pow(k,2));
		b1 = (2 * (v0*pow(k,2) -1)) / (1 + root2*k +pow(k,2));
		b2 = (1 - sqrt(v0) * root2*k + v0*pow(k,2)) / (1 + root2*k + pow(k,2));
		a1 = (2 * (v0*pow(k,2) -1)) /  (1 + root2*k +pow(k,2));
		a2 = (1 - sqrt(1 - root2*k + pow(k,2))) / (1 + root2*k + pow(k,2));

	} else

	//
	//    BASE BOOST
	//
	if ( gain < 0 && type == BASE) {

		//	    b0 =             (1 + root2*K + K^2) / (1 + root2*sqrt(V0)*K + V0*K^2);
		//	    b1 =                (2 * (K^2 - 1) ) / (1 + root2*sqrt(V0)*K + V0*K^2);
		//	    b2 =             (1 - root2*K + K^2) / (1 + root2*sqrt(V0)*K + V0*K^2);
		//	    a1 =             (2 * (V0*K^2 - 1) ) / (1 + root2*sqrt(V0)*K + V0*K^2);
		//	    a2 = (1 - root2*sqrt(V0)*K + V0*K^2) / (1 + root2*sqrt(V0)*K + V0*K^2);

		b0 = (1 + root2*k + pow(k,2)) / (1 + root2*sqrt(v0)*k + v0*pow(k,2));
		b1 = (2 * (pow(k,2) -1)) / (1 + root2*sqrt(v0)*k + v0*pow(k,2));
		b2 = (1 - root2*k + pow(k,2))  / (1 + root2*sqrt(v0)*k + v0*pow(k,2));
		a1 = (2 * (v0*pow(k,2) - 1)) / (1 + root2*sqrt(v0)*k + v0*pow(k,2));
		a2 = (1 - root2*sqrt(v0)*k + v0*pow(k,2)) / (1 + root2*sqrt(v0)*k + v0*pow(k,2));

	} else

	//
	//    TREBLE BOOST
	//
	if ( gain > 0 && type == TREBLE) {

		//	    b0 = (V0 + root2*sqrt(V0)*K + K^2) / (1 + root2*K + K^2);
		//	    b1 =             (2 * (K^2 - V0) ) / (1 + root2*K + K^2);
		//	    b2 = (V0 - root2*sqrt(V0)*K + K^2) / (1 + root2*K + K^2);
		//	    a1 =              (2 * (K^2 - 1) ) / (1 + root2*K + K^2);
		//	    a2 =           (1 - root2*K + K^2) / (1 + root2*K + K^2);

		b0 = (v0 + root2*sqrt(v0)*k + pow(k,2)) / (1 + root2*k +  pow(k,2));
		b1 = (2 * (pow(k,2) - v0)) / (1 + root2*k +  pow(k,2));
		b2 = (v0 - root2*sqrt(v0)*k + pow(k,2)) / (1 + root2*k +  pow(k,2));
		a1 = (2 * (pow(k,2) -1)) / (1 + root2*k +  pow(k,2));
		a2 = (1 - root2*k +  pow(k,2)) / (1 + root2*k +  pow(k,2));

	} else

	//
	//    TREBLE CUT
	//
	if ( gain < 0 && type == TREBLE) {

		//	    b0 =               (1 + root2*K + K^2) / (V0 + root2*sqrt(V0)*K + K^2);
		//	    b1 =                  (2 * (K^2 - 1) ) / (V0 + root2*sqrt(V0)*K + K^2);
		//	    b2 =               (1 - root2*K + K^2) / (V0 + root2*sqrt(V0)*K + K^2);
		//	    a1 =             (2 * ((K^2)/V0 - 1) ) / (1 + root2/sqrt(V0)*K + (K^2)/V0);
		//	    a2 = (1 - root2/sqrt(V0)*K + (K^2)/V0) / (1 + root2/sqrt(V0)*K + (K^2)/V0);

		b0 = (1 + root2*k + pow(k,2)) / (v0 + root2*sqrt(v0)*k + pow(k,2));
		b1 = (2 * (pow(k,2) - 1)) / (v0 + root2*sqrt(v0)*k + pow(k,2));
		b2 = (1 - root2*k + pow(k,2)) / (v0 + root2*sqrt(v0)*k + pow(k,2));
		a1 = (2 * (pow(k,2)/v0 - 1)) / (v0 + root2*sqrt(v0)*k + pow(k,2));
		a2 = (1 - root2/sqrt(v0)*k + pow(k,2)/v0) / (v0 + root2*sqrt(v0)*k + pow(k,2));

	} else {

		//
		//    ALL PASS
		//

	    b0 = v0;
	    b1 = 0;
	    b2 = 0;
	    a1 = 0;
	    a2 = 0;
	}

	a0 = 1;

	a_coeffs[0] = a0;
	a_coeffs[1] = a1;
	a_coeffs[2] = a2;

	b_coeffs[0] = b0;
	b_coeffs[1] = b1;
	b_coeffs[2] = b2;

	return 0;
}
