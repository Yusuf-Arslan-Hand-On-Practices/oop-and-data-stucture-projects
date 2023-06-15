// extends linked list

#ifndef MULTILINKEDLIST_H
#define MULTILINKEDLIST_H

#include <iostream>
#include <vector>
#include "linkedList.h"
#include "student.h"

using namespace std;

#define NEXT_ID 0
#define NEXT_CGPA 1

// extends linked list
class MultiLinkedList : public LinkedList {
private:
    // node class with vector of nodes
    struct Node {
        Student data;
        vector<Node *> next;

        Node(Student data, vector<Node *> next = vector<Node *>(2, nullptr)) : data(data), next(next) {}
    };

    vector<Node *> head;

public:
    MultiLinkedList() : head(vector<Node *>(2, nullptr)) {}
    // destructor
    ~MultiLinkedList() {
        while (head[NEXT_ID] != nullptr) {
            Node *temp = head[NEXT_ID];
            head[NEXT_ID] = head[NEXT_ID]->next[NEXT_ID];
            delete temp;
        }
    }

    // add function, adds id and cgpa sorted
    void add(Student data) override {
        // create new node
        Node *newNode = new Node(data);

        // add id sorted
        Node *curr = head[NEXT_ID];
        Node *prev = nullptr;
        while (curr != nullptr && Student::compareId(curr->data, data)) {
            prev = curr;
            curr = curr->next[NEXT_ID];
        }

        if (prev == nullptr) {
            head[NEXT_ID] = newNode;
        } else {
            prev->next[NEXT_ID] = newNode;
        }

        newNode->next[NEXT_ID] = curr;

        // add cgpa sorted
        curr = head[NEXT_CGPA];
        prev = nullptr;
        while (curr != nullptr && Student::compareCgpa(curr->data, data)) {
            prev = curr;
            curr = curr->next[NEXT_CGPA];
        }

        if (prev == nullptr) {
            head[NEXT_CGPA] = newNode;
        } else {
            prev->next[NEXT_CGPA] = newNode;
        }

        newNode->next[NEXT_CGPA] = curr;
    }

    // print 
    void print() override {
        Node *curr = head[NEXT_ID];
        while (curr != nullptr) {
            curr->data.tostring();
            cout << endl;
            curr = curr->next[NEXT_ID];
        }
        cout << endl;
    }

    // print cgpa sorted
    void printCgpa() {
        Node *curr = head[NEXT_CGPA];
        while (curr != nullptr) {
            curr->data.tostring();
            cout << endl;
            curr = curr->next[NEXT_CGPA];
        }
        cout << endl;
    }

    // remove
    void remove(Student data) override {
        // remove from both id and cgpa list
        Node *prev = nullptr;
        Node *curr = head[NEXT_ID];
        while (curr != nullptr && curr->data != data) {
            prev = curr;
            curr = curr->next[NEXT_ID];
        }

        if (curr == nullptr) {
            cout << "Element not found in list." << endl;
            return;
        }

        if (prev == nullptr) {
            head[NEXT_ID] = curr->next[NEXT_ID];
        } else {
            prev->next[NEXT_ID] = curr->next[NEXT_ID];
        }

        // remove from cgpa list
        prev = nullptr;
        curr = head[NEXT_CGPA];
        while (curr != nullptr && curr->data != data) {
            prev = curr;
            curr = curr->next[NEXT_CGPA];
        }

        if (curr == nullptr) {
            cout << "Element not found in list." << endl;
            return;
        }

        if (prev == nullptr) {
            head[NEXT_CGPA] = curr->next[NEXT_CGPA];
        } else {
            prev->next[NEXT_CGPA] = curr->next[NEXT_CGPA];
        }

        delete curr;
    }


};

#endif // MULTILINKEDLIST_H