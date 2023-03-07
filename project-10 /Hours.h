#include <iostream>

using namespace std;

#ifndef HOURS_H
#define HOURS_H

// Hours class that represents the time of the day
class Hours
{
public:
    int hour;
    int minute;
    // constructors
    Hours() : hour(0), minute(0) {}
    Hours(int h, int m) : hour(h), minute(m) {}
    // Overload the << operator
    friend ostream& operator<<(ostream& os, const Hours& h);
    // Overload the >> operator
    friend istream& operator>>(istream& is, Hours& h);
};

#endif