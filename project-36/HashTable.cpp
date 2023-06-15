#include "HashTable.h"
#include <iostream>
#include <iomanip>

/* This is the constructor for the HashTable class. */
template <typename Key, typename Value>
HashTable<Key, Value>::HashTable()
{
    alpha = 0.0;
    size = 0;
    capacity = 10;
    table = new HNode<Key, Value> *[capacity];
    for (int i = 0; i < capacity; i++)
    {
        table[i] = nullptr;
    }
}

/* This is the destructor for the HashTable class. It iterates through each element of the table array
and deletes each HNode in the linked list at that index. */
template <typename Key, typename Value>
HashTable<Key, Value>::~HashTable()
{
    for (int i = 0; i < capacity; i++)
    {
        HNode<Key, Value> *temp = table[i];
        while (temp != nullptr)
        {
            HNode<Key, Value> *next = temp->next;
            delete temp;
            temp = next;
        }
    }
    delete[] table;
}

/* This is the `add` method of the `HashTable` class. It takes in a key `k` and a value `v` and adds
them to the hash table.  */
template <typename Key, typename Value>
void HashTable<Key, Value>::add(Key k, Value v)
{
    int index = hash(k);
    HNode<Key, Value> *temp = table[index];
    while (temp != nullptr)
    {
        if (temp->key == k)
        {
            temp->value = v;
            return;
        }
        temp = temp->next;
    }
    table[index] = new HNode<Key, Value>(k, v, table[index]);
    size++;
    alpha = (double)size / capacity;
    if (alpha > 0.75)
    {
        rehash();
    }
}

/* This is the `remove` method of the `HashTable` class. It takes in a key `k` and removes the
corresponding key-value pair from the hash table. */
template <typename Key, typename Value>
void HashTable<Key, Value>::remove(Key k)
{
    int index = hash(k);
    HNode<Key, Value> *temp = table[index];
    HNode<Key, Value> *prev = nullptr;
    while (temp != nullptr)
    {
        if (temp->key == k)
        {
            if (prev == nullptr)
            {
                table[index] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            size--;
            alpha = (double)size / capacity;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

/* This is the `search` method of the `HashTable` class. It takes in a key `k` and searches for the
corresponding value in the hash table. */
template <typename Key, typename Value>
Value HashTable<Key, Value>::search(Key k)
{
    int index = hash(k);
    HNode<Key, Value> *temp = table[index];
    while (temp != nullptr)
    {
        if (temp->key == k)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    return Value("NULL");
}

/* This is the `rehash` method of the `HashTable` class. It is called when the load factor of the hash
table exceeds 0.75, indicating that the table is becoming too full and needs to be resized. */
template <typename Key, typename Value>
void HashTable<Key, Value>::rehash()
{
    int oldCapacity = capacity;
    capacity *= 2;
    cout << "rehashed..." << endl;
    cout << "previous table size: " << oldCapacity << ", new table size: " << capacity << ", current unique item count: " << size << ", current load factor: "
         << fixed << setprecision(2) << alpha << endl;
    HNode<Key, Value> **oldTable = table;
    table = new HNode<Key, Value> *[capacity];
    for (int i = 0; i < capacity; i++)
    {
        table[i] = nullptr;
    }
    rehashHelper(oldTable, oldCapacity);
    delete[] oldTable;
}

/* `rehashHelper` is a private method of the `HashTable` class that is called by the `rehash` method. */
template <typename Key, typename Value>
void HashTable<Key, Value>::rehashHelper(HNode<Key, Value> **oldTable, int oldCapacity)
{
    for (int i = 0; i < oldCapacity; i++)
    {
        HNode<Key, Value> *temp = oldTable[i];
        while (temp != nullptr)
        {
            add(temp->key, temp->value);
            temp = temp->next;
        }
    }
}

/* This is the `hash` method of the `HashTable` class. It takes in a key `k` and returns an index in
the hash table where the key-value pair should be stored. */
template <typename Key, typename Value>
int HashTable<Key, Value>::hash(Key k)
{
    std::size_t h = std::hash<Key>{}(k);
    int index = (int)h % capacity;

    // check if it is negative
    if (index < 0)
    {
        index += capacity;
    }

    return index;
}
