#include "BinarySearchTree.h"
int count1=-1;
int count2=0;
///int count3=0;
///int count4=0;
int main() {
    BinarySearchTree b;
    int N,key;
    int *first_i = new int(0);
    int count3=0;
    int count4=0;
    char ch[40];
    Node *p;

    cin>>N;
    int *x1=new int[N];
    int *x2=new int[N];
    int *x3=new int[N];
    for(int i=0;i<N;i++){
        cin>>key;
        cin.getline(ch,40);
        p=new Node(key,ch);
        b.insert(p);
    }

    int ied;
    cin>>ied;
    b.first_i(ied,N,first_i);


    int low,high;
    cin>>low>>high;
    b.remove_range(low,high);
    b.print_key(x1);
    count3=count2;

    int x;
    cin>>x;
    b.remove_range(-65535,x);
    count2=0;
    b.print_key(x2);
    count4=count2;

    int y;
    cin>>y;
    b.remove_range(y,65535);
    count2=0;
    b.print_key(x3);



    cout<<*first_i<<'\n';
    for(int i=0;i<count3;i++)cout<<x1[i]<<' ';
    cout<<endl;
    for(int i=0;i<count4;i++)cout<<x2[i]<<' ';
    cout<<endl;
    for(int i=0;i<count2;i++)cout<<x3[i]<<' ';
    cout<<endl;
    delete[] x1;
    delete[] x2;
    delete[] x3;




    return 0;
}