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

template <typename T> inline Node<T>::Node(){}
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
    
    void print();

};

template <typename T> LinkedList<T>::LinkedList(){}
template <typename T> LinkedList<T>::LinkedList(T item){
    this->head = new Node<T>(item);
}
template <typename T> void LinkedList<T>::addToList(T item){
    Node<T>* newNode = new Node<T>(item);
    Node<T>* travel = this->head;

    if (travel == NULL) {
        this->head = newNode;
        return;
    } else if (newNode->data->getPrice() < travel->data->getPrice()) {
        newNode->nextNode = this->head;
        return;
    } else if (newNode->data->getPrice() == travel->data->getPrice()) {
        Node<T>* qTravel = travel;
        // qTravel cannot be null, we confirm this through travel->data
        // Now we check if the current travel is greater.
        if (newNode->data->getNumStks() > travel->data->getNumStks()) {
            newNode->nextNode = travel;
            travel = newNode->nextNode;
            return;
        }
        while(true) {
            if (qTravel->nextNode == NULL) {
                qTravel->nextNode = newNode;
                return;
            } else if (newNode->data->getPrice() == qTravel->nextNode->data->getPrice() &&
             newNode->data->getNumStks() >= qTravel->nextNode->data->getNumStks()) {
                newNode->nextNode = qTravel->nextNode;
                qTravel->nextNode = newNode;
                return;
            } else if (newNode->data->getPrice() != qTravel->nextNode->data->getPrice()) {
                newNode->nextNode = qTravel->nextNode;
                qTravel->nextNode = newNode;
                return;
            }
            qTravel = qTravel->nextNode;
        }
    }

    while(true) {
        if (travel->nextNode == NULL) {
            travel->nextNode = newNode;
            break;
        }
        else if(newNode->data->getPrice() < travel->nextNode->data->getPrice()) {
            newNode->nextNode = travel->nextNode;
            travel->nextNode = newNode;
            break;
        }
        else if(newNode->data->getPrice() == travel->nextNode->data->getPrice()) {
            Node<T>* qTravel = travel;
            // qTravel cannot be null, we confirm this through travel->data
            // Now we check if the current travel is greater.
            if (newNode->data->getNumStks() > travel->data->getNumStks()) {
                newNode->nextNode = qTravel;
                travel = newNode->nextNode;
                return;
            }
            while(true) {
                if (qTravel->nextNode == NULL) {
                    qTravel->nextNode = newNode;
                    return;
                } else if (newNode->data->getPrice() == qTravel->nextNode->data->getPrice() &&
                 newNode->data->getNumStks() >= qTravel->nextNode->data->getNumStks()) {
                    newNode->nextNode = qTravel->nextNode;
                    qTravel->nextNode = newNode;
                    return;
                } else if (newNode->data->getPrice() != qTravel->nextNode->data->getPrice()) {
                newNode->nextNode = qTravel->nextNode;
                qTravel->nextNode = newNode;
                return;
                }
                qTravel = qTravel->nextNode;
            }
        }
        travel = travel->nextNode;
    }
}

template <typename T> inline void LinkedList<T>::rmvFrmList(T item) {
    std::cout << "rmvFromList: " << std::endl;
    Node<T>* trvsr = this->head;
    Node<T>* prev = trvsr;
    
    while(trvsr != NULL) {
        if(trvsr->data->getID() == item->getID()) { // We might need better checks for this.
            prev->nextNode = trvsr->nextNode; // Drop the node.
            
            std::cout << "Item removed." << std::endl;
            return;
        }
        prev = trvsr;
        trvsr = trvsr->nextNode;
    }
    std::cout << "Node not found." << std::endl;
}

template <typename T> inline void LinkedList<T>::print() {
    std::cout << "Print: " << std::endl;
    Node<T>* travel = this->head;
    int i = 0;
    while(travel != NULL){
        std::cout << "AccName: " << travel->data->getStkName() << std::endl;
        std::cout << "ID: " << travel->data->getID() << ": Price: " << travel->data->getPrice()
         << " Quantity: " << travel->data->getNumStks()  << std::endl;
        i++;
        travel = travel->nextNode;
    }
    std::cout << "I: " << i << std::endl;
}
#endif