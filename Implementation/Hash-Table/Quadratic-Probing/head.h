#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int id;
    string name;
    Node() {
        id = 0;
        name = "";
    }
    Node(int i, string n) {
        id = i;
        name = n;
    }
    void displayNode() {
        cout << "[" << id << " - " << name << "]";
    }
};

class HashTable {
    Node* table;
    int tableSize;
    int currentSize;
public:
    HashTable(int size) {
        tableSize = size;
        currentSize = 0;
        table = new Node[tableSize];
        for (int i = 0; i < tableSize; i++) {
            table[i].id = -1;
            table[i].name = "";
        }
    }
    ~HashTable() {
        delete[] table;
    }
    int hashFunction(int key) {
        return key % tableSize;
    }
    void insertItem(Node item) {
        if (currentSize == tableSize) {
            cout << "Hash Table is full, cannot insert\n";
            return;
        }
        int index = hashFunction(item.id);
        int originalIndex = index;
        int i = 0;
        while (table[index].id != -1 && i < tableSize) {
            i++;
            index = (originalIndex + i * i) % tableSize;
        }
        if (table[index].id == -1) {
            table[index] = item;
            currentSize++;
            cout << "Inserted (" << item.id << ", " << item.name << ") at index " << index << endl;
        } else {
            cout << "No empty slot found for (" << item.id << ", " << item.name << ")\n";
        }
    }
    bool searchItem(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        int i = 0;
        while (table[index].id != -1 && i < tableSize) {
            if (table[index].id == key)
                return true;
            i++;
            index = (originalIndex + i * i) % tableSize;
        }
        return false;
    }
    void displayHash() {
        cout << "\n----- HASH TABLE -----\n";
        for (int i = 0; i < tableSize; i++) {
            cout << i << " --> ";
            if (table[i].id == -1)
                cout << "EMPTY";
            else
                table[i].displayNode();
            cout << endl;
        }
    }
};
