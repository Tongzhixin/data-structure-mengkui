//
// Created by 仝 on 2019/11/25.
//
#include "BinarySearchTree.h"


void BinarySearchTree::insert(Node *x, BinarySearchTree::BinaryNode *&t) {
    if(t==NULL)
        t=new BinaryNode(*x,NULL,NULL);
    else if(x->key<t->data.key)
        insert(x,t->left);
    else insert(x,t->right);
}

void BinarySearchTree::remove(int x, BinarySearchTree::BinaryNode *&t) {
    if(t==NULL)return;
    if(x<t->data.key)remove(x,t->left);
    else if(t->data.key<x) remove(x,t->right);
    else if(t->left!=NULL&&t->right!=NULL){
        BinaryNode *tmp=t->right;
        while(tmp->left!=NULL)tmp=tmp->left;
        t->data=tmp->data;
        remove(t->data.key,t->right);
    }
    else{
        BinaryNode *oldNode=t;
        t=(t->left!=NULL)?t->left:t->right;
        delete oldNode;
    }

}

Node  *BinarySearchTree::find(int x, BinarySearchTree::BinaryNode *t) {
    if(t==NULL||t->data.key==x)
        if(t==NULL)return NULL;
        else return &t->data;
    if(x<t->data.key)
        return find(x,t->left);
    else return find(x,t->right);
}

void BinarySearchTree::makeEmpty(BinarySearchTree::BinaryNode *t) {
    if(t==NULL)return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}

BinarySearchTree::BinarySearchTree() {
    root=NULL;
}

BinarySearchTree::~BinarySearchTree() {
    makeEmpty(root);
}

Node *BinarySearchTree::find(int x) {
    return find(x,root);
}

void BinarySearchTree::insert(Node *x) {
    insert(x,root);
}

void BinarySearchTree::remove(int x) {
    remove(x,root);
}

void BinarySearchTree::first_i_pri(BinaryNode *t,int i,int N,int *p) {
    if(t==NULL)return;
    first_i_pri(t->left,i,N,p);
    count1++;
    if(count1 == N - i)
        *p=t->data.key;
    first_i_pri(t->right,i,N,p);
}

void BinarySearchTree::remove_range1(BinaryNode *&t,int low, int high) {
    if(t==NULL)return;
    remove_range1(t->left,low,high);
    if(high==65535||low==-65535)
        while (t!=NULL&&t->data.key>low&&t->data.key<high) {
            if(t->left==NULL&&t->right==NULL) {

                delete t;
                t = NULL;
            }
            remove_node(t);
        }
    else
        while (t!=NULL&&t->data.key>=low&&t->data.key<=high) {
            if(t->left==NULL&&t->right==NULL) {

               delete t;
                t = NULL;
            }
            remove_node(t);
         }
    if(t!=NULL)remove_range1(t->right,low,high);
}

void BinarySearchTree::remove_node(BinaryNode *t) {
    if(t==NULL)return;
    if(t->left!=NULL&&t->right!=NULL){
        BinaryNode *tmp=t->right;
        while(tmp->left!=NULL)tmp=tmp->left;
        t->data=tmp->data;
        remove(t->data.key,t->right);
    }
    else{
        if(t->right!=NULL){
            BinaryNode *next_node=t->right;
            t->data=next_node->data;
            t->right=next_node->right;
            t->left=next_node->left;
        }
        else{
            BinaryNode *next_node=t->left;
            t->data=next_node->data;
            t->right=next_node->right;
            t->left=next_node->left;

        }
    }

}

void BinarySearchTree::first_i(int i, int N,int *p) {
    first_i_pri(root,i,N,p);
}

void BinarySearchTree::print_key(BinarySearchTree::BinaryNode *t,int *&p) {
    if(t==NULL)return;
    print_key(t->left,p);
    p[count2]=t->data.key;
    count2++;
    print_key(t->right,p);
    
}

void BinarySearchTree::print_key(int *&p) {
    print_key(root,p);
}

void BinarySearchTree::remove_range(int low, int high) {
    remove_range1(root,low,high);

}

Node::Node(int x, char *m) :key(x){
    for(int i=0;m[i]!='\0'&&i<40;i++)
        value[i]=m[i];
}
