#include <iostream>

using namespace std;

class A_Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    A_Stack();
    A_Stack(int *, int, int);
    A_Stack(const A_Stack&);
    ~A_Stack();
    int isFull();
    int isEmpty();
    int push(int);
    int pop();
    int peek();
    int size();
    int display() ;
    int makeStackEmpty();
};
