// Implementation of Comparable class
#include <iostream>
#include "comparable.h"

using namespace std;

// Constructor
Comparable::Comparable(int x, int x_, int y)
{
    this->x = x;
    this->x_ = x_;
    this->y = y;
}

// Get x
int Comparable::getX()
{
    return x;
}

// Get x_
int Comparable::getX_()
{
    return x_;
}

// Get y
int Comparable::getY()
{
    return y;
}

// Print the Comparable object
void Comparable::print()
{
    cout << "(" << x << ", " << x_ << ", " << y << ")" << endl;
}

// Overload operators

// Less than, compares only the x value.
// Because Skylines will be inserted to the head according to their
// leftmost x value. 
bool Comparable::operator<(Comparable c)
{
    return x < c.x;
}

// Greater than, compares only the y value.
// It will used for getMax() function to find heighest skyline.
bool Comparable::operator>(Comparable c)
{
    return y > c.y;
}

// Equal, compares only the x value.
// it will be used for insert function to find correct position
// to insert skyline inorder to keep the list sorted.
bool Comparable::operator==(Comparable c)
{
    return x == c.x;
}

// Not equal, compares only the x value.
// Same as above.
bool Comparable::operator!=(Comparable c)
{
    return x != c.x;
}

// Less than or equal, compares only the x value.
bool Comparable::operator<=(Comparable c)
{
    return x <= c.x;
}

// Greater than or equal, compares only the x value.
bool Comparable::operator>=(Comparable c)
{
    return x >= c.x;
}
