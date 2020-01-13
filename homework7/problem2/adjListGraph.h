//
// Created by 仝 on 2019/12/19.
//
//Storge\ver_s、count、count1、
#ifndef PROBLEM2_ADJLISTGRAPH_H
#define PROBLEM2_ADJLISTGRAPH_H

#include <iostream>
using namespace std;

class adjListGraph{
private:
    int ver_s;
    int edges;
    struct edgeNode{
        int end;
        int weight;
        edgeNode *next;

        edgeNode(int e,int w,edgeNode *n=NULL){end=e;weight=w;next=n;}
    };
    struct verNode{
        int ver;
        edgeNode *head;

        verNode(edgeNode *h=NULL){head=h;}
    };
    verNode *verList;
    int find(int v){
        for (int i=0; i < ver_s; ++i)
            if(verList[i].ver==v) return i;
    }
    bool isDAG(int start,bool visited[]);
    void topSort(int start,bool visited[],int *Storge);//Storge

public:
    adjListGraph(int vSize,int d[]);
    void insert(int x,int y,int w);
    void remove(int x,int y);
    bool exist(int x,int y);
    ~adjListGraph();
    bool checkroute(int x,int y,int visited[],int N);//改编

    bool checkroute1(int start,int end,int visited[]);//改编
    bool isDAG();
    void topSort(int *Storge);//Storge
};



#endif //PROBLEM2_ADJLISTGRAPH_H
