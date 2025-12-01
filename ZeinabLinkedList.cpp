#include "ZeinabLinkedList.h"
#include <iostream>
using namespace std;
using std::string;

// Constructor
List::List() {
    head = NULL;
    cursor = NULL;
    prev = NULL;
}

// Destructor
List::~List() {
    makeListEmpty();
}

// Check if list is empty
bool List::ListIsEmpty() {
    return (head == NULL);
}

// Check if cursor is empty
bool List::CurIsEmpty() {
    return (cursor == NULL);
}

// Set cursor to head
void List::toFirst() {
    if (head != NULL) {
        cursor = head;
        prev = NULL;
    }
}

// Check if cursor is at first position
bool List::atFirst() {
    if (head == NULL && cursor == NULL)
        return true;
    if (cursor == head)
        return true;
    return false;
}

// Move cursor to next node
void List::Advance() {
    prev = prev->next;
    cursor = cursor->next;
}


// Move cursor to end of list
void List::toEnd() {
    if (!ListIsEmpty())
    {
        toFirst();
        while(cursor->next != NULL)
            advance();
    }
}

// Check if cursor is at end
bool List::atEnd() {
    if (cursor->next == NULL)
        return true;
    return false;
}

// Get list size
int List::ListSize() {
    int count = 0;
    node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Update data in current node
void List::updateData(char newData) {
    if (cursor != NULL) {
        cursor->data = newData;
    }
}

// Update key in current node
void List::updateKey(int newKey) {
    if (cursor != NULL) {
        cursor->key = newKey;
    }
}

// Retrieve data from current node (return value)
char List::RetrieveData() {
    if (cursor != NULL) {
        return cursor->data;
    }
    return '\0'; // Return null character if cursor is NULL
}

// Retrieve data from current node (by reference)
void List::RetrieveData(char &d) {
    if (cursor != NULL) {
        d = cursor->data;
    }
}

// Insert node at beginning with key and data
void List::insertFirst(int k, char d) {
    node* newNode = new node();
    newNode->key = k;
    newNode->data = d;
    newNode->next = head;
    head = newNode;
        cursor = head;
        prev = NULL;
}

// Insert node after cursor
void List::insertAfter(int k, char d) {

    node* newNode = new node();
    newNode->key = k;
    newNode->data = d;
    newNode->next = cursor->next;
    cursor->next = newNode;
    prev = cursor;
    cursor = newNode;
}

// Insert node before cursor
void List::insertBefore(int k, char d) {
    
    node* newNode = new node();
    newNode->key = k;
    newNode->data = d;

        newNode->next = cursor;
            prev->next = newNode;
            cursor = newNode;
    }


// Insert node at end
void List::insertEnd(int k, char d) {
   if (ListIsEmpty()) {
        insertFirst(k, d);
    } else {
        toEnd();
        insertAfter(k, d);
    }
}

// Delete current node
void List::DeleteNode() {
    node* p;
    p = cursor; 
    if(!CurIsEmpty()){
        if (!atFirst()) {
            cursor = cursor->next;
            head = cursor;
            delete p;
        }
        else {

        cursor = cursor->next;
        prev->next = cursor;

    delete p;
        }
    }
}

// Delete first node
void List::DeleteFirst() {
    if(!ListIsEmpty()){
       atFirst();
        DeleteNode();

    }       
    
}

// Delete last node
void List::DeleteEnd() {
    if (!ListIsEmpty()) {
        toEnd();
        DeleteNode();
    }
}

// Make list empty 
void List::makeListEmpty() {
    toFirst();
    while (!ListIsEmpty()) 
        DeleteNode();
}

// Search for a key in the list
bool List::search( const int & k) {
    bool found = false;
    toFirst();
    while ((!found)&&(cursor != NULL)) {
        if (k == cursor->key) {
            found = true;
        } else {
            Advance();
        }
    }
    return found;
}

// Insert node in order (sorted by key)
void List::orderInsert(const char & d , const int & k) {
   toFirst();
    while ((cursor != NULL) && (k > cursor->key)) 
        Advance();
if (prev == NULL) {
        insertFirst(k, d);
    } else {
        insertBefore(k, d);
    }
}

// Traverse and display the list
void List::traverse() {   
    
    toFirst();
    while (!CurIsEmpty()) {
        cout << "[" << cursor->key << "," << cursor->data << "] ";
        Advance();
    }
    cout << endl;
}

