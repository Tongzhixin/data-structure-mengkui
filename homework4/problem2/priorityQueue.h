//
// Created by 仝 on 2019/11/15.
//

#ifndef HOMEWORK_QUEUE_H
#define HOMEWORK_QUEUE_H
#include <iostream>
#include <cmath>
using namespace std;
class priorityQueue{
private:
    int currentSize;
    int *array;

    void buildHeap();
    void percolateDown(int hole);
public:
    priorityQueue(int *data,int size);
    ~priorityQueue();
    bool isEmpty();
    void enQueue(int &x);
    int deQueue();
    int getHead();
    int findMin(int x);

    void decreaseKey(int i,int value);
    int* getArray();
};



#endif //HOMEWORK_QUEUE_H
