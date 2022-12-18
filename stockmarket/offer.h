#ifndef OFFER_H
#define OFFER_H
#include "common.h"

class Offer { // An Offer can be either a buyer or seller
    protected:
        std::string stkName;
        int numStks;
        int price;
        int time;
    public:
    Offer(); // Default Constructor
    Offer(int , int ,int); // Overloaded Constructor

    /* Set Helper Functions */
    void setStkName(std::string);
    void setNumStks(int);
    void setPrice(int);
    void setTime(int);

    /* Get Helper Functions */
    std::string getStkName() const;
    int getNumStks() const;
    int getPrice() const;
    int getTime() const;
};

#endif // Offer_H