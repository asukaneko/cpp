//https://www.luogu.com.cn/problem/P1807
#include<bits/stdc++.h>
using namespace std;
int n,in[100010],m;
int dp[100010],vis[100010];
vector<int>edge[100010],val[100010];
void toposort(int n){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!in[i]){
            q.push(i);
        }
    }
    while(q.size()!=0){
        int u=q.front();q.pop();
        for(int i=0;i<edge[u].size();i++){
            int y=edge[u][i],v=val[u][i];
            if(!--in[y]){
                q.push(y);
            }
            if(vis[u]){
                dp[y]=max(dp[y],dp[u]+v);
                vis[y]=1;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edge[a].push_back(b);
        val[a].push_back(c);
        in[b]++;
    }
    dp[n]=-1;//这里是当没有最短路时输出-1
    vis[1]=1;//从1开始到n结束
    toposort(n);
    cout<<dp[n];
}
