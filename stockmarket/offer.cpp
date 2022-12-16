   #include "common.h"
    
    /* Constructors*/
    Offer::Offer(){ // Empty Constructor
        this->accName = "";
        this->numStks = 0;
        this->price = 0.0;
    } 
    Offer::Offer(std::string name, int numOfStks, float stkPrice){ // Overloaded constructor
        this->numStks = numOfStks;
        this->accName = name;
        this->price = stkPrice;
    }

    /* Set Helper Functions */
    void Offer::setAccName(std::string name) { // Offer Name
        this->accName = name;
    }
    void Offer::setNumStks(int numOfStks) { // Number of Stocks
        this->numStks = numOfStks;
    }
    void Offer::setPrice(float stkPrice) { // Stock Price
        this->price = stkPrice;
    }

    /* Get Helper Functions */
    std::string Offer::getAccName() {
        return this->accName;
    }
    int Offer::getNumStks() {
        return this->numStks;
    }
    float Offer::getPrice() {
        return this->price;
    }
    