#include"head.h"
int main() {
    L_queue queue;
    int choice;
    int element;
    string name;
    int id;
    cout<<"\nPLAYER MENU \n1:add \n2:delete \n3:peek \n4:isempty \n5:size \n6:display \n7:makeempty \n8:exit";
    do {
        cout<<"\nEnter your choice:";
        cin >> choice;

        switch (choice) {
            case 1:{
                cout << "Enter the player name : ";
                cin >> name;
		cout<<"Enter player id : ";
		cin>>id;
                Node* newnode= new Node(name , id);
                element=queue.enqueue(newnode);
                if(element==-1) {
                    cout<<" full, cannot add";
                }
                break;
	}       
            case 2: {
                element = queue.dequeue();
                if (element !=-1) {
                    cout << "player with id : " << element <<"is deleted"<< endl;
                }
                else 
                    cout<<"empty, cannot delete";                
                break;
    }
            case 3: {
                element = queue.peek();
                if (element != -1) {
                    cout << "1st player id : " << element<< endl;
                }
                break;
    }
            case 4:{
                if (queue.isEmpty()) {
                    cout << "queue is empty." << endl;
                } else {
                    cout << "queue is not empty." << endl;
                }
                break;
    }
            case 5: {
                cout << "Current queue size: " << queue.size() << endl;
                break;
    }
            case 6: {
                queue.display();
                break;
    }
            case 7: {
                queue.makeQueueEmpty();
                cout<<"queue is now empty"<<endl;
                break;
    }
            case 8: {
                cout << "Exiting..." << endl;
                break;
    } 
            default:
                cout << "Invalid choice. Please try again." << endl;
	}        
    } while (choice != 8);
    
     return 0;
}
