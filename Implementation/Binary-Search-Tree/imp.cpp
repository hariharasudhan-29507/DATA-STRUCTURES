#include"head.h"
TreeNode::TreeNode(int val1,string val2) {
   id = val1;
   name = val2;
   left=NULL;
   right=NULL;
}

TreeNode::~TreeNode(){
   id =0;
   name = "";
   right=NULL;
   left =NULL;
}

BST::BST() {root =NULL;}

BST::~BST() { root=NULL;}

bool BST::isempty() {return root==NULL;}

TreeNode* BST::getRoot() {return root; }

bool BST::insertNode(TreeNode *temp,TreeNode *newnode) {
   if(root ==NULL){
        root = newnode;
        return 1;
   }
   else{
      if(temp->id<newnode->id){
         if(temp->right==NULL) {
            temp->right=newnode;
            return 1;
         }
         else
            insertNode(temp->right,newnode);
      }
      else if (temp->id>newnode->id){
         if(temp->left==NULL) {
            temp->left=newnode;
            return 1;
         }
         else
            insertNode(temp->left,newnode);
      }
      else
         return 0;
   }
}

TreeNode* BST::deleteNode(TreeNode* temp,int key) {
    if(temp==NULL)
        return temp;
    if(key<temp->id)
        temp->left=deleteNode(temp->left,key);
    else if(key>temp->id)
        temp->right=deleteNode(temp->right,key);
    else{
        if(temp->left==NULL &&temp->right==NULL)
            return NULL;
        else if(temp->left==NULL){
            TreeNode* t=temp->right;
            temp=NULL;
            return t;
        }
        else if(temp->right==NULL){
            TreeNode* t= temp->left;
            temp=NULL;
            return t;
        }

        TreeNode* t =minValue(temp->right);
        temp->id=t->id;
        temp->right=deleteNode(temp->right,t->id);
    }
    return temp;
}

TreeNode* BST::minValue(TreeNode* temp){
    if(temp->left!=NULL)
        minValue(temp->left);
    else
        return temp;
}

void BST::inorder(TreeNode *temp){
   if(temp!=NULL){
      inorder(temp->left);
      cout<<temp->id<<":"<<temp->name<<",";
      inorder(temp->right);
   }
}

void BST::preorder(TreeNode *temp){
   if(temp!=NULL){
      cout<<temp->id<<":"<<temp->name<<",";
      preorder(temp->left);
      preorder(temp->right);
   }
}

void BST::postorder(TreeNode *temp){
   if(temp!=NULL){
      postorder(temp->left);
      postorder(temp->right);
      cout<<temp->id<<":"<<temp->name<<",";
    }
}

TreeNode* BST::search(TreeNode* temp,int key){
        if(temp==NULL ||temp->id ==key)
            return temp;
        else if(temp->id<key)
            search(temp->right,key);
        else if(temp->id>key)
            search(temp->left,key);
}

int BST::findMin(TreeNode* temp){
    if(temp->left!=NULL)
        findMin(temp->left);
    else
        return temp->id;
}

int BST::findMax(TreeNode* temp){
    if(temp->right!=NULL)
        findMax(temp->right);
    else
        return temp->id;
}
