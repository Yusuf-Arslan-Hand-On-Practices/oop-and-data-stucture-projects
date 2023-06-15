#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

// AVL Node
template <typename T>
struct AVLNode {
    T key;
    int height;
    AVLNode<T>* left;
    AVLNode<T>* right;
};

template <typename T>
class AVLTree {
public:
    AVLTree();
    ~AVLTree();
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
    AVLNode<T>* root;

    AVLNode<T>* insert(AVLNode<T>* node, T key);
    AVLNode<T>* remove(AVLNode<T>* node, T key);
    AVLNode<T>* removeMin(AVLNode<T>* node);
    AVLNode<T>* findMin(AVLNode<T>* node);
    int height(AVLNode<T>* node);
    int balanceFactor(AVLNode<T>* node);
    void updateHeight(AVLNode<T>* node);
    AVLNode<T>* rotateLeft(AVLNode<T>* node);
    AVLNode<T>* rotateRight(AVLNode<T>* node);
    AVLNode<T>* balance(AVLNode<T>* node);
    void searchAll(AVLNode<T>* node, T key, vector<T>* results);
    void inorder(AVLNode<T> *node);
    void inorder(AVLNode<T> *node, ofstream& file);
    void preorder(AVLNode<T>* node);
    void preorder(AVLNode<T>* node, ofstream& file);
    void printTree(AVLNode<T> *node, int indent, ofstream &file);
    void destroy(AVLNode<T> *node);
};

template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template <typename T>
AVLTree<T>::~AVLTree() {
    destroy(root);
}

template <typename T>
void AVLTree<T>::destroy(AVLNode<T>* node) {
    if (node == nullptr) {
        return;
    }

    destroy(node->left);
    destroy(node->right);
    delete node;
}

// Helper for insert function
template <typename T>
void AVLTree<T>::insert(T key) {
    root = insert(root, key);
}

template <typename T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T>* node, T key) {
    if (node == nullptr) {
        node = new AVLNode<T>{key, 1, nullptr, nullptr};
    } 
    else if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    else {
        // Key already exists in tree
        return node;
    }
    
    // Update height of node
    updateHeight(node);
    
    // Balance node if necessary
    return balance(node);
}

template <typename T>
void AVLTree<T>::remove(T key) {
    root = remove(root, key);
}

template <typename T>
AVLNode<T>* AVLTree<T>::remove(AVLNode<T>* node, T key) {
    if (node == nullptr) {
        // Key not found in tree
        return nullptr;
    }
    
    if (key < node->key) {
        node->left = remove(node->left, key);
    }
    else if (key > node->key) {
        node->right = remove(node->right, key);
    }
    else {
        // Key found in tree
        AVLNode<T>* leftChild = node->left;
        AVLNode<T>* rightChild = node->right;
        
        delete node;
        
        if (rightChild == nullptr) {
            return leftChild;
        }
        
        AVLNode<T>* minAVLNode = findMin(rightChild);
        minAVLNode->right = removeMin(rightChild);
        minAVLNode->left = leftChild;
        
        updateHeight(minAVLNode);
        
        return balance(minAVLNode);
    }
    
    updateHeight(node);
    
    return balance(node);
}



