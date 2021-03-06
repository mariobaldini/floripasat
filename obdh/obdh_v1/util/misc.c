/*
 * misc.c
 *
 *  Created on: 27 de abr de 2016
 *      Author: mario
 */

#include "misc.h"
#include "../hal/engmodel1.h"


void sysled_setup(void){
	SYSLED_PORT_DIR |= SYSLED_PIN; // set as output
	SYSLED_PORT_OUT &= ~SYSLED_PIN;
}
void sysled_toggle(void){
	SYSLED_PORT_OUT ^= SYSLED_PIN; //toggle port state
}
void sysled_on(void){
	SYSLED_PORT_OUT |= SYSLED_PIN;
}
void sysled_off(void){
	SYSLED_PORT_OUT &= ~SYSLED_PIN;
}



void payloadEnable_setup(void){
	PAYLOAD_ENABLE_PORT_DIR |= PAYLOAD_ENABLE_PIN; // set as output
	PAYLOAD_ENABLE_PORT_OUT &= ~PAYLOAD_ENABLE_PIN;
}
void payloadEnable_on(void){
	PAYLOAD_ENABLE_PORT_OUT |= PAYLOAD_ENABLE_PIN;
}
void payloadEnable_off(void){
	PAYLOAD_ENABLE_PORT_OUT &= ~PAYLOAD_ENABLE_PIN;
}
void payloadEnable_toggle(void){
	PAYLOAD_ENABLE_PORT_OUT ^= PAYLOAD_ENABLE_PIN; //toggle port state
}


char* int2str(char* stringBuffer, int16_t value){
	sprintf(stringBuffer, "%d", value);
	return stringBuffer;
}

char* uint2str(char* stringBuffer, uint16_t value){
	sprintf(stringBuffer, "%u", value);
	return stringBuffer;
}

char* float2str(char* stringBuffer, float value) {
	sprintf(stringBuffer, "%f", value);
	return stringBuffer;
}



// TODO: deprecate
unsigned char* aligned_right(unsigned char* data){
	int i,j;
	int n = 1;
	unsigned char string[intStringSize];

	//copping data to string
	for(i=0; i < intStringSize;i++)
		string[i]= data[i];

	//discovering the index
	for(i=0; i < intStringSize;i++){
		if (string[i]==NULL){
			j=i;
			break;
		}
	}
	//shifting to right
	for(i=j;i>=0;i--)
		string[intStringSize - n++]=string[i-1];


	//filling up with blank spaces
	for(i=intStringSize - j - 1;i>=0;i--)
		string[i]=' ';

	return string;
}



//TODO: deprecate
unsigned char hex2char(unsigned char byte){
	char character;
	switch(byte & 0x0f){
		case 0x00: character = '0'; break;
		case 0x01: character = '1'; break;
		case 0x02: character = '2'; break;
		case 0x03: character = '3'; break;
		case 0x04: character = '4'; break;
		case 0x05: character = '5'; break;
		case 0x06: character = '6'; break;
		case 0x07: character = '7'; break;
		case 0x08: character = '8'; break;
		case 0x09: character = '9'; break;
		case 0x0A: character = 'A'; break;
		case 0x0B: character = 'B'; break;
		case 0x0C: character = 'C'; break;
		case 0x0D: character = 'D'; break;
		case 0x0E: character = 'E'; break;
		case 0x0F: character = 'F'; break;
	}
	return character;
}



//TODO: deprecate
void frame2string(unsigned char frame[],unsigned char frame_string[], int size){
	int i;
	int j = 0;
	for(i=2; i < size; i+=5){
		frame_string[i]   = hex2char(frame[j] >> 4);
		frame_string[i+1] = hex2char(frame[j]);
		j++;
	}
}
