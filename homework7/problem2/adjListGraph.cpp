//
// Created by 仝 on 2019/12/19.
//
#include "adjListGraph.h"
extern int count;
extern int count1;
adjListGraph::adjListGraph(int vSize, int *d) {
    ver_s=vSize;edges=0;

    verList=new verNode[vSize];
    for(int i=0;i<ver_s;++i)verList[i].ver=d[i];

}

void adjListGraph::insert(int x, int y, int w) {
    int u=find(x),v=find(y);
    verList[u].head=new edgeNode(v,w,verList[u].head);
    ++edges;

}

void adjListGraph::remove(int x, int y) {

}

bool adjListGraph::exist(int x, int y) {
    return false;
}

adjListGraph::~adjListGraph() {
    int i;
    edgeNode *p;
    for(i=0;i<ver_s;++i)
        while((p=verList[i].head)!=NULL){
            verList[i].head=p->next;
            delete p;

        }
    delete[]verList;

}

bool adjListGraph::checkroute(int x, int y,int visited[],int N) {
    int startNo,endNo;

    for(int i=0;i<ver_s;++startNo)
        if(verList[startNo].ver==x)break;
    if(startNo==ver_s)return false;

    for(endNo=0;endNo<ver_s;++endNo)
        if(verList[endNo].ver==y)break;
    if(endNo==ver_s)return false;

    return checkroute1(startNo,endNo,visited);
}

bool adjListGraph::checkroute1(int start, int end, int *visited) {
    edgeNode *p=verList[start].head;
    bool flag;
    visited[start]=count;
    count++;
    while (p!=NULL){
        if(p->end==end)return true;
        if(!visited[p->end]){
            flag=checkroute1(p->end,end,visited);
            if(flag)return true;
            else {
                --visited[p->end];
                --count;
            }
        }
        p=p->next;

    }
    return false;
}

bool adjListGraph::isDAG() {
    bool *visited=new bool[ver_s];
    bool flag;

    for(int i=0;i<ver_s;++i){
        flag=isDAG(i,visited);
        if(!flag)return false;
        visited[i]=false;
    }
    return true;
}

bool adjListGraph::isDAG(int start, bool *visited) {
    edgeNode *p=verList[start].head;
    bool flag;

    visited[start]= true;
    while(p!=NULL){
        if(visited[p->end])return false;
        else flag=isDAG(p->end,visited);
        if(!flag)return false;
        visited[p->end]= false;
        p=p->next;
    }
    return true;
}

void adjListGraph::topSort(int *Storge) {
    bool *visited = new bool[ver_s];
    for (int i = 0; i < ver_s; ++i)visited[i] = false;

    for (int i = 0; i < ver_s; ++i) {
        if (visited[i])continue;
        topSort(i, visited, Storge);
    }
}

void adjListGraph::topSort(int start, bool *visited,int *Storge) {
    edgeNode *p=verList[start].head;
    visited[start]=true;
    while(p!=NULL){
        if(!visited[p->end])
            topSort(p->end,visited,Storge);
        p=p->next;

    }
    Storge[count1]=verList[start].ver;
    ++count1;
}


