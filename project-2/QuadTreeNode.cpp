#include "QuadTreeNode.h"


QuadTreeNode::QuadTreeNode(int x, int y, string value)
{
    this->x = x;
    this->y = y;
    this->value = value;
    this->nw = NULL;
    this->ne = NULL;
    this->sw = NULL;
    this->se = NULL;
}