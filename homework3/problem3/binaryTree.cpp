#include "binaryTree.h"



binaryTree::~binaryTree() {
    clear(root);

}

void binaryTree::clear() {
    clear(root);
}

bool binaryTree::isEmpty() {
    return root==NULL;
}



//这个创建函数用到了递归创建并且将指针进行了传递
void binaryTree::creat(int start, int num, int **nodes, Node *tmp) {

    if(nodes[start][1]!=-1){
        Node *left=new Node(nodes[nodes[start][1]][0]);
        tmp->left=left;
        creat(nodes[start][1],num,nodes,left);
    }
    if(nodes[start][2]!=-1){
        Node *right=new Node(nodes[nodes[start][2]][0]);
        tmp->right=right;
        creat(nodes[start][2],num,nodes,right);
    }
}

void binaryTree::clear(binaryTree::Node *&T) {
    if(T==NULL)return;
    clear(T->left);
    clear(T->right);
    delete T;
    T=NULL;
}


extern int counter2;
void binaryTree::preOrder(int num,int* preOrder) {
    this->preOrder(num,root,preOrder);

}

void binaryTree::preOrder(int num,binaryTree::Node *t, int *preOrder) {
    if(t==NULL)return;
    preOrder[counter2]=t->data;
    counter2++;
    this->preOrder(num,t->left,preOrder);
    this->preOrder(num,t->right,preOrder);
}

void binaryTree::midOrder(int num, int *preOrder) {
    midOrder(num,root,preOrder);
}
extern int counter;
void binaryTree::midOrder(int num, binaryTree::Node *t, int *preOrder) {
    if(t==NULL)return;
    midOrder(num,t->left,preOrder);
    preOrder[counter]=t->data;
    counter++;
    midOrder(num,t->right,preOrder);
}
extern int counter1;
void binaryTree::postOrder(int num, int *postOrder) {
    this->postOrder1(num,root,postOrder);
}

void binaryTree::postOrder1(int num, binaryTree::Node *t, int *postOrder) {
    if(t==NULL)return;
    postOrder1(num,t->left,postOrder);
    postOrder1(num,t->right,postOrder);
    postOrder[counter1]=t->data;
    counter1++;
}

