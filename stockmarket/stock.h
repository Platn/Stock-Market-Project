#ifndef STOCK_H
#define STOCK_H
#include "common.h"

template <typename T> struct Node {
    public:
    T* nextNode;

    bool LinkedList<T> operator<(const LinkedList<T>&,const LinkedList<T>&);
};



template <typename T> class LinkedList {
    private:
    Node<T>* bHead;
    Node<T>* bTail;
    public:
    LinkedList();
    LinkedList(Node<T>*){} // Overloaded constructor

    void addToList(Node<T>*);
    void rmvFrmList(Node<T>*);
    Node<T>* findNode(Node<T>*);
};

template <typename T> LinkedList<T>::LinkedList(){}
template <typename T> LinkedList<T>::LinkedList(Node<T>* firstBuy){
    this->bHead = firstBuy;
}
template <typename T> void LinkedList<T>::addToList(Node<T>* newNode){
    if(this->bHead == NULL) {
        this->bHead = newNode;
    }
    Node<T>* trave = this->bHead;
    Node<T>* prev = this->bHead;
    while(true) {
        if(trave->nextNode == NULL) {
            prev->nextNode = newNode;
        }
        else if(trave->)
    }
}
template <typename T> bool operator>=(const LinkedList<T>& val1,const LinkedList<T>& val2){

}



class Buyer : public Offer {
	public:
	Buyer(){}
};

class Seller : 	public Offer {
	public:
	Seller(){}
};

class Stock {
    private:
    std::string stkName;
    Buyer* bHead;
    Buyer* bTail;
    Seller* sHead;

    public:
    Stock();
    Stock(std::string); // Overloaded function

    /* Helper Functions*/
    void setStkName(std::string);
    void addToBList(Buyer*);
    void addToSList(Seller*);

    void rmvFromBList(Buyer*);
    void rmvFromSList(Seller*);

    // findBuyer() will be used in removeBList?    
    // void findBuyer(Buyer*); 

    
};

#endif