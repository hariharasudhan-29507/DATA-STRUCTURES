#include"head.h"
int main()
{
    int s;
    cout << "Enter the table size:";
    cin >> s;
    O_Hash ob1(s);
    int ch;
    cout << "1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\n";
    do {
        cout << "Enter the choice:" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int k;
            string name; // Added missing semicolon
            cout << "Enter student id:";
            cin >> k;
            cout << "Enter student name:";
            cin >> name;
            // Removed manual node creation and passed parameters directly to the new insert method
            int out = ob1.insert(k, name);
            cout << "The element is inserted at " << out << " bucket" << endl;
            break;
        }
        case 2:
        {
            int k;
            cout << "Enter the element to delete:";
            cin >> k;
            int out = ob1.delete1(k);
            if (out == -1)
            {
                cout << "The element is not found in the table" << endl;
            }
            else
            {
                cout << "The element is deleted successfully" << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Table:" << endl;
            ob1.display();
            break;
        }
        case 4:
        {
            int k;
            cout << "Enter the key to search:";
            cin >> k;
            int out = ob1.search(k);
            if (out == -1)
            {
                cout << "The key is not present in the table" << endl;
            }
            else
            {
                cout << "The key is present in the table at " << out << endl;
            }
            break;
        }
        case 5: // Added case 5 to handle the exit condition gracefully
        {
            break;
        }
        default:
            cout << "Invalid Expression\n";
        }
    } while (ch != 5);
    cout << "Exiting the program" << endl;
    return 0; // Standard practice to return 0 from main
}
