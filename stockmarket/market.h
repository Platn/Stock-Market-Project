#ifndef MARKET_H
#define MARKET_H
#include "common.h"
#include "customer.h"
class Market : public Account {
    private:
    std::unordered_map<std::string,Customer*> customList;
    std::vector<Transaction*> tList;
    int offerNum;
    public:
    Market();
    Market(std::string);
    
    // By having them inherit, they are able to be differentiated in terms of what can be added
    void addBOffer(std::string, Buyer*);
    void addSOffer(std::string, Seller*);

    // void rmvBOffer(std::string, Buyer*);
    // void rmvSOffer(std::string, Seller*);

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