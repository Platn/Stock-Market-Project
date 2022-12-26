#ifndef OFFER_H
#define OFFER_H
#include "common.h"

class Offer { // An Offer can be either a buyer or seller
    protected:
        std::string stkName;
        std::string custName;
        int numStks;
        int price;
        int time;
        int id;
    public:
    Offer(); // Default Constructor
    Offer(int,int,int,int); // Overloaded Constructor

    /* Set Helper Functions */
    void setStkName(std::string);
    void setCustName(std::string);
    void setNumStks(int);
    void setPrice(int);
    void setTime(int);
    void setID(int);

    /* Get Helper Functions */
    std::string getStkName() const;
    std::string getCustName() const;
    int getNumStks() const;
    int getPrice() const;
    int getTime() const;
    int getID() const;
};

#endif // Offer_H