// Workshop 3 _ lab
// Name: Juhee Lee
// Seneca email : jlee651@myseneca.ca
// student ID : 128261203
// Date: 2021/ 02/ 04
////////////////////////////////////////////////
#include "cstring.h"
namespace sdds {

	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len) {
		int x;
		int srclen = strLen(src);

		if (srclen < len) { //if src length is smaller than len
			for (x = 0; x < srclen; x++) {
				des[x] = src[x];
			}
			des[srclen] = '\0';
		}
		else {
			for (x = 0; x < len; x++) {
				des[x] = src[x];
			}
			des[len] = '\0';
		}
	}
	// returns the lenght of the C-string in characters
	int strLen(const char* s) {
		int x;
		int count = 0;
		for (x = 0; s[x] != '\0'; x++) {
			count++;
		}
		return count;
	}


	}

  

