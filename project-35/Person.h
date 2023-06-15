#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

/*
This is a header file defining a class called "Person". The class has private member variables name,
number, and location. It also has public member functions including constructors, destructor, getters for the private
member variables, and overloaded comparison operators.
*/
class Person
{
private:
    string name;
    string number;
    string location;

public:
    Person(string fullName, string phoneNumber, string location);
    Person(string search);
    Person();
    ~Person();
    string getName();
    string getNumber();
    string getLocation();
    bool operator<(const Person &other);
    bool operator>(const Person &other);
    bool operator==(const Person &other);
    bool operator!=(const Person &other);
    friend ostream &operator<<(ostream &os, const Person &contact);
};

#include "Person.cpp"

#endif