#include"head1.h"
int main() {

    A_Stack stack;

    int choice;
    int element;

     cout<<"\n----------------MENU-------------------";
     cout << "\n1:push \n2:pop \n3:peek \n4:isempty \n5:isfull \n6:size \n7:display \n8:makestackempty \n9:exit ";
     do{
	cout<<endl;
     cout<<"Enter your choice:";
     cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to push: ";
                cin >> element;
                element=stack.push(element);
                if(element==-1) {
                    cout<<"Stack is full, cannot push elements"<<endl;
                }
                break;
            case 2:
                element = stack.pop();
                if (element != -1) {
                    cout << "Popped element: " << element << endl;
                }
                if (element==-1){
                    cout<<"Stack is empty, cannot pop elements";
                }
                break;
            case 3:
                element = stack.peek();
                if (element != -1) {
                    cout << "Top element: " << element << endl;
                }
                break;
            case 4:
                if (stack.isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 5:
                if (stack.isFull()) {
                    cout << "Stack is full." << endl;
                } else {
                    cout << "Stack is not full." << endl;
                }
                break;
            case 6:
                cout << "Current stack size: " << stack.size() << endl;
                break;
            case 7:
                stack.display();
                break;
            case 8:
                stack.makeStackEmpty();
                cout<<"Stack is now empty"<<endl;
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

     return 0;
}
