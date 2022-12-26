#include "market.h"

Market::Market(){
    this->offerNum = -1;
}

Market::Market(std::string name) {
    this->accName = name;
    this->offerNum = -1;
}
void Market::addBOffer(std::string stkSym, Buyer* bOffer){
    // std::cout << "Market AddSOffer" << std::endl;
    auto search = this->stkMap.find(stkSym);
    if (search != this->stkMap.end()) {
        // std::cout << "Adding sell offer" << std::endl;
        search->second->addBuy(bOffer);
        return;
    }
    // std::cout << "AddSOffer not found" << std::endl;
}

void Market::addSOffer(std::string stkSym, Seller* sOffer){
    // std::cout << "Market AddSOffer" << std::endl;
    auto search = this->stkMap.find(stkSym);
    if (search != this->stkMap.end()) {
        // std::cout << "Adding sell offer" << std::endl;
        search->second->addSell(sOffer);
        return;
    }
    // std::cout << "AddSOffer not found" << std::endl;
}
// void Market::rmvBOffer(std::string stkSym, Buyer* bOffer) {
//     std::cout << "Market rmvBOffer" << std::endl;
// }
// void Market::rmvSOffer(std::string stkSym, Seller*sOffer) {

// }
void Market::setAccName(std::string name) {
    ((Account*)this)->setAccName(name);
}
std::string Market::getAccName() const {
    return  ((Account*)this)->getAccName();
}
void Market::addStock(Stock* newStock) { // Only used for Stock Market creation
    std::pair<std::string,Stock*> stkNode(newStock->getStkSym(),newStock);
    // std::cout << "Market AddStock Values: " << newStock->getStkSym() << std::endl;
    stkMap.insert(stkNode);
}
/* incOrderNum() increments the offer number for each offer sent in.*/
void Market::incOfferNum(){
    this->offerNum++;
}
int Market::getOfferNum(){
    this->incOfferNum();
    return this->offerNum;
}
void Market::addCustomer(Customer* customer) {
    // std::cout << "Market Add Customer" << std::endl;
    this->customList.insert(std::make_pair(customer->getAccName(), customer));
}

Customer* Market::getCustomer(std::string accName) {
    auto search = this->customList.find(accName);
    // std::cout << "Inside Market Get Customer: " << std::endl;
    std::cout << "Searching for: " << accName << std::endl;
    if(search != this->customList.end()){
        // std::cout << " was found." << std::endl;
        return search->second;
    }
    // std::cout << " was not found." << std::endl;
    return NULL;
}