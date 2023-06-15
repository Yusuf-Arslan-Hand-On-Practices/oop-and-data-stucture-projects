#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "student.h"

using namespace std;

class LinkedList{
private:
    struct Node {
        Student data;
        Node* next;
        Node(Student data, Node* next = nullptr) : data(data), next(next) {}
    };
    
    Node* head;
    
public:
    LinkedList() : head(nullptr) {}
    
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    virtual void add(Student data) {
        Node* newNode = new Node(data, head);
        head = newNode;
    }
    
    virtual void remove(Student data) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr && curr->data != data) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            cout << "Element not found in list." << endl;
            return;
        }
        if (prev == nullptr) {
            head = curr->next;
        } else {
            prev->next = curr->next;
        }
        delete curr;
    }
    
    virtual void print() {
        Node* curr = head;
        while (curr != nullptr) {
            curr->data.tostring();
            cout << endl;
            curr = curr->next;
        }
        cout << endl;
    }
};

#endif // LINKEDLIST