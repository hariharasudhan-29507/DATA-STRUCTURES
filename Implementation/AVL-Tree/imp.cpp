#include"head.h"
int main() {
    AVLTree tree;
    int choice, val;
    string n;

    cout << "\nMenu\n";
    cout << "1.  Insert\n2.  Search\n3.  Inorder \n4.  Preorder \n5.  Postorder \n6.  Find Min\n7.  Find Max\n8.  Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter id to insert: ";
                cin >> val;
                cout<<"Enter name to insert:";
                cin>>n;
                tree.setRoot(tree.insertNode(tree.getRoot(), val,n));
                cout << "Inserted.\n";
                break;
            case 2:
                cout << "Enter id to search: ";
                cin >> val;
                if (tree.searchNode(tree.getRoot(), val))
                    cout << "Found.\n";
                else
                    cout << "Not Found.\n";
                break;
            case 3:
                cout << "Inorder:\n";
                tree.inorderTraversal(tree.getRoot());
                cout << "\n";
                break;
            case 4:
                cout << "Preorder: \n";
                tree.preorderTraversal(tree.getRoot());
                cout << "\n";
                break;
            case 5:
                cout << "Postorder: \n";
                tree.postorderTraversal(tree.getRoot());
                cout << "\n";
                break;
            case 6:
                if (tree.getRoot() != NULL)
                    cout << "Mininum id: " << tree.findMinNode(tree.getRoot())->getData() << "\n";
                else
                    cout << "Tree is empty.\n";
                break;
            case 7:
                if (tree.getRoot() != NULL)
                    cout << "Maximum id: " << tree.findMaxNode(tree.getRoot())->getData() << "\n";
                else
                    cout << "Tree is empty.\n";
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    return 0;
}
