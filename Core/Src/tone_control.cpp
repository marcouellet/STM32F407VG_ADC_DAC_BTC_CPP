/*
 * tone_control.c
 */

#include <global.h>
#include <dsp_main.h>
#include <dsp_util.h>
#include <dsp_token.h>
#include <tone_control.h>
#include "string.h"

tone_intensity_level bass_intensity_level = NONE;
tone_intensity_level treble_intensity_level = NONE;

tone_intensity_level get_level(int token_level) {

	tone_intensity_level level = NEUTRAL;

	if (token_level < -10) {

		if (token_level < -40) {
			level = LOW_STRONG;
		} else if (token_level < -30) {
			level = LOW_MODERATE;
		} else {
			level = LOW_WEAK;
		}
	} else if (token_level > 10) {

		if (token_level > 40) {
			level = HIGH_STRONG;
		} else if (token_level > 30) {
			level = HIGH_MODERATE;
		} else {
			level = HIGH_WEAK;
		}
	}
	return level;
}

void process_levels_update_message() {

	memset(buffer, 0, sizeof(buffer));
	buffer_index = 0;
	timer_count = 0;

	char int_str_buffer[15];
	strcat(buffer, "VOL=");
	strcat(buffer, int2char(token_levels[token_volume], int_str_buffer));
	strcat(buffer, " BAS=");
	strcat(buffer, int2char(token_levels[token_bass], int_str_buffer));
	strcat(buffer, " TRE=");
	strcat(buffer, int2char(token_levels[token_treble], int_str_buffer));
	strcat(buffer, " BAL=");
	strcat(buffer, int2char(token_levels[token_balance], int_str_buffer));
	strcat(buffer, "\n");
}

void process_received_message()
{
	process_token_updates(buffer);
}
