
#include "Queue.h"
// #include "Stack.h"

bool find_shortest_path(int** maze, int N, int** path, int& path_length) {
    // 请实现本函数
    // 函数逻辑请用队列类或栈类实现，并在本文件中引入相关头文件
    const int INF=10000;
    Queue st;
    point *cur=new point() ,*pre;
    int d[N][N];
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            d[i][j]=INF;
    bool flag= false;
    cur->x=cur->y=0;
    d[0][0]=0;
    st.enQueue(cur);
    int aspect[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
    if(maze[0][0]==1)return false;        //先判断是否第一个就是1
    else {
        while (!st.isEmpty()) {                          //采用bfs算法
            pre = st.deQueue();
            if (cur->x == N - 1 && cur->y == N - 1) {
                flag = true;
                break;
            }
            for (int i = 0; i < 4; ++i) {
                int nx = pre->x + aspect[i][0], ny = pre->y + aspect[i][1];
                if (0 <= nx && nx < N && 0 <= ny && ny < N && maze[nx][ny] == 0 && d[nx][ny] == INF) {
                    cur = new point(nx, ny, pre);
                    st.enQueue(cur);
                    d[nx][ny] = d[pre->x][pre->y] + 1; //我这里在点坐标里加了一个指针，
                    // 这样以来就可以通过指针访问上一个点，更为快捷
                }
            }
        }


        if (flag) {
            path_length = d[N - 1][N - 1];
            path[0] = new int[path_length + 1];
            path[1] = new int[path_length + 1];
            for (int i = path_length; i >= 0; --i) {
                path[0][i] = cur->x;
                path[1][i] = cur->y;
                cur = cur->last;
            }
        }
        return flag;
    }
}

// main cannot be modified
int main() {
    // initialize
    int N;
    cin>>N;
    int **maze = new int*[N];
    for(int i =0; i < N; i++) {
        maze[i] = new int[N];
    }
    for(int i = 0;i < N; i++){
        for(int j = 0;j < N;j++){
            cin>>maze[i][j];
        }
    }

    // path should be an array of size [2][path_length]
    int **path = new int*[2];
    int path_length = 0;

    // should be finished
    if(find_shortest_path(maze, N, path, path_length)){
        for(int i = 0;i < path_length+1; i++){
            //path[0][i]: row
            //path[1][i]: column
            cout<<'('<<path[0][i]<<','<<path[1][i]<<')';
        }
        cout<<endl;
    }else{
        cout<<"Not found"<<endl;
    }

    // free memory
    for (int i = 0; i < N; i++)
    {
        delete []maze[i];
        maze[i] = NULL;
    }
    delete []maze;
    maze = NULL;
    for (int i = 0; i < 2; i++)
    {
        if(path_length>0)delete []path[i];
        path[i] = NULL;
    }
    delete []path;
    path = NULL;

    return 0;
}

