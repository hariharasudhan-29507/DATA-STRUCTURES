#include"head.h"
int main() {
    int size, choice, key;
    string name;
    cout << "Enter table size (preferably a prime number): ";
    cin >> size;
    HashTable ht(size);
    do {
        cout << "\n1.Insert\n2.Search\n3.Display\n4.Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter ID: ";
            cin >> key;
            cout << "Enter Name: ";
            cin >> name;
            ht.insertItem(Node(key, name));
            break;
        case 2:
            cout << "Enter ID to search: ";
            cin >> key;
            if (ht.searchItem(key))
                cout << "Key " << key << " found\n";
            else
                cout << "Key " << key << " not found\n";
            break;
        case 3:
            ht.displayHash();
            break;
        case 4:
            cout << "Exiting\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 4);
return 0;
}
