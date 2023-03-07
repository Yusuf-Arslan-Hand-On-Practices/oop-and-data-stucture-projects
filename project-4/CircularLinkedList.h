// Header file of a Circular Linked List

#include <iostream>
#include "Node.h"

using namespace std;

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

namespace cllist
{
    template <class T>
    class CircularLinkedList
    {
    private:
        node::Node<T>* head;
        int size;
    public:
        CircularLinkedList();
        ~CircularLinkedList();
        void insertTail(T* data);
        void insertHead(T* data);
        void insertBefore(T* data, const T* before);
        void insertAfter(T* data, const T* after);
        void removeIfEqual(const T* data);
        int getPosition(const T* data);
        T* getData(int position);
        void print();
        int getSize() const;
    };
} // namespace cllist

#include "CircularLinkedList.cpp"
#endif