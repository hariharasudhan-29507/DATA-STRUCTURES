#include"header.h"
//1
A_List::A_List(){
   size = 0;
   capacity = 10;
   arr = new int[capacity];
   for (int i=0 ;i<capacity;i++)
      arr[i] = -1;
}
//2
A_List::A_List(int *a,int s,int c){
   capacity =c;
   size =s;
   arr = new int[c];
   for(int i= 0;i<size;i++)
      arr[i] = a[i];
   for(int i=size;i<capacity;i++)
      arr[i]=-1;
}
//3
A_List::A_List(const A_List&mylist ){
   int i=0;
   capacity=mylist.capacity;
   size=mylist.size;
   arr=new int[capacity];
   for(i=0;i<size;i++)
      arr[i]=mylist.arr[i];
   for(i=size;i<capacity;i++)
      arr[i]=-1;
}
//4
int A_List::isFull(){
   if(capacity == size)
      return 1;
   else
      return 0;
}
//5
int A_List::isEmpty(){
   if(size==0)
      return 1;
   else
      return 0;
}
//6
int A_List::insertAtLast(int element){
   if(!isFull()){
      arr[size++]=element;
      return 1;
   }
   else
      return 0;
}
//7
int A_List::displayList(){
   if(!isEmpty()){
      cout<<"DATA :"<<endl;
      for(int i=0;i<size;i++)
         cout<<arr[i]<<" ";
      cout<<endl;
   }
   else
      return 0;
}
//8
int A_List::insertByPos(int element,int pos){
   if(!isFull()){
      if(pos<=0||pos>=size+1)
         return -2;
      else{
         if(isEmpty()&&pos==1){
            insertAtFirst(element);
         }
         else if(isEmpty()&&pos!=1){
            return -3;
         }
         else{
            int i;
            for(i=size;i>pos-1;i--)
               arr[i]=arr[i-1];
            arr[i]=element;
            size++;
         }
         return 1;
      }
   }
   else
      return 0;
}
//9
int A_List::deleteAtFirst(){
   if(!isEmpty()){
      for(int i=0;i<size;i++)
         arr[i]=arr[i+1];
      size--;
      return 1;
   }
   else
      return 0;
}
//10
int A_List::insertAtFirst(int element){
   if(!isFull()){
      if(isEmpty()){
         arr[size++]=element;
      }
      else{
         for(int i=size;i>0;i--)
            arr[i]=arr[i-1];
         arr[0]=element;
         size++;
      }
      return 1;
   }
   else
      return 0;
}
//11
int A_List::makeListEmpty(){
   while(!isEmpty()){
      deleteAtFirst();
   }
   return 1;
}
//12
int A_List::searchAtLast(){
   if(!isEmpty()){
      return arr[size-1];
   }
   else
      return -1;
}
//13
int A_List::searchAtFirst(){
   if(!isEmpty()){
      return arr[0];
   }
   else
      return -1;
}
//14
int A_List::searchAnElt(int key){
   if(!isEmpty()){
      for(int i=0;i<size;i++){
         if(arr[i]==key){
            return i;
         }
      }
      return -2;
   }
   else
      return -1;
}
//15
int A_List::retrieveEltIndex(int index){
   if(!isEmpty()){
      if(index>size-1)
         return -2;
      else
         return arr[index];
   }
   else
      return -1;
}
//16
int A_List::deleteByPos(int pos){
   if(!isEmpty()){
      if(pos<=0||pos>=size+1)
         return -2;
      else{
         for(int i=pos-1;i<size;i++)
            arr[i]=arr[i+1];
         arr[--size]=-1;
      }
      return 1;
   }
   else
      return -3;
}
//17
int A_List::deleteAtLast(){
   if(!isEmpty()){
      arr[--size]==-1;
      return 1;
   }
   else
      return 0;
}
