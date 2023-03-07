// Header for Comparable class
// This class is used for the keep information about the
// Skyline's points
#include <iostream>

using namespace std;

#ifndef COMPARABLE_H
#define COMPARABLE_H

class Comparable
{
    private:
        int x;
        int x_;     
        int y;

    public:
        Comparable(int, int, int);
        int getX();
        int getX_();
        int getY();
        void print();
        // Overload operators
        bool operator<(Comparable);
        bool operator>(Comparable);
        bool operator==(Comparable);
        bool operator!=(Comparable);
        bool operator<=(Comparable);
        bool operator>=(Comparable);

        // Overload << operator
        friend ostream& operator<<(ostream& os, const Comparable& c)
        {
            os << "(" << c.x << ", " << c.x_ << ", " << c.y << ")";
            return os;
        }
};

#endif