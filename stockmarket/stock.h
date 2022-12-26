
#ifndef STOCK_H
#define STOCK_H
#include "common.h"
#include "linkedlist.h"
#include "offer.h"

class Buyer : public Offer {
    private:
    std::string buyerName;
	public:
	Buyer(){}
};

class Seller : public Offer {
	public:
	Seller(){}
};

class Stock {
    private:
    std::string stkSym;
    LinkedList<Buyer*> bHead;
    LinkedList<Seller*> sHead;
    int lastPrice; // Used to populate range of buys and sells within the stock itself

    public:
    Stock();
    Stock(std::string); // Overloaded function

    /* Helper Functions*/
    void setStkSym(std::string);
    std::string getStkSym() const;

    /* Standard: addBuy() and addSell() are strictly used for non-sorted list. */
    void addBuy(Buyer*);
    void addSell(Seller*);

    /* Debugging: addBuyMax() and addSellMin() are used to easily sort.  */
    void addBuyMax(Buyer*);
    void addSellMin(Seller*);

    void setLastPrice(int);
    int getLastPrice() const;

    void rmvBuy(Buyer*);
    void rmvSell(Seller*);

    LinkedList<Buyer*> getBuyList();
    LinkedList<Seller*> getSellList();

    /*Used for debugging purposes*/
    void printBuy();
    void printSell();

    std::string retBuyInfo();
    std::string retSellInfo();


};

#endif // STOCK_H