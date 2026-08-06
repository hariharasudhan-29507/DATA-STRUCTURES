#include <iostream>
using namespace std;

class AVLTreeNode {
private:
    int id;
    string name;
    AVLTreeNode *left;
    AVLTreeNode *right;
    int height;

public:
    string getName();
    AVLTreeNode(int val,string n);
    int getData();
    AVLTreeNode* getLeft();
    AVLTreeNode* getRight();
    int getHeight();
    void setData(int val);
    void setLeft(AVLTreeNode* node);
    void setRight(AVLTreeNode* node);
    void setHeight(int h);
};


class AVLTree {
private:
    AVLTreeNode* root;
    int mymax(int a, int b);

public:
    AVLTree();
    AVLTreeNode* RightRotate(AVLTreeNode *k3);
    AVLTreeNode* LeftRotate(AVLTreeNode *k1);
    AVLTreeNode* LRRotate(AVLTreeNode *k3);
    AVLTreeNode* RLRotate(AVLTreeNode *k1);
    AVLTreeNode* insertNode(AVLTreeNode *node, int val,string n);
    AVLTreeNode* searchNode(AVLTreeNode *node, int val);
    AVLTreeNode* findMinNode(AVLTreeNode *node);
    AVLTreeNode* findMaxNode(AVLTreeNode *node);


    void inorderTraversal(AVLTreeNode *node);
    void preorderTraversal(AVLTreeNode *node);
    void postorderTraversal(AVLTreeNode *node);

    int getHeight(AVLTreeNode *node);
    int BF(AVLTreeNode *node);
    AVLTreeNode* getRoot();
    void setRoot(AVLTreeNode *node);
};
