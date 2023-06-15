#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

// BST Node
template <typename T>
struct BSTNode {
    T key;
    BSTNode<T>* left;
    BSTNode<T>* right;
};

template <typename T>
class BSTree {
public:
    BSTree();
    ~BSTree();
    void insert(T key);
    void remove(T key);
    bool search(T key);
    vector<T> searchAll(T key);
    void inorder();
    void preorder();
    void printTree();
    int getLeftHeight();
    int getRightHeight();

private:
    BSTNode<T>* root;

    BSTNode<T>* insert(BSTNode<T>* node, T key);
    BSTNode<T>* remove(BSTNode<T>* node, T key);
    BSTNode<T>* removeMin(BSTNode<T>* node);
    BSTNode<T>* findMin(BSTNode<T>* node);
    void searchAll(BSTNode<T>* node, T key, vector<T>* results);
    void inorder(BSTNode<T> *node);
    void inorder(BSTNode<T> *node, ofstream &file);
    void preorder(BSTNode<T> *node);
    void preorder(BSTNode<T> *node, ofstream &file);
    void printTree(BSTNode<T> *node, int indent, ofstream &file);
    void destroy(BSTNode<T>* node);
};


template <typename T>
BSTree<T>::BSTree() : root(nullptr) {}

template <typename T>
BSTree<T>::~BSTree() {
    destroy(root);
}

template <typename T>
void BSTree<T>::destroy(BSTNode<T>* node) {
    if (node == nullptr) {
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
}

// Helper for insert function
template <typename T>
void BSTree<T>::insert(T key) {
    root = insert(root, key);
}

template <typename T>
BSTNode<T>* BSTree<T>::insert(BSTNode<T>* node, T key) {
    if (node == nullptr) {
        node = new BSTNode<T>{key, nullptr, nullptr};
    }
    else if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}

template <typename T>
void BSTree<T>::remove(T key) {
    root = remove(root, key);
}

template <typename T>
BSTNode<T>* BSTree<T>::remove(BSTNode<T>* node, T key) {
    if (node == nullptr) {
        return nullptr;
    } else if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else if (node->left != nullptr && node->right != nullptr) {
        node->key = findMin(node->right)->key;
        node->right = removeMin(node->right);
    } else {
        BSTNode<T>* oldBSTNode = node;
        node = (node->left != nullptr) ? node->left : node->right;
        delete oldBSTNode;
    }
    return node;
}

template <typename T>
BSTNode<T>* BSTree<T>::removeMin(BSTNode<T>* node) {
    if (node->left == nullptr) {
        return node->right;
    }
    node->left = removeMin(node->left);
    return node;
}

template <typename T>
BSTNode<T>* BSTree<T>::findMin(BSTNode<T>* node) {
    if (node->left == nullptr) {
        return node;
    }
    return findMin(node->left);
}

template <typename T>
bool BSTree<T>::search(T key) {
    BSTNode<T>* node = root;
    while (node != nullptr) {
        if (key < node->key) {
            node = node->left;
        } else if (key > node->key) {
            node = node->right;
        } else {
            return true;
        }
    }
    return false;
}

template <typename T>
vector<T> BSTree<T>::searchAll(T key) {
    vector<T> results;
    searchAll(root, key, &results);
    return results;
}

template <typename T>
void BSTree<T>::searchAll(BSTNode<T>* node, T key, vector<T>* results) {
    if (node == nullptr) {
        return;
    }
    
    searchAll(node->left, key, results);
    
    if (node->key == key) {
        results->push_back(node->key);
    }
    
    searchAll(node->right, key, results);
}

template <typename T>
void BSTree<T>::inorder() {
    // open file
    ofstream file;
    file.open("inorderBST.txt");
    inorder(root, file);
    file.close();
}

template <typename T>
void BSTree<T>::inorder(BSTNode<T>* node) {
    if (node == nullptr) {
        return;
    }

    inorder(node->left);
    cout << node->key << "\n";
    inorder(node->right);
}

// inorder to file
template <typename T>
void BSTree<T>::inorder(BSTNode<T>* node, ofstream &file) {
    if (node == nullptr) {
        return;
    }

    inorder(node->left, file);
    file << node->key << "\n";
    inorder(node->right, file);
}

template <typename T>
void BSTree<T>::preorder() {
    // open file
    ofstream file;
    file.open("preorderBST.txt");
    preorder(root, file);
    file.close();
}

template <typename T>
void BSTree<T>::preorder(BSTNode<T>* node) {
    if (node == nullptr) {
        return;
    }
    
    cout << node->key << "\n";
    preorder(node->left);
    preorder(node->right);
}

// preorder to file
template <typename T>
void BSTree<T>::preorder(BSTNode<T>* node, ofstream &file) {
    if (node == nullptr) {
        return;
    }
    
    file << node->key << "\n";
    preorder(node->left, file);
    preorder(node->right, file);
}

template <typename T>
void BSTree<T>::printTree() {
    // open file
    ofstream file;
    file.open("DrawBSTree.txt");
    printTree(root, 0, file);
    file.close();
}

template <typename T>
void BSTree<T>::printTree(BSTNode<T>* node, int indent, ofstream& file) {
    if (node == nullptr) {
        return;
    }

    file << string(indent, ' ') << "|--";

    // ---- print only first and last names ----
    ostringstream stream;
    stream << node->key;
    string keyString = stream.str();
    int pos;
    for (int i = 0, count = 0; i < keyString.length(); i++) {
        if (keyString[i] == ' ') {
            if (count == 1) {
                pos = i;
                break;
            }
            count++;
        }
    }
    file << keyString.substr(0, pos) << endl;
    // ---- print only first and last names ----

    if (node->left != nullptr) {
        file << string(indent, ' ');
        printTree(node->left, indent + 2, file);
    }
    if (node->right != nullptr) {
        file << string(indent, ' ');
        printTree(node->right, indent + 2, file);
    }
}

template <typename T>
int BSTree<T>::getLeftHeight() {
    BSTNode<T>* node = root;
    int height = 0;
    while(node != nullptr) {
        height++;
        node = node->left;
    }

    return height;
}

template <typename T>
int BSTree<T>::getRightHeight() {
    BSTNode<T>* node = root;
    int height = 0;
    while(node != nullptr) {
        height++;
        node = node->right;
    }

    return height;
}

#endif