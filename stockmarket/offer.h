#ifndef OFFER_H
#define OFFER_H
#include "common.h"

class Offer { // An Offer can be either a buyer or seller
    private:
        std::string accName;
        int numStks;
        float price;
        
    public:
    
    Offer(); // Default Constructor
    Offer(std::string name, int numOfStks, float stkPrice); // Overloaded Constructor

    /* Set Helper Functions */
    void setAccName(std::string name);
    void setNumStks(int numOfStks);
    void setPrice(float stkPrice);
    void setB_S(bool B_S);

    /* Get Helper Functions */
    std::string getAccName();
    int getNumStks();
    float getPrice();

};

#endif // Offer_H