#include <iostream>
#include <string>

using namespace std;

struct tree_node {
    int time;
    string activity;
    tree_node *right;
    tree_node *left;
    tree_node *parent;
    tree_node(int t, const string &a) : time(t), activity(a),
    right(nullptr), left(nullptr),
    parent(nullptr) {}
};

// Helper functions
// Check if time is valid
bool isTimeValid(int time);

// Return the string representation of a time
string numToTime(int number);

// Fill a string with zeros
string fillWithZeros(int num_zeros, const string& input);

// Free function to avoid garbage collection
void free(tree_node *node);


// Define the ActivityBST class here
class ActivityBST {
    private:
        tree_node *root;
        void insert(tree_node *node, tree_node *new_node);
        void appendAll(ActivityBST &bst, tree_node *node) const;
        void printInOrder(tree_node *node, ostream &out) const;
    public:
        ActivityBST() : root(nullptr) {}
        ActivityBST(const ActivityBST &bst);
        ~ActivityBST() { free(root); }
        void add(int time, const string &activity);
        // Overload assignment operator
        ActivityBST &operator=(const ActivityBST &bst);
        // Overload + operator
        ActivityBST operator+(const ActivityBST &bst) const;
        // Overload += operator
        ActivityBST &operator+=(const ActivityBST &bst);
        // Overload << operator
        friend ostream &operator<<(ostream &os, const ActivityBST &bst);
};

