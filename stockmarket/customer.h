#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "common.h"
#include "account.h"
class Customer : public Account {
    private:

    public:
    Customer();
    Customer(std::string accName);
    
    void  addBOffer(std::string, Buyer*);
    void  addSOffer(std::string, Seller*);
    
};
#endif