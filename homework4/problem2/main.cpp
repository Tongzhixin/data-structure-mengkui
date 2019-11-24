#include<iostream>
#include "priorityQueue.h"


int main() {
    /* initialize */
    int N;
    cin>>N;
    int *nodes = new int[N];
    for(int i=0;i<N;i++){
        cin>>nodes[i];
    }
    int x, value;
    cin>>x;
    cin>>value;
    priorityQueue pq(nodes, N);
    // priorityQueue<int> pq(nodes, N);

    /* findMin() test */
    int r = pq.findMin(x);

    /* before decrease key */
    int* a;
    /* a should be a copy of array of priorityQueue */
    a = pq.getArray();
    for(int i=0;i<N;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;

    /* decreaseKey() test */
    pq.decreaseKey(r, value);

    a = pq.getArray();
    for(int i=0;i<N;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;

    while(!pq.isEmpty()){
        cout<<pq.deQueue()<<' ';
    }
    cout<<endl;

    /* free memory */
    delete []nodes;
    delete []a;

    return 0;
}