#include <iostream>
#include <string>

#include "Hours.h"

using namespace std;

#ifndef ANIMAL_H
#define ANIMAL_H
// Animal class that represents an animal
class Animal
{
    protected:
        string id;
        string animalName;
        string ownerName;
        string ownerSurname;
        Hours totalHours;
        int totalMins;
    public:
        // constructors
        Animal() : id(""), animalName(""), ownerName(""), ownerSurname(""), totalHours(0, 0), totalMins(0) {}
        Animal(string id, string animalName, string ownerName, string ownerSurname);
        // calculate the total minutes
        int calculateMinutes(const Hours& checkin, const Hours& checkout);
};

// constructor
Animal::Animal(string id, string animalName, string ownerName, string ownerSurname)
{
    this->id = id;
    this->animalName = animalName;
    this->ownerName = ownerName;
    this->ownerSurname = ownerSurname;
}

// calculate the total minutes
int Animal::calculateMinutes(const Hours& checkin, const Hours& checkout)
{
    // If hours are same and checkout is after checkin
    if (checkout.hour == checkin.hour && checkout.minute > checkin.minute)
    {
        this->totalMins = checkout.minute - checkin.minute;
    }
    // If checkout hour is after checkin hour
    else if (checkout.hour > checkin.hour)
    {
        this->totalMins = (checkout.hour - checkin.hour) * 60 + checkout.minute - checkin.minute;
    }
    else
    {
        // Return -1 to time control
        return -1;
    }
    return this->totalMins;
}

#endif

