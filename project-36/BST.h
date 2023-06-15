#ifndef BST_H
#define BST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

// BST Node
template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
};

// This is a declaration of a templated Binary Search Tree (BST) class.
// The class has a private member variable `root` which is a pointer to a `Node` struct.
// The `Node` struct has a templated data member and two pointers to `Node` structs for the left and right children.
template <typename T>
class BST
{
public:
    BST();
    ~BST();
    void add(T data);
    void remove(T data);
    T search(T data);

private:
    Node<T> *root;
    Node<T> *add(Node<T> *node, T data);
    Node<T> *remove(Node<T> *node, T data);
    Node<T> *removeMin(Node<T> *node);
    Node<T> *findMin(Node<T> *node);
    void destroy(Node<T> *node);
};

#include "BST.cpp"

#endif