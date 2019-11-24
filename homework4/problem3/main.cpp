#include <iostream>
#include "priorityQueue.h"
int minBoxSize(int N, int *items, int capacity) {
    int *data=new int[N];
    int num=0;

    for(int i=0;i<N;i++)data[i]=capacity;
    priorityQueue a(data, N);
    bubbleSort(items,N);
    for(int i=0;i<N;i++){
        a.decreaseKey(a.findMin(items[i]),items[i]);
        while(a.getHead()==0){
            num++;
            a.deQueue();
        }
    }
    while(!a.isEmpty())
        if(a.deQueue()<capacity)
            num++;
    delete[]data;
    return num;

    // 请构造并使用优先级队列类实现该函数
}






int main() {
    /* initialize */
    int N;
    cin>>N;
    int* items = new int[N];
    for(int i=0;i<N;i++) {
        cin>>items[i];
    }
    int capacity;
    cin>>capacity;

    /* test */
    cout<<minBoxSize(N, items, capacity)<<endl;

    /* free memory */
    delete []items;
    return 0;
}
