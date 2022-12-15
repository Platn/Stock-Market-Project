#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "common.h"
class Account { // An account can be either a buyer or seller
    private:
        std::string accName;
        int numStks;
        float price;
        bool buySell; // 0 = seller, 1 = buyer
    public:
    
    Account(); // Default Constructor
    Account(std::string name, int numOfStks, float stkPrice, bool B_S); // Overloaded Constructor

    /* Set Helper Functions */
    void setAccName(std::string name);
    void setNumStks(int numOfStks);
    void setPrice(float stkPrice);
    void setB_S(bool B_S);


    /* Get Helper Functions */
    std::string getAccName();
    int getNumStks();
    float getPrice();
    bool getB_S();



};

#endif // ACCOUNT_H