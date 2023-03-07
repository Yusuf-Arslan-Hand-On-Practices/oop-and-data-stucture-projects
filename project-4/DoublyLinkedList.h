// Header file of Doubly Linked List

#include <iostream>
#include "Node.h"

using namespace std;

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

namespace dllist
{
    template <class T>
    class DoublyLinkedList
    {
    private:
        node::Node<T>* head;
        int size;

        // helper functions
        void insertHead(T* data);
        void insertTail(T* data);
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void insertAtPosition(int position, T* data);
        int getPosition(const T* data);
        T* getData(int position);
        void print();
        void reversePrint();
        int getSize() const;
    };
} // namespace dllist

#include "DoublyLinkedList.cpp"
#endif