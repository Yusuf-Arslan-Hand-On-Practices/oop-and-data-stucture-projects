#include <stdio.h>
#include <stdlib.h>

// Implementation of AVL Tree with C language
// AVL nodes contains data, height, left child, right child and parent
typedef struct AVLNode {
    int data;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
    struct AVLNode *parent;
} AVLNode;

// Create a new AVL node
AVLNode *createAVLNode(int data) {
    AVLNode *newNode = (AVLNode *) malloc(sizeof(AVLNode));
    newNode->data = data;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

// Get the height of the node
int getHeight(AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Get the balance factor of the node
int getBalanceFactor(AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Update the height of the node
void updateHeight(AVLNode *node) {
    node->height = (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right)) + 1;
}

// Right rotation
void rightRotate(AVLNode **root, AVLNode *x) {
    AVLNode *y = x->left;
    x->left = y->right;
    if (y->right != NULL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
    updateHeight(x);
    updateHeight(y);
}

// Left rotation
void leftRotate(AVLNode **root, AVLNode *x) {
    AVLNode *y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
    updateHeight(x);
    updateHeight(y);
}

// Insert a node into the AVL tree
void insertAVLNode(AVLNode **root, AVLNode *node) {
    if (*root == NULL) {
        *root = node;
    } else {
        AVLNode *temp = *root;
        while (temp != NULL) {
            if (node->data < temp->data) {
                if (temp->left == NULL) {
                    temp->left = node;
                    node->parent = temp;
                    break;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = node;
                    node->parent = temp;
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }
        while (temp != NULL) {
            updateHeight(temp);
            int balanceFactor = getBalanceFactor(temp);
            if (balanceFactor > 1 && getBalanceFactor(temp->left) >= 0) {
                rightRotate(root, temp);
            } else if (balanceFactor > 1 && getBalanceFactor(temp->left) < 0) {
                leftRotate(root, temp->left);
                rightRotate(root, temp);
            } else if (balanceFactor < -1 && getBalanceFactor(temp->right) <= 0) {
                leftRotate(root, temp);
            } else if (balanceFactor < -1 && getBalanceFactor(temp->right) > 0) {
                rightRotate(root, temp->right);
                leftRotate(root, temp);
            }
            temp = temp->parent;
        }
    }
}

// Inorder traversal of the AVL tree
void inOrder(AVLNode *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d\n", root->data);
    inOrder(root->right);
}

// print given level of the tree
void printGivenLevel(AVLNode *root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
        if (root->parent != NULL) {
            printf("(%d", root->parent->data);
            // find if left child of parent or right child of parent
            if (root->parent->left == root) {
                printf(" L) ");
            } else {
                printf(" R) ");
            }
        }
        // print balance factor
        printf("(%d B) ", getBalanceFactor(root));
    } else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

// print level order traversal of the tree
void printLevelOrder(AVLNode *root) {
    int h = getHeight(root);
    int i;
    for (i = 1; i <= h; i++) {
        printGivenLevel(root, i);
        printf("\n");
    }
}



// Driver code
int main() {
    AVLNode *root = NULL;
    insertAVLNode(&root, createAVLNode(72));
    insertAVLNode(&root, createAVLNode(18));
    insertAVLNode(&root, createAVLNode(28));
    insertAVLNode(&root, createAVLNode(36));
    insertAVLNode(&root, createAVLNode(27));
    insertAVLNode(&root, createAVLNode(117));
    insertAVLNode(&root, createAVLNode(108));
    insertAVLNode(&root, createAVLNode(90));

    printf("Inorder traversal of the AVL tree is:\n");
    inOrder(root);
    printf("Level order traversal of the AVL tree is:\n");
    printLevelOrder(root);

}




