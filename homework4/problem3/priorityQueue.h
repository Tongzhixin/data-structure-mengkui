//
// Created by 仝 on 2019/10/29.
//

#ifndef HOMEWORK_QUEUE_H
#define HOMEWORK_QUEUE_H
#include <iostream>
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
    int deQueue();
    int getHead();
    int findMin(int x);
    void decreaseKey(int i,int value);
    int* getArray();
};
void bubbleSort(int *a,int size);

#endif //HOMEWORK_QUEUE_H
