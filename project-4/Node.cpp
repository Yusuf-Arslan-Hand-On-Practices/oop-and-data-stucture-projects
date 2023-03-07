// Implementation file of a Linked List node

#include "Node.h"

namespace node
{
    template <class T>
    Node<T>::Node(T* data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    template <class T>
    Node<T>::~Node()
    {
        delete data;
    }

    template <class T>
    void Node<T>::setData(T* data)
    {
        this->data = data;
    }

    template <class T>
    T* Node<T>::getData()
    {
        return data;
    }

    template <class T>
    void Node<T>::setNext(Node* next)
    {
        this->next = next;
    }

    template <class T>
    Node<T>* Node<T>::getNext()
    {
        return next;
    }

    template <class T>
    void Node<T>::setPrev(Node* prev)
    {
        this->prev = prev;
    }

    template <class T>
    Node<T>* Node<T>::getPrev()
    {
        return prev;
    }
    
} // namespace node