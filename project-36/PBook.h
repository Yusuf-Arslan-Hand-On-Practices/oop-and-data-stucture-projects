#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include "Person.h"
#include "BST.h"
#include "HashTable.h"

using namespace std;

#ifndef PBOOK
#define PBOOK

/* This is a class definition for a phone book. It contains private member variables `contactHTable` and `contactsBST`, 
which are a hash table and a binary search tree respectively, both containing `Person` objects. 
*/
class PBook {
private:
    HashTable<string, Person> contactHTable;
    BST<Person> contacsBST;
    void addToBST(Person contact);
    void addToHTable(Person contact);

public:
    PBook();
    ~PBook();
    void load(string filename);
    void add(Person contact);
    void remove(Person contact);
    void search(Person contact);
};


PBook::PBook() {
    contactHTable = HashTable<string, Person>();
    contacsBST = BST<Person>();
}

PBook::~PBook() {
    contactHTable.~HashTable();
    contacsBST.~BST();
}

void PBook::load(string filename) {
    ifstream file(filename);
    string firstname, lastname, phone, location;
    
    while (file >> firstname >> lastname >> phone >> location) {
        Person contact(firstname + " " + lastname, phone, location);
        addToBST(contact);
        addToHTable(contact);
    }

    file.close();
}

void PBook::add(Person contact) {
    cout << endl << "Adding an item to the phonebook BST ...";
    cout << endl << "=====================================" << endl;
    auto s = chrono::high_resolution_clock::now();
    addToBST(contact);
    auto e = chrono::high_resolution_clock::now();
    auto durationBST = chrono::duration_cast<chrono::microseconds>(e - s);
    cout << "Person has been added successfully to the BST" << endl;

    cout << endl << "Adding an item to the phonebook Hash Table ..." << endl;
    cout << "=====================================" << endl;
    s = chrono::high_resolution_clock::now();
    addToHTable(contact);
    e = chrono::high_resolution_clock::now();
    auto durationHTable = chrono::duration_cast<chrono::microseconds>(e - s);
    cout << "Person has been added successfully to the Hash Table" << endl;


    cout << endl << "Adding contact to the Binary Tree took " 
         << durationBST.count() * 1000.0 << " nanoseconds..." << endl;    

    cout << "Adding contact to the Hash Table took "
         << durationHTable.count() * 1000.0 << " nanoseconds..." << endl;

    cout << "Speed Up: " << durationBST.count() * 1000.0 / durationHTable.count() * 1000.0 << endl;

}


void PBook::addToBST(Person contact) {
    contacsBST.add(contact);
}

void PBook::addToHTable(Person contact) {
    contactHTable.add(contact.getName(), contact);
}

void PBook::remove(Person contact) {
    auto s = chrono::high_resolution_clock::now();
    contacsBST.remove(contact);
    auto e = chrono::high_resolution_clock::now();

    auto durationBST = chrono::duration_cast<chrono::microseconds>(e - s);

    s = chrono::high_resolution_clock::now();
    contactHTable.remove(contact.getName());
    e = chrono::high_resolution_clock::now();

    auto durationHTable = chrono::duration_cast<chrono::microseconds>(e - s);

    cout << endl << "Deleted successfully..." << endl;
    cout << endl
         << "Deletion from the Binary Tree took " << durationBST.count() * 1000.0 << " nanoseconds..." << endl;
    cout << "Deletion from the Hash Table took " << durationHTable.count() * 1000.0 << " nanoseconds..." << endl;

    cout << "Speed Up: " << (durationBST.count() * 1000.0) / (durationHTable.count() * 1000.0) << endl;
}

void PBook::search(Person contact) {
    cout << endl
         << "Searching an item in the phonebook (BST) ..." << endl;

    cout << endl
         << "Phonebook: Searching for: (" << contact.getName() << ")" << endl;
    cout << "=====================================" << endl;
    auto s = chrono::high_resolution_clock::now();
    Person result = contacsBST.search(contact);
    auto e = chrono::high_resolution_clock::now();
    auto durationBST = chrono::duration_cast<chrono::microseconds>(e - s);
    // print the contact
    if (result.getName() == "NULL") {
        cout << "Name not found!" << endl;
    } else {
        cout << result << endl;
    }

    cout << endl
         << "Searching an item in the phonebook (Hash Table) ..." << endl;

    cout << endl
            << "Phonebook: Searching for: (" << contact.getName() << ")" << endl;
    cout << "=====================================" << endl;

    s = chrono::high_resolution_clock::now();
    result = contactHTable.search(contact.getName());
    e = chrono::high_resolution_clock::now();
    auto durationHTable = chrono::duration_cast<chrono::microseconds>(e - s);
    // print the contact
    if (result.getName() == "NULL") {
        cout << "Name not found!" << endl;
    } else {
        cout << result << endl;
    }
    cout << endl
         << "The search in BST took " << durationBST.count() * 1000.0 << " nanoseconds..." << endl
         << "The search in Hash Table took " << durationHTable.count() * 1000.0 << " nanoseconds..." << endl
         << endl;

    cout << "Speed Up: " << (durationBST.count() * 1000.0) / (durationHTable.count() * 1000.0) << endl;
}


#endif