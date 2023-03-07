#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef HASHMAP_H
#define HASHMAP_H

// The HashMap class, it is templated to support any type of key and value.
class HashMap {
private:
    // The Node class, it is templated to support any type of key and value.
    class Node {
    public:
        string key;
        int value;
        bool isDeleted;
        Node(string key, int value) {
            this->key = key;
            this->value = value;
            this->isDeleted = false;
        }
    };

    // The hash table.
    vector<Node*> table;
    // The number of elements in the hash table.
    int size;
    // The number of deleted elements in the hash table.
    int deleted;

    // The hash function.
    int hash(string key) {
        // Calculate the hash value of the key by using the polynomial rolling hash function.
        int hash = 0;
        for (int i = 0; i < key.length() - 1; i++) {
            hash = (hash * 31 + (unsigned char)(key[i])) % 1007;
        }
        return hash;
    }

    // The rehash function.
    void rehash() {
        // Create a new hash table.
        vector<Node*> newTable(table.size() * 2);
        // Copy the elements from the old hash table to the new hash table.
        for (int i = 0; i < table.size(); i++) {
            if (table[i] != NULL && !table[i]->isDeleted) {
                int index = hash(table[i]->key);
                
                while (newTable[index] != NULL) {
                    index = (index + 1) % newTable.size();
                }
                newTable[index] = table[i];
            }
        }
        // Replace the old hash table with the new hash table.
        table = newTable;
    }

public:
    // The constructor.
    HashMap() {
        table = vector<Node*>(10);
        size = 0;
        deleted = 0;
    }

    // Parameterized constructor.
    HashMap(int size) {
        table = vector<Node*>(size);
        size = 0;
        deleted = 0;
    }

    // The destructor.
    ~HashMap() {
        for (int i = 0; i < table.size(); i++) {
            if (table[i] != NULL) {
                delete table[i];
            }
        }
    }

    // The put method.
    void put(string key, int value) {
        // Check if the load factor is greater than 0.5.
        if ((size + deleted) / (double)table.size() > 0.5) {
            // Rehash the hash table.
            rehash();
        }
        // Find the index of the key.
        int index = hash(key);
        // Check if the key already exists.
        while (table[index] != NULL && table[index]->key != key) {
            index = (index + 1) % table.size();
        }
        // Check if the key already exists.
        if (table[index] != NULL && table[index]->key == key) {
            // Update the value of the key.
            table[index]->value = value;
            // Check if the key is deleted.
            if (table[index]->isDeleted) {
                // Update the number of deleted elements.
                deleted--;
                // Update the number of elements.
                size++;
                // Update the flag.
                table[index]->isDeleted = false;
            }
        } else {
            // Create a new node.
            Node* node = new Node(key, value);
            // put the node into the hash table.
            table[index] = node;
            // Update the number of elements.
            size++;
        }
    }

    // The find method.
    int find(string key) {
        // Find the index of the key.
        int index = hash(key);
        // Check if the key exists.
        while (table[index] != NULL && table[index]->key != key) {
            index = (index + 1) % table.size();
        }
        // Check if the key exists.
        if (table[index] != NULL && table[index]->key == key) {
            // Check if the key is deleted.
            if (table[index]->isDeleted) {
                // Return NULL.
                return -1;
            }
            // Return the value of the key.
            return table[index]->value;
        } else {
            // Return NULL.
            return -1;
        }

    }

    string findKey(string key) {
        // Find the index of the key.
        int index = hash(key);
        // Check if the key exists.
        while (table[index] != NULL && table[index]->key != key) {
            index = (index + 1) % table.size();
        }
        // Check if the key exists.
        if (table[index] != NULL && table[index]->key == key) {
            // Check if the key is deleted.
            if (table[index]->isDeleted) {
                // Return NULL.
                return NULL;
            }
            // Return the value of the key.
            return table[index]->key;
        } else {
            // Return NULL.
            return NULL;
        }
    }

    // The size method.
    int findSize() {
        return size;
    }

    // The print method.
    void print() {
        for (int i = 0; i < table.size(); i++) {
            if (table[i] != NULL) {
                cout << table[i]->key << " " << table[i]->value << " " << table[i]->isDeleted << endl;
            } else {
                cout << "NULL" << endl;
            }
        }
    }
};

#endif