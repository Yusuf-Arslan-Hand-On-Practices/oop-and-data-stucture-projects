// Header file for the Modified Priority Queue
// It is a min heap and keeps two vectors. One is for comparable objects and other is
// represents the index of the comparable object in the heap.

#include <iostream>
#include <vector>

#include "Comparable.h"

using namespace std;

// Class definition for a Min Priority Queue.
class MPQ
{
    private:
        struct Node
        {
            Comparable *value;  // Comparable object
            int label;      // Represents the index of the comparable object in comparables vector
        };
        vector<Node> comparables;   // Vector of comparable objects
        vector<int> labels;         // Vector of labels, represents the heap
        int size;                   // Size of the heap
        void swap(int i, int j);    // Swaps two nodes in the heap
    public:
        MPQ();
        ~MPQ();
        void insert(Comparable value, int label);
        Comparable remove();
        Comparable remove(int label);
        Comparable getMax();
        void printSkyline();
};

// Default constructor
MPQ::MPQ()
{
    size = 0;
}

// Destructor
MPQ::~MPQ()
{
    for (int i = 0; i < comparables.size(); i++)
    {
        delete comparables[i].value;
    }
}

// Inserts a comparable object into the heap and heapifies it
void MPQ::insert(Comparable value, int label)
{
    Node n;
    n.value = new Comparable(value.getX(), value.getY(), value.getX1());
    n.label = label;
    comparables.push_back(n);
    labels.push_back(size);
    size++;
    // Find parent, left and childs and heapify it 
    int i = size - 1;
    
    // while the new node is smaller than its adjacent node, the swap the (bubling from right to left)
    while (i > 0 && *comparables[labels[i]].value < *comparables[labels[(i - 1)]].value)
    {
        swap(i, (i - 1));
        i = (i - 1);
    }
}

// Removes the minimum element from the heap and returns it.
// shifts all elements to the left and heapifies the heap
Comparable MPQ::remove()
{
    // Return null if the heap is empty
    if (size == 0)
    {
        return Comparable(0, 0, 0);
    }

    // Get the top element of the heap
    Comparable top = *comparables[labels[0]].value;

    // shift all elements to the left
    for (int i = 0; i < size - 1; i++)
    {
        labels[i] = labels[i + 1];
    }

    size--;

    return top;
}

// Remove with label
// Removes the element with the given label from the heap and returns it.
// shifts all elements after the removed element to the left and heapifies the heap
Comparable MPQ::remove(int label)
{
    // Return null if the heap is empty
    if (size == 0)
    {
        return Comparable(0, 0, 0);
    }

    // start from 0 to find the index of the element with the given label
    int i = 0;
    while (i < size && labels[i] != label)
    {
        i++;
    }

    // Return 0, 0, 0 object if the element with the given label is not found
    if (i == size)
    {
        return Comparable(0, 0, 0);
    }

    // Get the element with the given label
    Comparable top = *comparables[labels[i]].value;

    // shift all elements after the removed element to the left
    for (int j = i; j < size - 1; j++)
    {
        labels[j] = labels[j + 1];
    }

    size--;

    return top;
}

// Returns the maximum element in the heap
Comparable MPQ::getMax()
{
    if (size == 0)
    {
        return Comparable(0, 0, 0);
    }

    Comparable max = *comparables[labels[0]].value;
    for (int i = 0; i < size; i++)
    {
        if (*comparables[labels[i]].value > max)
        {
            max = *comparables[labels[i]].value;
        }
    }
    return max;
}


// prints the heap
void MPQ::printSkyline()
{
    Comparable max = this->getMax();        // Find the max x'
    MPQ temp;                               // Create a temporary heap, to store each point of the City
    int label = 0;                          // Label for each point

    // Iterate through the City, and add each point to the temporary heap
    for (int i = 0; i < max.getX1(); i++)   
    {
        Comparable c = this->remove();
        for (int j = c.getX(); j < c.getX1(); j++)
        {
            temp.insert(Comparable(j, c.getY(), -1), label);
            label++;
        }
        // Add zero height buildings - to keep track of the empty spaces
        temp.insert(Comparable(i, 0, -1), label);
        label++;
    }

    // Print the skyline
    Comparable prev = temp.remove();
    if (prev.getX() != 0)
    {
        // If the first point is not at x = 0, print (0, 0) as the first point
        cout << 0 << " " << 0 << "\n";
    }
    // Print the first point
    cout << prev.getX() << " " << prev.getY() << "\n";
    
    // While the temporary heap is not empty, print the points
    while (temp.size != 0)
    {
        Comparable c = temp.remove();
        if (c.getX() != prev.getX())
        {
            if (c.getY() != prev.getY())
            {
                // If the height of the current point is not equal to the height of the previous point, print the current point
                cout << c.getX() << " " << c.getY() << "\n";
            }
            prev = c;
        }
    }
    cout << max.getX1() << " " << 0 << "\n";
}

// swaps two nodes in the heap
void MPQ::swap(int i, int j)
{
    int temp = labels[i];
    labels[i] = labels[j];
    labels[j] = temp;
}

