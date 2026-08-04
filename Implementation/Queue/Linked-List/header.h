#include<iostream>
using namespace std;
class Node {
    public:
        string player_name;
        int player_id;
        Node *next;
    public:
        Node(string , int);
        Node(const Node &);
        friend class L_list;
        ~Node();
};
class L_queue {
        Node *head;
    public:
        L_queue();
        ~L_queue();
        int isEmpty();
        void display();
        int makeQueueEmpty();
        int enqueue(Node*);
        int dequeue();
        int peek();
        int size();
};
