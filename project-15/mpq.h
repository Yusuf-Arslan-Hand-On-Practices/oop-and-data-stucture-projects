// Header for MPQ class
#include <iostream>
#include <string>

#include "comparable.h"

using namespace std;

#ifndef MPQ_H
#define MPQ_H

// Linked list is used to implement the MPQ
class MPQ
{
    private:
    // Node structure
    struct Node
        {
            Comparable *value;
            int label;
            Node *next;
        };
    Node *head;
    
    public:
        MPQ();
        MPQ(string filename);
        ~MPQ();
        // Insert MPQ class in order, min heap
        void insert(Comparable *value, int label);
        // Remove the value with given label
        Comparable remove(int label);
        // Get the max value - does not remove it
        Comparable getMax();
        // Get the first value and remove it
        Comparable pop();
        // Return true if the MPQ is empty
        bool isEmpty();    
        
        // This is helper function for the skyline algorithm
        // It will used for finding the furthest x value
        int getFurthest();
        // Print the MPQ
        void print();
};

#endif
