#include "common.h"

Account::Account(){}

void Account::addBuyOffer(std::string stkName, Buyer* bOffer){
    auto search = stkMap.find(stkName);
    if(search != stkMap.end()) { // Exists
        std::cout << stkName << " was found." << std::endl;
        search->second->addBuy(bOffer);
    }
    else { // Stock was not found.
        /* Create a new stock, store the offer inside of the buyers list and map it*/
        std::cout << stkName << " was not found." << std::endl;
        Stock* newStock = new Stock(stkName);
        newStock->addBuy(bOffer);
        stkMap.insert(std::make_pair(stkName,newStock)); // Okay that's fine. I think we might have leaking memory here.
        // newStock = NULL; // We need to check later to see if this works.
    }
}

void Account::addSellOffer(std::string stkName, Seller* sOffer){
    auto search = stkMap.find(stkName);
    // std::cout << typeid(search).name() << std::endl;
    if(search != stkMap.end()) { // Exists
        std::cout << stkName << " was found." << std::endl;
        
        search->second->addSell(sOffer);
    }
    else { // Stock was not found.
        /* Create a new stock, store the offer inside of the buyers list and map it*/
        std::cout << stkName << " was not found." << std::endl;
        Stock* newStock = new Stock(stkName);
        newStock->addSell(sOffer);
        stkMap.insert(std::make_pair(stkName,newStock)); // Okay that's fine. I think we might have leaking memory here.
        // newStock = NULL; // We need to check later to see if this works.
    }
}

void rmvBOffer(std::string, Buyer*) {
}

void rmvSOffer(std::string, Seller*) {

}

void Account::setAccName(std::string name) {
    this->accName = name;
}

std::string Account::getAccName() const {
    return this->accName;
}
