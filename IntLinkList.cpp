#include "IntLinkList.h"

#pragma once

#include "IntLinkList.h"
#include <stdlib.h>

IntLinkList::IntLinkList() {
// Set up the list
    head = nullptr;
    length = 0;
}

// Destructor
IntLinkList::~IntLinkList() {
    Node* oldHead;

    while (head != nullptr) // Don't need to delete things if the head is null
    {
        oldHead = head;// Remember the original head
        head = head->next;// Advance the head
        delete oldHead;// Delete the old head
    }
}

void IntLinkList::Add(int elem) {
// Make and initialize a new node
    Node* node = new Node;
    node->next = nullptr;// Good practice to immediatly initialize
    node->data = elem;

// Add the new node to front
    node->next = head;
    head = node;// Node is now the head

// Book keeping... list size increased by one
    length++;
}

void IntLinkList::Remove(int elem) {
// Don't do anything if the list is empty
    if (head == nullptr)
        return;

    Node* prev = nullptr;// no previous initially
    Node* curr = head;
    bool found = false;// flag to see if we found it

    while (curr != nullptr) {
    // if we find the element...
        if (curr->data == elem) {
            found = true;
            break;
        }

        prev = curr;// Update previous
        curr = curr->next;// Advance curr
    }

    // Didn't find it... return out
    if (!found)
        return;

    // What if the node we are trying to delete is the head?
    if (curr == head) {
        head = head->next;// Advance the head
        delete curr;
    } else {
    // General remove case
        prev->next = curr->next;
        delete curr;
    }

    // Book keeping...
    length--;
}

int IntLinkList::at(int index) {
    // Check to see if we are within bounds
    if (index > length || index < 0)
        exit(0);

    // Hop "index" times down the list
    Node* curr = head;
    for (int i = 0; i < index; i++)
        curr = curr->next;

    // Return the value at the index
    return curr->data;
}


bool IntLinkList::Contains(int elem) {
    // Start search at the head and return true if we find it
    Node* curr = head;
    while (curr != nullptr)
    {
        if (curr->data == elem)
            return true;

        curr = curr->next;
    }

    // Return false if we go through the entire list
    // and don't find it
    return false;
}

int IntLinkList::Size() {
    return length;
}
