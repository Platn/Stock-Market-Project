#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "common.h"

class Transaction {
    private:
    std::string stkSym;
    Buyer* bOffer;
    Seller* sOffer;
    

    public:
    Transaction();
    Transaction(std::string, Buyer*, Seller*);
    void setStkSym(std::string);
    void setBOffer(Buyer*);
    void setSOffer(Seller*);
    std::string getStkSym() const;
    Buyer* getBOffer();
    Seller* getSOffer();
    
};

#endif