#include "common.h"

Stock::Stock() {
    stkName = "";
}

Stock::Stock(std::string name) {
    stkName = name;
}


void Stock::addToBList(Buyer* newBuy) {
    
    // Insert vector lambda sort function here
}

void Stock::addToSList(Seller* newSale) {

    // Insert vector lambda sort function here.
}

void Stock::rmvFromBList(Buyer* buyer) {
    // Insert vector find function here, or just do a remove on vector?
}

void Stock::rmvFromSList(Seller* seller) {
    // Insert vector find function here, or just do a remove on vector?
    
}


