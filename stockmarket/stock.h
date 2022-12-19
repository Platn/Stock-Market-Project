#ifndef STOCK_H
#define STOCK_H
#include "common.h"
#include "linkedlist.h"

class Buyer : public Offer {
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

    void addBuy(Buyer*);
    void addSell(Seller*);

    void setLastPrice(int);
    int getLastPrice() const;

    void rmvBuy(Buyer*);
    void rmvSell(Seller*);
    
};

#endif // STOCK_H