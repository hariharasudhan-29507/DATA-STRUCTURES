#include<iostream>
using namespace std;
class TreeNode {
   private:
    int id;
    string name;
    TreeNode *left;
    TreeNode *right;

   public:
    TreeNode(int,string);
    ~TreeNode();
    friend class BST;
};

class BST {
    TreeNode *root;

   public:
     BST();
     ~BST();
     TreeNode* getRoot();
     bool isempty();
     bool insertNode(TreeNode* ,TreeNode*);
     TreeNode* deleteNode(TreeNode*,int);
     TreeNode* minValue(TreeNode*);
     void inorder(TreeNode* );
     void preorder(TreeNode* );
     void postorder(TreeNode* );
     TreeNode* search(TreeNode*,int);
     int findMin(TreeNode*);
     int findMax(TreeNode*);

};