template <typename T>
bool AVLTree<T>::search(T key) {
    AVLNode<T>* current = root;
    
    // find the key
    while (current != nullptr) {
        if (current->key == key) {
            return true;
        }
        else if (key < current->key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    
    return false;
}

// search all instances inorder return the vector 
template <typename T>
vector<T> AVLTree<T>::searchAll(T key) {
    // call helper searchAll
    vector<T> results;
    searchAll(root, key, &results);
    return results;
}

// helper search all function traverse the tree inorder and returns the all instances
template <typename T>
void AVLTree<T>::searchAll(AVLNode<T>* node, T key, vector<T>* results) {
    if (node == nullptr) {
        return;
    }
    
    searchAll(node->left, key, results);
    
    if (node->key == key) {
        results->push_back(node->key);
    }
    
    searchAll(node->right, key, results);
}

// helper for remove function
template <typename T>
AVLNode<T>* AVLTree<T>::findMin(AVLNode<T>* node) {
    AVLNode<T>* current = node;
    
    while (current->left != nullptr) {
        current = current->left;
    }
    
    return current;
}

// helper for remove function
template <typename T>
AVLNode<T>* AVLTree<T>::removeMin(AVLNode<T>* node) {
    if (node->left == nullptr) {
        return node->right;
    }
    
    node->left = removeMin(node->left);
    
    updateHeight(node);
    
    return balance(node);
}


// returns height of the node
template <typename T>
int AVLTree<T>::height(AVLNode<T>* node) {
    return (node == nullptr ? 0 : node->height);
}

// returns balance factor of the node
template <typename T>
int AVLTree<T>::balanceFactor(AVLNode<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    
    return height(node->right) - height(node->left);
}

// updates height to make balance
template <typename T>
void AVLTree<T>::updateHeight(AVLNode<T>* node) {
    if (node == nullptr) {
        return;
    }
    
    node->height = max(height(node->left), height(node->right)) + 1;
}

// left rotation
template <typename T>
AVLNode<T>* AVLTree<T>::rotateLeft(AVLNode<T>* node) {
    AVLNode<T>* rightChild = node->right;
    node->right = rightChild->left;
    rightChild->left = node;

    updateHeight(node);
    updateHeight(rightChild);
    
    return rightChild;
}

// right rotation
template <typename T>
AVLNode<T>* AVLTree<T>::rotateRight(AVLNode<T>* node) {
    AVLNode<T>* leftChild = node->left;
    node->left = leftChild->right;
    leftChild->right = node;
    
    updateHeight(node);
    updateHeight(leftChild);
    
    return leftChild;
}

// balance
template <typename T>
AVLNode<T>* AVLTree<T>::balance(AVLNode<T>* node) {
    if (node == nullptr) {
        return nullptr;
    }
    
    if (balanceFactor(node) == 2) {
        if (balanceFactor(node->right) < 0) {
            node->right = rotateRight(node->right);
        }
        
        return rotateLeft(node);
    }
    else if (balanceFactor(node) == -2) {
        if (balanceFactor(node->left) > 0) {
            node->left = rotateLeft(node->left);
        }
        
        return rotateRight(node);
    }
    
    return node;
}

// helper for recursive inorder function
template <typename T>
void AVLTree<T>::inorder() {
    // open file
    ofstream file;
    file.open("inorderAVL.txt");
    inorder(root, file);
    file.close();
}

template <typename T>
void AVLTree<T>::inorder(AVLNode<T>* node) {
    if (node == nullptr) {
        return;
    }
    
    inorder(node->left);
    cout << node->key << "\n";
    inorder(node->right);
}

// inorder to file
template <typename T>
void AVLTree<T>::inorder(AVLNode<T>* node, ofstream& file) {
    if (node == nullptr) {
        return;
    }
    
    inorder(node->left, file);
    file << node->key << "\n";
    inorder(node->right, file);
}


// helper for recursive preorder function
template <typename T>
void AVLTree<T>::preorder() {
    // open file
    ofstream file;
    file.open("preorderAVL.txt");
    preorder(root, file);
    file.close();
}

template <typename T>
void AVLTree<T>::preorder(AVLNode<T>* node) {
    if (node == nullptr) {
        return;
    }
    
    cout << node->key << "\n";
    preorder(node->left);
    preorder(node->right);
}

// preorder to file
template <typename T>
void AVLTree<T>::preorder(AVLNode<T>* node, ofstream& file) {
    if (node == nullptr) {
        return;
    }
    
    file << node->key << "\n";
    preorder(node->left, file);
    preorder(node->right, file);
}

template <typename T>
void AVLTree<T>::printTree() {
    // open file
    ofstream file;
    file.open("DrawAVLTree.txt");
    printTree(root, 0, file);
    file.close();
}

// pretty print
template <typename T>
void AVLTree<T>::printTree(AVLNode<T>* node, int indent, ofstream& file) {
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
int AVLTree<T>::getLeftHeight() {
    AVLNode<T>* node = root;
    int height = 0;
    while(node != nullptr) {
        height++;
        node = node->left;
    }

    return height - 1; // remove the first node
}

template <typename T>
int AVLTree<T>::getRightHeight() {
    AVLNode<T>* node = root;
    int height = 0;
    while(node != nullptr) {
        height++;
        node = node->right;
    }
    return height - 1; // remove the first node
}

#endif
