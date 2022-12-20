#include "exchange.h"

Exchange::Exchange(){}
Exchange::Exchange(std::string sym, Buyer* bOffer, Seller* sOffer) {
    this->stkSym = sym;
    this->bOffer = bOffer;
    this->sOffer = sOffer;
}
void Exchange::setStkSym(std::string sym) {
    this->stkSym = sym;
}
void Exchange::setBOffer(Buyer* buyer) {
    this->bOffer = buyer;
}
void Exchange::setSOffer(Seller* seller) {
    this->sOffer = seller;
}
std::string Exchange::getStkSym() const {
    return this->stkSym;
}
Buyer* Exchange::getBOffer() {
    return this->bOffer;
}
Seller* Exchange::getSOffer(){
    return this->sOffer;
}
