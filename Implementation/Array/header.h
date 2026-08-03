#include<iostream>
using namespace std;

class A_List{

   private:
      int *arr;
      int size;
      int capacity;

   public:

      A_List();
      A_List(int*,int, int);
      A_List(const A_List &);
      int insertAtFirst(int);
      int insertAtLast(int);
      int insertByPos(int,int);
      int deleteAtFirst();
      int deleteAtLast();
      int deleteByPos(int);
      int isFull();
      int isEmpty();
      int displayList();
      int makeListEmpty();
      int retrieveEltIndex(int);
      int searchAtFirst();
      int searchAtLast();
      int searchAnElt(int);

};
