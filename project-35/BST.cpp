#include "BST.h"

template <typename T>
BST<T>::BST()
{
    root = nullptr;
}

template <typename T>
BST<T>::~BST()
{
    destroy(root);
}

/* This is the implementation of the `destroy` function in a binary search tree (BST) class template. */
template <typename T>
void BST<T>::destroy(Node<T> *node)
{
    if (node == nullptr)
    {
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
}

/* This is the implementation of the `add` function in a binary search tree (BST) class template. */
template <typename T>
void BST<T>::add(T data)
{
    root = add(root, data);
}

/* This is the implementation of the `add` function in a binary search tree (BST) class template. It
takes a parameter `node` of type `Node<T>*` and a parameter `data` of type `T`. */
template <typename T>
Node<T> *BST<T>::add(Node<T> *node, T data)
{
    if (node == nullptr)
    {
        node = new Node<T>{data, nullptr, nullptr};
    }
    else if (data < node->data)
    {
        node->left = add(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = add(node->right, data);
    }
    return node;
}

/* This is the implementation of the `remove` function in a binary search tree (BST) class template. It
takes a parameter `data` of type `T` and removes the node with that data from the BST.  */
template <typename T>
void BST<T>::remove(T data)
{
    root = remove(root, data);
}

/* This is the implementation of the `remove` function in a binary search tree (BST) class template. It
takes a parameter `node` of type `Node<T>*` and a parameter `data` of type `T`. */
template <typename T>
Node<T> *BST<T>::remove(Node<T> *node, T data)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else if (data < node->data)
    {
        node->left = remove(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = remove(node->right, data);
    }
    else if (node->left != nullptr && node->right != nullptr)
    {
        node->data = findMin(node->right)->data;
        node->right = removeMin(node->right);
    }
    else
    {
        Node<T> *oldBSTNode = node;
        node = (node->left != nullptr) ? node->left : node->right;
        delete oldBSTNode;
    }
    return node;
}

/* This is the implementation of the `removeMin` function in a binary search tree (BST) class template. */
template <typename T>
Node<T> *BST<T>::removeMin(Node<T> *node)
{
    if (node->left == nullptr)
    {
        return node->right;
    }
    node->left = removeMin(node->left);
    return node;
}

/* This is the implementation of the `findMin` function in a binary search tree (BST) class template.
value (i.e., the leftmost node in the subtree). It then returns a pointer to that node. */
template <typename T>
Node<T> *BST<T>::findMin(Node<T> *node)
{
    if (node->left == nullptr)
    {
        return node;
    }
    return findMin(node->left);
}

/* This is the implementation of the search function in a binary search tree (BST) class template. It
takes a parameter `data` of type `T` and returns a value of type `T`. */
template <typename T>
T BST<T>::find(T data)
{
    Node<T> *node = root;
    while (node != nullptr)
    {
        if (data < node->data)
        {
            node = node->left;
        }
        else if (data > node->data)
        {
            node = node->right;
        }
        else
        {
            return node->data;
        }
    }
    return T();
}