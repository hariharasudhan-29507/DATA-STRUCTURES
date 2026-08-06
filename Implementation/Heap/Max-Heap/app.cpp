#include"head.h"
int main() {
    int height;
    cout << "Enter height : ";
    cin >> height;

    maxheap h(height);
    Node n;
    int choice, key, value;

    cout << "\n---- Max Heap Menu ----\n";
    cout << "1. Insert \n";
    cout << "2. Delete maximum \n";
    cout << "3. Find maximum \n";
    cout << "4. Increase by \n";
    cout << "5. Increase to\n";
    cout << "6. Decrease by\n";
    cout << "7. Decrease to\n";
    cout << "8. Heap Sort\n";
    cout << "9. Display heap\n";
    cout << "10. Build heap\n";
    cout << "11. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            n.getDetails();
            h.insertion(n);
            break;
        case 2: {
            Node removed = h.remove();
            cout << "Deleted Element: ";
            removed.displayDetails();
            break;
        }
        case 3: {
            Node maxNode = h.findMax();
            cout << "Maximum element: ";
            maxNode.displayDetails();
            break;
        }
        case 4:
            cout << "Enter Id: ";
            cin >> key;
            cout << "Enter value to increase by: ";
            cin >> value;
            h.increaseBy(key, value);
            break;
        case 5:
            cout << "Enter Id: ";
            cin >> key;
            cout << "Enter new value to increase to: ";
            cin >> value;
            h.increaseTo(key, value);
            break;
        case 6:
            cout << "Enter Id: ";
            cin >> key;
            cout << "Enter value to decrease by: ";
            cin >> value;
            h.decreaseBy(key, value);
            break;
        case 7:
            cout << "Enter Id: ";
            cin >> key;
            cout << "Enter new value to decrease to: ";
            cin >> value;
            h.decreaseTo(key, value);
            break;
        case 8:
            h.heapSort();
            break;
        case 9:
            h.display();
            break;
        case 10: {
            int nCount;
            cout << "Enter number of elements: ";
            cin >> nCount;
            Node arr[nCount];
            for (int i = 0; i < nCount; i++) {
                cout << "\nEnter detail " << i + 1 << ":\n";
                arr[i].getDetails();
            }
            h.buildHeap(arr, nCount);
            break;
        }
        case 11:
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
