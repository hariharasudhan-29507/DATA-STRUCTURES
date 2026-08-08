#include <iostream>
#include <string> // Use <string> instead of <string.h> for C++ string functionality

using namespace std;

class H_Node {
private:
    int data;
    string vname; // Added missing semicolon
    H_Node* next;
public:
    H_Node(int data, string vname);
    ~H_Node();
    friend class O_Hash;
};

class O_Hash {
private:
    int size;
    H_Node** arr;
public:
    O_Hash(int);
    ~O_Hash();
    int insert(int key, string name); // Modified to pass key and name directly
    int delete1(int);
    int search(int);
    void display();
    int hashFunction(int);
};
