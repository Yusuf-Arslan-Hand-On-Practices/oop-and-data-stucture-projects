// Implementation of the MPQ class
#include <iostream>
#include <string>
#include <fstream>

#include "mpq.h"
#include "comparable.h"

using namespace std;

// Constructor
MPQ::MPQ()
{
    head = NULL;
}
// Read the file and create the MPQ
MPQ::MPQ(string filename)
{
    head = NULL;
    ifstream file;
    file.open(filename);

    // If the file is opened
    if (file.is_open())
    {
        // First line is number of skylines which is not used in this program
        int n;
        file >> n;

        int x, x_, y;
        int label = 0;

        // Read the file
        while (file >> x >> y >> x_)
        {
            // Create a new Comparable object
            Comparable *c = new Comparable(x, x_, y);
            // Insert the Comparable object to the MPQ
            insert(c, label);
            label++;
        }
    }
    // If the file is not opened
    else
    {
        cout << "File is not opened" << endl;
    }
}

// Destructor
MPQ::~MPQ()
{
    Node *current = head;
    Node *next = NULL;

    // Delete all nodes
    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }
}

// Insert MPQ class in order, min heap
void MPQ::insert(Comparable *value, int label)
{
    // Create a new node
    Node *newNode = new Node;
    newNode->value = value;
    newNode->label = label;
    newNode->next = NULL;

    // If the list is empty
    if (head == NULL)
    {
        head = newNode;
    }
    // If the list is not empty
    else
    {
        // If the new node is smaller than the head
        if (*newNode->value < *head->value)
        {
            newNode->next = head;
            head = newNode;
        }
        // If the new node is greater than the head
        else
        {
            Node *current = head;
            Node *previous = NULL;

            // Find the correct position to insert the new node to min heap
            while (current != NULL && *current->value < *newNode->value)
            {
                previous = current;
                current = current->next;
            }

            // Insert the new node
            newNode->next = current;
            previous->next = newNode;
        }
    }
}

// Remove the value with given label
Comparable MPQ::remove(int label)
{
    Node *current = head;
    Node *previous = NULL;

    // Find the node with given label
    while (current != NULL && current->label != label)
    {
        previous = current;
        current = current->next;
    }

    // If the node is found
    if (current != NULL)
    {
        // If the node is the head
        if (current == head)
        {
            head = head->next;
        }
        // If the node is not the head
        else
        {
            previous->next = current->next;
        }

        // Save the value
        Comparable value = *current->value;

        // Delete the node
        delete current;

        // Return the value
        return value;
    }
    // If the node is not found
    else
    {
        // If the node is not found, 
        // return a value with x = 0, x_ = 0, y = 0
        Comparable value = Comparable(0, 0, 0);
        return value;
    }
}

// Get the max value - does not remove it
Comparable MPQ::getMax()
{
    // Compare the values and return the max
    if (head == NULL)
    {
        // If the list is empty, 
        // return a value with x = 0, x_ = 0, y = 0
        Comparable value = Comparable(0, 0, 0);
        return value;
    }
    else
    {
        // If the list is not empty,
        Comparable value = *head->value;
        Node *current = head->next;
        // Find the max value in the MQP (which is height in this case)
        while (current != NULL && *current->value > value)
        {
            value = *current->value;
            current = current->next;
        }
        return value;
    }
}

// Get the first value and remove it
Comparable MPQ::pop()
{
    // If the list is empty
    if (head == NULL)
    {
        // If the list is empty, 
        // return a value with x = 0, x_ = 0, y = 0
        Comparable value = Comparable(0, 0, 0);
        return value;
    }
    // If the list is not empty
    else
    {
        // Save the value
        Comparable value = *head->value;

        // Delete the node
        Node *temp = head;
        head = head->next;
        delete temp;

        // Return the value
        return value;
    }
}

// Return true if the MPQ is empty
bool MPQ::isEmpty()
{
    return head == NULL;
}

// Find furthest x value - where the skylines end
int MPQ::getFurthest()
{
    // If the list is empty
    if (head == NULL)
    {
        return 0;
    }

    // Find the furthest x_ value (where the skylines end)
    Node *current = head;
    int furthest = head->value->getX_();
    current = current->next;
    while (current != NULL)
    {
        if (current->value->getX_() > furthest)
        {
            furthest = current->value->getX_();
        }
        current = current->next;
    }

    return furthest;
}

// Print the MPQ
void MPQ::print()
{
    Node *current = head;

    // Print all nodes
    while (current != NULL)
    {
        cout << current->label << ": " << *current->value << endl;
        current = current->next;
    }
}

