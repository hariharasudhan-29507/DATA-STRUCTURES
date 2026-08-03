#include"header.h"
int main(){
   A_List a1;
   int *a;
   int s,c;
   cout<<"Enter capacity of Array:";
   cin>>c;
   a= new int[c];
   cout<<"Enter Size of Array:";
   cin>>s;
   for (int i=0;i<s;i++){
      cout<<"Enter Elements of Array "<<i+1<<" :";
      cin>>a[i];
   }
   A_List a2(a,s,c);
   A_List a3(a2);
   int choice;
   cout<<"\tMAIN MENU\n1.To Check Array is Empty or Not\n2.To Check Array is Full or Not\n3.Insert Elements\n4.Delete Elements\n5.Search Elements\n6.Make List Empty\n7.Retrieve An Index\n8.Display Data\n9.Exit"<<endl;
   do {
      cout<<"Enter your Choice:";
      cin>>choice;

      switch(choice){
         case 1:
            (a2.isEmpty())?(cout<<"Array 2 is Empty."<<endl):(cout<<"Array 2 is Not Empty."<<endl);
            break;

         case 2:
            (a2.isFull())?(cout<<"Array 2 is Full."<<endl):(cout<<"Array 2 is Not Full."<<endl);
            break;

         case 3:
            int c1;
            do{
               cout<<"\tInsert MENU\n1.Insert At First\n2.Insert At Last\n3.Insert At Any Position\n4.Display\n5.Back To MAIN MENU"<<endl;
               cout<<"Enter your Choice:";
               cin>>c1;
               int e,p,r;

               switch(c1){
                  case 1:
                    cout<<"Enter Element to Insert At First:";
                    cin>>e;
                    (a2.insertAtFirst(e))?(cout<<"Element "<<e<<" is successfully added at First"<<endl):(cout<<"Element is not successfully added."<<endl);
                    break;

                  case 2:
                    cout<<"Enter Element to Insert At Last:";
                    cin>>e;
                    (a2.insertAtLast(e))?(cout<<"Element "<<e<<" is successfully added at last"<<endl):(cout<<"Element is not successfully added."<<endl);
                    break;

                  case 3:
                    cout<<"Enter Position to Insert:";
                    cin>>p;
                    cout<<"Enter Element to Insert At Any Position:";
                    cin>>e;
                    r = a2.insertByPos(e,p);
                    if(r == -2){ cout<<"IndexOutOfBounds:Index is Invalid."<<endl;}
                    else if(r == -3){ cout<<"EmptyListError:List is Empty First Insert At First Position."<<endl;}
                    else if(r == 1){ cout<<"Element "<<e<<" is Insert At "<<p<<" successfully."<<endl;}
                    else if(r == 0){ cout<<"InsufficentCapacityError:List is Full."<<endl;}
                    else{cout<<"Error !!"<<endl;}
                    break;
                  case 4:
                    cout<<"Array 2 ";
                    if(a2.displayList()==0){ cout<<"EmptyListError:List is Empty."<<endl;}
                    break;

                  case 5:
                    cout<<"Returning to Main Menu..."<<endl;
                    break;

                  default:
                    cout<<"Error:Invalid Choice."<<endl;
               }
            }while(c1!=5);
            break;

         case 4:
             int c2;
             cout<<"\tDelete MENU\n1.Delete At First\n2.Delete At Last\n3.Delete At Any Position\n4.Display\n5.Back To MAIN MENU"<<endl;
               do{
		  cout<<"Enter your Choice:";
               cin>>c2;

               switch(c2){
                  case 1:
                    (a2.deleteAtFirst())?(cout<<"First Element is deleted successfully."<<endl):(cout<<"Element is not successfully added."<<endl);
                    break;

                  case 2:
                    (a2.deleteAtLast())?(cout<<"Last Element is deleted successfully."<<endl):(cout<<"Element is not successfully added."<<endl);
                    break;

                  case 3:
                    int p,r;
                    cout<<"Enter Position to Delete:";
                    cin>>p;
                    r = a2.deleteByPos(p);
                    if(r == -2){ cout<<"IndexOutOfBounds:Index is Invalid."<<endl;}
                    else if(r == -3){ cout<<"EmptyListError:List is Empty."<<endl;}
                    else if(r == 1){ cout<<"Element At Position "<<p<<" deleted successfully."<<endl;}
                    else{cout<<"Error !!"<<endl;}
                    break;

                  case 4:
                    cout<<"Array 2 ";
                    if(a2.displayList()==0){ cout<<"EmptyListError:List is Empty."<<endl;}
                    break;

                  case 5:
                    cout<<"Returning To Main Menu.."<<endl;
                    break;

                  default:
                    cout<<"Error:Invalid Choice."<<endl;
               }
             }while(c2!=5);
             break;

         case 5:
             int c3;
             do{
                cout<<"\tSearch MENU\n1.Search At First\n2.Search At Last\n3.Search An Any Element\n4.Display\n5.Back To MAIN MENU"<<endl;
                cout<<"Enter your Choice:";
                cin>>c3;

                switch(c3){
                   int r;
                   case 1:
                     r = a2.searchAtFirst();
                     if(r == -1){ cout<<"EmptyListError:List is Empty."<<endl;}
                     else{ cout<<"Element "<<r<<" is at First index."<<endl;}
                     break;

                   case 2:
                     r = a2.searchAtLast();
                     if(r == -1){ cout<<"EmptyListError:List is Empty."<<endl;}
                     else{ cout<<"Element "<<r<<" is at last index."<<endl;}
                     break;

                   case 3:
                     int key;
                     cout<<"Enter Element to Search By Key:";
                     cin>>key;
                     r = a2.searchAnElt(key);
                     if(r == -2){ cout<<"Element "<<key<<" Not Found at index "<<r<<"."<<endl; }
                     else if(r == -1){ cout<<"EmptyListError:List is Empty."<<endl;}
                     else{ cout<<"Element "<<key<<" Found at index "<<r<<"."<<endl;}
                     break;

                   case 4:
                     cout<<"Array 2 ";
                     if(a2.displayList()==0){ cout<<"EmptyListError:List is Empty."<<endl;}
                     break;

                   case 5:
                     cout<<"Returning to Main Menu..."<<endl;
                     break;

                   default:
                     cout<<"Error:Invalid Choice."<<endl;
                }
             }while(c3!=4);
             break;

         case 6:
             if(a2.makeListEmpty()==1){ cout<<"List Made Empty Successfully."<<endl;}
             break;

         case 7:
             int index,r;
             cout<<"Enter Element to Retrieve by Index:";
             cin>>index;
             r = a2.retrieveEltIndex(index);
             if(r == -2){ cout<<"IndexOutOfBounds:Index is Invalid."<<endl;}
             else if(r == -1){ cout<<"EmptyListError:List is Empty."<<endl;}
             else{ cout<<"\""<<r<<"\" is At index "<<index<<"."<<endl;}
             break;

         case 8:
            cout<<"Array 2 ";
            if(a2.displayList()==0){ cout<<"EmptyListError:List is Empty."<<endl;}
            break;

         case 9:
            cout<<"Exiting..."<<endl;
            break;

         default:
            cout<<"Error:Invalid Choice."<<endl;

      }
   }while(choice!=9);
}
