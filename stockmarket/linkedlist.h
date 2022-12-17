#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "common.h"

template <typename T> struct Node {
    public:
    Node<T>* nextNode;
    T* data;
};

template <typename T> class LinkedList {
    private:
    Node<T>* bHead;
    Node<T>* bTail;
    public:
    LinkedList();
    LinkedList(Node<T>*); // Overloaded constructor

    void addToList(Node<T>*);
    void rmvFrmList(Node<T>*);
    Node<T>* findNode(Node<T>*);

    bool lessThan(int const& val1, int const& val2);

};

template <typename T> inline LinkedList<T>::LinkedList(){}
template <typename T> inline LinkedList<T>::LinkedList(Node<T>* firstBuy){
    this->bHead = firstBuy;
}
template <typename T> inline void LinkedList<T>::addToList(Node<T>* newNode){
    if(this->bHead == NULL) {
        this->bHead = newNode;
    }
    Node<T>* trave = this->bHead;
    Node<T>* prev = this->bHead;
    while(true) {
        if(trave->nextNode == NULL) {
            prev->nextNode = newNode;
            break;
        }
        else if(lessThan(newNode,trave)){ // If newNode is less than traverser
            if (trave == this->bHead) { // and traverser is the head
                newNode->nextNode = trave;
                bHead = newNode;
            } else {
                /* Set our previous node to the newNode, set the newNode's
                ** nextNode to traverser
                */
                prev->nextNode = newNode;
                newNode->nextNode = trave;
            }
            break;
        }
        // Move the values forward if none of the above occurs.
        prev->trave;
        trave = trave->nextNode;
    }
}
template <typename T> inline bool LinkedList<T>::lessThan(int const &val1, int const &val2){
    if (val1 <= val2) {
        return true;
    }
    else{
        return false;
    }
}
#endif