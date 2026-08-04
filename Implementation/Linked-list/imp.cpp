#include "header.h"
Node :: Node(int val)
{
   data = val;
   next = NULL;
}
Node :: ~Node()
{
   data = -1;
   next = NULL;
}
L_List :: L_List()
{
   head=NULL;
}
int L_List :: isEmpty()
{
   if (head == NULL)
      return 1;
   else
      return 0;
}
int L_List :: insertAtFirst(Node* newNode)
{
   if(isEmpty())
   {
      head=newNode;
   }
   else
   {
      newNode-> next=head;
      head = newNode;
   }
   return 1;
}
void L_List :: displayList()
{
   Node* temp=head;
   if (temp ==  NULL ) {
      cout<< "NULL" <<endl;
   }
   else {
      while(temp -> next!=NULL)
      {
         cout << temp -> data << "\t";
         temp = temp->next;
      }
      cout << temp -> data <<"\n";
   }
}
int L_List :: insertAtLast(Node* newNode)
{
   if(isEmpty())
   {
      head =newNode;
   }
   else
   {
      Node* temp=head;
      while(temp -> next!=NULL)
      {
         temp=temp -> next;
      }
      temp -> next = newNode ;
   }
   return 1;
}
int L_List :: insertAtPos(Node* newNode,int pos)
{
   if(pos<1)
      return 0;
   if(pos == 1)
   {
      if(isEmpty())
      {
         head = newNode;
      }
      else
      {
         newNode -> next = head;
         head = newNode;
      }
      return 1;
   }
   else
   {
      Node* current = head;
      Node* previous = NULL;
      int currentpos = 1;
      while(current!=NULL && currentpos<pos) {
         previous = current;
         current = current -> next;
         currentpos++;
      }
      if(currentpos==pos)
      {
         if(previous!=NULL)
         {
            newNode -> next =current;
            previous -> next = newNode;
         }
         return 1;
      }
      else
         return 0;
   }
}
int L_List :: deleteAtFirst()
{
   if(isEmpty())
      return 0;
   else{
      Node* temp = head;
      head = head -> next;
      delete temp;
      temp = NULL;
   }
   return 1;
}
int L_List :: deleteAtLast()
{
   if(isEmpty())
      return 0;
   else {
      Node* current = head;
      Node* prev = NULL;
      while(current -> next!=NULL)
      {
         prev=current;
         current = current -> next;
      }
      prev -> next = NULL;
      delete current;
      current = NULL;
   }
   return 1;
}
int L_List :: deleteAtPos(int pos) {
   if (pos <1)
      return 0;
   else if ( pos ==1){
      if(isEmpty())
         return 0;
      else{
         Node* temp = head;
         head = head -> next;
         delete temp;
         return 1;
      }
   }
   else
   {
      Node* current = head;
      Node* previous = NULL;
      int currentpos=1;
      while(current!=NULL && currentpos <pos)
      {
         previous = current;
         current = current -> next;
         currentpos++;
      }
      if ( currentpos == pos && current!=NULL)
      {
         if(previous!=NULL)
         {
            previous -> next = current->next;
            delete current;
         }
         return 1;
      }
      else
         return 0;
   }
}
Node* L_List :: searchByValue(int value)
{
   Node* current = head;
   while(current!=head)
   {
      if(current -> data == value)
      {
         return current ;
      }
      current = current -> next;
      return NULL;
   }
}
Node* L_List :: searchByPos(int pos)
{
   if (pos<1)
   {
      return NULL;
   }
   Node* current = head;
   int currentpos=1;
   while( current !=NULL && currentpos<pos)
   {
      current=current->next;
      currentpos++;
   }
   if(currentpos==pos && current!=NULL)
      return current;
   else
      return NULL;
}
void L_List :: makeListEmpty()
{
   Node* current = head;
   Node* prev = NULL;
   while( current != NULL) {
      prev = current;
      current = current -> next;
      delete prev;
   }
   head = NULL;
}
int L_List::insertBeforeAnElement(Node* newNode, int value) {
       if (isEmpty()) {
          return 0;
       }
       else {
          if ( head -> data == value)
          {
             newNode -> next = head;
             head = newNode ;
             return 1;
          }
          else
          {
             Node* current = head;
             Node* prev =NULL;
             while (current !=NULL && current ->data !=value ){
                prev = current;
                current=current ->next;
             }
             if ( current!=NULL){
                newNode ->next =current;
                prev ->next = newNode;
                return 1;
             }
             else
                return 0;
          }
       }
}
int L_List :: deleteAfterAnElement(int val){
   if (isEmpty())
      return 0;
   else{
      Node* current = head;
      while(current != NULL && current -> data != val){
         current = current -> next;
      }
      if( current != NULL && current -> next != NULL) {
         Node* temp = current->next;
         current->next = temp->next;
         delete temp;
         return 1;
      }
      else
         return 0;
   }
}
