#include <iostream>
#include <string>
#include "HashTable.h"
#include "BST.h"
#include "Person.h"
#include "PBook.h"

using namespace std;

int main()
{
    PBook phoneBook;
    string input;

    cout << "Enter the file name: ";
    cin >> input;
    phoneBook.load(input);
    cout << endl;

    while (1)
    {
        cout << endl
             << "Choose which action to perform from 1 to 4:" << endl;
        cout << "1 - Search a phonebook contact" << endl;
        cout << "2 - Adding a phonebook contact" << endl;
        cout << "3 - Deleting a phonebook contact" << endl;
        cout << "4 - Press 4 to exit" << endl;
        cin >> input;

        if (input == "1")
        {
            string firstName;
            string lastName;
            cout << "Search for a contact: ";
            cin >> firstName >> lastName;
            Person contact(firstName + " " + lastName);
            phoneBook.search(contact);
        }
        else if (input == "2")
        {
            cout << "Enter the information of the contact to be added:" << endl;
            string firstName, lastName, phone, city;
            cout << endl
                 << "Name: ";
            cin >> firstName >> lastName;
            cout << endl
                 << "Tel: ";
            cin >> phone;
            cout << endl
                 << "City: ";
            cin >> city;
            Person contact(firstName + " " + lastName, phone, city);
            phoneBook.add(contact);
        }
        else if (input == "3")
        {
            cout << endl
                 << "Deleting an item from the phonebook . . ." << endl;
            cout << "Enter the full name of the contact to be deleted: ";
            string firstName, lastName;
            cin >> firstName >> lastName;
            Person contact(firstName + " " + lastName);
            phoneBook.remove(contact);
        }
        else if (input == "4")
        {
            cout << "Exiting the program. . ." << endl;
            break;
        }
    }
    return 0;
}
