#ifndef MARKET_H
#define MARKET_H
#include "common.h"

class Market : public Account {
    private:
    std::unordered_map<std::string,Customer*> customList;
    int offerNum;
    public:
    Market();
    Market(std::string);
    
    // By having them inherit, they are able to be differentiated in terms of what can be added
    // void addBuyOffer(std::string, Buyer*);
    // void addSellOffer(std::string, Seller*);

    void rmvBOffer(std::string, Buyer*);
    void rmvSOffer(std::string, Seller*);

    void setAccName(std::string);
    std::string getAccName() const;

    void addStock(Stock*);
    // Stock* findStock(std::string);

    void incOfferNum();
    int getOfferNum();

    void addCustomer(Customer*);
    Customer* getCustomer(std::string);
};

#endif