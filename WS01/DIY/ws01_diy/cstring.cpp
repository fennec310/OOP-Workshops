// Workshop 1 _ DIY
// Name: Juhee Lee
// Seneca email : jlee651@myseneca.ca
// student ID : 128261203
// Date: 2021/01/24
////////////////////////////////////////////////

#include <iostream>
#include "cstring.h"


namespace sdds {

	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src) {
		int x;
		for (x = 0; src[x] != '\0'; x++) {
			des[x] = src[x];
		}
		des[x] = '\0';
	}

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

		}else{ 
			for (x = 0; x < len; x++) {
				des[x] = src[x];
			}
		}

	}


	// Compares two C-strings
	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2) {
		int x;
		int s1len = strLen(s1);
		int cmp = 0;
		int dif = 0;

		for (x = 0; x < s1len; x++) {
			dif = s1[x] - s2[x]; //assign the difference between s1 and s2 in dif
			if (dif == 0) {
				cmp += 0;
			}
			else {
				cmp += dif;
				break; 
			}
		}
		return cmp;

	}

	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strnCmp(const char* s1, const char* s2, int len) {
		int x;
		int cmp = 0;
		int dif = 0;
		for (x = 0; x < len; x++) {
			dif = s1[x] - s2[x];
			if (dif == 0) {
				cmp += 0;
			}
			else {
				cmp += dif; 
				break;
			}
		}
		return cmp;
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

	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2) {

		const char* str1_pos;
		const char* str2_pos;

		if (*str2 == '\0') return (char*)str1; // if str2 is empty string, then return the starting address of str1

		while (*str1 != '\0') { // loop till str1 meet '\0'
			if (*str1 == *str2) { // if character of str1 and str2 is same,
				str1_pos = str1 + 1; 
				str2_pos = str2 + 1;
				//keep loop when str1_pos and str2_pos don't meet '\0' and both have same character.
				while (*str1_pos != '\0' && *str2_pos != '\0' && *str1_pos == *str2_pos) {
					str1_pos++;
					str2_pos++;
				}
				if (*str2_pos == '\0') return (char*)str1; // if str2_pos meet '\0' then it found matching letter. return str1 address.
				if (*str1_pos == '\0') break; //leftover length of str1 is less then str2 length. can't find matching letter.
			}
			str1++; // move to next str1 address
		}

		return (char*)nullptr; // visited all str1 address but no match was found.
	}


	// Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src) {
		
		int x;
		int des_newlen = strLen(des); // find the null terminator of des string.
		for (x = 0; src[x] != '\0'; x++) {
			des[des_newlen] = src[x]; // put src letter from the null termiator address of des string
			des_newlen++;
		}
		des[des_newlen] = '\0'; 
	}
	
}