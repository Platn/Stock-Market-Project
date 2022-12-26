   #include "offer.h"
    
    /* Constructors*/
    Offer::Offer(){ // Empty Constructor
        this->numStks = 0;
        this->price = 0.0;
        this->time = -1;
        this->id = -1;
    } 
    Offer::Offer(int numOfStks, int stkPrice, int transTime, int offerID){ // Overloaded constructor
        this->numStks = numOfStks;
        this->price = stkPrice;
        this->time = transTime;
        this->id = offerID;
    }

    /* Set Helper Functions */

    void Offer::setStkName(std::string name){
        this->stkName = name;
    }
    void Offer::setCustName(std::string name){
        this->custName = name;
    }
    void Offer::setNumStks(int numOfStks){ // Number of Stocks
        this->numStks = numOfStks;
    }
    void Offer::setPrice(int stkPrice){ // Stock Price
        this->price = stkPrice;
    }
    void Offer::setTime(int transTime){
        this->time = transTime;
    }
    void Offer::setID(int offerID){
        this->id = offerID;
    }

    /* Get Helper Functions */
    std::string Offer::getStkName() const{
        return this->stkName;
    }
    std::string Offer::getCustName() const{
        return this->custName;
    }
    int Offer::getNumStks() const{
        return this->numStks;
    }
    int Offer::getPrice() const{
        return this->price;
    }
    int Offer::getTime() const{
        return this->time;
    }
    int Offer::getID() const{
        return this->id;
    }
    