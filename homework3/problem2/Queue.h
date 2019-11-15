//
// Created by 仝 on 2019/10/29.
//

#ifndef HOMEWORK_QUEUE_H
#define HOMEWORK_QUEUE_H
#include <iostream>
using namespace std;

struct point{
    int x{},y{};
    point *last;
    point(int &x1,int &y1,point *n){x=x1;y=y1;last=n;}
    point():last(NULL){}
    ~point()= default;
};

class Queue{
private:
    struct node{
        point x;
        node *next;
        explicit node (point x1,node *n=NULL):x(x1),next(NULL){}
        node():next(NULL){}
        ~node()= default;
    };
    node *front,*rear;
public:
    Queue();
    ~Queue();
    bool isEmpty()const;
    void enQueue(point *cur);
    point *deQueue();
  //  point *getHead()const;

};
bool find_shortest_path(int** maze, int N, int** path, int& path_length);




#endif //HOMEWORK_QUEUE_H
