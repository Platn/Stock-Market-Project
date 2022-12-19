#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "common.h"
/* Account is used to store an individual person's account information regarding what stocks they have.*/

class Account {
    protected:
    // Each account will contain a hashmap that links the stockname to its own Stock object
    std::string accName;
    std::unordered_map<std::string,Stock*> stkMap;
    
    public:
    Account();
    Account(std::string);
    
    void setAccName(std::string);
    std::string getAccName() const;
    virtual void addBOffer(std::string, Buyer*);
    virtual void addSOffer(std::string, Seller*);

    void rmvBOffer(std::string, Buyer*);
    void rmvSOffer(std::string, Seller*);

    Stock* findStock(std::string);

};

#endif