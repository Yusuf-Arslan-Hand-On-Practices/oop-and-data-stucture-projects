#include <iostream>
#include <string>
#include <time.h>

#include "ActivityBST.h"

using namespace std;

// Helper functions
bool isTimeValid(int time) {
    bool valid = true;

    if (time < 0 || time > 2359) valid = false;
    if (time % 100 > 59) valid = false;

    return valid;
}

// Return the string representation of a time
string numToTime(int number) { 
    return fillWithZeros(2, to_string(number/100))+":"+ fillWithZeros(2, to_string(number%100)); 
}

// Fill a string with zeros
string fillWithZeros(int num_zeros, const string& input) { 
    int zeros_to_add = num_zeros - input.length(); 
    if (zeros_to_add < 0) zeros_to_add = 0; 
    return string(zeros_to_add, '0') + input;
}

// Free function to avoid garbage collection
void free(tree_node *node) {
    if (node == nullptr) return;
    free(node->left);
    free(node->right);
    delete node;
}
// ------------ Helper functions end ------------

// Copy constructor
ActivityBST::ActivityBST(const ActivityBST &bst) {
    root = nullptr;
    appendAll(*this, bst.root);
}

// Add a new node to the tree
void ActivityBST::add(int time, const string &activity) {
    if (!isTimeValid(time)) return;
    tree_node *new_node = new tree_node(time, activity);
    if (root == nullptr) {
        root = new_node;
    } else {
        insert(root, new_node);
    }
}

// PRIVATE HELPER -- to insert a node into the tree, recursively
void ActivityBST::insert(tree_node *node, tree_node *new_node) {
    if (new_node->time < node->time) {
        if (node->left == nullptr) {
            node->left = new_node;
            new_node->parent = node;
        } else {
            insert(node->left, new_node);
        }
    } else {
        if (node->right == nullptr) {
            node->right = new_node;
            new_node->parent = node;
        } else {
            insert(node->right, new_node);
        }
    }
}

// PRIVATE HELPER -- iterates through the tree and adds each node to the new tree
void ActivityBST::appendAll(ActivityBST &bst, tree_node *node) const {
    if (node == nullptr) return;
    bst.add(node->time, node->activity);
    appendAll(bst, node->left);
    appendAll(bst, node->right);
}

// PRIVATE HELPER -- iterates through the tree and prints each node to the output stream
void ActivityBST::printInOrder(tree_node *node, ostream &out) const {
    if (node == nullptr) return;
    printInOrder(node->left, out);
    out << "[" << numToTime(node->time) << "] - " << node->activity << endl;
    printInOrder(node->right, out);
}

// Overload assignment operator
ActivityBST &ActivityBST::operator=(const ActivityBST &bst) {
    // if both are the same, return
    if (this == &bst) return *this;
    
    // else destroy the current tree
    free(root);

    // then copy the new tree
    root = nullptr;
    appendAll(*this, bst.root);

    return *this;
}

// Overload + operator
ActivityBST ActivityBST::operator+(const ActivityBST &bst) const {
    ActivityBST new_bst;
    appendAll(new_bst, root);
    appendAll(new_bst, bst.root);
    return new_bst;
}

// Overload += operator
ActivityBST &ActivityBST::operator+=(const ActivityBST &bst) {
    appendAll(*this, bst.root);
    return *this;
}

// Overload << operator
ostream &operator<<(ostream &os, const ActivityBST &bst) {
    if (bst.root != nullptr) {
        bst.printInOrder(bst.root, os);
    }
    return os;
}