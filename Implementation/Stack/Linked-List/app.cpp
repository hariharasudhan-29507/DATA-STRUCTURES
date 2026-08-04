#include"head2.h"
int main() {
    L_Stack stack;

    int ele,ele1;
    int choice;
    int id ;
    string name;

    cout<<"\nMENU \n1:Add details \n2:Delete detail \n3:show 1st detail  \n4:isempty  \n5:size \n6:display \n7:makestackempty \n8:exit \n";
    do {
        cout << "Enter your choice";
        cin >> choice;

        switch (choice) {
            case 1:{
                cout << "Enter id : ";
                cin >> id;
		cout << "Enter name:";
		cin>>name;
                Node* newnode= new Node(name , id);
                ele=stack.push(newnode);
                if(ele==-1) {
                    cout<<"Stack is full, cannot push elements";
                }
                break;
            }
            case 2: {
                ele = stack.pop();
                if (ele ==1) {
                    cout << "Popped element: " << ele << endl;
                }
                else if (ele==-1){
                    cout<<"no details cant delete";
                }
                break;
            }
            case 3: {
                ele = stack.peek();
                if (ele == -1) {
                    cout << "detail not found"<< endl;
                }
                break;
            }
            case 4:{
                if (stack.isEmpty()) {
                    cout << "no details" << endl;
                } else {
                    cout << "contains elements" << endl;
                }
                break;
            }
	   case 5: {
                cout << "Current size: " << stack.size() << endl;
                break;
            }
            case 6: {
                stack.display();
                break;
            }
            case 7: {
                stack.makeStackEmpty();
                cout<<"Stack is now empty"<<endl;
                break;
            }
            case 8: {
                cout << "Exiting..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

     return 0;
}

