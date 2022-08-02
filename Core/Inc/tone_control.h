/*
 * tone_control.h
 */

#ifndef INC_TONE_CONTROL_H_
#define INC_TONE_CONTROL_H_

typedef enum {NONE, LOW_STRONG, LOW_MODERATE, LOW_WEAK, NEUTRAL, HIGH_WEAK, HIGH_MODERATE, HIGH_STRONG} tone_intensity_level;

extern tone_intensity_level bass_intensity_level;
extern tone_intensity_level treble_intensity_level;

extern tone_intensity_level get_level(int token_level);
extern void process_received_message();
extern void process_levels_update_message();

#endif /* INC_TONE_CONTROL_H_ */
