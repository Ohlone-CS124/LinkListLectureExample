#include "IntLinkList.h"
#include <iostream>

using namespace std;

int main() {
    IntLinkList list;

    cout << "---------------- Adding Stuff -----------------" << endl;
    for (int i = 0; i < 10; i++)
        list.Add(i * 2);

    for (int i = 0; i < list.Size(); i++)
        cout << "The element of the " << i << "th node is " << list.at(i) << endl;

    cout << "---------------- Checking Contain -----------------" << endl;
    if (list.Contains(10))
        cout << "The list has 10" << endl;
    else
        cout << "The list does NOT have 10" << endl;


    cout << "---------------- Checking Remove -----------------" << endl;
    cout << "Trying to remove 10" << endl;
    list.Remove(10);
    if (list.Contains(10))
        cout << "The list has 10" << endl;
    else
        cout << "The list does NOT have 10" << endl;

    for (int i = 0; i < list.Size(); i++)
        cout << "The element of the " << i << "th node is " << list.at(i) << endl;

    cout << "Trying to remove everything" << endl;
    for (int i = 0; i < 10; i++)
        list.Remove(i * 2);

    cout << "Size of list is now " << list.Size() << endl;
    
    return 0;
}
