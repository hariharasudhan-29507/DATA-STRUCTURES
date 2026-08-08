#include"head.h"
int main() {
    int size = 7;
    int choice, key;
    cout << "=========================================\n";
    cout << "     Hash Table using Double Hashing\n";
    cout << "   h1(x) = x % 7, h2(x) = 5 - (x % 5)\n";
    cout << "=========================================\n";
    HashTable ht(size);
    do {
        cout << "\n========= HASH TABLE MENU =========";
        cout << "\n1. Insert Key";
        cout << "\n2. Search Key";
        cout << "\n3. Display Table";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insertItem(key);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                if (ht.searchItem(key))
                    cout << " Key " << key << " found in table!\n";
                else
                    cout << " Key " << key << " not found!\n";
                break;
            case 3:
                ht.displayHash();
                break;
            case 4:
                cout << " Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
return 0;
}
