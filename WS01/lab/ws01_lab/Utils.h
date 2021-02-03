// Workshop 1 _ Lab
// Name: Juhee Lee
// Seneca email : jlee651@myseneca.ca
// student ID : 128261203
// Date: 2021/01/19
////////////////////////////////////////////////
#ifndef SDDS_UTILS_H // include guard
#define SDDS_UTILS_H

namespace sdds {

	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);

}

#endif