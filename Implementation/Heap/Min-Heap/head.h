#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

class node{
   private:
      int vid;
      char vname[50];
   public:
      node();
      void displayDetails();
      void getDetails();
   friend class MinHeap;
};
class MinHeap {
private:
    int capacity, size;
    node *arr;

public:
    MinHeap(int height);
    ~MinHeap();

    bool isEmpty();
    bool isFull();

    int insertion(node val);
    int deleteMin();

    void percolateUp(int idx);
    void percolateDown(int idx);

    void increaseBy(int elt, int val);
    void increaseTo(int elt, int val);

    void decreaseBy(int elt, int val);
    void decreaseTo(int elt, int val);

    void buildHeap(int input[], int n);
    void heapSort();

    void display();
};
