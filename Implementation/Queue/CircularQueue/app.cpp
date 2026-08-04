#include"head.h"
int main() {

    C_Queue queue;
    int choice;
    int element;
    cout<<"\n MENU \n1.TO ENQUEUE \n2.TO DEQUEUE \n3.PEEK \n4.ISEMPTY \n5.ISFULL \n6.SIZE \n7.DISPLAY \n8.TO MAKE QUEUE EMPTY \n9:EXIT";
    do{
        cout<<"\nEnter the Choice:";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the element to enqueue: ";
                cin >> element;
                element=queue.enqueue(element);
                if(element==-1) {
                    cout<<"QUEUE is full, cannot ENQUEUE";
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
                cout << "EXITING.............."<<endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

     return 0;
}
