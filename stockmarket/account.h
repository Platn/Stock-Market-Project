#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "common.h"
/* Account is used to store an individual person's account information regarding what stocks they have.*/

class Account {
    private:
    // Each account will contain a hashmap that links the stockname to the its own Stock object
    std::unordered_map<std::string,Stock*> stkMap;
    std::string accName;
    public:
    Account();
    Account(std::string);
    
    void addBuyOffer(std::string, Buyer*); // Buy will need the name of the stock and the offer to be added
    void addSellOffer(std::string, Seller*);

    void rmvBOffer(std::string, Buyer*);
    void rmvSOffer(std::string, Seller*);

    void setAccName(std::string);
    std::string getAccName() const;

};

#endif