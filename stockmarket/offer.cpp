   #include "common.h"
    
    /* Constructors*/
    Offer::Offer(){ // Empty Constructor
        this->numStks = 0;
        this->price = 0.0;
        this->time = -1;
    } 
    Offer::Offer(int numOfStks, int stkPrice, int transTime){ // Overloaded constructor
        this->numStks = numOfStks;
        this->price = stkPrice;
        this->time = transTime;
    }

    /* Set Helper Functions */

    void Offer::setStkName(std::string name){
        this->stkName = name;
    }
    void Offer::setNumStks(int numOfStks) { // Number of Stocks
        this->numStks = numOfStks;
    }
    void Offer::setPrice(int stkPrice) { // Stock Price
        this->price = stkPrice;
    }
    void Offer::setTime(int transTime) {
        this->time = transTime;
    }

    /* Get Helper Functions */
    std::string Offer::getStkName() const {
        return this->stkName;
    }
    int Offer::getNumStks() const{
        return this->numStks;
    }
    int Offer::getPrice() const{
        return this->price;
    }
    int Offer::getTime() const {
        return this->time;
    }
    