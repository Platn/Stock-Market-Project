#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "common.h"

/* Account is used to store an individual person's account information regarding what they have*/

class Account {
    private:
    std::vector<Buyer*> bList;
    std::vector<Seller*> sList;

    public:
    Account();
};

#endif