// Head file of street class

#include <iostream>
#include <string>
#include <vector>
#include "Apartment.h"
#include "Flat.h"
#include "CircularLinkedList.h"

using namespace std;

using namespace aprt;
using namespace flt;

#ifndef STREET_H
#define STREET_H

namespace strt
{
    class Street
    {
    private:
        cllist::CircularLinkedList<Apartment> apartments;
    public:
        Street();
        ~Street();
        void add_apartment(Apartment& apartment, string pos);
        void remove_apartment(string name);
        void add_flat(Flat& flat, string apartment_name, int pos);
        void make_flat_empty(string apartment_name, int pos);
        int find_sum_of_max_bandwidth();
        void merge_two_apartments(string name1, string name2);
        void relocate_flats_to_same_apartment(int TODO);
        string list_apartments();
    };
} // namespace strt

#include "Street.cpp"
#endif // STREET_H