#include <iostream>
#include <string>
#include "AVLTree.h"
#include "BSTree.h"
#include "Contact.h"
#include "PhoneBook.h"


using namespace std;

int main(int argc, char const *argv[]) {
    PhoneBook phoneBook;
    string input;

    cout << "Please enter the contact file name: ";
    cin >> input;
    phoneBook.load(input);
    cout << endl;
    // phoneBook.print();

    while (1) {
        cout << endl 
             << "Choose which action to perform from 1 to 6:" << endl;
        cout << "1 - Search a phonebook contact" << endl;
        cout << "2 - Adding a phonebook contact" << endl;
        cout << "3 - Deleting a phonebook contact" << endl;
        cout << "4 - Print the phonebook to a file(inorder)" << endl;
        cout << "    Print the phonebook to a file(preorder)" << endl;
        cout << "5 - Draw the phonebook as a Tree to a file" << endl;
        cout << "6 - Press 6 to exit" << endl;
        cin >> input;

        if (input == "1") {
            cout << "Search for a contact: ";
            cin >> input;
            Contact contact(input);
            phoneBook.search(contact);
        }
        else if (input == "2") {
            cout << "Enter the information of the contact to be added:" << endl;
            string firstName, lastName, phone, city;
            cout << endl << "Name: ";
            cin >> firstName >> lastName;
            cout << endl
                 << "Tel: ";
            cin >> phone;
            cout << endl << "City: ";
            cin >> city;
            Contact contact(firstName + " " + lastName, phone, city);
            phoneBook.insert(contact);
        }
        else if (input == "3") {
            cout << endl
                 << "Deleting an item from the phonebook . . ." << endl;
            cout << "Enter the full name of the contact to be deleted: ";
            cin >> input;
            Contact contact(input);
            phoneBook.remove(contact);
        }
        else if (input == "4") {
            cout << "Printing the phonebook to a file. . ." << endl;
            phoneBook.printInOrder();
            phoneBook.printPreOrder();
        }
        else if (input == "5") {
            cout << "Drawing the phonebook as a Tree to a file. . ." << endl;
            phoneBook.printAVL();
            phoneBook.printBST();
        }
        else if (input == "6") {
            cout << "Exiting the program. . ." << endl;
            break;
        }
    }
    return 0;
}
