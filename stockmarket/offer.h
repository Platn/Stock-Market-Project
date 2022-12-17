#ifndef OFFER_H
#define OFFER_H
#include "common.h"

class Offer { // An Offer can be either a buyer or seller
    protected:
        std::string accName;
        int numStks;
        int price;
        int time;
    public:
    Offer(); // Default Constructor
    Offer(int , int ,int); // Overloaded Constructor

    /* Set Helper Functions */
    void setAccName(std::string);
    void setNumStks(int);
    void setPrice(int);
    void setTime(int);

    /* Get Helper Functions */
    std::string getAccName() const;
    int getNumStks() const;
    int getPrice() const;
    int getTime() const;
};

#endif // Offer_H