#include "BST.h"

template <typename T>
BST<T>::BST() {
    root = nullptr;
}

template <typename T>
BST<T>::~BST() {
    destroy(root);
}

template <typename T>
void BST<T>::destroy(Node<T>* node) {
    if (node == nullptr) {
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
}

// Helper for add function
template <typename T>
void BST<T>::add(T data) {
    root = add(root, data);
}

template <typename T>
Node<T>* BST<T>::add(Node<T>* node, T data) {
    if (node == nullptr) {
        node = new Node<T>{data, nullptr, nullptr};
    }
    else if (data < node->data) {
        node->left = add(node->left, data);
    }
    else if (data > node->data) {
        node->right = add(node->right, data);
    }
    return node;
}

template <typename T>
void BST<T>::remove(T data) {
    root = remove(root, data);
}

template <typename T>
Node<T>* BST<T>::remove(Node<T>* node, T data) {
    if (node == nullptr) {
        return nullptr;
    } else if (data < node->data) {
        node->left = remove(node->left, data);
    } else if (data > node->data) {
        node->right = remove(node->right, data);
    } else if (node->left != nullptr && node->right != nullptr) {
        node->data = findMin(node->right)->data;
        node->right = removeMin(node->right);
    } else {
        Node<T>* oldNode = node;
        node = (node->left != nullptr) ? node->left : node->right;
        delete oldNode;
    }
    return node;
}

template <typename T>
Node<T>* BST<T>::removeMin(Node<T>* node) {
    if (node->left == nullptr) {
        return node->right;
    }
    node->left = removeMin(node->left);
    return node;
}

template <typename T>
Node<T>* BST<T>::findMin(Node<T>* node) {
    if (node->left == nullptr) {
        return node;
    }
    return findMin(node->left);
}

template <typename T>
T BST<T>::search(T data) {
    Node<T>* node = root;
    while (node != nullptr) {
        if (data < node->data) {
            node = node->left;
        } else if (data > node->data) {
            node = node->right;
        } else {
            return node->data;
        }
    }
    return T("NULL");
}