#include <iostream>
#include <string>
#include <chrono>
#include "Person.h"
#include "BST.h"
#include "HashTable.h"

using namespace std;

#ifndef PBOOK
#define PBOOK

/*
    This is a class definition for a phone book (PBook)
    that contains private member variables `contactHTable` and `contactsBST` of types
    `HashTable<string, Person>` and `BST<Person>` respectively.
    It also has private member functions `addToBST` and `addToHTable` that take a `Person` object as input.
*/
class PBook
{
private:
    HashTable<string, Person> contactHTable;
    BST<Person> contacsBST;
    void addToBST(Person person);
    void addToHTable(Person person);

public:
    PBook();
    ~PBook();
    void loadFromFile(string filename);
    void add(Person person);
    void remove(Person person);
    void find(Person person);
};

#include "PBook.cpp"

#endif