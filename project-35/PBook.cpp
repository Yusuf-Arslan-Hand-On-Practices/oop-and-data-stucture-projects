#include "PBook.h"

PBook::PBook() {}

PBook::~PBook() {}

/**
 * This function loads data from a file and adds it to a binary search tree and a hash table.
 */
void PBook::loadFromFile(string filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error opening file..." << endl;
        exit(1);
    }
    string firstname, lastname, phone, location;
    while (file >> firstname >> lastname >> phone >> location)
    {
        string name = firstname + " " + lastname;
        Person person(name, phone, location);
        addToBST(person);
        addToHTable(person);
    }
    file.close();
}

/**
 * The function adds a person to both a binary search tree and a hash table, and measures the time it
 * takes to add to each data structure.
 */
void PBook::add(Person person)
{
    cout << endl
         << "Adding an item to the phonebook BST ...";
    cout << endl
         << "=====================================" << endl;
    cout << "Person has been added successfuly to the BST" << endl;
    auto s = chrono::high_resolution_clock::now();
    addToBST(person);
    auto e = chrono::high_resolution_clock::now();
    auto durationBST = chrono::duration_cast<chrono::microseconds>(e - s);

    cout << endl
         << "Adding an item to the phonebook Hash Table ..." << endl;
    cout << "=====================================" << endl;
    cout << "Person has been added successfuly to the Hash Table" << endl;
    s = chrono::high_resolution_clock::now();
    addToHTable(person);
    e = chrono::high_resolution_clock::now();
    auto durationHTable = chrono::duration_cast<chrono::microseconds>(e - s);

    cout << endl
         << "Adding person to the Binary Tree took ";
    cout << durationBST.count() * 1000.0 << " nanoseconds..." << endl;

    cout << "Adding person to the Hash Table took ";
    cout << durationHTable.count() * 1000.0 << " nanoseconds..." << endl;

    cout << "Speed Up: " << durationBST.count() * 1000.0 / durationHTable.count() * 1000.0 << endl;
}

/**
 * This function adds a person to a binary search tree in a phone book.
 */
void PBook::addToBST(Person person)
{
    contacsBST.add(person);
}

/**
 * This function adds a person object to a hash table using their full name as the key.
 */
void PBook::addToHTable(Person person)
{
    contactHTable.add(person.getName(), person);
}

/**
 * The function removes a person from both a binary search tree and a hash table, and measures the time
 * it takes for each operation.
 */
void PBook::remove(Person person)
{
    auto s = chrono::high_resolution_clock::now();
    contacsBST.remove(person);
    auto e = chrono::high_resolution_clock::now();

    auto durationBST = chrono::duration_cast<chrono::microseconds>(e - s);

    s = chrono::high_resolution_clock::now();
    contactHTable.remove(person.getName());
    e = chrono::high_resolution_clock::now();

    auto durationHTable = chrono::duration_cast<chrono::microseconds>(e - s);

    cout << endl
         << "Deleted successfuly..." << endl;
    cout << endl;
    cout << "Deletion from the BST took " << durationBST.count() * 1000.0 << " nanoseconds..." << endl;
    cout << "Deletion from the Hash Table took " << durationHTable.count() * 1000.0 << " nanoseconds..." << endl;

    cout << "Speed Up: " << (durationBST.count() * 1000.0) / (durationHTable.count() * 1000.0) << endl;
}

/**
 * The function searches for a person in a phonebook using both a binary search tree and a hash table,
 * and outputs the results and the time taken for each search.
 */
void PBook::find(Person person)
{
    cout << endl
         << "Searching an item in the phonebook (BST) ..." << endl;

    cout << endl
         << "Phonebook: Searching for: (" << person.getName() << ")" << endl;
    cout << "=====================================" << endl;
    auto s = chrono::high_resolution_clock::now();
    Person result = contacsBST.find(person);
    auto e = chrono::high_resolution_clock::now();
    auto durationBST = chrono::duration_cast<chrono::microseconds>(e - s);
    if (result.getName() == "NULL")
    {
        cout << "Name not found!" << endl;
    }
    else
    {
        cout << result << endl;
    }

    cout << endl
         << "Searching an item in the phonebook (Hash Table) ..." << endl;

    cout << endl
         << "Phonebook: Searching for: (" << person.getName() << ")" << endl;
    cout << "=====================================" << endl;

    s = chrono::high_resolution_clock::now();
    result = contactHTable.find(person.getName());
    e = chrono::high_resolution_clock::now();
    auto durationHTable = chrono::duration_cast<chrono::microseconds>(e - s);
    if (result.getName() == "NULL")
    {
        cout << "Name not found!" << endl;
    }
    else
    {
        cout << result << endl;
    }
    cout << endl
         << "The search in BST took " << durationBST.count() * 1000.0 << " nanoseconds..." << endl
         << "The search in Hash Table took " << durationHTable.count() * 1000.0 << " nanoseconds..." << endl
         << endl;

    cout << "Speed Up: " << (durationBST.count() * 1000.0) / (durationHTable.count() * 1000.0) << endl;
}