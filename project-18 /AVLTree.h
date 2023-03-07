// This file includes AVLTree class declaration and AVLTree implementation.
// The AVLTree includes the following functions: insert, remove, find, print, update, and printProduct.
// Also it includes private functions to help the public functions.

#ifndef AVLTree_h
#define AVLTree_h

#include <iostream>
#include <string>
#include <queue>

#include "Tree.h"

using namespace std;

class AVLTree : public Tree
{
private:
    // Node structure - To store key, data and pointers to left and right children and height
    // Node represents a product
    struct Node
    {
        string key;
        string data;
        Node *left;
        Node *right;
        int height;
        Node(string key, string data) : key(key), data(data), left(NULL), right(NULL), height(0) {}
    };

    // Root node
    Node *root;

    // Private functions - To help public functions
    void insert(string key, string data, Node *&node); // Insert helper  
    void remove(string key, Node *&node);              // Remove helper
    void printGivenLevel(Node *node, int level, queue<Node*> &q);     // Print helper        
    void printProduct(ofstream &out, string name, string key, Node *node);                    // Print key helper
    string* find(const string& key, Node *node);       // Find helper
    int height(Node *node);                            // Height helper
    int max(int a, int b);                                      // Max helper
    void leftRotation(Node *&node);                    // Perform left-left rotation
    void rightRotation(Node *&node);                   // Perform right-right rotation
    void leftRightRotation(Node *&node);               // Perform left-right rotation
    void rightLeftRotation(Node *&node);               // Perform right-left rotation
    void balance(Node *&node);                         // Balance helper
    void destroy(Node *&node);                         // Destroy helper - for destructor
    Node *findMin(Node *node);                // Find minimum helper
    void update(string key, string data, Node *&node); // Update helper
public:
    AVLTree();      // Constructor
    ~AVLTree();     // Destructor
    void insert(string key, string data);   // Insert a new node
    void remove(string key);                // Remove a node
    void print(ofstream &out);                           // Print all nodes in level order
    void printProduct(ofstream &out, string name, string key);     // Print a node
    string* find(const string& key);                // Find a node
    void update(string key, string data);           // Update a node
};

// Constructor
AVLTree::AVLTree()
{
    root = NULL;
}

// Destructor
AVLTree::~AVLTree()
{
    destroy(root);
}

