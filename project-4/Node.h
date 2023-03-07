// Header file of a Linked List node
// Tamplate class

#include <iostream>
using namespace std;


#ifndef NODE_H
#define NODE_H


namespace node
{
    template <class T>
    class Node
    {
    private:
        T* data;
        Node* next;
        Node* prev;

    public:
        Node(T* data);
        ~Node();
        void setData(T* data);
        T* getData();
        void setNext(Node* next);
        Node* getNext();
        void setPrev(Node* prev);
        Node* getPrev();
    };
} // namespace CLL  class C

#include "Node.cpp"
#endif // NODE_H

