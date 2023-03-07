// Header file of Flat class

#include <iostream>
#include <string>

using namespace std;

#ifndef FLAT_H
#define FLAT_H

namespace flt
{
    class Flat
    {
    private:
        int id;
        int initial_bandwidth;
        int is_empty;

    public:
        Flat(int id, int initial_bandwidth, int is_empty);
        ~Flat();
        int getId();
        int getInitialBandwidth();
        int getIsEmpty();
        void setInitialBandwidth(int initial_bandwidth);
        void setIsEmpty(int is_empty);
        std::string toString() const;

        // Overload the == operator
        bool operator==(const Flat& other) const;
        // Overload the != operator
        bool operator!=(const Flat& other) const;
    };
} // namespace flt

#include "Flat.cpp"

#endif // FLAT_H