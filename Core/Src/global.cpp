/*
 * dsp_buffer.cpp
 */

#include <arm_math.h>
#include <consts.h>

// Delay Line
#define	DELAY_BUF	12000
float32_t	delayLeft[DELAY_BUF];
float32_t	delayRight[DELAY_BUF];
volatile int delayPtr = 0;
volatile int t = 0;

char buffer[50];
uint8_t timer_count, buffer_index;

