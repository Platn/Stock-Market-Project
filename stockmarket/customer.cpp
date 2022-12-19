#include "customer.h"

Customer::Customer(std::string accName){
    this->accName = accName;
}
void Customer::addBOffer(std::string stkSym, Buyer* bOffer) {
    auto search = stkMap.find(stkSym);
    if(search != stkMap.end()) { // Exists
        std::cout << stkSym << " was found." << std::endl;
        search->second->addBuy(bOffer);
    }
    else { // Stock was not found.
        /* Create a new stock, store the offer inside of the buyers list and map it*/
        std::cout << stkSym << " was not found." << std::endl;
        Stock* newStock = new Stock(stkSym);
        newStock->addBuy(bOffer);
        stkMap.insert(std::make_pair(stkSym,newStock)); // Okay that's fine. I think we might have leaking memory here.
        // newStock = NULL; // We need to check later to see if this works.
    }
}
void Customer::addSOffer(std::string stkSym, Seller* sOffer) {
    auto search = stkMap.find(stkSym);
    if(search != stkMap.end()) { // Exists
        std::cout << stkSym << " was found." << std::endl;
        search->second->addSell(sOffer);
    }
    else { // Stock was not found.
        /* Create a new stock, store the offer inside of the buyers list and map it*/
        std::cout << stkSym << " was not found." << std::endl;
        Stock* newStock = new Stock(stkSym);
        newStock->addSell(sOffer);
        stkMap.insert(std::make_pair(stkSym,newStock)); // Okay that's fine. I think we might have leaking memory here.
        // newStock = NULL; // We need to check later to see if this works.
    }
}

