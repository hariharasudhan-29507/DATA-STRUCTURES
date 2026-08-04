#include<iostream>
using namespace std;
class C_Queue {
    int *queuearr;
    int capacity;
    int front;
    int rear;

    public:
        C_Queue();
        ~C_Queue();
        int enqueue(int);
        int dequeue();
        int peek();
        int isFull();
        int isEmpty();
        int size();
        int displayQueue();
        int makeQueueEmpty();
};
