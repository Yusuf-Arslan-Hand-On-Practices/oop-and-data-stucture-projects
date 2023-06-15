#ifndef PERSON
#define PERSON

#include <iostream>
#include <string>

using namespace std;

/* This is a class definition for a `Person` class. It has private member
variables `name`, `phone`, and `location`, and public member functions including constructors,
destructor, getters for the member variables, and overloaded comparison operators.
*/
class Person
{
private:
    string name;
    string phone;
    string location;

public:
    Person(string name, string phone, string location);
    Person(string search);
    ~Person();
    string getName();
    string getPhone();
    string getLocation();
    bool operator<(const Person &other);
    bool operator>(const Person &other);
    bool operator==(const Person &other);
    bool operator!=(const Person &other);
    friend ostream &operator<<(ostream &os, const Person &contact);
};

#include "Person.cpp"

#endif