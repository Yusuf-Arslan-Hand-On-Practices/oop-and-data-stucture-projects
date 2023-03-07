// This file includes LLRBTree (Left Leaning Red-Black Tree) class implementation.
// The class extends the Tree class and implements the following 
// public functions: insert, remove, print, printProduct, find, update.
#include <iostream>
#include <string>
#include <queue>

using namespace std;

#include "Tree.h"

// LLRBTree class
class LLRBTree : public Tree
{
private:
    // Node structure
    struct Node
    {
        string key;
        string data;
        Node *left;
        Node *right;
        bool color;     // true for red, false for black
        Node(string key, string data) : key(key), data(data), left(nullptr), right(nullptr), color(true) {}
    };
    // Root node
    Node *root;

public:
    LLRBTree();
    ~LLRBTree();
    void insert(string key, string data); // Insert a node
    void remove(string key);              // Remove a node
    void print(ofstream &out);                         // Print the tree
    void printProduct(ofstream &out, string name, string key); // Print a node
    string* find(const string& key);      // Find a node
    void update(string key, string data); // Update a node

private:
    void insert(string key, string data, Node *&node); // Insert helper
    void remove(string key, Node *&node);              // Remove helper
    void printGivenLevel(Node *node, int level, queue<Node*> &q);     // Print helper        
    void printProduct(ofstream &out, string name, string key, Node *node); // Print helper
    void destroy(Node *&node);                         // Destroy helper - for destructor
    Node* find(const string& key, Node *node);         // Find helper
    void update(string key, string data, Node *&node); // Update helper
    bool isRed(Node *node);                            // Check if a node is red
    Node* rotateLeft(Node *node);                      // Rotate left
    Node* rotateRight(Node *node);                     // Rotate right
    void flipColors(Node *node);                       // Flip colors
    Node* moveRedLeft(Node *node);                     // Move red left
    Node* moveRedRight(Node *node);                    // Move red right
    Node* balance(Node *node);                         // Balance the tree
    Node* min(Node *node);                             // Find the minimum node
    int height(Node *node);                            // Height helper
};

// Constructor
LLRBTree::LLRBTree()
{
    root = NULL;
}

// Destructor
LLRBTree::~LLRBTree()
{
    destroy(root);
}

// Insert a node
void LLRBTree::insert(string key, string data)
{
    insert(key, data, root);
    root->color = false;    // Root is always black
}

// Remove a node
void LLRBTree::remove(string key)
{
    if (!isRed(root->left) && !isRed(root->right))
        root->color = true;
    remove(key, root);
    if (root != NULL)
        root->color = false;    // Root is always black
}

// Print Level Order
void LLRBTree::print(ofstream &out)
{
    queue<Node *> levelQueue;

    if (root == NULL)
    {
        out << "{}" << endl;
        return;
    }
    out << endl;
    int h = height(root);
    for (int i = 1; i <= h; i++)
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
void LLRBTree::printGivenLevel(Node *node, int level, queue<Node *> &levelQueue)
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
void LLRBTree::printProduct(ofstream &out, string name, string key)
{
    // Call print product helper
    printProduct(out, name, key, root);
}

// Print Product Helper
void LLRBTree::printProduct(ofstream &out, string name, string key, Node *node)
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

// Find a node
string* LLRBTree::find(const string& key)
{
    Node *node = find(key, root);
    if (node == NULL)
        return NULL;
    else
        return &node->data;
}

// Update a node
void LLRBTree::update(string key, string data)
{
    update(key, data, root);
}

// Insert a node left leaning order in red black tree 
void LLRBTree::insert(string key, string data, Node *&node)
{
    if (node == NULL)
    {
        node = new Node(key, data);
        return;
    }
    if (key < node->key)
    {
        insert(key, data, node->left);
    }
    else
    {
        insert(key, data, node->right);
    }
    if (isRed(node->right) && !isRed(node->left))
        node = rotateLeft(node);
    if (isRed(node->left) && isRed(node->left->left))
        node = rotateRight(node);
    if (isRed(node->left) && isRed(node->right))
        flipColors(node);
}

// Remove a node
void LLRBTree::remove(string key, Node *&node)
{
    if (key < node->key)
    {
        if (!isRed(node->left) && !isRed(node->left->left))
            node = moveRedLeft(node);
        remove(key, node->left);
    }
    else
    {
        if (isRed(node->left))
            node = rotateRight(node);
        if (key == node->key && (node->right == NULL))
        {
            delete node;
            node = NULL;
            return;
        }
        if (!isRed(node->right) && !isRed(node->right->left))
            node = moveRedRight(node);
        if (key == node->key)
        {
            Node *x = min(node->right);
            node->key = x->key;
            node->data = x->data;
            remove(node->key, node->right);
        }
        else
            remove(key, node->right);
    }
    node = balance(node);
}

// Destroy the tree
void LLRBTree::destroy(Node *&node)
{
    if (node == NULL)
        return;
    destroy(node->left);
    destroy(node->right);
    delete node;
    node = NULL;
}

// Find a node
LLRBTree::Node* LLRBTree::find(const string& key, Node *node)
{
    if (node == NULL)
        return NULL;
    if (key < node->key)
        return find(key, node->left);
    else if (key > node->key)
        return find(key, node->right);
    else
        return node;
}

// Update a node
void LLRBTree::update(string key, string data, Node *&node)
{
    if (node == NULL)
        return;
    if (key < node->key)
        update(key, data, node->left);
    else if (key > node->key)
        update(key, data, node->right);
    else
        node->data = data;
}

// Check if a node is red
bool LLRBTree::isRed(Node *node)
{
    if (node == NULL)
        return false;
    return node->color;
}

// Rotate left
LLRBTree::Node* LLRBTree::rotateLeft(Node *node)
{
    Node *x = node->right;
    node->right = x->left;
    x->left = node;
    x->color = x->left->color;
    x->left->color = true;
    return x;
}   

// Rotate right
LLRBTree::Node* LLRBTree::rotateRight(Node *node)
{
    Node *x = node->left;
    node->left = x->right;
    x->right = node;
    x->color = x->right->color;
    x->right->color = true;
    return x;
}

// Flip colors
void LLRBTree::flipColors(Node *node)
{
    node->color = !node->color;
    node->left->color = !node->left->color;
    node->right->color = !node->right->color;
}

// Move red node left
LLRBTree::Node* LLRBTree::moveRedLeft(Node *node)
{
    flipColors(node);
    if (isRed(node->right->left))
    {
        node->right = rotateRight(node->right);
        node = rotateLeft(node);
        flipColors(node);
    }
    return node;
}

// Move red node right
LLRBTree::Node* LLRBTree::moveRedRight(Node *node)
{
    flipColors(node);
    if (isRed(node->left->left))
    {
        node = rotateRight(node);
        flipColors(node);
    }
    return node;
}

// Balance the tree
LLRBTree::Node* LLRBTree::balance(Node *node)
{
    if (isRed(node->right))
        node = rotateLeft(node);
    if (isRed(node->left) && isRed(node->left->left))
        node = rotateRight(node);
    if (isRed(node->left) && isRed(node->right))
        flipColors(node);
    return node;
}

// Find the minimum node
LLRBTree::Node* LLRBTree::min(Node *node)
{
    if (node->left == NULL)
        return node;
    else
        return min(node->left);
}

// find height of tree
int LLRBTree::height(Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

