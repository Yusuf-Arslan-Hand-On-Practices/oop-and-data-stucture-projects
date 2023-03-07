// This file includes the information about the Skylines.
// It contains x, x' and y values. 
// Comparision operators are overloaded.
#include <iostream>

using namespace std;

class Comparable
{
    private:
        int x;
        int x1;
        int y;
    public:
        Comparable(int x, int y, int x1);
        int getX();
        int getX1();
        int getY();
        void setX(int x);
        void setX1(int x1);
        void setY(int y);
        bool operator<(const Comparable &c) const;
        bool operator>(const Comparable &c) const;
        bool operator==(const Comparable &c) const;
        bool operator!=(const Comparable &c) const;
        bool operator<=(const Comparable &c) const;
        bool operator>=(const Comparable &c) const;
        friend ostream& operator<<(ostream& os, const Comparable& c);
};
// Default constructor
Comparable::Comparable(int x, int y, int x1)
{
    this->x = x;
    this->y = y;
    this->x1 = x1;
}

// Getters
int Comparable::getX()
{
    return x;
}

int Comparable::getX1()
{
    return x1;
}

int Comparable::getY()
{
    return y;
}

// Setters
void Comparable::setX(int x)
{
    this->x = x;
}

void Comparable::setX1(int x1)
{
    this->x1 = x1;
}

void Comparable::setY(int y)
{
    this->y = y;
}

// Overloaded operators
// < operator compares to x values to make min heap
bool Comparable::operator<(const Comparable &c) const
{
    if (x == c.x)
    {
        // Print skyline in the order of y values
        return (y > c.y);
    }
    return (x < c.x);
}

// > operator
bool Comparable::operator>(const Comparable &c) const
{
    return (x1 > c.x1);
}

// == operator
bool Comparable::operator==(const Comparable &c) const
{
    return (x == c.x);
}

// != operator
bool Comparable::operator!=(const Comparable &c) const
{
    return (x != c.x);
}

// <= operator
bool Comparable::operator<=(const Comparable &c) const
{
    return (x <= c.x);
}

// >= operator
bool Comparable::operator>=(const Comparable &c) const
{
    return (x >= c.x);
}

// << operator
ostream& operator<<(ostream& os, const Comparable& c)
{
    os << c.x << " " << c.x1 << " " << c.y;
    return os;
}

