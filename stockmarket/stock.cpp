#include "stock.h"

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
    this->bHead.addToList(newBuy);
}
void Stock::addSell(Seller* newSale) {
    this->sHead.addToList(newSale);
}
void Stock::addBuyMax(Buyer* newBuy) {
    this->bHead.addToListTimeMax(newBuy);
}
void Stock::addSellMin(Seller* newSale) {
    this->sHead.addToListMin(newSale);
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
LinkedList<Buyer*> Stock::getBuyList() {
    return this->bHead;
}
LinkedList<Seller*> Stock::getSellList() {
    return this->sHead;
}
void Stock::printBuy() {
    this->bHead.print();
}
void Stock::printSell() {
    this->sHead.print();
}
std::string Stock::retBuyInfo() {
    return this->bHead.retListInfo();
}

std::string Stock::retSellInfo() {
    return this->sHead.retListInfo();

}