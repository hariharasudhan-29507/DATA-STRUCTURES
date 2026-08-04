#include<iostream>
using namespace std;
class Node {
    public:
        int p_id;
	string p_name;
        Node *next;
    public:
        Node(string,int);
	Node(const Node &);
	friend class L_list;
        ~Node();
};

class L_Stack {
        Node *top;
    public:
        L_Stack();
        int isEmpty();
        void display();
        int makeStackEmpty();
        int push(Node*);
        int pop();
        int peek();
        int size();
};
