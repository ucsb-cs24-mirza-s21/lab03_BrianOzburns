// intlist.cpp
// Implements class IntList
// Brian Ozawa Burns, 04/24/2021

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    if ( !source.first ){ // source list is empty
        // list is already empty, set first to null
        this->first = nullptr;
        this->first->info = 0;
        this->first->next = nullptr;
    }
    else{ // list needs to be copied, node by node
        Node *j = source.first; // using j as placeholder for source list
        this->first = nullptr;
        while ( j ){
            int info = j->info;
            this->append(info);
            j = j->next;
        }
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node *n = this->first;
    while ( n ){
        Node *deleteThisNode = n;
        n = n->next;
        delete deleteThisNode;
    }
    n = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    // checks if list is empty
    if ( !this->first ){
        return 0;
    }

    int sum = 0;
    Node *n;
    n = this->first;

    while ( n ){
        sum += n->info;
        n = n->next;
    }
    n = nullptr;

    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    // checks if list is empty
    if ( !this->first ){
        return false;
    }

    Node *n;
    n = this->first;

    while ( n ){
        if ( n->info == value ){
            return true;
        }
        n = n->next;
    }
    n = nullptr;

    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    // checks if list is empty
    if ( !this->first ){
        return 0;
    }

    int max = this->first->info;
    Node *n;
    n = this->first;

    while ( n ){
        if ( n->info > max ){
            max = n->info;
        }
        n = n->next;
    }
    n = nullptr;

    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    // checks if list is empty
    if ( !this->first ){
        return 0.0;
    }

    double avg = 0.0;
    Node *n;
    n = this->first;

    while ( n ){
        avg += n->info;
        n = n->next;
    }
    n = nullptr;

    avg /= this->count();

    return avg;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    if ( !this->first ){ // list empty, insert node as head
        this->first = new Node;
        this->first->info = value;
        this->first->next = nullptr;
    }
    else{
        Node *n = new Node;
        n->info = this->first->info;
        this->first->info = value;
        n->next = this->first->next;
        this->first->next = n;
    }
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    // this and source are the same
    if ( this == &source ){
        return *this;
    }
    // check if this list is not empty, delete its nodes
    if ( this->first ){
        Node *n = this->first;
        while ( n ){
            Node *deleteThisNode = n;
            n = n->next;
            delete deleteThisNode;
        }
        this->first = nullptr;
        n = nullptr;
    }
    // check if source is empty, if so, return empty list
    if ( !source.first ){
        return *this;
    }
    // this list is empty, copy source to it, node by node
    Node *j = source.first; // using j as placeholder for source list
    while ( j ){
        int info = j->info;
        this->append(info);
        j = j->next;
    }
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
