#include "head1.h"
A_Stack::A_Stack() {
    top = -1;
    capacity = 10;
    arr = new int[capacity];
    for (int i =0 ;i<capacity; i++)
        arr[i]=-1;
}

int A_Stack::isFull(){
    return top +1==capacity;
}

int A_Stack::isEmpty(){
    return top==-1;
}

int A_Stack::push(int element){
    if(!isFull()){
        arr[++top]=element;
        return 1;
    }
    else return -1;
}

int A_Stack::pop(){
    if(!isEmpty()){
        int element = arr[top];
        arr[top--]=-1;
        return element;
    }
    else return -1;
}

int A_Stack::peek(){
    if(!isEmpty())
        return arr[top];
    else
        return -1;
}

int A_Stack::size(){
    if(!isEmpty())
        return top+1;
    else
        return -1;
}

A_Stack::~A_Stack(){
    top=0;
    capacity=0;
    delete[] arr;
    arr= NULL;
}

int A_Stack::display(){
    if(!isEmpty()){
        for (int i=top;i>=0;i--)
            cout<<arr[i]<<" ";
    }
    else
        return -1;
}

int A_Stack::makeStackEmpty(){
    int element;
    while(!isEmpty())
        element=pop();
    return 1;
}
