#include"head.h"
AVLTreeNode::AVLTreeNode(int val,string n) {
    id = val;
    name=n;
    left = right = NULL;
    height = 1;
}
string AVLTreeNode::getName(){
   return name;
}
int AVLTreeNode::getData() {
    return id;
}
AVLTreeNode* AVLTreeNode::getLeft() {
    return left;
}
AVLTreeNode* AVLTreeNode::getRight() {
    return right;
}
int AVLTreeNode::getHeight() {
    return height;
}
void AVLTreeNode::setData(int val) {
    id = val;
}
void AVLTreeNode::setLeft(AVLTreeNode* node) {
    left = node;
}
void AVLTreeNode::setRight(AVLTreeNode* node) {
    right = node;
}
void AVLTreeNode::setHeight(int h) {
    height = h;
}

AVLTree::AVLTree() {
    root = NULL;
}

int AVLTree::mymax(int a, int b) {
    return (a > b) ? a : b;
}

int AVLTree::getHeight(AVLTreeNode *node) {
    return (node == NULL) ? 0 : node->getHeight();
}

int AVLTree::BF(AVLTreeNode *node) {
    return (node == NULL) ? 0 : getHeight(node->getLeft()) - getHeight(node->getRight());
}


AVLTreeNode* AVLTree::RightRotate(AVLTreeNode *k3) {
    AVLTreeNode *k2 = k3->getLeft();
    AVLTreeNode *T2 = k2->getRight();

    k2->setRight(k3);
    k3->setLeft(T2);

    k3->setHeight(1 + mymax(getHeight(k3->getLeft()), getHeight(k3->getRight())));
    k2->setHeight(1 + mymax(getHeight(k2->getLeft()), getHeight(k2->getRight())));
    return k2;
}

AVLTreeNode* AVLTree::LeftRotate(AVLTreeNode *k1) {
    AVLTreeNode *k2 = k1->getRight();
    AVLTreeNode *T2 = k2->getLeft();

    k2->setLeft(k1);
    k1->setRight(T2);

    k1->setHeight(1 + mymax(getHeight(k1->getLeft()), getHeight(k1->getRight())));
    k2->setHeight(1 + mymax(getHeight(k2->getLeft()), getHeight(k2->getRight())));
    return k2;
}

AVLTreeNode* AVLTree::LRRotate(AVLTreeNode *k3) {
    k3->setLeft(LeftRotate(k3->getLeft()));
    return RightRotate(k3);
}

AVLTreeNode* AVLTree::RLRotate(AVLTreeNode *k1) {
    k1->setRight(RightRotate(k1->getRight()));
    return LeftRotate(k1);
}


AVLTreeNode* AVLTree::insertNode(AVLTreeNode *node, int val,string n) {
    if (node == NULL) return new AVLTreeNode(val,n);

    if (val < node->getData())
        node->setLeft(insertNode(node->getLeft(), val,n));
    else if (val > node->getData())
        node->setRight(insertNode(node->getRight(), val,n));
    else
        return node;

    node->setHeight(1 + mymax(getHeight(node->getLeft()), getHeight(node->getRight())));
    int balance = BF(node);

    if (balance > 1 && val < node->getLeft()->getData()) return RightRotate(node);
    if (balance < -1 && val > node->getRight()->getData()) return LeftRotate(node);
    if (balance > 1 && val > node->getLeft()->getData()) return LRRotate(node);
    if (balance < -1 && val < node->getRight()->getData()) return RLRotate(node);

    return node;
}

AVLTreeNode* AVLTree::searchNode(AVLTreeNode *node, int val) {
    if (node == NULL || node->getData() == val) return node;
    if (val < node->getData()) return searchNode(node->getLeft(), val);
    return searchNode(node->getRight(), val);
}


AVLTreeNode* AVLTree::findMinNode(AVLTreeNode *node) {
    AVLTreeNode *current = node;
    while (current && current->getLeft() != NULL) current = current->getLeft();
    return current;
}

AVLTreeNode* AVLTree::findMaxNode(AVLTreeNode *node) {
    AVLTreeNode *current = node;
    while (current && current->getRight() != NULL) current = current->getRight();
    return current;
}


void AVLTree::inorderTraversal(AVLTreeNode *node) {
    if (node == NULL) return;
    inorderTraversal(node->getLeft());
    cout << node->getData() << " "<<node->getName()<<"\n";
    inorderTraversal(node->getRight());
}

void AVLTree::preorderTraversal(AVLTreeNode *node) {
    if (node == NULL) return;
    cout << node->getData() << " "<<node->getName()<<"\n";
    preorderTraversal(node->getLeft());
    preorderTraversal(node->getRight());
}

void AVLTree::postorderTraversal(AVLTreeNode *node) {
    if (node == NULL) return;
    postorderTraversal(node->getLeft());
    postorderTraversal(node->getRight());
    cout << node->getData() << " "<<node->getName()<<"\n";
}


AVLTreeNode* AVLTree::getRoot() {
    return root;
}
void AVLTree::setRoot(AVLTreeNode *node) {
    root = node;
}
