// Implementation of an Street class

#include "Street.h"

namespace strt
{
    Street::Street() = default;

    Street::~Street() = default;

    void Street::add_apartment(Apartment& apartment, string pos)
    {
        if (pos == "head")
        {
            apartments.insertHead(&apartment);
            return;
        }

        // Tokenize the string with the delimiter '_'
        // The first token is status and other token is apartment name
        char* token = strtok((char*) pos.c_str(), "_");
        string status = token;

        token = strtok(NULL, "");
        string apartment_name = token;
      
        Apartment *target = new Apartment(apartment_name, -1);

        if (status == "before")
        {
            apartments.insertBefore(&apartment, target);
        }
        else if (status == "after")
        {
            apartments.insertAfter(&apartment, target);
        }
        else
        {
            cout << "Invalid position" << endl;
        }
    }

    void Street::remove_apartment(string name)
    {
        Apartment *target = new Apartment(name, -1);
        apartments.removeIfEqual(target);
    }

    void Street::add_flat(Flat& flat, string apartment_name, int pos)
    {
        int index = apartments.getPosition(new Apartment(apartment_name, -1));
        Apartment *apartment = apartments.getData(index);
        apartment->addFlat(flat, pos);
    }

    void Street::make_flat_empty(string apartment_name, int pos)
    {
        int index = apartments.getPosition(new Apartment(apartment_name, -1));
        Apartment *apartment = apartments.getData(index);
        apartment->makeFlatEmpty(pos);
    }

    string Street::list_apartments()
    {
        cout << "List of apartments:" << endl;
        // size
        string result = "";
        for (int i = 0; i < apartments.getSize(); i++)
        {
            Apartment *apartment = apartments.getData(i);
            result += apartment->toString() + "\n";
        }
        return result;
    }

}