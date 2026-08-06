#include"head.h"
int main() {
    int height,c;
    cout << "Enter heap height: ";
    cin >> height;

    MinHeap heap(height);
    int choice, val, elt;
    cout << "\n--- Min Heap Menu ---\n";
    cout << "1. Insert\n";
    cout << "2. Delete Min\n";
    cout << "3. Increase By\n";
    cout << "4. Increase To\n";
    cout << "5. Decrease By\n";
    cout << "6. Decrease To\n";
    cout << "7. Build Heap\n";
    cout << "8. Heap Sort\n";
    cout << "9. Display\n";
    cout << "10. Exit\n";
    do {

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                c=heap.insertion(val);
                if(c==0){
                    cout<<"Heap is full.\n";
                }
                else
                cout<<val<<" inserted.\n";
                break;
            case 2:
                cout << "Deleted Min: " << heap.deleteMin() << endl;
                break;
            case 3:
                cout << "Enter element and value to increase by: ";
                cin >> elt >> val;
                heap.increaseBy(elt, val);
                break;
            case 4:
                cout << "Enter element and new value: ";
                cin >> elt >> val;
                heap.increaseTo(elt, val);
                break;
            case 5:
                cout << "Enter element and value to decrease by: ";
                cin >> elt >> val;
                heap.decreaseBy(elt, val);
                break;
            case 6:
                cout << "Enter element and new value: ";
                cin >> elt >> val;
                heap.decreaseTo(elt, val);
                break;
            case 7: {
                int n;
                cout << "Enter number of elements: ";
                cin >> n;
                int arr[n];
                cout << "Enter elements: ";
                for (int i = 0; i < n; i++) cin >> arr[i];
                heap.buildHeap(arr, n);
                heap.display();
                break;
            }
            case 8:
                heap.heapSort();

                break;

            case 9:
                heap.display();
                break;

            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 10);
    return 0;
}
