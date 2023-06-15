#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>

using namespace std;

// This is a header file defining a templated HashTable class. 
// The `HNode` struct represents a node in the hash table, containing a key, value, 
// and a pointer to the next node. The `HashTable` class contains 
// functions for adding, removing, and searching for key-value pairs in the hash table.
template <typename Key, typename Value>
struct HNode {
    Key key;
    Value value;
    HNode<Key, Value> *next;
    HNode(Key k, Value v, HNode<Key, Value> *n) : key(k), value(v), next(n) {}
};

template <typename Key, typename Value>
class HashTable {
public:
    HashTable();
    ~HashTable();
    void add(Key k, Value v);
    void remove(Key k);
    Value search(Key k);
private:
    double alpha; // load factor
    int size;
    int capacity;
    HNode<Key, Value> **table;

    int hash(Key k);
    void rehash();
    void rehashHelper(HNode<Key, Value> **oldTable, int oldCapacity);

};

#include "HashTable.cpp"

#endif
