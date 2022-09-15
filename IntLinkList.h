//
// Created by Paul Raupach on 9/14/22.
//


#ifndef INTLINKLIST_H
#define INTLINKLIST_H

class IntLinkList {
public:
    //default constructor
    //initializes list with length = 0 and head pointing to null
    IntLinkList();

    //destructor
    ~IntLinkList();

    // Adds an element to the front of the list
    void Add(int elem);

    // Removes an element from the list
    void Remove(int elem);

    // Returns the node at index (The index 0 would return the head data)
    int at(int index);

    // Returns true if elem is in the list
    bool Contains(int elem);

    // Returns the size of the list
    int Size();
private:
    struct Node {
        Node *next;
        int data;
    };
    Node *head;
    int length;
};

#endif //INTLINKLIST_H
