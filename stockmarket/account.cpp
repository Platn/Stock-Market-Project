#include "common.h"

Account::Account(){
    this->accName = "";
}
Account::Account(std::string name) {
    this->accName = name;
}
void Account::setAccName(std::string name) {
    this->accName = name;
}
std::string Account::getAccName() const{
    return this->accName;
}
void Account::addBOffer(std::string stkSym, Buyer* bOffer){
    std::cout << "Inside Account addBOffer: " << std::endl;
    Stock* symbol = findStock(stkSym);
    bOffer->setStkName(stkSym);
    std::cout << "Inside addBOffer: ";
    if (symbol != NULL) {
        std::cout << "Stock found." << std::endl;
        symbol->addBuy(bOffer);
    }
}
void Account::addSOffer(std::string stkSym, Seller* sOffer){
    std::cout << "Inside Account addBOffer: " << std::endl;
    Stock* symbol = findStock(stkSym);
    sOffer->setStkName(stkSym);
    std::cout << "Inside addSOffer: ";
    if (symbol != NULL) {
        std::cout << "Stock found." << std::endl;
        symbol->addSell(sOffer);
    }
}
void Account::rmvBOffer(std::string stkSym, Buyer* bOffer){
    std::cout << "Inside Account rmvBOffer: " << std::endl;
    Stock* symbol = findStock(stkSym);
    std::cout << "Inside rmvBOffer: ";
    if (symbol != NULL) {
        std::cout << "Stock found." << std::endl;
        symbol->rmvBuy(bOffer);
       // Finish removing
    }
    // Here we just use the string inside of the buyOffer? But is the buyoffer string going to stay there?
    // Does that mean we need to pass in the string removal? We will for now.
}
void Account::rmvSOffer(std::string stkSym, Seller* sOffer){
    std::cout << "Inside Account rmvSOffer: " << std::endl;
    Stock* symbol = findStock(stkSym);
    std::cout << "Inside rmvSOffer: ";
    if (symbol != NULL) {
        std::cout << "Stock found." << std::endl;
        symbol->rmvSell(sOffer);
    }
}
Stock* Account::findStock(std::string stkName) {
    std::cout << "Inside findStock: ";
    auto search = stkMap.find(stkName);
    if (stkMap.find(stkName) == stkMap.end()) { // Stock not found
        std::cout << "Stock not found." << std::endl;
        return NULL;
    }
    return search->second;
}