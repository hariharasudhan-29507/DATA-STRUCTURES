#include <iostream>
using namespace std;
class Node {
   public:
      int data;
      Node* next;
   public:
      Node(int);
      ~Node();
};
class L_List {
   public:
      Node* head;
   public:
      L_List();
      int isEmpty();
      int insertAtFirst(Node*);
      int insertAtLast(Node*);
      int insertAtPos(Node*,int);
      int deleteAtFirst();
      int deleteAtLast();
      int deleteAtPos(int);
      void displayList();
      void makeListEmpty();
      Node* searchByValue(int);
      Node* searchByPos(int);
      int insertBeforeAnElement(Node*,int);
      int deleteAfterAnElement(int);
};
