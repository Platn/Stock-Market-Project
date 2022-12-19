#ifndef MARKET_H
#define MARKET_H
#include "common.h"

class Market {
    private:
    // Each account will contain a hashmap that links the stockname to the its own Stock object
    std::unordered_map<std::string,Stock*> stkMap;
    std::string accName;
    int offerNum;
    public:
    Market();
    Market(std::string);
    
    // By having them inherit, they are able to be differentiated in terms of what can be added
    void mapBuyOffer(std::string, Buyer*);
    void mapSellOffer(std::string, Seller*);

    void rmvBOffer(std::string, Buyer*);
    void rmvSOffer(std::string, Seller*);

    void setAccName(std::string);
    std::string getAccName() const;

    void addStock(Stock*);
    Stock* findStock(std::string);

    void incOfferNum();
    int getOfferNum();
};

#endif