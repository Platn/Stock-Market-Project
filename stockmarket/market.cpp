#include "market.h"

Market::Market(){
    this->offerNum = 0;
}

Market::Market(std::string name) {
    this->accName = name;
    this->offerNum = 0;
}

/* Below needs to be inside of Customer */
// void Market::addBuyOffer(std::string stkName, Buyer* bOffer){
//     auto search = stkMap.find(stkName);
//     if(search != stkMap.end()) { // Exists
//         std::cout << stkName << " was found." << std::endl;
//         search->second->addBuy(bOffer);
//     }
//     else { // Stock was not found.
//         /* Create a new stock, store the offer inside of the buyers list and map it*/
//         std::cout << stkName << " was not found." << std::endl;
//         Stock* newStock = new Stock(stkName);
//         newStock->addBuy(bOffer);
//         stkMap.insert(std::make_pair(stkName,newStock)); // Okay that's fine. I think we might have leaking memory here.
//         // newStock = NULL; // We need to check later to see if this works.
//     }
// }
// void Market::addSellOffer(std::string stkName, Seller* sOffer){
//     auto search = stkMap.find(stkName);
//     if(search != stkMap.end()) { // Exists
//         std::cout << stkName << " was found." << std::endl;
//         search->second->addSell(sOffer);
//     }
//     else { // Stock was not found.
//         /* Create a new stock, store the offer inside of the buyers list and map it*/
//         std::cout << stkName << " was not found." << std::endl;
//         Stock* newStock = new Stock(stkName);
//         newStock->addSell(sOffer);
//         stkMap.insert(std::make_pair(stkName,newStock)); // Okay that's fine. I think we might have leaking memory here.
//         // newStock = NULL; // We need to check later to see if this works.
//     }
// }

void rmvBOffer(std::string, Buyer*) {

}
void rmvSOffer(std::string, Seller*) {

}
void Market::setAccName(std::string name) {
    ((Account*)this)->setAccName(name);
}
std::string Market::getAccName() const {
    return  ((Account*)this)->getAccName();
}
void Market::addStock(Stock* newStock) { // Only used for Stock Market creation
    std::pair<std::string,Stock*> stkNode(newStock->getStkSym(),newStock);
    std::cout << "AddStock Values: " << newStock->getStkSym() << std::endl;
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
