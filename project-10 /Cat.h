#include <iostream>
#include <string>

#include "Animal.h"
#include "Hours.h"

using namespace std;

#ifndef CAT_H
#define CAT_H

// Cat class inherits from Animal class
class Cat : public Animal
{
    protected:
        string type;
    public:
        Cat() : Animal(), type("") {}
        Cat(string id, string animalName, string ownerName, string ownerSurname, string type) : Animal(id, animalName, ownerName, ownerSurname), type(type) {}
        void printInfo();
};

#endif
