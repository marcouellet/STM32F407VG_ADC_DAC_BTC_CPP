/*
 * biquad.h
 */

#ifndef INC_BIQUAD_H_
#define INC_BIQUAD_H_

enum {
    bq_type_lowpass = 0,
    bq_type_highpass,
    bq_type_bandpass,
    bq_type_notch,
    bq_type_peak,
    bq_type_lowshelf,
    bq_type_highshelf
};

class Biquad {
public:
    Biquad();
    Biquad(int type, double Fc, double Q, double peakGainDB);
    ~Biquad();
    void setType(int type);
    void setQ(double Q);
    void setFc(double Fc);
    void setPeakGain(double peakGainDB);
    void setBiquad(int type, double Fc, double Q, double peakGainDB);
    float process(float in);
    float process2(float in);

protected:
    void calcBiquad(void);

    volatile int type;
    volatile double a0, a1, a2, b1, b2;
    volatile double Fc, Q, peakGain;
    volatile double z1, z2;
    volatile double in_z1, in_z2, out_z1, out_z2;
};

// Biquad transposed direct form 2 :
// 	y[n]=a0*x[n]+z1[n-1]
// where
// 	z1[n]=z2[n-1]+a1*x[n]-b1*y[n]
// and
//  z2[n]=a2*x[n]-b2*y[n]
//
inline float Biquad::process(float in) {
	volatile double out = in * a0 + z1;
    z1 = in * a1 + z2 - b1 * out;
    z2 = in * a2 - b2 * out;
    return out;
}

inline float Biquad::process2(float in) {
	volatile double out = in * a0 + a1 * in_z1 +  a2 * in_z2 - b1 * out_z1 - b2 * out_z2;
    in_z2 = in_z1;
    in_z1 = in;
    out_z2 = out_z1;
    out_z1 = out;
    return out;
}

#endif /* INC_BIQUAD_H_ */
