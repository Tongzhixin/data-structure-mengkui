#include "priorityQueue.h"


void priorityQueue::buildHeap() {
    for(int i=currentSize/2;i>0;i--)
        percolateDown(i);
}

void priorityQueue::percolateDown(int hole) {
    int child;
    int tmp=array[hole];

    for(;hole*2<=currentSize;hole=child){
        child=hole*2;
        if(child!=currentSize&&array[child+1]<array[child])
            child++;
        if(array[child]<tmp)array[hole]=array[child];
        else break;
    }
    array[hole]=tmp;
}

priorityQueue::priorityQueue(int *data, int size) {
    array=new int[size+1];
    for(int i=0;i<size;i++)
        array[i+1]=data[i];
    currentSize=size;
    buildHeap();
}

priorityQueue::~priorityQueue() {
    delete []array;
}

bool priorityQueue::isEmpty() {
    return currentSize==0;
}

int priorityQueue::deQueue() {
    int minItem;
    minItem=array[1];
    array[1]=array[currentSize--];
    percolateDown(1);
    return minItem;
}

int priorityQueue::getHead() {
    return array[1];
}

int priorityQueue::findMin(int x) {
    int tmp=array[currentSize];
    int s=1;
    int count=currentSize;
    while(s<=currentSize){
        if(x<=array[s]){
            if(tmp>array[s]) {
                tmp = array[s];
                count = s;
            }
        }
        s++;
    }

    return count;
}

void priorityQueue::decreaseKey(int i, int value) {
    array[i]-=value;
    int hole=i;
    int tmp=array[i];
    for(;hole>1&&tmp<array[hole/2];hole/=2)
        array[hole]=array[hole/2];
    array[hole]=tmp;
}

int *priorityQueue::getArray() {
    int *p=new int[currentSize];
    for(int i=0;i<currentSize;i++)p[i]=array[i+1];
    return p;
}
void bubbleSort(int *a,int size){
    int i,j;
    int tmp;
    bool flag= true;

    for(i=0;i<(size-1)&&flag;i++){
        flag= false;
        for(j=size-1;j>i;j--)
            if(a[j-1]<a[j]){
                tmp=a[j-1];
                a[j-1]=a[j];
                a[j]=tmp;
                flag= true;
            }
    }
}


