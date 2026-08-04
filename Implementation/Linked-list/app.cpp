#include "header.h"
int main()
{
   L_List list;
   cout << "____________________MENU____________________" <<endl;
   cout << "1.INSERT AT FIRST\n2.INSERT AT LAST\n3.INSERT BY POSITION\n4.DELETE AT FIRST\n5.DELETE AT LAST\n6.DELETE BY POSITION\n7.SEARCH BY VALUE\n8.SEARCH BY POSITION\n9.INSERT BEFORE AN ELEMENT\n10.DELETE AFTER AN ELEMENT\n11.DISPLAY LIST\n12.IS EMPTY\n13.MAKE LIST EMPTY \n 14.EXIT" << endl;
   while ("True") {
      int ch;
      cout << "Enter your choice " << endl;
      cin >> ch;
      if(ch==1){
         int ielef;
         cout <<"Enter the element to insert at first :";
         cin >> ielef;
         Node *newNode1=new Node(ielef);
         list.insertAtFirst(newNode1);
         cout << "List after inserting at the begining" <<endl;
         list.displayList();
      }
      else if (ch == 2){
         int ielel;
         cout << "Enter the element to be inserted at last :" <<endl;
         cin >> ielel;
         Node *newNode3=new Node(ielel);
         list.insertAtLast(newNode3);
         list.displayList();
      }
      else if ( ch == 3) {
         int ipos;
         int pele;
         int ip;
         cout << "Enter the element to be insert :" << endl;
         cin >> pele;
         Node *newNode4=new Node(pele);
         cout << "Enter the position the element to be inserted" <<endl;
         cin >> ipos;
         ip = list.insertAtPos(newNode4,ipos);
         if (ip == 0)
            cout << " Invalid position " <<endl ;
         else {
            cout << "Element inserted at the position " <<endl ;
            list.displayList();
         }
      }
      else if ( ch == 4){
         int df;
         df=list.deleteAtFirst();
         if ( df == 0)
            cout << "LIST IS EMPTTY..." << endl;
         else
         {
            cout << "First element deleted " << endl ;
            list.displayList();
         }
      }
      else if ( ch == 5) {
         int dl;
         dl=list.deleteAtLast();
         if ( dl == 0)
            cout << "List is empty..." <<endl;
         else
         {
            cout << "Last Element deleted " << endl;
            list.displayList();
         }
      }
      else if ( ch == 6) {
         int dpos;
         int dp;
         cout << "Enter the position of the element to be deleted:" <<endl;
         cin >> dpos;
         dp=list.deleteAtPos(dpos);
         if ( dp == 0)
            cout << "Invalid position " << endl;
         else{
            cout << "Element deleted " <<endl;
            list.displayList();
         }
      }
      else if ( ch == 7) {
         int val;
         Node* sval;
         cout << "Enter the value to be searched:" << endl;
         cin >> val;
         sval=list.searchByValue(val);
         if ( sval == NULL )
            cout << "Value not found....." <<endl;
         else {
            cout << "Value found at ";
            cout << sval <<endl;
         }
      }
      else if ( ch == 8 ) {
         int pos;
         Node* spos;
         cout << "Enter the position to search:" <<endl;
         cin >> pos;
         spos = list.searchByPos(pos);
         if ( spos == NULL)
            cout << "NO value found at that position:" <<endl;
         else{
            cout << "value found at that pos" <<endl;
            cout << spos -> data <<endl;
         }

      }
      else if ( ch == 9 ) {
         int val;
         int ins;
         cout << "Enter the element to insert ana element before this :" <<endl;
         cin >> val;
         cout << "Enter the element to be inserted:" <<endl;
         cin >> ins;
         Node* newNode7 = new Node(ins);
         int inaf=list.insertBeforeAnElement(newNode7,val);
         if(inaf== 0)
         {
            cout << "LIST IS EMPTY " <<endl;
         }
         else
         {
            cout << "ELEMENT INSERTED BEFORE THE GIVEN ELEMENT" <<endl;
            list.displayList();
         }
      }
      else if ( ch == 10 ) {
         int value;
         cout << "Enter the element whose next value should deleted:" << endl;
         cin >> value;
         int del;
         del=list.deleteAfterAnElement(value);
         if ( del== 0)
            cout << "LIST IS EMPTY" << endl;
         else
         {
            cout << "ELEMENT DELETED " <<endl;
            list.displayList();
         }
      }
      else if ( ch == 11) {
         list.displayList();
      }
      else if ( ch == 12) {
         int ie;
         ie=list.isEmpty();
         if(ie==1)
            cout << "LIST IS EMPTY" <<endl;
         else
            cout << "LIST IS NOT EMPTY" << endl;
      }
      else if ( ch == 13 ) {
         list.makeListEmpty();
         cout << "list Emptied , successfully" <<endl;
      }
      else if ( ch == 14 ) {
         cout << "Exiting...." <<endl;
         break;
      }
   }

   return 0;
}
