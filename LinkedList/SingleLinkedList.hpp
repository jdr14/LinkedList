//
//  SingleLinkedList.hpp
//  LinkedList
//
//  Created by Joseph Rodgers on 12/12/23.
//

#ifndef SingleLinkedList_hpp
#define SingleLinkedList_hpp

#include <stdio.h> // C
#include <iostream> // C++

template<class T>
class PhysicalDataStructureInterFace
{
protected:
    int length; // Number of elements in the data container
public:
    virtual void display(void) = 0;
    virtual bool add(T element) = 0;
    virtual bool del(T element) = 0;
    virtual int search(T element) = 0;
    virtual bool isEmpty(void) = 0;
};

//typedef struct node{
//    int i; // Representative of some data
//    node *next;
//} node_t;

template <class T = int>
struct node {
    T data;
    node *next;
};

template<class T = int> // Uses defalt template as int in case one is not provided
class LinkedList : public PhysicalDataStructureInterFace<T>
{
private:
    node<T> * head;
    node<T> * tail;
public:
    LinkedList(void); // constructor
    ~LinkedList(void); // destructor
    void display(void);
    bool add(T element);
    bool del(T element);
    int search(T element);
    bool isEmpty(void);
};

template<class T> // Constructor set head node to nullptr
LinkedList<T>::LinkedList(void) : head(nullptr), tail(nullptr) {
    this->length = 0;  // initialize protected member from parent/base class/iface
}

template<class T> // Destructor free all dynamically allocated memory
LinkedList<T>::~LinkedList(void) {
    if(head == nullptr) { // list is empty (i.e. nothing to free)
        return;
    }
    node<T> *curr = head;
    while (curr != nullptr) {
        node<T> * nodeToDelete = curr;
        curr = curr->next;
        delete nodeToDelete; // use free instead if allocated with malloc
    }
}

template<class T>
void LinkedList<T>::display(void) {
    std::cout << "{";

    node<T> *curr = head;
    while (curr != nullptr) { // will automatically return if empty
        std::cout << curr->data << ", ";
        curr = curr->next;
    }

    std::cout << "}" << std::endl;
}

template<class T>
bool LinkedList<T>::add(T element) {
    
    // Build new item node
    node<T> * newItem = new node<T>;
    if (newItem == nullptr) { // double check that memory allocation was successful
        return false;
    }
    newItem->data = element;
    newItem->next = nullptr;
    
    if (this->isEmpty()) {
        head = newItem;
        tail = newItem;
    }
    else {
        tail->next = newItem;
        tail = tail->next;
    }
    this->length++;
    return true;
}

template<class T>
bool LinkedList<T>::del(T element) {
    // Case:  List is empty
    if (this->isEmpty()) {
        return false;  // Cannot delete something that is not there
    }
    
    // Case:  Only one item to check
    if (head->next == nullptr) {
        if (head->data == element) {
            delete head;
            head = nullptr;
            this->length = 0;
            return true;
        }
        return false;
    }
    
    node<T> *prev = head;
    node<T> *curr = head->next;
    
    // Check prev node before looping
    if (prev->data == element) {
        delete prev;
        head = curr;
        return true;
    }
    while (curr != nullptr) {
        if (curr->data == element) {
            prev->next = curr->next; // Update the previous node's next to point to the current pointer's next node
            delete curr; // Return the heap allocated memory
            curr = prev->next;
            this->length--; // decrement the length
            return true; // Node was found and deleted
        }
        else {
            prev = prev->next;
            curr = curr->next;
        }
    }
    return false; // nothing deleted
}

// Return's -1 if the element specified was not found in the list
template<class T>
int LinkedList<T>::search(T element) {
    node<T> * curr = head;
    int i = 0; // node containing specified element/data was found at the ith element
    while(curr != nullptr) {
        if (curr->data == element) {
            return i;
        }
        i++; // increment the index
        curr = curr->next; // move to next element
    }
    return -1; // not found
}

template<class T>
bool LinkedList<T>::isEmpty(void) {
    // Should also be empty if (length == 0)
    return (head == nullptr);
}


#endif /* SingleLinkedList_hpp */
