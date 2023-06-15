#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include "Contact.h"
#include "BSTree.h"
#include "AVLTree.h"

using namespace std;

#ifndef PBOOK
#define PBOOK

class PhoneBook {
private:
    AVLTree<Contact> contactsAVL;
    BSTree<Contact> contacsBST;
    void insertToAVL(Contact contact);
    void insertToBST(Contact contact);

public:
    PhoneBook();
    ~PhoneBook();
    void load(string filename);
    void insert(Contact contact);
    void remove(Contact contact);
    void search(Contact contact);
    void searchAll(Contact contact);
    void printInOrder();
    void printPreOrder();
    void printAVL();
    void printBST();
};


PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

void PhoneBook::load(string filename) {
    ifstream file(filename);
    string firstname, lastname, phone, location;

    // load to BST
    cout << "Loading the phonebook into a BST." << endl;
    auto start = chrono::high_resolution_clock::now();
    while (file >> firstname >> lastname >> phone >> location) {
        Contact contact(firstname + " " + lastname, phone, location);
        insertToBST(contact);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Phonebook creation in BST took " << duration.count() / 1000.0 << " milliseconds. . ." << endl;
    cout << "The tree is not balanced." << endl;
    cout << "The heights of BST are for left: " << contacsBST.getLeftHeight() << 
            " and right: " << contacsBST.getRightHeight() << endl;

    file.close();

    // load to AVL
    file.open(filename);
    cout << "Loading the phonebook into an AVL." << endl;
    start = chrono::high_resolution_clock::now();
    while (file >> firstname >> lastname >> phone >> location) {
        Contact contact(firstname + " " + lastname, phone, location);
        insertToAVL(contact);
    }
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Phonebook creation in AVL took " << duration.count() / 1000.0 << " milliseconds. . ." << endl;
    cout << "The tree is balanced." << endl;
    cout << "The heights of AVL are for left: " << contactsAVL.getLeftHeight() << 
            " and right: " << contactsAVL.getRightHeight() << endl;

    file.close();
}

void PhoneBook::insert(Contact contact) {
    cout << endl << "Adding an item to the phonebook BST . . .";
    cout << "====================================" << endl;
    cout << "Contact has been added successfully to the BST" << endl;
    auto start = chrono::high_resolution_clock::now();
    insertToBST(contact);
    auto end = chrono::high_resolution_clock::now();
    auto durationBST = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << endl << "Adding an item to the phonebook AVL . . ." << endl;
    cout << "====================================" << endl;
    cout << "Contact has been added successfully to the AVL Tree" << endl;
    start = chrono::high_resolution_clock::now();
    insertToAVL(contact);
    end = chrono::high_resolution_clock::now();
    auto durationAVL = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << endl << "Adding contact to the Binary Tree took " 
         << durationBST.count() * 1000.0 << " nanoseconds. . ." << endl;    

    cout << "Adding contact to the AVL Tree took "
         << durationAVL.count() * 1000.0 << " nanoseconds. . ." << endl;
}

void PhoneBook::insertToAVL(Contact contact) {
    contactsAVL.insert(contact);
}

void PhoneBook::insertToBST(Contact contact) {
    contacsBST.insert(contact);
}

void PhoneBook::remove(Contact contact) {
    auto start = chrono::high_resolution_clock::now();
    contacsBST.remove(contact);
    auto end = chrono::high_resolution_clock::now();

    auto durationBST = chrono::duration_cast<chrono::microseconds>(end - start);

    start = chrono::high_resolution_clock::now();
    contactsAVL.remove(contact);
    end = chrono::high_resolution_clock::now();

    auto durationAVL = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << endl << "Deleted successfully. . ." << endl;
    cout << endl
         << "Deletion from the Binary Tree took " << durationBST.count() * 1000.0 << " nanoseconds. . ." << endl;
    cout << "Deletion from the AVL Tree took " << durationAVL.count() * 1000.0 << " nanoseconds. . ." << endl;
}

void PhoneBook::search(Contact contact) {
    cout << endl
         << "Searching an item in the phonebook (BST) . . ." << endl;

    cout << endl
         << "Phonebook: Searching for: (" << contact.getFullName() << ")" << endl;
    cout << "====================================" << endl;
    auto start = chrono::high_resolution_clock::now();
    vector<Contact> contacts = contacsBST.searchAll(contact);
    auto end = chrono::high_resolution_clock::now();
    auto durationBST = chrono::duration_cast<chrono::microseconds>(end - start);
    // print the contacts with iterator
    for (auto c : contacts) {
        cout << c << endl;
    }

    cout << endl
         << "Searching an item in the phonebook (AVL) . . ." << endl;

    cout << endl
            << "Phonebook: Searching for: (" << contact.getFullName() << ")" << endl;
    cout << "====================================" << endl;

    start = chrono::high_resolution_clock::now();
    contacts = contactsAVL.searchAll(contact);
    end = chrono::high_resolution_clock::now();
    auto durationAVL = chrono::duration_cast<chrono::microseconds>(end - start);
    // print the contacts with iterator
    for (auto c : contacts) {
        cout << c << endl;
    }
    cout << endl
         << "The search in BST took " << durationBST.count() * 1000.0 << " nanoseconds. . ." << endl
         << "The search in AVL took " << durationAVL.count() * 1000.0 << " nanoseconds. . ." << endl
         << endl;
    
}

void PhoneBook::searchAll(Contact contact) {
    cout << "AVL: ";
    vector<Contact> resultsAVL = contactsAVL.searchAll(contact);
    for (int i = 0; i < resultsAVL.size(); i++) {
        cout << resultsAVL[i] << endl;
    }
    cout << "BST: ";
    vector<Contact> resultsBST = contacsBST.searchAll(contact);
    for (int i = 0; i < resultsBST.size(); i++) {
        cout << resultsBST[i] << endl;
    }
}

void PhoneBook::printInOrder() {
    cout << endl << "BST Phonebook printed inorder" << endl;
    contacsBST.inorder();
    cout << endl;

    cout << endl << "AVL Phonebook printed inorder" << endl;
    contactsAVL.inorder();
    cout << endl;
}

void PhoneBook::printPreOrder() {
    cout << endl
         << "BST Phonebook printed preorder" << endl;
    contacsBST.preorder();
    cout << endl;

    cout << endl
         << "AVL Phonebook printed preorder" << endl;

    contactsAVL.preorder();

    cout << endl;
}

void PhoneBook::printAVL() {
    cout << endl
         << "AVL Tree drawed." << endl
         << endl;
    contactsAVL.printTree();
}

void PhoneBook::printBST() {
    cout << endl
         << "BST Tree drawed." << endl
         << endl;
    contacsBST.printTree();
}

#endif