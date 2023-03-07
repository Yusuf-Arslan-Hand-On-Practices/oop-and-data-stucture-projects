#include <iostream>

using namespace std;

// This file includes implementation of the MPQ class
// It needs inside value, label and next pointer

// Value is a class that refers to the x and y coordinates of the building and label is where the building finishes
// Value is comparable according to the x coordinate

// Building class keeps the value and the label of the building
// And it is comparable according to the x coordinate

// MPQ class has a head pointer and the size of the queue and it is implemented as a linked list


// Comparable class is an abstract class that is used to compare the buildings
class Comparable {
public:
    virtual bool operator<(Comparable &other) = 0;
    virtual bool operator>(Comparable &other) = 0;
    virtual bool operator==(Comparable &other) = 0;
};

// Value class keeps the x and y coordinates of the building -- it is comparable according to the x coordinate
// Because min heap will be used to insert the buildings, the buildings will be compared according to the x coordinate
class Value : public Comparable {
public:
    int x;
    int y;

    Value(int x, int y) {
        this->x = x;
        this->y = y;
    }

    bool operator<(Comparable &other) {
        Value *otherValue = dynamic_cast<Value *>(&other);
        return this->x < otherValue->x;
    }
    bool operator>(Comparable &other) {
        Value *otherValue = dynamic_cast<Value *>(&other);
        return this->x > otherValue->x;
    }
    bool operator==(Comparable &other) {
        Value *otherValue = dynamic_cast<Value *>(&other);
        return this->x == otherValue->x;
    }

    friend ostream &operator<<(ostream &os, const Value &value) {
        os << value.x << " " << value.y;
        return os;
    }
};

// Building class keeps the value (x, y) and the label of the building
class Building : public Comparable {
public:
    Value *value;
    int label;

    // Constructor
    Building(Value *value, int label) {
        this->value = value;
        this->label = label;
    }
    // To compares the buildings according to the x coordinate for the insert function (min heap)
    bool operator<(Comparable &other) {
        Building *otherBuilding = dynamic_cast<Building *>(&other);
        return *this->value < *otherBuilding->value;
    }
    // To compares the buildings according to the label for getMax function
    bool operator>(Comparable &other) {
        Building *otherBuilding = dynamic_cast<Building *>(&other);
        return this->label > otherBuilding->label;
    }
    // To compares the buildings according to the label for the remove function
    bool operator==(Comparable &other) {
        Building *otherBuilding = dynamic_cast<Building *>(&other);
        return this->label == otherBuilding->label;
    }

    // print the building
    void print() {
        cout << *this->value << " " << this->label << endl;
    }
};

// MPQ class has a head pointer and the size of the queue and it is implemented as a linked list
class MPQ {
public:
    // Node class keeps the value and the next pointer
    class Node {
    public:
        Comparable *value;
        Node *next;

        Node(Comparable *value) {
            this->value = value;
            this->next = NULL;
        }
    };

    Node *head;
    int size;

    MPQ() {
        this->head = NULL;
        this->size = 0;
    }

    /**
     * If the list is empty, insert the new node at the head. Otherwise, find the correct position for
     * the new node and insert it there
     */
    void insert(Comparable *value) {
        Node *newNode = new Node(value);
        if (this->head == NULL) {
            this->head = newNode;
        } else {
            Node *current = this->head;
            Node *previous = NULL;
            while (current != NULL && *current->value < *value) {
                previous = current;
                current = current->next;
            }
            if (previous == NULL) {
                newNode->next = this->head;
                this->head = newNode;
            } else {
                newNode->next = current;
                previous->next = newNode;
            }
        }
        this->size++;
    }

    /**
     * If the list is empty, return NULL. Otherwise, create a temporary Building object to compare the
     * labels. If the current node is NULL or the labels don't match, return NULL. Otherwise, if the
     * previous node is NULL, set the head to the next node. Otherwise, set the previous node's next to
     * the current node's next. Decrement the size and return the current node's value
     * 
     */
    Comparable *remove(int label) {
        if (this->head == NULL) {
            return NULL;
        }
        Node *current = this->head;
        Node *previous = NULL;

        // Create a temp Building to compare the labels
        Building *temp = new Building(new Value(0, 0), label);

        while (current != NULL && !(*current->value == *temp)) {
            previous = current;
            current = current->next;
        }
        if (current == NULL) {
            return NULL;
        }
        if (previous == NULL) {
            this->head = this->head->next;
        } else {
            previous->next = current->next;
        }
        this->size--;
        return current->value;
    }

    /**
     * If the head is null, return null, otherwise return the value of the head
     */
    Comparable *peek() {
        if (this->head == NULL) {
            return NULL;
        }
        return this->head->value;
    }

    /**
     * Returns true if the list is empty, false otherwise
     */
    bool isEmpty() {
        return this->head == NULL;
    }

    /**
     * If the head is null, return null. Otherwise, return the value of the head, set the head to the
     * next node, and decrement the size
     */
    Comparable *pop() {
        if (this->head == NULL) {
            return NULL;
        }
        Comparable *value = this->head->value;
        this->head = this->head->next;
        this->size--;
        return value;
    }

    /**
     * It returns the largest value in the list.
     */
    Comparable *getMax() {
        Node *current = this->head;
        Comparable *max = current->value;
        while (current != NULL) {
            if (*current->value > *max) {
                max = current->value;
            }
            current = current->next;
        }
        return max;
    }

    /**
     * The function takes a pointer to a node, and then prints the value of the node, which is a
     * pointer to a building
     */
    void print() {
        Node *current = this->head;
        while (current != NULL) {
            // Cast to Building
            Building *building = dynamic_cast<Building *>(current->value);
            building->print();
            current = current->next;
        }
        cout << endl;
    }
};




