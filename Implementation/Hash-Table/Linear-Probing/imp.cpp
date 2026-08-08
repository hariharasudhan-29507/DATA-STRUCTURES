#include "head.h"

node :: node (){
   vid=-1;
   strcpy(vname," ");
}
void node :: getDetails(){
   cout<<"Enter id :";
   cin>>vid;
   cout<<"Enter name :";
   cin>>vname;
}
void node :: displayDetails(){
   cout<<"id :"<<vid<<"\t";
   cout<<"name :"<<vname; }


LinearProbing::LinearProbing(int s)
{
    tablesize=s;
    HT=new node*[s];
    isDeleted = new bool[s];
    for(int i=0;i<tablesize;i++)
    {
        HT[i]=NULL;
       isDeleted[i] = false;
    }
}

LinearProbing::~LinearProbing()
{

    for(int i=0; i<tablesize; ++i) {
        if(HT[i] != NULL) {
            delete HT[i];
        }
    }
    delete[] HT;
    delete[] isDeleted;
    tablesize=0;
}


int LinearProbing::hashFunction(int key)
{
    return key % tablesize;
}


int LinearProbing::insert(node* newNode)
{
    int startIdx = hashFunction(newNode->vid);
    int index = startIdx;

    do {

        if (HT[index] == NULL || isDeleted[index]) {
            if (HT[index] == NULL) {

                HT[index] = new node();
            }

            HT[index]->vid = newNode->vid;
            strcpy(HT[index]->vname, newNode->vname);
            isDeleted[index] = false;
           delete newNode;
            return index;
        }


        if (HT[index]->vid == newNode->vid && !isDeleted[index]) {
             cout << "Error: ID " << newNode->vid << " already exists." << endl;
             delete newNode;
             return -1;
        }

        index = (index + 1) % tablesize;
    } while (index != startIdx);

    delete newNode;
    return -2; }

int LinearProbing::delete1(int key)
{
    int startIdx = hashFunction(key);
    int index = startIdx;

    do {
        if (HT[index] != NULL && !isDeleted[index] && HT[index]->vid == key) {
            isDeleted[index] = true;
            return index;
        }

        if (HT[index] == NULL) {
            return -2;
        }

        index = (index + 1) % tablesize;
    } while (index != startIdx);

    return -2; // Not found
}

int LinearProbing::search(int key)
{
    int startIdx = hashFunction(key);
    int index = startIdx;

    do {
        if (HT[index] != NULL && !isDeleted[index] && HT[index]->vid == key) {
            return index; // Found
        }

        if (HT[index] == NULL) {
            return -2; // Not found
        }

        index = (index + 1) % tablesize;
    } while (index != startIdx);

    return -2; // Not found
}

void LinearProbing::display()
{
    for(int i=0;i<tablesize;i++)
    {
        cout<<"Index "<<i<<": ";
        if(HT[i]==NULL)
        {
            cout<<"Empty"<<endl;
        }
        else if (isDeleted[i]) {
            cout << "[DELETED]" << endl;
        }
        else
        {
            HT[i]->displayDetails();
            cout << endl;
        }
    }
}
