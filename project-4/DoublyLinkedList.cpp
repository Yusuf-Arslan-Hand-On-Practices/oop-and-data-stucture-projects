// Implementation of DoublyLinkedList class

#include "DoublyLinkedList.h"

namespace dllist
{
    template <class T>
    DoublyLinkedList<T>::DoublyLinkedList()
    {
        this->head = nullptr;
        this->size = 0;
    }

    template <class T>
    DoublyLinkedList<T>::~DoublyLinkedList() = default;

    template <class T> // HELPER - Insert head of the list with prev and next pointers
    void DoublyLinkedList<T>::insertHead(T* data)
    {
        node::Node<T>* newNode = new node::Node<T>(data);
        if (head == nullptr)
        {
            this->head = newNode;
            this->head->setNext(head);
            this->head->setPrev(head);
        }
        else
        {
            newNode->setNext(head);
            newNode->setPrev(head->getPrev());
            this->head->getPrev()->setNext(newNode);
            this->head->setPrev(newNode);
            this->head = newNode;
        }
        this->size++;
    }

    template <class T> // HELPER - Insert tail of the list with prev and next pointers
    void DoublyLinkedList<T>::insertTail(T* data)
    {
        node::Node<T>* newNode = new node::Node<T>(data);
        if (head == nullptr)
        {
            this->head = newNode;
            this->head->setNext(head);
            this->head->setPrev(head);
        }
        else
        {
            newNode->setNext(head);
            newNode->setPrev(head->getPrev());
            this->head->getPrev()->setNext(newNode);
            this->head->setPrev(newNode);
        }
        this->size++;
    }

    template <class T>
    void DoublyLinkedList<T>::insertAtPosition(int position, T* data)
    {
        if (position < 0 || position > this->size)
        {
            cout << "Invalid position" << endl;
            return;
        }
        if (position == 0)
        {
            insertHead(data);
        }
        else if (position == this->size)
        {
            insertTail(data);
        }
        else
        {
            node::Node<T>* newNode = new node::Node<T>(data);
            node::Node<T>* current = this->head;
            for (int i = 0; i < position - 1; i++)
            {
                current = current->getNext();
            }
            newNode->setNext(current->getNext());
            newNode->setPrev(current);
            current->getNext()->setPrev(newNode);
            current->setNext(newNode);
            this->size++;
        }
    }

    // get position of the first occurrence of the data
    template <class T>
    int DoublyLinkedList<T>::getPosition(const T* data)
    {
        node::Node<T>* current = this->head;
        int position = 0;
        while (current != nullptr)
        {
            if (current->getData() == data)
            {
                return position;
            }
            current = current->getNext();
            position++;
        }
        return -1;
    }

    template <class T>
    T* DoublyLinkedList<T>::getData(int position)
    {
        if (position < 0 || position >= this->size)
        {
            cout << "Invalid position" << endl;
            return nullptr;
        }
        node::Node<T>* current = this->head;
        for (int i = 0; i < position; i++)
        {
            current = current->getNext();
        }
        return current->getData();
    }
    

    // Print
    template <class T>
    void DoublyLinkedList<T>::print()
    {
        if (this->head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        node::Node<T>* current = this->head;
        do
        {
            cout << *current->getData() << " ";
            current = current->getNext();
        } while (current != this->head);
        cout << endl;
    }
    
    // reverse print
    template <class T>
    void DoublyLinkedList<T>::reversePrint()
    {
        if (this->head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        node::Node<T>* current = this->head->getPrev();
        do
        {
            cout << *current->getData() << " ";
            current = current->getPrev();
        } while (current != this->head->getPrev());
        cout << endl;
    }

    template <class T>
    int DoublyLinkedList<T>::getSize() const
    {
        return this->size;
    }
}
    