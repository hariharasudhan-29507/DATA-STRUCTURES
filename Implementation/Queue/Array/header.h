#include<iostream>
using namespace std;
class A_Queue {
    int *queuearr;
    int capacity;
    int front;
    int rear;

    public:
        A_Queue();
        ~A_Queue();
        int enqueue(int);
        int dequeue();
        int peek();
        int isFull();
        int isEmpty();
        int size();
        int displayQueue();
        int makeQueueEmpty();
};
