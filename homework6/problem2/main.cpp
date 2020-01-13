#include <iostream>
using namespace std;
void quickSort(int a[],int low,int high);
void quickSort(int a[],int size){
    quickSort(a,0,size-1);
}
int divide(int a[],int low,int high);
void Nsqr(int a[],int size,int k);
void nlogN(int a[],int size,int k);


int main() {
    int N,k;
    cin>>N;
    int *a=new int[N];

    for(int i=0;i<N;++i){
        cin>>a[i];
    }
    cin>>k;

    Nsqr(a,N,k);
    cout<<endl;
    nlogN(a,N,k);

    delete []a;
    return 0;
}


void quickSort(int a[],int low,int high){
    int mid;
    if(low>=high) return;
    mid=divide(a,low,high);
    quickSort(a,low,mid-1);
    quickSort(a,mid+1,high);
}

int divide(int a[],int low,int high){
    int k=a[low];
    do{
        while(low<high&&a[high]>k)--high;
        if(low<high){
            a[low]=a[high];
            ++low;
        }
        while(low<high&&a[low]<k) ++low;
        if(low<high){
            a[high]=a[low];
            --high;
        }
    }while(low!=high);
    a[low]=k;
    return low;
}
void Nsqr(int a[],int size,int k){
    int min,max;
    for(int i=0;i<size-1;++i)
        for(int j=i+1;j<size;++j)
            if(a[i]+a[j]==k){
                min=a[i];
                max=a[j];
                if(min>max){
                    min=a[j];
                    max=a[i];
                }
                cout<<"("<<min<<","<<max<<")";
            }

}


void nlogN(int a[],int size,int k){
    quickSort(a,size);

    int j=size-1,i=0;
    while(i<j){
        if(a[i]+a[j]>k)--j;
        else if(a[i]+a[j]<k) ++i;
        else {
            cout<<"("<<a[i]<<","<<a[j]<<")";
            ++i;
            --j;
        }
    }
}
