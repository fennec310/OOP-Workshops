// Workshop 3 _ lab
// Name: Juhee Lee
// Seneca email : jlee651@myseneca.ca
// student ID : 128261203
// Date: 2021/ 02/ 04
////////////////////////////////////////////////
#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {


	void Item::setName(const char* name) {
			strnCpy(m_itemName, name, 21);
			
	}

	//Sets the Item to a recognizable safe Empty State. Do this by setting the price to an impossible value like 0.0 and setting the m_itemName to a blank string  (first character set to null).
	void Item::setEmpty() {

			m_itemName[0] = '\0';
		 	m_price = 0.0;

	}


	//Sets the m_itemName attribute to the Cstring pointed by the name argument using the setName method and sets the m_price and m_taxed attributes to the corresponding arguments.
	//If price is less than 0 or name is null, then the Item is set to a recognizable invalid empty state(safe empty state).
	void Item::set(const char* name, double price, bool taxed) {
		
		if (name == nullptr || name[0] == '\0' || price < 0 ) {
			//the data is invalid, we can reject it and store default values that identify the object's state as an empty state
			setEmpty();
		}
		else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
		
	}

	void Item::display()const {
		bool check = isValid();
		if (check != 0) {

			char yn[4] = "\0";
		
			if (m_taxed) {
				strnCpy(yn, "Yes", 4);
			}
			else {
				strnCpy(yn, "No ", 4);			
			}

			cout << "| ";
			cout.setf(ios::left);
			cout.fill('.');
			cout.width(20);
			cout << m_itemName << " | ";
			cout.unsetf(ios::left);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.fill(' ');
			cout.width(7);
			cout.precision(2);
			cout << m_price << " | ";
			cout.unsetf(ios::right);
			cout << yn << " |" << endl;

		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}

	}

	//Returns true if the Item is not set to the empty state (As done in setEmpty function) .
	//This function can not modify its owner.
	bool Item::isValid()const {
		bool flag = false;

		if (m_itemName[0] == '\0') { 
			flag = false;
		}
		else {
			flag = true;
		}

		return flag;
	}

	//Returns the m_price attribute;
	double Item::price()const {
		return m_price;
	}
	
	//Returns the product of m_price and 0.13(define a constant double value for this tax rate). Or it returns 0.0 if the m_taxed is false.
	double Item::tax()const { 
		
		const double rate = 0.13;
		double tax = 0.0;

		if (m_taxed) {
			tax = m_price * rate;
		}
		else {
			tax = 0.0;
		}
		return tax;
	}




}