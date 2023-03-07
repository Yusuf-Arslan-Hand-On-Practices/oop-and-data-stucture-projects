// Header file of an Apartment class

#include <iostream>
#include <string>
#include <vector>
#include "Flat.h"
#include "DoublyLinkedList.h"


#ifndef APARTMENT_H
#define APARTMENT_H

using namespace std;

namespace aprt
{
    class Apartment
    {
    private:
        string name;
        int max_bandwidth;
        dllist::DoublyLinkedList<flt::Flat> flats;

        // helper function
        int getTotalBandwidth();

    public:
        Apartment(string name, int max_bandwidth);
        ~Apartment();
        string getName();
        int getMaxBandwidth();
        void setName(string name);
        void setMaxBandwidth(int max_bandwidth);
        void addFlat(flt::Flat& flat, int pos);
        void makeFlatEmpty(int pos);
        string toString();

        // Overload the == operator
        bool operator==(const Apartment& other) const;
        // Overload the != operator
        bool operator!=(const Apartment& other) const;
        // Overload the << operator
    };
} // namespace aprt

#include "Apartment.cpp"
#endif // APARTMENT_H