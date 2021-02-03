// Workshop 1 _ Lab
// Name: Juhee Lee
// Seneca email : jlee651@myseneca.ca
// student ID : 128261203
// Date: 2021/01/19
////////////////////////////////////////////////
#ifndef SDDS_FILE_H // include guard
#define SDDS_FILE_H 
#include "ShoppingRec.h"

namespace sdds {
    
    
    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec* rec);
    void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif