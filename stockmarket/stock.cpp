#include "common.h"

Stock::Stock() {
    stkSym = "";
}
Stock::Stock(std::string symbol) {
    stkSym = symbol;
}
void Stock::setStkSym(std::string symbol) {
    this->stkSym = symbol;
}
std::string Stock::getStkSym() const {
    return this->stkSym;
}

void Stock::addBuy(Buyer* newBuy) {
    bHead.addToList(newBuy);
}
void Stock::addSell(Seller* newSale) {
    sHead.addToList(newSale);
}

void Stock::setLastPrice(int price) {
    this->lastPrice = price;
}
int Stock::getLastPrice() const {
    return this->lastPrice;
}

void Stock::rmvBuy(Buyer* buyer) {
    this->bHead.rmvFrmList(buyer);
}
void Stock::rmvSell(Seller* seller) {
    this->sHead.rmvFrmList(seller);
}