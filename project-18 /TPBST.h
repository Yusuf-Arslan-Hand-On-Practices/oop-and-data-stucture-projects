// Tho Phase Binary Search Tree Implementation
// This file is a binary search tree implementation but nodes includes a AVL or RB tree.
#include <iostream>
#include <string>

using namespace std;


// products can be an AVL or RB tree, so it is a template class
// T is a template class and has to extend Tree class
// Enable if T is a Tree class
template <class T>
class TPBST
{
private:
    // PrimaryNode structure to represent a category
    struct PrimaryNode
    {
        string name;
        PrimaryNode *left;
        PrimaryNode *right;
        T products;     // AVL or RB tree
    };
    // Root node
    PrimaryNode *root;

public:
    TPBST();
    ~TPBST();
    void insert(string name, string key, string data); // Insert a category and a new product to that category
    // Update a product
    void removeProduct(string name, string key);     // Remove a product
    void update(string name, string key, string newData);
    void find(ofstream &out, string name, string key);             // Find the category and then product
    void print(ofstream &out);                            // Print tree level by level
    void printCategory(ofstream &out, string name);                 // Print a category
    void printProduct(ofstream &out, string name, string key);      // Print a product

private:
    void insert(string name, string key, string data, PrimaryNode *&node); // Insert helper
    void removeProduct(string name, string key, PrimaryNode *&node); // Remove helper
    void update(string name, string key, string newData, PrimaryNode *&node); // Update helper
    void find(ofstream &out, string name, string key, PrimaryNode *node); // Find helper
    void print(ofstream &out, PrimaryNode *node, int level);                  // Print helper for level order
    void printCategory(ofstream &out, string name, PrimaryNode *node);     // Print helper for a category
    void printProduct(ofstream &out, string name, string key, PrimaryNode *node); // Print helper for a product
    void destroy(PrimaryNode *&node);                         // Destroy helper - for destructor
    int height(PrimaryNode *node);                            // Height helper
};

// Constructor
template <class T>
TPBST<T>::TPBST()
{
    root = NULL;
}

// Destructor
template <class T>
TPBST<T>::~TPBST()
{
    destroy(root);
}

// Insert a category and a new product to that category
template <class T>
void TPBST<T>::insert(string name, string key, string data)
{
    insert(name, key, data, root);
}

// Insert helper
template <class T>
void TPBST<T>::insert(string name, string key, string data, PrimaryNode *&node)
{
    if (node == NULL)
    {
        node = new PrimaryNode;
        node->name = name;
        node->left = NULL;
        node->right = NULL;
        node->products.insert(key, data);
    }
    else if (name < node->name)
        insert(name, key, data, node->left);
    else if (name > node->name)
        insert(name, key, data, node->right);
    else
        node->products.insert(key, data);
}

// Remove a product
template <class T>
void TPBST<T>::removeProduct(string name, string key)
{
    removeProduct(name, key, root);
}

// Remove helper
template <class T>
void TPBST<T>::removeProduct(string name, string key, PrimaryNode *&node)
{
    if (node == NULL)
        return;
    else if (name < node->name)
        removeProduct(name, key, node->left);
    else if (name > node->name)
        removeProduct(name, key, node->right);
    else
        node->products.remove(key);
}

// Update a product
template <class T>
void TPBST<T>::update(string name, string key, string newData)
{
    update(name, key, newData, root);
}

// Update helper
template <class T>
void TPBST<T>::update(string name, string key, string newData, PrimaryNode *&node)
{
    if (node == NULL)
        return;
    else if (name < node->name)
        update(name, key, newData, node->left);
    else if (name > node->name)
        update(name, key, newData, node->right);
    else
        node->products.update(key, newData);
}


// Find the category and then product
template <class T>
void TPBST<T>::find(ofstream &out, string name, string key)
{
    out << "{" ;
    find(out, name, key, root);
    out << "}" << endl;
}

// Find helper
template <class T>
void TPBST<T>::find(ofstream &out, string name, string key, PrimaryNode *node)
{
    if (node == NULL)
    {// out << "{}" << endl;
    }
    else if (name < node->name)
        find(out, name, key, node->left);
    else if (out, name > node->name)
        find(out, name, key, node->right);
    else
    {
        string *data = node->products.find(key);
        if (data == NULL)
        {
            // out << "{}" << endl;
        }
        else
        {
            out << endl << "\"" << name << "\":" << endl;
            out << "    \"" << key << "\":\"" << *data << "\"" << endl;
        }
    }
}

// Print tree level by level
template <class T>
void TPBST<T>::print(ofstream &out)
{
    int height = this->height(root);
    if (height == 0)
    {
        out << "{}" << endl;
        return;
    }

    out << "{" << endl;
    for (int i = 1; i <= height + 1; i++)
        print(out, root, i);
    out << "}" << endl;
}

// Print helper for level order
template <class T>
void TPBST<T>::print(ofstream &out, PrimaryNode *node, int level)
{
    if (node == NULL)
        return;
    else if (level == 1)
    {
        out << "\"" << node->name << "\":";
        node->products.print(out);
    }
    else
    {
        print(out, node->left, level - 1);
        print(out, node->right, level - 1);
    }
}

// Print a category
template <class T>
void TPBST<T>::printCategory(ofstream &out, string name)
{
    out << "{" ;
    printCategory(out, name, root);
    out << "}" << endl;
}

// Print helper for a category
template <class T>
void TPBST<T>::printCategory(ofstream &out, string name, PrimaryNode *node)
{
    if (node == NULL)
        return;
    else if (name < node->name)
        printCategory(out, name, node->left);
    else if (name > node->name)
        printCategory(out, name, node->right);
    else
    {
        out << endl << "\"" << node->name << "\":";
        node->products.print(out);
    }
}

// Print a product
template <class T>
void TPBST<T>::printProduct(ofstream &out, string name, string key)
{
    printProduct(out, name, key, root);
}

// Print helper for a product
template <class T>
void TPBST<T>::printProduct(ofstream &out, string name, string key, PrimaryNode *node)
{
    if (node == NULL)
    {
        out << "{}" << endl;
    }
    else if (name < node->name)
        printProduct(out, name, key, node->left);
    else if (name > node->name)
        printProduct(out, name, key, node->right);
    else
    {
        out << "{" ;
        node->products.printProduct(out, name, key);
        out << "}" << endl;
    }
}

// Destroy helper - for destructor
template <class T>
void TPBST<T>::destroy(PrimaryNode *&node)
{
    if (node == NULL)
        return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

// Height helper
template <class T>
int TPBST<T>::height(PrimaryNode *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}
