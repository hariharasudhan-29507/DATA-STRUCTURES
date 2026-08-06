#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Node {
public:
    int id;
    string name;

    Node() {
        id = -1;
        name = "";
    }

    void getDetails() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
    }

    void displayDetails() {
        cout << "ID: " << id << "\tName: " << name << endl;
    }
};

class maxheap {
    int capacity, Size;
    Node *arr;

public:
    maxheap(int);
    ~maxheap();
    void insertion(Node);
    Node remove();
    void percolateUp(int);
    void percolateDown(int);
    Node findMax();
    int search(int);
    void increaseBy(int, int);
    void increaseTo(int, int);
    void decreaseBy(int, int);
    void decreaseTo(int, int);
    void buildHeap(Node[], int);
    void heapSort();
    void display();
};
