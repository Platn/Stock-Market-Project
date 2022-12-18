#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "common.h"


template <typename T> struct Node {
    public:
    Node<T>* nextNode;
    T data;

    Node();
    Node(T);
    bool operator<(Node<T> const &n);
};

template <typename T> bool Node<T>::operator<(Node<T> const &n) {
    if (this->data.getValue() < n.data.getValue()) {
      return true;
    } else {
      return false;
    }
}

template <typename T> inline Node<T>::Node(){
    
}
template <typename T> inline Node<T>::Node(T input){
    this->data = input;
}

template <typename T> class LinkedList {
    private:
    Node<T>* head;
    public:
    LinkedList();
    LinkedList(T); // Overloaded constructor

    void addToList(T);
    void rmvFrmList(T);
    Node<T>* findNode(T);

    bool lessThan(int const& val1, int const& val2);

};

template <typename T> inline LinkedList<T>::LinkedList(){}
template <typename T> inline LinkedList<T>::LinkedList(T item){
    this->head = new Node<T>(item);
}
template <typename T> inline void LinkedList<T>::addToList(T item){
    Node<T>* newNode = new Node<T>(item);
    if(this->head == NULL) {
        this->head = newNode;
        return;
    }
    Node<T>* trave = this->head;
    Node<T>* prev = this->head;
    while(true) {
        if(trave->nextNode == NULL) {
            prev->nextNode = newNode;
            break;
        }
        else if(newNode < trave){ // If newNode is less than traverser
            if (trave == this->head) { // and traverser is the head
                newNode->nextNode = trave;
                head = newNode;
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
        prev = prev->nextNode;
        trave = trave->nextNode;
    }
}

#endif