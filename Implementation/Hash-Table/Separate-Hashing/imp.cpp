#include "head.h"
H_Node::H_Node(int data1, string vname1) // Constructor must match declaration
{
    data = data1;
    vname = vname1; // Assign the passed vname
    next = NULL;
}

H_Node::~H_Node()
{
    // data = -1; // Not necessary in destructor
    // vname = " "; // Not necessary in destructor
    // next = NULL; // The node being deleted will be removed from list
}

// --- O_Hash Implementation ---
O_Hash::O_Hash(int s)
{
    size = s;
    arr = new H_Node*[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = NULL;
    }
}

O_Hash::~O_Hash()
{
    // Proper cleanup for a hash table (though basic deletion is fine here)
    for (int i = 0; i < size; ++i) {
        H_Node* current = arr[i];
        while (current != NULL) {
            H_Node* next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] arr;
}

int O_Hash::hashFunction(int key)
{
    return key % size;
}

// Modified insert function to handle node creation internally
int O_Hash::insert(int key, string name)
{
    int index = hashFunction(key);
    H_Node* newNode = new H_Node(key, name); // Use correct H_Node constructor
    newNode->next = arr[index];
    arr[index] = newNode;
    return index;
}

int O_Hash::delete1(int key)
{
    int index = hashFunction(key);
    H_Node* temp = arr[index];
    H_Node* prev = NULL;
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return -1;
    }
    if (prev == NULL)
    {
        arr[index] = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    delete temp;
    return 1;
}

void O_Hash::display()
{
    // Using a simple loop as the original `count` logic was confusing
    for (int i = 0; i < size; i++)
    {
        H_Node* temp = arr[i];
        cout << "Bucket " << i << ": ";
        if (temp == NULL)
        {
            cout << "Empty";
        }
        else
        {
            while (temp != NULL)
            {
                // Corrected separator usage
                cout << temp->data << "|" << temp->vname;
                if (temp->next != NULL) {
                    cout << "\t-> ";
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }
    cout << endl;
}

int O_Hash::search(int key)
{
    int index = hashFunction(key);
    H_Node* temp = arr[index];
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return index;
        }
        temp = temp->next;
    }
    return -1;
}
