#include <iostream>
#include <string>

#include "QuadTreeNode.h"

using namespace std;

class QuadTree
{
private:
    QuadTreeNode *root;
    int height, width;
public:
    QuadTree(int height, int width);
    QuadTree(int height, int width, QuadTreeNode *root);
    ~QuadTree();
    void insert(int x, int y, QuadTreeNode *node);
    void print();
};