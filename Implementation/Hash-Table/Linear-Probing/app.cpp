#include"head.h"
int main()
{
    int s;
    cout<<"Enter the table size:"<<endl;
    cin>>s;
    LinearProbing ob1(s);
    int ch;
    cout<<"1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n";
    do{
        cout<<"Enter the choice:"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                node* newNode = new node(); // Create a temporary node object
                newNode->getDetails(); // Get details from the user
                int out=ob1.insert(newNode); // Pass the node pointer to insert
                if(out==-2)
                {
                    cout<<"The table is full insertion fails"<<endl;
                }
                else if (out == -1) {
                    // Specific case for key already exists
                }
                else
                {
                    cout<<"The element is inserted at  "<<out<<endl;
                }
                break;
            }
            case 2:
            {
                int k;
                cout<<"Enter the key (ID) to delete:";
                cin>>k;
                int out=ob1.delete1(k);
                if(out==-2)
                {
                    cout<<"The key is not present in the table deletion fails"<<endl;
                }
                else
                {
                    cout<<"The element is deleted at  "<<out<<endl;
                }
                break;
            }
            case 3:
            {
                int k;
                cout<<"Enter the key (ID) to search:";
                cin>>k;
                int out=ob1.search(k);
                if(out==-2)
                {
                    cout<<"The key is not found in the table"<<endl;
                }
                else
                {
                    cout<<"The key is present in the table at  "<<out<<endl;
                }
                break;
            }
            case 4:
            {
                cout<<"The table is"<<endl;
                ob1.display();
                break;
            }
            case 5: {
                break;
            }
            default:
            cout<<"Invalid Expression\n";
        }
    }while(ch!=5);
    cout<<"Exiting the program"<<endl;
    return 0;
}
