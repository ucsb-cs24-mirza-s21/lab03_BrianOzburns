// intlist.cpp
// Implements class IntList
// Brian Ozawa Burns, 04/24/2021

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT THIS
}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
}


// return sum of values in list
int IntList::sum() const {
    // checks if list is empty
    if ( !this->first ){
        return 0;
    }

    int sum = 0;
    Node *temp;
    temp = this->first;

    while ( temp ){
        sum += temp->info;
        temp = temp->next;
    }
    temp = nullptr;

    return sum; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    // checks if list is empty
    if ( !this->first ){
        return false;
    }

    Node *temp;
    temp = this->first;

    while ( temp ){
        if ( temp->info == value ){
            return true;
        }
        temp = temp->next;
    }
    temp = nullptr;

    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    // checks if list is empty
    if ( !this->first ){
        return 0;
    }

    int max = this->first->info;
    Node *temp;
    temp = this->first;

    while ( temp ){
        if ( temp->info > max ){
            max = temp->info;
        }
        temp = temp->next;
    }
    temp = nullptr;

    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    // checks if list is empty
    if ( !this->first ){
        return 0.0;
    }

    double avg = 0.0;
    Node *temp;
    temp = this->first;

    while ( temp ){
        avg += temp->info;
        temp = temp->next;
    }
    avg /= this->count();

    return avg; // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    if ( !this->first ){ // list empty, insert node as head
        first = new Node;
        first->info = value;
    }
    else{
        Node *temp = new Node;
        temp->info = this->first->info;
        this->first->info = value;
        temp->next = this->first->next;
        this->first->next = temp;
    }
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
