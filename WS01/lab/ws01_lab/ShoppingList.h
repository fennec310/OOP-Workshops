// Workshop 1 _ Lab
// Name: Juhee Lee
// Seneca email : jlee651@myseneca.ca
// student ID : 128261203
// Date: 2021/01/19
////////////////////////////////////////////////
#ifndef SDDS_SHOPPINGLIST_H // include guard
#define SDDS_SHOPPINGLIST_H


namespace sdds {

	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();


}

#endif