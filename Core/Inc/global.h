/*
 * buffer.h
 */

#ifndef INC_BUFFER_H_
#define INC_BUFFER_H_

#include <arm_math.h>

#define AMPLI_FACTOR 1
//#define MODE_16BIT
#define MODE_24BIT
#ifdef MODE_16BIT
#define BUF_SAMPLES SAMPLES*2
#endif
#ifdef MODE_24BIT
#define BUF_SAMPLES SAMPLES*2*2
#endif

extern char buffer[50];
extern uint8_t timer_count, buffer_index;

#endif /* INC_BUFFER_H_ */
