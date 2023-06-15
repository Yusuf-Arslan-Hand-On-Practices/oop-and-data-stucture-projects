#include "Person.h"

Person::Person(string name, string phone, string location)
{
    this->name = name;
    for (int i = 0; i < name.length(); i++)
    {
        this->name[i] = toupper(name[i]);
    }
    this->phone = phone;
    this->location = location;
}

Person::Person(string search)
{
    this->name = search;
    for (int i = 0; i < name.length(); i++)
    {
        name[i] = toupper(search[i]);
    }
}

Person::~Person() {}

string Person::getName()
{
    return name;
}

string Person::getPhone()
{
    return phone;
}

string Person::getLocation()
{
    return location;
}

bool Person::operator<(const Person &other)
{
    return name < other.name;
}

bool Person::operator>(const Person &other)
{
    return name > other.name;
}

bool Person::operator==(const Person &other)
{
    return name == other.name;
}

bool Person::operator!=(const Person &other)
{
    return name != other.name;
}

ostream &operator<<(ostream &os, const Person &contact)
{
    os << contact.name << " " << contact.phone << " " << contact.location;
    return os;
}