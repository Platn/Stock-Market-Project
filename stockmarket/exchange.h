#ifndef EXCHANGE_H
#define EXCHANGE_H
#include "common.h"

class Exchange {
    private:
    std::string stkSym;
    Buyer* bOffer;
    Seller* sOffer;
    
    public:
    Exchange();
    Exchange(std::string, Buyer*, Seller*);
    void setStkSym(std::string);
    void setBOffer(Buyer*);
    void setSOffer(Seller*);
    std::string getStkSym() const;
    Buyer* getBOffer();
    Seller* getSOffer();
    
};

#endif