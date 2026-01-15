// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    Node* curr = head;
    while(curr){
        Node* del = curr;
        curr = curr->next;
        delete del;
    }
    head = nullptr;
    tail = nullptr;
    if(source.head){
        head = new Node();
        head -> info = source.head -> info;
        head -> next = nullptr;
        tail = head;
        curr = source.head -> next;
        while(curr){
            Node* p = new Node();
            p -> info = curr -> info;
            p -> next = nullptr;
            tail -> next = p;
            tail = tail -> next;
            curr = curr -> next;
        }
    }
    //IMPLEMENT THIS
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* curr = head;
    while(curr){
        Node* del = curr;
        curr = curr->next;
        delete del;
    }
    head = nullptr;
    tail = nullptr;
    //IMPLEMENT THIS
}


// return sum of infos in list
int IntList::sum() const {
    if(!head)return 0;
    int ans = 0;
    Node* curr = head;
    while(curr){
        ans += curr -> info;
        curr = curr -> next;
    }
    return ans;
}

// returns true if info is in the list; false if not
bool IntList::contains(int info) const {
    if(!head)return false;
    Node* curr = head;
    while(curr){
        if(curr -> info == info)return true;
        curr = curr -> next;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum info in list, or 0 if empty list
int IntList::max() const {
    if(!head)return 0;
    Node* curr = head;
    int m = curr -> info;
    while(curr){
        if(curr -> info > m){
            m = curr -> info;
        }
        curr = curr -> next;
    }
    return m;
}

// returns average (arithmetic mean) of all infos, or
// 0 if list is empty
double IntList::average() const {
    if(!head) return 0;
    int ans = IntList::sum();
    double res = (double)ans / IntList::count();
    return res; // REPLACE THIS NON-SOLUTION
}

// inserts info as new node at beginning of list
void IntList::push_front(int info) {
    Node* p = new Node();
    p -> info = info;
    p -> next = head;
     if(!head){
        tail = p;
    }
    head = p;
    // IMPLEMENT
}

// append info at end of list
void IntList::push_back(int info) {
    Node* p = new Node();
    p -> info = info;
    p -> next = nullptr;
    if(!head){
        head = p;
        tail = head;
    }
    else{
        tail -> next = p;
        tail = p;
    }
    
    // IMPLEMENT
 
}

// return count of infos
int IntList::count() const {
    if(!head)return 0;
    int cnt = 0;
    Node* curr = head;
    while(curr){
        cnt ++;
        curr = curr -> next;
    }
   //IMPLEMENT THIS
   return cnt;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if(this == &source) return *this;
    Node* curr = head;
    while(curr){
        Node* del = curr;
        curr = curr->next;
        delete del;
    }
    head = nullptr;
    tail = nullptr;
    if(!source.head) return *this;
    head = new Node();
    head -> info = source.head -> info;
    head -> next = nullptr;
    tail = head;
    if(!source.head->next) return *this;
    curr = source.head -> next;
    while(curr){
        Node* p = new Node();
        p -> info = curr -> info;
        p -> next = nullptr;
        tail -> next = p;
        tail = p;
        curr = curr -> next;
    }
    //IMPLEMENT
    return *this;
}

// constructor sets up empty list
IntList::IntList(){
    head = nullptr;
    tail = nullptr;
    //IMPLEMENT THIS 
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print infos enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

