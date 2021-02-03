// Workshop 1 _ Lab
// Name: Juhee Lee
// Seneca email : jlee651@myseneca.ca
// student ID : 128261203
// Date: 2021/01/19
////////////////////////////////////////////////
#ifndef SDDS_SHOPPINGREC_H // include guard
#define SDDS_SHOPPINGREC_H

namespace sdds {

	
	const int MAX_TITLE_LENGTH = 50;

	struct ShoppingRec {
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};


	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);


}

#endif