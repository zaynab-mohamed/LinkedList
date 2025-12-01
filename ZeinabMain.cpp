#include <iostream>
#include "ZeinabLinkedList.h"
using namespace std;

int main() {
    List Zeinablist;
    int z;
    char d;
    
    // test insert functions
    Zeinablist.insertFirst(5, 'x');
    Zeinablist.insertEnd(10, 'y');
    Zeinablist.orderInsert(7, 'z');
    Zeinablist.orderInsert(3, 'a');
    
    cout << "List after inserts:\n";
    Zeinablist.traverse();
    
    // test search
    cout << "\nSearching for key 7: ";
    if(Zeinablist.search(7))
        cout << "Found\n";
    else
        cout << "Not found\n";
    
    // test navigation
    Zeinablist.toFirst();
    cout << "First element data: " << Zeinablist.RetrieveData() << endl;
    
    Zeinablist.toEnd();
    cout << "Last element data: " << Zeinablist.RetrieveData() << endl;
    
    // test update
    Zeinablist.toFirst();
    Zeinablist.Advance();
    Zeinablist.updateData('w');
    cout << "\nList after update:\n";
    Zeinablist.traverse();
    
    // test delete
    Zeinablist.DeleteFirst();
    cout << "\nList after delete first:\n";
    Zeinablist.traverse();
    
    cout << "\nList size: " << Zeinablist.ListSize() << endl;
    
    return 0;
}
