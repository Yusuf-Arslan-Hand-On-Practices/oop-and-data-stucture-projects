#include <iostream>
#include "Hours.h"

using namespace std;

// implementation of the << operator
ostream& operator<<(ostream& os, const Hours& h)
{
    os << h.hour << ":" << h.minute;
    return os;
}

// implementation of the >> operator
istream& operator>>(istream& is, Hours& h)
{
    is >> h.hour >> h.minute;
    return is;
}

