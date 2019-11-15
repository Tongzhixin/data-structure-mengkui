//
// Created by 仝 on 2019/10/29.
//

#ifndef HOMEWORK_QUEUE_H
#define HOMEWORK_QUEUE_H
#include <iostream>
using namespace std;
class binaryTree{
    friend void preorder_tranversal(int num, int** nodes, int* preOrder);
    friend void midorder_tranversal(int num, int** nodes, int* midOrder);
    friend void postorder_tranversal(int num, int** nodes, int* postOrder);
private:
    struct Node{
        Node *left,*right;
        int data{};

        Node():left(NULL),right(NULL){}
        explicit Node(int item,Node *L=NULL,Node *R=NULL):data(item),left(L),right(R){}
        ~Node()= default;
    };
    Node *root{};
public:
    binaryTree():root(NULL){}
    explicit binaryTree(int x){root=new Node(x);}
    ~binaryTree();
    void clear();
    void clear(Node *&T);
    bool isEmpty();
    void preOrder(int num,int *preOrder);//递归入口
    void preOrder(int num,Node *t,int *preOrder);
    void midOrder(int num,int *preOrder);
    void midOrder(int num,Node *t,int *preOrder);
    void postOrder(int num,int *postOrder);
    void postOrder1(int num,Node *t,int *postOrder);



    void creat(int start, int num, int **nodes, Node *tmp);
};

#endif