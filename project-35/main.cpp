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
     string filename, answer;

     cout << "Enter the file name: ";
     cin >> filename;
     phoneBook.loadFromFile(filename);
     cout << endl
          << endl;

     while (1)
     {
          cout << endl
               << "Choose which action to perform from 1 to 4:"
               << endl;
          cout << "1 - Search a phonebook contact"
               << endl;
          cout << "2 - Adding a phonebook contact"
               << endl;
          cout << "3 - Deleting a phonebook contact"
               << endl;
          cout << "4 - Press 4 to exit"
               << endl;

          cin >> answer;

          if (answer == "1")
          {
               string firstName, lastName;
               cout << "Search for a contact: ";
               cin >> firstName >> lastName;

               string name = firstName + " " + lastName;
               Person person(name);
               phoneBook.find(person);
          }
          else if (answer == "2")
          {
               cout << "Enter the information of the contact to be added:" << endl;
               string firstName, lastName, number, city;
               cout << endl
                    << "Name: ";
               cin >> firstName >> lastName;
               cout << endl
                    << "Tel: ";
               cin >> number;
               cout << endl
                    << "City: ";
               cin >> city;

               string name = firstName + " " + lastName;
               Person person(name, number, city);
               phoneBook.add(person);
          }
          else if (answer == "3")
          {
               cout << endl
                    << "Deleting an item from the phonebook ..." << endl;
               cout << "Enter the full name of the contact to be deleted: ";
               string firstName, lastName;
               cin >> firstName >> lastName;
               string name = firstName + " " + lastName;
               Person person(name);
               phoneBook.remove(person);
          }
          else if (answer == "4")
          {
               cout << "Program exiting..." << endl;
               break;
          }
     }
     return 0;
}
