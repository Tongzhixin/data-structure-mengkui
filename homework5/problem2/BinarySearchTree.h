//
// Created by 仝 on 2019/11/25.
//

#ifndef PROBLEM2_BINARYSEARCHTREE_H
#define PROBLEM2_BINARYSEARCHTREE_H

#include <iostream>
using namespace std;
extern int count1;
extern int count2;
struct Node{
    int key;
    char value[40];
    Node(int x=0,char *m=NULL);
};
class BinarySearchTree{

private:
    struct BinaryNode{
        Node data;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode (Node the_data,BinaryNode *lt=NULL,BinaryNode *rt=NULL):data(the_data),left(lt),right(rt){}
    };
    BinaryNode *root;
    void insert(Node *x,BinaryNode *&t);
    void remove(int x,BinaryNode *&t);
    Node * find(int x,BinaryNode *t);
    void makeEmpty(BinaryNode *t);
    void remove_node(BinaryNode *t);
    void first_i_pri(BinaryNode *t,int i,int N,int *p);
    void print_key(BinaryNode *t,int *&p);
    void remove_range1(BinaryNode *&t,int low,int high);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    Node *find(int x);
    void insert(Node *x);
    void remove(int x);

    void first_i(int i,int N,int *p);
    void print_key(int *&p);
    void remove_range(int low,int high);
};



#endif //PROBLEM2_BINARYSEARCHTREE_H
