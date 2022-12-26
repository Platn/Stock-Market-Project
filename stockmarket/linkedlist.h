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
    Node<T>* tail; // Only to be used in non-sorted version;
    public:
    LinkedList();
    LinkedList(T); // Overloaded constructor

    void addToList(T);
    void addToListMax(T);
    void addToListMin(T);
    void rmvFrmList(T);
    Node<T>* findNode(T);
    
    void print();
    std::string retListInfo();

};



template <typename T> LinkedList<T>::LinkedList(){}
template <typename T> LinkedList<T>::LinkedList(T item){
    this->head = new Node<T>(item);
    this->tail = head;
}
template <typename T> void LinkedList<T>::addToList(T item) {
    Node<T>* travel = this->head;

    if (travel == NULL) {
        this->head = new Node<T>(item);
        return;
    }

    while(true) {
        if(travel->nextNode == NULL) {
            travel->nextNode = new Node<T>(item);
            return;
        }
        travel = travel->nextNode;
    }
}
template <typename T> void LinkedList<T>::addToListMax(T item){
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

template<typename T> inline void LinkedList<T>::addToListMin(T item) {
    std::cout << "Inside addToListMin" << std::endl;

    Node<T>* newNode = new Node<T>(item);
    Node<T>* travel = this->head;

    if (travel == NULL) {
        this->head = newNode;
        return;
    } else if (newNode->data->getPrice() > travel->data->getPrice()) {
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
        else if(newNode->data->getPrice() > travel->nextNode->data->getPrice()) {
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

template<typename T> inline void LinkedList<T>::rmvFrmList(T item) {
    std::cout << "rmvFromList: " << std::endl;
    Node<T>* travel = this->head;
    Node<T>* prev = travel;
    
    while(travel != NULL) {
        if(travel->data->getID() == item->getID()) { // We might need better checks for this.
            prev->nextNode = travel->nextNode; // Drop the node.
            
            std::cout << "Item removed." << std::endl;
            return;
        }
        prev = travel;
        travel = travel->nextNode;
    }
    std::cout << "Node not found." << std::endl;
}

template <typename T> inline void LinkedList<T>::print() {
    std::cout << "Print:" << std::endl;
    Node<T>* travel = this->head;
    int i = 0;
    while(travel != NULL){
        std::cout << "StkName: " << travel->data->getStkName() << " CustName" 
        << travel->data->getCustName() << std::endl;
        std::cout << "ID: " << travel->data->getID() << ": Price: " << travel->data->getPrice()
         << " Quantity: " << travel->data->getNumStks()  << std::endl;
        i++;
        travel = travel->nextNode;
    }
    std::cout << "I: " << i << std::endl;
}

template<typename T> inline std::string LinkedList<T>::retListInfo() {
    std::string info = "";
    // std::cout << "Return Info" << std::endl;
    Node<T>* travel = this->head;
    info += "StockName,CustomerName,Price,Time,ID\n";
    while(travel != NULL) {
        info += travel->data->getStkName() + "," + travel->data->getCustName() + ","
        + std::to_string(travel->data->getPrice()) + "," + std::to_string(travel->data->getTime()) 
        + "," + std::to_string(travel->data->getID());
        if (travel->nextNode == NULL) {
            break;
        } else {
            info += "\n";
            travel = travel->nextNode;
        }
    }

    return info;
}
#endif