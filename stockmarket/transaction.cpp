#include "transaction.h"

Transaction::Transaction(){}
Transaction::Transaction(std::string sym, Buyer* bOffer, Seller* sOffer) {
    this->stkSym = sym;
    this->bOffer = bOffer;
    this->sOffer = sOffer;
}
void Transaction::setStkSym(std::string sym) {
    this->stkSym = sym;
}
void Transaction::setBOffer(Buyer* buyer) {
    this->bOffer = buyer;
}
void Transaction::setSOffer(Seller* seller) {
    this->sOffer = seller;
}
std::string Transaction::getStkSym() const {
    return this->stkSym;
}
Buyer* Transaction::getBOffer() {
    return this->bOffer;
}
Seller* Transaction::getSOffer(){
    return this->sOffer;
}
