// Implementation file of a Circular Linked List

#include "CircularLinkedList.h"

namespace cllist
{
    template <class T>
    CircularLinkedList<T>::CircularLinkedList()
    {
        this->head = nullptr;
        this->size = 0;
    }

    template <class T>
    CircularLinkedList<T>::~CircularLinkedList() = default;

    template <class T>
    void CircularLinkedList<T>::insertTail(T* data)
    {
        node::Node<T>* newNode = new node::Node<T>(data);
        if (this->head == nullptr)
        {
            this->head = newNode;
            this->head->setNext(head);
            size++;
        }
        else
        {
            node::Node<T>* current = this->head;
            while (current->getNext() != this->head)
            {
                current = current->getNext();
            }
            current->setNext(newNode);
            newNode->setNext(head);
            this->size++;
        }
    }

    template <class T>
    void CircularLinkedList<T>::insertHead(T* data)
    {
        node::Node<T>* newNode = new node::Node<T>(data);
        if (this->head == nullptr)
        {
            this->head = newNode;
            this->head->setNext(head);
            size++;
        }
        else
        {
            node::Node<T>* current = this->head;
            while (current->getNext() != this->head)
            {
                current = current->getNext();
            }
            current->setNext(newNode);
            newNode->setNext(head);
            this->head = newNode;
            this->size++;
        }
    }

    template <class T>
    void CircularLinkedList<T>::insertBefore(T* data, const T* before)
    {
        if (this->head == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            node::Node<T>* newNode = new node::Node<T>(data);
            // If both data and before are equal
            if (*this->head->getData() == *before)
            {
                this->insertHead(data);
            }
            else
            {
                node::Node<T>* current = this->head;
                while (current->getNext() != this->head && *current->getNext()->getData() != *before)
                {
                    current = current->getNext();
                }
                if (current->getNext() == this->head)
                {
                    cout << "Data not found" << endl;
                }
                else
                {
                    newNode->setNext(current->getNext());
                    current->setNext(newNode);
                    this->size++;
                }
            }
        }
    }

    template <class T>
    void CircularLinkedList<T>::insertAfter(T* data, const T* after)
    {
        if (this->head == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            node::Node<T>* newNode = new node::Node<T>(data);

            if (*this->head->getData() == *after)
            {
                newNode->setNext(this->head->getNext());
                this->head->setNext(newNode);
                this->size++;
            }
            else
            {
                node::Node<T>* current = this->head;
                while (current->getNext() != this->head && *current->getData() != *after)
                {
                    current = current->getNext();
                }
                if (current->getNext() == this->head)
                {
                    if (*current->getData() == *after)
                    {
                        current->setNext(newNode);
                        newNode->setNext(head);
                        this->size++;
                    }
                    else
                    {
                        cout << "Element not found" << endl;
                    }
                }
                else
                {
                    newNode->setNext(current->getNext());
                    current->setNext(newNode);
                    this->size++;
                }
            }
        }
    }

    template <class T>
    void CircularLinkedList<T>::removeIfEqual(const T* data)
    {
        if (this->head == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            if (this->head->getData() == data)
            {
                node::Node<T>* current = this->head;
                while (current->getNext() != this->head)
                {
                    current = current->getNext();
                }
                current->setNext(this->head->getNext());
                delete this->head;
                this->head = current->getNext();
                this->size--;
            }
            else
            {
                node::Node<T>* current = this->head;
                while (current->getNext() != this->head && current->getNext()->getData() != data)
                {
                    current = current->getNext();
                }
                if (current->getNext() == this->head)
                {
                    cout << "Element not found" << endl;
                }
                else
                {
                    node::Node<T>* temp = current->getNext();
                    current->setNext(current->getNext()->getNext());
                    delete temp;
                    this->size--;
                }
            }
        }
    }

    template <class T>
    int CircularLinkedList<T>::getPosition(const T* data)
    {
        if (this->head == nullptr)
        {
            cout << "List is empty" << endl;
            return -1;
        }
        else
        {
            int position = 0;
            node::Node<T>* current = this->head;
            while (current->getNext() != this->head && current->getData() != data)
            {
                current = current->getNext();
                position++;
            }
            if (current->getNext() == this->head)
            {
                if (current->getData() == data)
                {
                    return position;
                }
                else
                {
                    cout << "Element not found" << endl;
                    return -1;
                }
            }
            else
            {
                return position;
            }
        }
    }

    template <class T>
    T* CircularLinkedList<T>::getData(int position)
    {
        if (this->head == nullptr)
        {
            cout << "List is empty" << endl;
            return nullptr;
        }
        else
        {
            if (position < 0 || position >= this->size)
            {
                cout << size << "Invalid position" << endl;
                return nullptr;
            }
            else
            {
                node::Node<T>* current = this->head;
                for (int i = 0; i < position; i++)
                {
                    current = current->getNext();
                }
                return current->getData();
            }
        }
    }

    template <class T>
    void CircularLinkedList<T>::print()
    {
        if (this->head == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            node::Node<T>* current = this->head;
            while (current->getNext() != this->head)
            {
                cout << *(current->getData()) << " ";
                current = current->getNext();
            }
            cout << *(current->getData()) << endl;
        }
    }

    template <class T>
    int CircularLinkedList<T>::getSize() const
    {
        return this->size;
    }
}