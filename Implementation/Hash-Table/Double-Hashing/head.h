#include<iostream>
using namespace std;
class HashTable {
    int *table;
    int tableSize;
    int currentSize;
public:
    HashTable(int size);
    ~HashTable();
    int hash1(int key);
    int hash2(int key);
    void insertItem(int key);
    bool searchItem(int key);
    void displayHash();
};
