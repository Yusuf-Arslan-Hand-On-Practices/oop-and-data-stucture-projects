// Implementation of the ActivityBST class

#include "activity_bst.h"

#include <iostream>

using namespace std;

// Helper Function Declarations
string fill_with_zeros(int num_zeros, const string& input);
string number_to_time(int number);
bool is_valid_time(int time);
void add_activity_helper(tree_node*& root, int time, const string& activity);
void print_activity_helper(tree_node* root, tree_node* prev, int time);
tree_node* get_first_activity(tree_node* root);
tree_node* get_last_activity(tree_node* root);
tree_node* get_smallest_greater_than(tree_node* root, tree_node* prev, int time);
tree_node* get_greatest_smaller_than(tree_node* root, tree_node* prev, int time);
void print_single_activity_helper(tree_node* root, const string& activity);


// Add an activity with name 'activity' and time 'time'
/**
 * If the root is null, create a new node and set it as the root. Otherwise, call the helper function
 * 
 * @param root a pointer to the root of the tree
 * @param time The time of the activity.
 * @param activity The activity to add
 * 
 * @return a pointer to a tree_node.
 */
void add_activity(tree_node *&root, int time, const string &activity)
{
    if (!is_valid_time(time))
    {
        cerr << "ERROR! Could not add activity 'act' due to illegal time value" << endl;
        return;
    }

    if (root == nullptr)
    {
        root = new tree_node(time, activity);
        root->parent = nullptr;
    }
    else
    {
        add_activity_helper(root, time, activity);
    }
    cout << "Added activity '" << activity << "' at " << number_to_time(time) << endl;
}

/**
 * If the time is less than the root's time, then add the activity to the left subtree, otherwise add
 * it to the right subtree
 * 
 * @param root the root of the tree
 * @param time the time of the activity
 * @param activity the activity to be added
 * 
 * @return a pointer to the root of the tree.
 */
void add_activity_helper(tree_node*& root, int time, const string& activity)
{
    if (root->time > time)
    {
        if (root->left == nullptr)
        {
            root->left = new tree_node(time, activity);
            root->left->parent = root;
            return;
        }
        add_activity_helper(root->left, time, activity);
    }
    else
    {
        if (root->right == nullptr)
        {
            root->right = new tree_node(time, activity);
            root->right->parent = root;
            return;
        }
        add_activity_helper(root->right, time, activity);
    }
}

// Print the name of the activity occurring at time 'time'
/**
 * The function prints the activity of the tree at the given time
 * 
 * @param root the root of the tree
 * @param time the time of the day to print the activity for
 * 
 * @return a pointer to a tree_node.
 */
void print_activity(tree_node *root, int time)
{
    if (!is_valid_time(time))
    {
        cerr << "ERROR! Could not print activity due to illegal time value" << endl;
        return;
    }
    print_activity_helper(root, nullptr, time);
}


/**
 * Traverse the tree inorder and find the interval that contains the time
 * 
 * @param root the root of the tree
 * @param prev the previous node that was visited
 * @param time the time you want to find the activity for
 * 
 * @return the activity that is happening at the time.
 */
void print_activity_helper(tree_node* root, tree_node* prev, int time)
{
    // Traver tree inorder and find the interval that contains the time
    if (root == nullptr)
    {
        if (prev == nullptr)
        {
            cout << "Time: " << number_to_time(time) << ", Activitiy: free" << endl;
            return;
        }
        cout << "Time: " << number_to_time(time) << ", Activitiy: " << prev->activity << endl;
        return;
    }
    if (time < root->time)
    {
        print_activity_helper(root->left, prev, time);
    }
    else
    {
        print_activity_helper(root->right, root, time);
    }
}


// Print the duration of the activity occurring at time 'time'
/**
 * It prints the activity and duration of the activity that is currently taking place at the given time
 * 
 * @param root the root of the tree
 * @param time the time to print the activity and duration for
 * 
 * @return the first activity in the tree.
 */
void print_activity_and_duration(tree_node *root, int time)
{
    if (!is_valid_time(time))
    {
        cerr << "ERROR! Could not print activity and duration due to illegal time value" << endl;
        return;
    }

    tree_node* first_activity = get_first_activity(root);
    if (time < first_activity->time)
    {
        cout << "Time period: [00:00 - " << number_to_time(first_activity->time) << "]: free" << endl;
        return;
    }

    tree_node* last_activity = get_last_activity(root);
    if (time >= last_activity->time)
    {
        cout << "Time period: [" << number_to_time(last_activity->time) << " - 00:00]: " << last_activity->activity << endl;
        return;
    }

    tree_node* next = get_smallest_greater_than(root, nullptr, time);
    tree_node* current = get_greatest_smaller_than(root, nullptr, time);
    // print the interval
    cout << "Time period: [" << number_to_time(current->time) << " - " << number_to_time(next->time) << "]: " << current->activity << endl;
}



// --------- Helper Functions ------------
/**
 * If the root is null, return null. If the root's left child is null, return the root. Otherwise,
 * return the first activity in the left subtree
 * 
 * @param root the root of the tree
 * 
 * @return The first activity in the tree.
 */
tree_node* get_first_activity(tree_node* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->left == nullptr)
    {
        return root;
    }
    return get_first_activity(root->left);
}

