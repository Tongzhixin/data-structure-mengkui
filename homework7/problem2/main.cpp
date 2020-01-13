#include "adjListGraph.h"
int count=1;
int count1=0;
int main() {
    int N,i,start,end,m;
    m=0;
    bool flag1,flag2;
    cin>>N;
    int *d=new int[N];
    int *visited=new int[N];
    int *x=new int[(N*(N-1))/2];
    int *y=new int[(N*(N-1))/2];
    char ch;
    for(int m1=0;m1<N;++m1)visited[m1]=0;
    for(i=0;i<(N*(N-1))/2;++i){

        cin>>ch;cin>>x[i];cin>>ch;cin>>y[i];cin>>ch;
        flag1=true;
        flag2=true;
        for(int j=0;j<m;++j){
            if(d[j]==x[i])flag1= false;
            if(d[j]==y[i]||x[i]==y[i])flag2=false;
        }
        if(flag1){
            d[m]=x[i];
            ++m;
        }
        if(flag2){
            d[m]=y[i];
            ++m;
        }
        cin.get(ch);
        if(ch=='\n')break;
    }

    adjListGraph g(N,d);
    for(int m1=0;m1<=i;++m1){
        g.insert(x[m1],y[m1],1);
    }
    cin>>start>>end;
    if(g.checkroute(start,end,visited,N)) {
        for (int m3 = 1; m3 <= N; ++m3) {
            flag1 = false;
            for (int n = 0; n < N; ++n)
                if (visited[n] == m3) {
                    cout << d[n] << " ";
                    flag1 = true;
                    break;
                }
            if (!flag1)break;
        }
        cout<<end;
    }
    cout<<endl;
    int *Storge=new int[N];
    if(!g.isDAG()) cout<<"loop";
    else {
        g.topSort(Storge);
        for(int m4=N-1;m4>=0;--m4)cout<<Storge[m4]<<" ";
    }
    delete[]x;
    delete[]y;
    delete[]d;
    delete[]Storge;
    return 0;
}