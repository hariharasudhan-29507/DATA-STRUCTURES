#include"head.h"
C_Queue::C_Queue(){
    front=-1;
    rear=-1;
    capacity=5;
    queuearr = new int[capacity];
}

C_Queue::~C_Queue(){
    front=-1;
    rear=-1;
    capacity=0;
    delete[] queuearr;
    queuearr=NULL;
}

int C_Queue::isFull(){
    return ((rear+1)%capacity)==front;
}

int C_Queue::isEmpty(){
    return (front==-1&&rear==-1);
}

int C_Queue::enqueue(int element) {
        if(!isFull()){
            if(front==-1 && rear==-1){
                front=0;
                rear=0;
                queuearr[rear]=element;
            }
            else{
                rear=(rear+1)%capacity;
                queuearr[rear]=element;
            }
            return 1;
        }
        else
            return -1;
}

int C_Queue::dequeue(){
    if(!isEmpty()){
        int dltelt=queuearr[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%capacity;
        }
        return dltelt;
    }
    else
        return -1;
}

int C_Queue::displayQueue(){
    if(!isEmpty()){
        int i =front;
        while(i!=rear){
            cout<<queuearr[i]<<"  ";
            i=(i+1)%capacity;
        }
        cout<<queuearr[i]<<endl;
        cout<<"FRONT:"<<front<<endl;
        cout<<"REAR:"<<rear<<endl;
    }
    else
        return -1;
}

int C_Queue::makeQueueEmpty(){
    while(!isEmpty())
        dequeue();
    return 1;
}

int C_Queue::peek(){
    return (!isEmpty())? queuearr[front]:-1;
}

int C_Queue::size(){
    if(!isEmpty()){
        int c=0;
        int i =front;
        while(i!=rear){
            c++;
            i=(i+1)%capacity;
        }
        c++;
        return c;
    }
    else
        return -1;
}
