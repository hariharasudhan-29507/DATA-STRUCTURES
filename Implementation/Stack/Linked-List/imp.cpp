#include"head2.h"
Node::Node(string name , int id) {
    p_name = name;
    p_id = id ;
    next = NULL;
}

Node :: Node(const Node & other){
   p_name = other.p_name;
   p_id = other.p_id;
   next = other.next;
}

Node::~Node() {
    p_id=-1;
    p_name= " ";
    next = NULL;
}

L_Stack::L_Stack () {
    top = NULL;
}

int L_Stack::isEmpty() {
    return top==NULL;
}

int L_Stack::push(Node* newnode) {
    if(isEmpty())
        top=newnode;
    else{
        newnode->next=top;
        top=newnode;
    }
    return 1;
}

int L_Stack::pop() {
    if (isEmpty())
        return -1;
    Node* temp= top;
    int element= top->p_id;
    top=top->next;
    delete temp;
    temp=NULL;
    cout<<"id "<<element<<" is successfully deleted"<<endl;
}

int L_Stack::peek(){
    if(!isEmpty()){
       cout<<"        1st detail        "<<endl;
       cout<<top->p_id<<"\t"<<top->p_name;
    }
    else
        return -1;
}

int L_Stack::size() {
    int count=0;
    Node* temp=top;
    while(temp!=NULL) {
        count++;
        temp=temp->next;
    }
    return count;
}

int L_Stack::makeStackEmpty(){
    Node* temp=top;
    while(top!=NULL) {
        top = top->next;
        delete temp;
        temp=top;
    }
}

void L_Stack::display() {
    if (!isEmpty()){
       Node* temp=top;
       cout << "----------------------"<<endl ;
       cout << "        DETAILS       "<<endl ;
       cout << "----------------------"<<endl ;
       while(temp!=NULL) {
          cout<<temp->p_id<<"\t"<<temp->p_name<<endl;
          temp=temp->next;
       }
       cout << "----------------------"<<endl ;
    }
    else
       cout<<"no details";
}
