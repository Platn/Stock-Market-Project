   #include "common.h"
    
    /* Constructors*/
    Account::Account(){ // Empty Constructor
        this->accName = "";
        this->numStks = 0;
        this->price = 0.0;
        buySell = 0;
    } 
    Account::Account(std::string name, int numOfStks, float stkPrice, bool B_S){ // Overloaded constructor
        this->numStks = numOfStks;
        this->accName = name;
        this->price = stkPrice;
        this->buySell = B_S;
    }

    /* Set Helper Functions */
    void Account::setAccName(std::string name) { // Account Name
        this->accName = name;
    }
    void Account::setNumStks(int numOfStks) { // Number of Stocks
        this->numStks = numOfStks;
    }
    void Account::setPrice(float stkPrice) { // Stock Price
        this->price = stkPrice;
    }
    void Account::setB_S(bool B_S) { // Buyer or seller
        this->buySell = B_S;
    }

    /* Get Helper Functions */
    std::string Account::getAccName() {
        return this->accName;
    }
    int Account::getNumStks() {
        return this->numStks;
    }
    float Account::getPrice() {
        return this->price;
    }
    bool Account::getB_S(){
        return this->buySell;
    }

    