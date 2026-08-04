#include"header1.h"
A_Queue::A_Queue(){
    capacity=5;
    front=-1;
    rear=-1;
    queuearr= new int[capacity];
    for(int i=0;i<5;i++)
        queuearr[i]=-1;
}

int A_Queue::isEmpty(){
    return (front==-1 && rear==-1) ||(front>rear);
}

int A_Queue::isFull(){
    return ((rear+1)==capacity);
}

int A_Queue::enqueue(int element) {
        if(!isFull()){
            if(front==-1 && rear==-1){
                front=0;
                rear=0;
                queuearr[rear]=element;
            }
            else{
                queuearr[++rear]=element;
            }
            return 1;
        }
        else
            return -1;
}


int A_Queue::dequeue(){
    if(!isEmpty()){
        int dltelt=queuearr[front];
        if(front==0 && rear==0){
            front=-1;
            rear=-1;
        }
        else{
            front++;
        }
        return dltelt;
    }
    else
        return -1;
}

int A_Queue::displayQueue(){
    if(!isEmpty()){
        for(int i=front;i<=rear;i++)
            cout<<queuearr[i]<<"  ";
        cout<<"\n";
    }
    else
        return -1;
}

int A_Queue::makeQueueEmpty(){
    while(!isEmpty())
        dequeue();
}

int A_Queue::peek(){
    return (!isEmpty())? queuearr[front]:-1;
}

int A_Queue::size(){
    return (!isEmpty())? ((rear-front)+1):-1;
}

A_Queue::~A_Queue(){
    capacity=0;
    front=0;
    rear=0;
    delete[] queuearr;
    queuearr = NULL;
}
