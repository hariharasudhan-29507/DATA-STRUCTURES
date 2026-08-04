#include"header1.h"
int main() {

    A_Queue queue;

    int choice;
    int element;


    cout<<"\nMENU \n1:enqueue \n2:dequeue \n3:peek \n4:isempty \n5:isfull \n6:size \n7:display \n8:makequeueempty \n9:exit";
    do{
        cout<<"\nEnter the choice:";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the element to enqueue: ";
                cin >> element;
                element=queue.enqueue(element);
                if(element==-1) {
                    cout<<"queue is full, cannot enqueue";
                }
                break;
            case 2:
                element = queue.dequeue();
                if (element != -1) {
                    cout << "dequeued element: " << element << endl;
                }
                if (element==-1){
                    cout<<"queue is empty, cannot dequeue";
                }
                break;
            case 3:
                element = queue.peek();
                if (element != -1) {
                    cout << "Top element: " << element << endl;
                }
                break;
            case 4:
                if (queue.isEmpty()) {
                    cout << "queue is empty." << endl;
                } else {
                    cout << "queue is not empty." << endl;
                }
                break;
            case 5:
                if (queue.isFull()) {
                    cout << "queue is full." << endl;
                } else {
                    cout << "queue is not full." << endl;
                }
                break;
            case 6:
                cout << "Current queue size: " << queue.size() << endl;
                break;
            case 7:
                queue.displayQueue();
                break;
            case 8:
                queue.makeQueueEmpty();
                cout<<"queue is now empty";
                break;
            case 9:
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

     return 0;
}
