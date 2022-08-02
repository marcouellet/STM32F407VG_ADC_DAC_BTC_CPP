/*
 * dsp_token.cpp
 */

#include <dsp_token.h>
#include <dsp_util.h>

int token_levels[4] = {0,0,0,0};

void get_token_value(const char* str_token, uint16_t length, int* token, int* value)
{
	int i;
	 for(i=0;i<length;i++)
	   	{
	   		  if(str_token[i]==' ')
	   	  		  break;
	   	}
	 if (i==length) {
		 *token = *value = -1;
	 }
	 else {
			if(string_compare(str_token, TOKEN_VOLUME, i))
			{*token = token_volume;} else
			if(string_compare(str_token, TOKEN_BASS, i))
			{*token = token_bass;} else
			if(string_compare(str_token, TOKEN_TREBLE, i))
			{*token = token_treble;} else
			if(string_compare(str_token, TOKEN_BALANCE, i))
			{*token = token_balance;}

			*value = -1;
			if (i < length) {
				*value = char2int(str_token + i, length - i);
			}
	 }
}

int locate_token(char * buffer_start, int buffer_length, int* token_length) {
	int i;
	for(i=0;i<buffer_length;i++)
	{
		  if(buffer_start[i]==',')
			  break;
	}
	*token_length = i;
	return i > 0;
}

void get_token_value(char* str_token, uint16_t length, int* token, int* value)
{
	int i;
	 for(i=0;i<length;i++)
	   	{
	   		  if(str_token[i]==' ')
	   	  		  break;
	   	}
	 if (i==length) {
		 *token = *value = -1;
	 }
	 else {
			if(string_compare(str_token, TOKEN_VOLUME, i))
			{*token = token_volume;} else
			if(string_compare(str_token, TOKEN_BASS, i))
			{*token = token_bass;} else
			if(string_compare(str_token, TOKEN_TREBLE, i))
			{*token = token_treble;} else
			if(string_compare(str_token, TOKEN_BALANCE, i))
			{*token = token_balance;}

			*value = -1;
			if (i < length) {
				*value = char2int(str_token + i, length - i);
			}
	 }
}

void process_token(int token, int value) {

	if (token != -1 && value != -1) {
		token_levels[token] = value;
	}
}

void process_token_updates(char buffer[]) {

	int token, value,token_length;
	char * buffer_start = &buffer[0];
	int buffer_length = strlen(buffer);

	while (buffer_length > 0 && locate_token(buffer_start, buffer_length, &token_length)) {
		get_token_value(buffer_start, token_length, &token, &value);
		process_token(token, value);
		buffer_start+=token_length+1;
		buffer_length-= token_length+1;
	}
}
