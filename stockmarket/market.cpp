#include "market.h"

Market::Market(){
    this->offerNum = 0;
}

Market::Market(std::string name) {
    this->accName = name;
    this->offerNum = 0;
}
// void rmvBOffer(std::string, Buyer*) {

// }
// void rmvSOffer(std::string, Seller*) {

// }
void Market::setAccName(std::string name) {
    ((Account*)this)->setAccName(name);
}
std::string Market::getAccName() const {
    return  ((Account*)this)->getAccName();
}
void Market::addStock(Stock* newStock) { // Only used for Stock Market creation
    std::pair<std::string,Stock*> stkNode(newStock->getStkSym(),newStock);
    std::cout << "Market AddStock Values: " << newStock->getStkSym() << std::endl;
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
    std::cout << "Add Customer" << std::endl;
    this->customList.insert(std::make_pair(customer->getAccName(), customer));
}

Customer* Market::getCustomer(std::string accName) {
    auto search = this->customList.find(accName);
    std::cout << "Inside Market Get Customer: " << std::endl;
    std::cout << accName;
    if(search != this->customList.end()){
        std::cout << " was found" << std::endl;
        return search->second;
    }
    std::cout << "was not found" << std::endl;
}