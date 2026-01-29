//思路 
//1 构建图
//2 求图中的最短路
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    //dp数组的初始化

    while(cin>>n>>m){
        vector<vector<vector<int>>> grid(n+1,vector<vector<int>>(n+1,vector<int>(n+1,INT_MAX/2)));
        for(int i=0;i<m;i++){
            //构建图
            int a,b,l;
            cin>>a>>b>>l;
            //无权图需要双向定义
            grid[a][b][0] = l;
            grid[b][a][0] = l;
        }
        //开始弗洛伊德
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    grid[i][j][k] = min(grid[i][j][k-1],grid[i][k][k-1]+grid[k][j][k-1]);
                }
            }
        }
        int res,x,y;
        cin>>x>>y;
        res = grid[x][y][n];
        if(res == INT_MAX/2) cout<<"No path"<<endl;
        else cout<<res<<endl;
    }

    return 0;
}