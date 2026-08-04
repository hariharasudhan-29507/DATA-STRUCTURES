#include"head.h"
Node::Node(string val , int val1) {
    player_name = val;
    player_id = val1;
    next = NULL;
}

Node::~Node() {
    player_name=" ";
    player_id=-1;
    next = NULL;
}

L_queue::L_queue () {
    head = NULL;
}

int L_queue::isEmpty() {
    return head==NULL;
}

int L_queue::enqueue(Node* newnode){
    if(isEmpty())
        head=newnode;
    else{
        Node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
    return 1;
}

int L_queue::dequeue(){
    if(isEmpty())
        return -1;
    Node* temp=head;
    int elt=temp->player_id;
    head=head->next;
    delete temp;
    temp=NULL;
    return elt;
}

int L_queue::peek(){
    return (!isEmpty())?head->player_id:-1;
}

int L_queue::size(){
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void L_queue::display(){
    Node* temp=head;
    cout<<"    Player details   "<<endl;
    cout<<"---------------------"<<endl;
    cout<<"id\tplayer name"<<endl;
    while(temp!=NULL){
        cout<<temp->player_id<<"\t"<<temp->player_name << endl;
        temp=temp->next;
    }

}

int L_queue::makeQueueEmpty(){
    while(!isEmpty())
        int element=dequeue();
}

L_queue::~L_queue(){
    delete head;
    head =NULL;
}

