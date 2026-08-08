#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class node {
    private:
      int vid;
      char vname[50];
    public:
      node();
      void displayDetails();
      void getDetails();
    friend class LinearProbing;
};

class LinearProbing
{
    private:
    int tablesize;
    node **HT;
    bool *isDeleted;

    public:
    LinearProbing(int);
    ~LinearProbing();
    int hashFunction(int key);
    int insert(node* newNode);
    int delete1(int key);
    int search(int key);
    void display();
};
