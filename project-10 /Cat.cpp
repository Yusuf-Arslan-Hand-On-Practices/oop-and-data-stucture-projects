#include <iostream>
#include <string>

#include "Cat.h"
#include "Animal.h"
#include "Hours.h"

using namespace std;


// print the information of the cat
void Cat::printInfo()
{
    cout << "Id of the animal is " << this->id << endl;
    cout << "Name of the animal is " << this->animalName << endl;
    cout << "Name of the animal's owner is " << this->ownerName << endl;
    cout << "Surname of the animal's owner is " << this->ownerSurname << endl;
    cout << "Type of the animal is cat" << endl;
}
