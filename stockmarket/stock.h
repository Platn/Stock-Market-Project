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
    std::string stkName;
    LinkedList<Buyer*> bHead;
    LinkedList<Seller*> sHead;

    public:
    Stock();
    Stock(std::string); // Overloaded function

    /* Helper Functions*/
    void setStkName(std::string);
    void addBuy(Buyer*);
    void addSell(Seller*);

    void rmvBuy(Buyer*);
    void rmvSell(Seller*);

    // findBuyer() will be used in removeBList?
    // void findBuyer(Buyer*);
};

#endif // STOCK_H