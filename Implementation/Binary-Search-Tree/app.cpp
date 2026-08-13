#include"head.h"
int main() {
    BST tree;
    int id;
    string name;
    int choice, value;
    TreeNode* result;


        cout << "\n***MENU***\n";
        cout << "1. Insert user\n";
        cout << "2. Delete user\n";
        cout << "3. Search an user\n";
        cout << "4. Find Minimum\n";
        cout << "5. Find Maximum\n";
        cout << "6. Inorder Traversal\n";
        cout << "7. Preorder Traversal\n";
        cout << "8. Postorder Traversal\n";
        cout << "9. Exit\n";

        do{
           cout<<"\nEnter your choice :";
           cin>>choice;
           switch (choice) {
            case 1:
                cout << "Enter id: ";
                cin >> id;
                cout<<"Enter name:";
                cin >> name;
                tree.insertNode(tree.getRoot(), new TreeNode(id,name));
                cout << "Inserted " << id << " into the BST successfully.\n";
                break;

            case 2:
                cout << "Enter id to delete: ";
                cin >> id;
                result=tree.deleteNode(tree.getRoot(), id);
                if(result!=NULL)
                    cout<<"user deleted \n";
                else
                    cout<<"user is not deleted \n";
                break;

            case 3:
                cout << "Enter id to search: ";
                cin >> id;
                result = tree.search(tree.getRoot(), id);
                if (result != NULL)
                    cout <<id << " found in the BST.\n";
                else
                    cout << id << " not found in the BST.\n";
                break;

            case 4:
                if (!tree.isempty())
                    cout << "Minimum value: " << tree.findMin(tree.getRoot()) << "\n";
                else
                    cout << "Tree is empty!\n";
                break;

            case 5:
                if (!tree.isempty())
                    cout << "Maximum value: " << tree.findMax(tree.getRoot()) << "\n";
                else
                    cout << "Tree is empty!\n";
                break;

            case 6:
                cout << "Inorder Traversal result: ";
                tree.inorder(tree.getRoot());
                cout << "\n";
                break;

            case 7:
                cout << "Preorder Traversal result: ";
                tree.preorder(tree.getRoot());
                cout << "\n";
                break;

            case 8:
                cout << "Postorder Traversal result: ";
                tree.postorder(tree.getRoot());
                cout << "\n";
                break;

            case 9:
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
