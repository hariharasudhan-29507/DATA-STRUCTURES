#include"head.h"
HashTable::HashTable(int size) {
    tableSize = size;
    currentSize = 0;
    table = new int[tableSize];
    for (int i = 0; i < tableSize; i++)
        table[i] = -1;  // -1 means empty
}
// Destructor
HashTable::~HashTable() {
    delete[] table;
}
// Primary hash function: h1(x) = x % 7
int HashTable::hash1(int key) {
    return key % 7;
}
// Secondary hash function: h2(x) = 5 - (x % 5)
int HashTable::hash2(int key) {
    return 5 - (key % 5);
}
// Insert key using explicit double hashing logic
void HashTable::insertItem(int key) {
    if (currentSize == tableSize) {
        cout << " Hash Table is full! Cannot insert " << key << endl;
        return;
    }
    int index1 = hash1(key);
    int step = hash2(key);
    cout << " Inserting key " << key
         << " | h1 = " << index1
         << ", h2 = " << step << endl;
    // Step 1: Try initial slot
    if (table[index1] == -1) {
        table[index1] = key;
        currentSize++;
        cout << "Inserted key " << key << " at index " << index1 << endl;
        return;
    }
    int i = 1;
    int newIndex;
    while (i < tableSize) {
        newIndex = (index1 + i * step) % tableSize;
        cout << "   Probing index " << newIndex << endl;
        if (table[newIndex] == -1) {
            table[newIndex] = key;
            currentSize++;
            cout << "Inserted key " << key << " at index " << newIndex << endl;
            return;
        }
        i++;
    }
    cout << "Could not find empty slot for key " << key << " (Table full or all slots checked)" << endl;
}
bool HashTable::searchItem(int key) {
    int index1 = hash1(key);
    int step = hash2(key);
    cout << "Searching for key " << key
         << " | h1 = " << index1
         << ", h2 = " << step << endl;
    if (table[index1] == key)
        return true;
    int i = 1;
    int newIndex;
    while (i < tableSize && table[(index1 + i * step) % tableSize] != -1) {
        newIndex = (index1 + i * step) % tableSize;
        cout << " Checking index " << newIndex << endl;
        if (table[newIndex] == key)
            return true;
        i++;
    }
    return false;
}
// Display Hash Table
void HashTable::displayHash() {
    cout << "\n----- Hash Table (Double Hashing) -----\n";
    for (int i = 0; i < tableSize; i++) {
        cout << i << " --> ";
        if (table[i] == -1)
            cout << "EMPTY";
        else
            cout << table[i];
        cout << endl;
    }
    cout << "---------------------------------------\n";
}
