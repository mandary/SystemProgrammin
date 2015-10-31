#include <stdlib.h>
#include <stdio.h>

#include "DumpHex.h"

//Yufang Sun
//1334960
//mandary@uw.edu


char* DumpHex(const void *pData, unsigned int byteLen) {
	if(byteLen > 0) {
		char* result = (char*)malloc(byteLen * 3);
		if(result == NULL) {
			printf("Out of memory.\n");
			return NULL;
		}
		int i;
		unsigned char* data = (unsigned char*)pData;
		for(i = 0; i < byteLen; i++) {
			sprintf(result + 3 * i, "%02x ", data[i]);
		}
		result[byteLen * 3 - 1] = '\0';
		printf("\n");
		return result;
	}
	return NULL;
}