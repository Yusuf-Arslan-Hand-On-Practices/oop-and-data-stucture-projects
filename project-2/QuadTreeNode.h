#include <iostream>
#include <string>

using namespace std;

class QuadTreeNode
{
private:
    int x, y;
    QuadTreeNode *nw, *ne, *sw, *se;
    string value;
public:
    QuadTreeNode(int x, int y, string value);
    ~QuadTreeNode();
    void print();
};