/**
 * If the root is null, return null. If the root's right child is null, return the root. Otherwise,
 * return the last activity of the root's right child
 * 
 * @param root the root of the tree
 * 
 * @return The last activity in the tree.
 */
tree_node* get_last_activity(tree_node* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->right == nullptr)
    {
        return root;
    }
    return get_last_activity(root->right);
}

/**
 * If the root is null, return the previous node. If the root's time is greater than the time, return
 * the smallest greater than the root's left child. Otherwise, return the smallest greater than the
 * root's right child
 * 
 * @param root the root of the tree
 * @param prev the previous node that was visited
 * @param time the time we're looking for
 * 
 * @return The smallest node greater than the given time.
 */
tree_node* get_smallest_greater_than(tree_node* root, tree_node* prev, int time)
{
    if (root == nullptr)
    {
        return prev;
    }
    if (root->time > time)
    {
        return get_smallest_greater_than(root->left, root, time);
    }
    return get_smallest_greater_than(root->right, prev, time);
}

/**
 * Traverses the tree in reverse inorder and finds the greatest node smaller and equal than the time.
 * 
 * @param root The root of the tree
 * @param prev the previous node that was visited
 * @param time the time we want to find the greatest node smaller than
 * 
 * @return The greatest node smaller than time.
 */
tree_node* get_greatest_smaller_than(tree_node* root, tree_node* prev, int time)
{
    // !! Traverses the tree in reverse inorder and finds the greatest node smaller and -- equal -- than time !!
    if (root == nullptr)
    {
        return prev;
    }
    if (root->time <= time)
    {
        return get_greatest_smaller_than(root->right, root, time);
    }
    return get_greatest_smaller_than(root->left, prev, time);
}
// --------- Helper Functions - End ------------


// Print the duration of every occurrence of activity 'activity'
/**
 * Print the duration of every occurrence of activity 'activity'
 * 
 * @param root the root of the tree
 * @param activity The activity to print.
 */
void print_single_activity(tree_node *root, const string &activity)
{
    if (activity == "free")
    {
        tree_node* first_activity = get_first_activity(root);
        cout << "Time period: [00:00 - " << number_to_time(first_activity->time) << "]: free" << endl;
        // Because user can enter 'free' as activity, I don't return here.
    }

    print_single_activity_helper(root, activity);
}

/**
 * Print the duration of every occurrence of activity 'activity'
 * 
 * @param root The root of the tree
 * @param activity The activity to print
 * 
 * @return the smallest node in the tree that is greater than the given time.
 */
void print_single_activity_helper(tree_node* root, const string& activity)
{
    // Print the activities in inorder to make it chronological
    if (root == nullptr)
    {
        return;
    }
    print_single_activity_helper(root->left, activity);

    if (root->activity == activity)
    {
        tree_node* next = get_smallest_greater_than(root, nullptr, root->time);
        cout << "Time period: [" << number_to_time(root->time) << " - " << number_to_time(next->time) << "]: " << root->activity << endl;
    }
    
    print_single_activity_helper(root->right, activity);
}

// Print the starting time of every activity
/**
 * If the root is not null, print all the activities in the left subtree, print the activity at the
 * root, then print all the activities in the right subtree
 * 
 * @param root The root of the tree.
 * 
 * @return the number of activities that are in the tree.
 */
void print_all_activities(tree_node *root)
{
    // Traverse the tree inorder and print the activities in chronological order
    if (root == nullptr)
    {
        return;
    }
    print_all_activities(root->left);
    cout << "[" << number_to_time(root->time) << "] - " << root->activity << endl;
    print_all_activities(root->right);
}


// Delete the tree pointed at by `root`
/**
 * If the root is null, return. Otherwise, delete the left subtree, delete the right subtree, and
 * delete the root
 * 
 * @param root The root of the tree to be deleted.
 * 
 * @return the number of nodes in the tree.
 */
void delete_tree(tree_node *root)
{
    if (root == nullptr)
    {
        return;
    }
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}


//  ---------- HELPER FUNCTIONS ----------
/**
 * It takes a number of zeros to add and a string, and returns a string with the number of zeros added
 * to the front of the string
 * 
 * @param num_zeros The number of zeros you want to add to the string.
 * @param input The string to be padded with zeros.
 * 
 * @return a string of zeros and the input string.
 */
string fill_with_zeros(int num_zeros, const string& input)
{ 
    int zeros_to_add = num_zeros - input.length(); 
    if (zeros_to_add < 0) zeros_to_add = 0; 
        return string(zeros_to_add, '0') + input;
}

/**
 * It takes a number and converts it to a string of the format HH:MM
 * 
 * @param number The number to be converted to time.
 * 
 * @return a string that is the time in the format of HH:MM.
 */
string number_to_time(int number)
{ 
    return fill_with_zeros(2, to_string(number/100))+":"+ fill_with_zeros(2, to_string(number%100)); 
}

/**
 * If the time is less than 0 or greater than 2359, or if the time's minutes are greater than 59, then
 * the time is invalid.
 * 
 * @param time The time to be checked.
 * 
 * @return a boolean value.
 */
bool is_valid_time(int time)
{
    bool valid = true;

    if (time < 0 || time > 2359) valid = false;
    if (time % 100 > 59) valid = false;

    return valid;
}
