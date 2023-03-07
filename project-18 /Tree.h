// Abstract class for a tree
#ifndef TREE_H
#define TREE_H

#include <string>

using namespace std;
// Abstract class for a tree, it enables to perform operations in TTBST
class Tree
{
    virtual void insert(string key, string data) = 0;   // Insert a node
    virtual void remove(string key) = 0;                // Remove a node
    virtual void print(ofstream &out) = 0;                           // Print the tree
    virtual void printProduct(ofstream &out, string name, string key) = 0;     // Print a node
    virtual string* find(const string& key) = 0;        // Find a node
    virtual void update(string key, string data) = 0;   // Update a node
};

#endif