// Destroy
void AVLTree::destroy(Node *&node)
{
    if (node != NULL)
    {
        // Destroy left and right subtrees and delete node
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

// Insert
void AVLTree::insert(string key, string data)
{
    // Call insert helper
    insert(key, data, root);
}

// Insert Helper
void AVLTree::insert(string key, string data, Node *&node)
{
    if (node == NULL)
    {
        // Create new node
        node = new Node(key, data);
    }
    else if (key < node->key)
    {
        // Insert left
        insert(key, data, node->left);
        // After insertion, balance the tree
        balance(node);
    }
    else if (key > node->key)
    {
        // Insert right
        insert(key, data, node->right);
        // After insertion, balance the tree
        balance(node);
    }
}

// Remove
void AVLTree::remove(string key)
{
    // Call remove helper
    remove(key, root);
}

// Remove Helper
void AVLTree::remove(string key, Node *&node)
{
    // Remove node and balance the tree
    if (node == NULL)
    {
        return;
    }
    else if (key < node->key)
    {
        // Remove left
        remove(key, node->left);
    }
    else if (key > node->key)
    {
        // Remove right
        remove(key, node->right);
    }
    else
    {
        // Found
        if (node->left == NULL && node->right == NULL)
        {
            // No children
            delete node;
            node = NULL;
        }
        else if (node->left == NULL)
        {
            // One child - right
            Node *temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == NULL)
        {
            // One child - left
            Node *temp = node;
            node = node->left;
            delete temp;
        }
        else
        {
            // Two children
            Node *temp = findMin(node->right);
            node->key = temp->key;
            node->data = temp->data;
            remove(temp->key, node->right);
        }
    }
    // After removal, balance the tree
    balance(node);
}

// Find
string* AVLTree::find(const string& key)
{
    // Call find helper
    return find(key, root);
}

// Find Helper
string* AVLTree::find(const string& key, Node *node)
{
    if (node == NULL)
    {
        // Not found
        return NULL;
    }
    else if (key < node->key)
    {
        // Find left
        return find(key, node->left);
    }
    else if (key > node->key)
    {
        // Find right
        return find(key, node->right);
    }
    else
    {
        // Found
        return &node->data;
    }
}

// Print Level Order
void AVLTree::print(ofstream &out)
{
    queue<Node *> levelQueue;

    if (root == NULL)
    {
        out << "{}" << endl;
        return;
    }
    out << endl;
    int h = height(root);
    for (int i = 1; i <= h + 1; i++)
    {
        // Indentation
        out << "    ";     

        // Print given level, add nodes to queue
        printGivenLevel(root, i, levelQueue);
        // Print comma after each node, but not after last node
        while (!levelQueue.empty())
        {
            Node *temp = levelQueue.front();
            levelQueue.pop();
            if (!levelQueue.empty())
            {
                out << "\"" << temp->key << "\":"  << "\"" << temp->data  << "\",";
            }
            else
            {
                out << "\"" << temp->key << "\":"  << "\"" << temp->data  << "\"";
            }
        }
        levelQueue = queue<Node *>();
        out << endl;
    }
}

// Print given level helper. Adds nodes in specified level to queue.
void AVLTree::printGivenLevel(Node *node, int level, queue<Node *> &levelQueue)
{
    if (node == NULL)
    {
        return;
    }
    else if (level == 1)
    {
        levelQueue.push(node);
    }
    else
    {
        // Print left and right subtrees
        printGivenLevel(node->left, level - 1, levelQueue);
        printGivenLevel(node->right, level - 1, levelQueue);
    }
}

// Print Product
void AVLTree::printProduct(ofstream &out, string name, string key)
{
    // Call print product helper
    printProduct(out, name, key, root);
}

// Print Product Helper
void AVLTree::printProduct(ofstream &out, string name, string key, Node *node)
{
    if (node == NULL)
    {
        return;
    }
    else if (key < node->key)
    {
        // Print product left
        printProduct(out, name, key, node->left);
    }
    else if (key > node->key)
    {
        // Print product right
        printProduct(out, name, key, node->right);
    }
    else
    {
        // Found
        out << endl << "\"" << name << "\":";
        out << endl << "    \"" << node->key << "\":\"" << node->data << "\"" << endl;
    }
}

// Height
int AVLTree::height(Node *node)
{
    if (node == NULL)
    {
        return -1;
    }
    else
    {
        return node->height;
    }
}

// Max
int AVLTree::max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// Left Left Rotation
void AVLTree::leftRotation(Node *&node)
{
    // Perform a left-left rotation.
    Node *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    temp->height = max(height(temp->left), node->height) + 1;
    node = temp;
}

// Right Right Rotation
void AVLTree::rightRotation(Node *&node)
{
    // Perform a right-right rotation.
    Node *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    temp->height = max(height(temp->right), node->height) + 1;
    node = temp;
}

// Left Right Rotation
void AVLTree::leftRightRotation(Node *&node)
{
    // Perform a left-right rotation.
    rightRotation(node->left);
    leftRotation(node);
}

// Right Left Rotation
void AVLTree::rightLeftRotation(Node *&node)
{
    // Perform a right-left rotation.
    leftRotation(node->right);
    rightRotation(node);
}

// Balance
void AVLTree::balance(Node *&node)
{
    // Checking if the tree is balanced. If it is not, it will rotate the tree to make it balanced.
    if (node == NULL)
    {
        return;
    }

    if (height(node->left) - height(node->right) > 1)
    {
        // Left heavy
        if (height(node->left->left) >= height(node->left->right))
        {
            // If the left child is left heavy, perform a left-left rotation.
            leftRotation(node);
        }
        else
        {
            // If the left child is right heavy, perform a left-right rotation.
            leftRightRotation(node);
        }
    }
    else if (height(node->right) - height(node->left) > 1)
    {
        // Right heavy
        if (height(node->right->right) >= height(node->right->left))
        {
            // If the right child is right heavy, perform a right-right rotation.
            rightRotation(node);
        }
        else
        {
            // If the right child is left heavy, perform a right-left rotation.
            rightLeftRotation(node);
        }
    }

    // Update the height of the node.
    node->height = max(height(node->left), height(node->right)) + 1;
}

// Find Min
AVLTree::Node *AVLTree::findMin(Node *node)
{
    // Find the minimum data in the tree.
    if (node == NULL)
    {
        return NULL;
    }
    else if (node->left == NULL)
    {
        // Found the minimum data.
        return node;
    }
    else
    {
        // Find the minimum data in the left subtree.
        return findMin(node->left);
    }
}

// Update
void AVLTree::update(string key, string data)
{
    // Call update helper
    update(key, data, root);
}

// Update Helper
void AVLTree::update(string key, string data, Node *&node)
{
    if (node == NULL)
    {
        return;
    }
    else if (key < node->key)
    {
        // Update left
        update(key, data, node->left);
    }
    else if (key > node->key)
    {
        // Update right
        update(key, data, node->right);
    }
    else
    {
        // Found
        node->data = data;
    }
}



#endif

