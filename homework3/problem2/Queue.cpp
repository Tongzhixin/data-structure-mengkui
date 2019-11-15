//
// Created by 仝 on 2019/10/29.
//放置队列的函数

#include "Queue.h"

bool Queue::isEmpty() const {
    return front==NULL;
}

void Queue::enQueue(point *cur) {
    if(rear==NULL)
        front=rear=new node(*cur);
    else
        rear=rear->next=new node(*cur);
}

point *Queue::deQueue() {
    node *tmp=front;
    point *value=new point ;
    value->x=front->x.x;
    value->y=front->x.y;
    value->last=front->x.last;
    front=front->next;
    if(front==NULL) rear=NULL;
    delete tmp;
    return value;
}

//point Queue::getHead() const {
  //  return front->x;
//}

Queue::Queue() {
    front=rear=NULL;

}

Queue::~Queue() {
    node *tmp;
    while(front!=NULL){
        tmp=front;
        front=front->next;
        delete tmp;
    }

}


