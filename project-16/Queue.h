/*
    Queue implementation for descrete event simulation
*/
#include <iostream>

#include "Order.h"

using namespace std;
using namespace ordr;

#ifndef QUEUE_H
#define QUEUE_H

namespace que {
    class Queue {
        public:
            // Struct for the node
            struct Node {
                Order* order;
                Node *next;
            };
        
        private:
            Node *front;
            Node *rear;

        public:
            Queue();
            ~Queue();
            void enqueueArrivalTime(Order &order);
            void enqueuePrice(Order &order);
            // For barista, priority queue
            void enqueueOrderFinishTime(Order &order);
            Order* dequeue();
            const Order* peek();
            const Order* peekRear();
            bool isEmpty();
            void setEmpty();
            void print();
    };

    Queue::Queue()
    {
        front = NULL;
        rear = NULL;
    }

    Queue::~Queue() {}
    
    // enqeue with order price (priority queue)
    void Queue::enqueuePrice(Order &order)
    {
        Node *temp = new Node;
        temp->order = &order;
        temp->next = NULL;
        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            Node *current = front;
            Node *previous = NULL;
            while (current != NULL && current->order->getPrice() > order.getPrice())
            {
                previous = current;
                current = current->next;
            }
            if (previous == NULL)
            {
                temp->next = front;
                front = temp;
            }
            else
            {
                temp->next = current;
                previous->next = temp;
            }

            // If the order is the highest price, it will be the rear
            if (current == NULL)
            {
                rear = temp;
            }
        }
    }

    void Queue::enqueueOrderFinishTime(Order &order)
    {
        Node *temp = new Node;
        temp->order = &order;
        temp->next = NULL;
        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            Node *current = front;
            Node *previous = NULL;
            while (current != NULL && current->order->getOrderFinishedTime() < order.getOrderFinishedTime())
            {
                previous = current;
                current = current->next;
            }
            if (previous == NULL)
            {
                temp->next = front;
                front = temp;
            }
            else
            {
                temp->next = current;
                previous->next = temp;
            }
        }
    }

    void Queue::enqueueArrivalTime(Order &order)
    {
        Node *temp = new Node;
        temp->order = &order;
        temp->next = NULL;
        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            Node *current = front;
            Node *previous = NULL;
            while (current != NULL && current->order->getArrivalTime() < order.getArrivalTime())
            {
                previous = current;
                current = current->next;
            }
            if (previous == NULL)
            {
                temp->next = front;
                front = temp;
            }
            else
            {
                temp->next = current;
                previous->next = temp;
            }

            // If the order is the highest price, it will be the rear
            if (current == NULL)
            {
                rear = temp;
            }
        }
    }

    Order* Queue::dequeue()
    {
        Order* order;
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            Node *temp = front;
            order = temp->order;
            front = front->next;
        }
        return order;
    }

    const Order* Queue::peek()
    {
        if (front == NULL)
        {
            return NULL;
        }
        else
        {
            return front->order;
        }
    }

    const Order* Queue::peekRear()
    {
        if (rear == NULL)
        {
            cout << "Queue is empty" << endl;
            return NULL;
        }
        else
        {
            return rear->order;
        }
    }

    bool Queue::isEmpty()
    {
        return front == NULL;
    }

    void Queue::setEmpty()
    {
        front = NULL;
        rear = NULL;
    }

    void Queue::print()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            temp->order->print();
            cout << endl;
            temp = temp->next;
        }
    }
}

#endif
