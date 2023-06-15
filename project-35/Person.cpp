#include "Person.h"

/**
 * This is a constructor for the Person class that initializes the name, number, and location variables
 * to default values.
 */
Person::Person()
{
    name = "NULL";
    number = "";
    location = "";
}

/**
 * The function initializes a Person object with a given name, number, and location, and converts the
 * name to uppercase.
 */
Person::Person(string name, string number, string location)
{
    this->name = name;
    for (int i = 0; i < name.length(); i++)
    {
        this->name[i] = toupper(name[i]);
    }
    this->number = number;
    this->location = location;
}

/**
 * The function takes a string input and converts it to uppercase letters.
 * Then assigns it to the name
 */
Person::Person(string search)
{
    this->name = search;
    for (int i = 0; i < name.length(); i++)
    {
        name[i] = toupper(search[i]);
    }
}

Person::~Person()
{
    // Nothing to do
}

/**
 * The function returns the name of a Person object.
 */
string Person::getName()
{
    return name;
}

/**
 * The function returns the phone number of a person object.
 */
string Person::getNumber()
{
    return number;
}

/**
 * The function returns the location of a person.
 */
string Person::getLocation()
{
    return location;
}

/**
 * This is an implementation of the less than operator for the Person class, which compares the names
 * of two Person objects.
 */
bool Person::operator<(const Person &other)
{
    return name < other.name;
}

/**
 * The function overloads the ">" operator for the Person class to compare names.
 */
bool Person::operator>(const Person &other)
{
    return name > other.name;
}

/**
 * The function checks if two Person objects have the same name.
 */
bool Person::operator==(const Person &other)
{
    return name == other.name;
}

/**
 * The function defines the inequality operator for the Person class by comparing the names of two
 * Person objects.
 */
bool Person::operator!=(const Person &other)
{
    return name != other.name;
}

/**
 * This is an overloaded operator function that outputs the name, number, and location of a Person
 * object to an output stream.
 */
ostream &operator<<(ostream &os, const Person &contact)
{
    os << contact.name << " " << contact.number << " " << contact.location;
    return os;
}