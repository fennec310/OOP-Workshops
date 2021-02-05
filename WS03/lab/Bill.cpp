// Workshop 3 _ lab
// Name: Juhee Lee
// Seneca email : jlee651@myseneca.ca
// student ID : 128261203
// Date: 2021/ 02/ 04
////////////////////////////////////////////////
#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

  
    
    //Adds all the taxes of the items using a loop and returns the sum.
    double Bill::totalTax()const {
        double sum = 0.0;
        int i = 0;
        for (i = 0; i < m_noOfItems; i++) {
            sum += m_items[i].tax();
        }
        return sum;
    }

    //Adds all the prices of the items using a loop and returns the sum;
    double Bill::totalPrice()const {
        double sum = 0.0;
        int i = 0;
        for (i = 0; i < m_noOfItems; i++) {
            sum += m_items[i].price();
        }
        return sum;
    }


    void Bill::Title()const {
        bool check = isValid();
        cout << "+--------------------------------------+" << endl;

        if (check != 0) { // Bill is valid
            cout << "| ";
            cout.setf(ios::left);
            cout.width(36);
            cout << m_title << " |" << endl;
            cout << "+----------------------+---------+-----+" << endl;
            cout << "| Item Name            | Price   + Tax |" << endl;
            cout << "+----------------------+---------+-----+" << endl;
           // cout.unsetf(ios::left);
        }
        else {// Bill is invalid
            cout << "| Invalid Bill                         |" << endl;
            cout << "+----------------------+---------+-----+" << endl;
            cout << "| Item Name            | Price   + Tax |" << endl;
            cout << "+----------------------+---------+-----+" << endl;

        }

    }

    void Bill::footer()const {
        bool check = isValid();
        double tax;
        double price;
        double total;

        cout << "+----------------------+---------+-----+" << endl;
        if (check != 0) {
            tax = totalTax();
            price = totalPrice();
            total = tax + price;

            cout << "|                Total Tax: ";
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.width(10);
            cout.precision(2);
            cout << tax << " |" << endl;
            cout << "|              Total Price: ";
            cout.width(10);
            cout << price << " |" << endl;
            cout.width(10);
            cout << "|          Total After Tax: ";
            cout.width(10);
            cout << total << " |" << endl;
            cout << "+--------------------------------------+" << endl;
       
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
            cout << "+--------------------------------------+" << endl;
        }
        
    }


    //Sets the Bill object to an empty state by setting m_title to an Empty Cstring and m_items to nullptr
    void Bill::setEmpty() {
        
       m_title[0] = '\0';
       m_items = nullptr;
    }

    bool Bill::isValid()const {
        bool flag = false;
        int check = 0;
        int i = 0;
        if (m_items == nullptr || m_title[0] == '\0') {
            flag = false;
        }
        else {
            for (i = 0; i < m_noOfItems; i++) {
                check += m_items[i].isValid(); 
            }

            if (check == m_noOfItems) { // all items are valid
                flag = true;
            }
            else {
                flag = false; // one or more items are invalid;
            }
        }
        return flag;
    }



    bool Bill::add(const char* item_name, double price, bool taxed) {
        bool flag = false;
       
        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            
            flag = true;
        }
        else {
            flag = false;
        }
        return flag;
    }

    void Bill::display()const {
        int i = 0;

        Title();
        for (i = 0; i < m_noOfItems; i++) {
            m_items[i].display();
        }
        footer();

    }


    void Bill::init(const char* title, int noOfItems) {

        int i = 0;
        
        if (title == nullptr || title[0] == '\0' || noOfItems <= 0) {// empty state
            setEmpty();

        }
        else {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;

            strnCpy(m_title, title, 37); // //copy the Cstring pointed by the title argument into m_title

            m_items = new Item[m_noOfItems]; //dynamically allocate an array of Items pointed by m_items member variable.

            for (i = 0; i < m_noOfItems; i++) { // dynamically allocated Items are set to empty
                m_items[i].setEmpty();
            }
        }
    }

    void Bill::deallocate() {
        
        delete[] m_items;

        m_items = nullptr;
    }


}