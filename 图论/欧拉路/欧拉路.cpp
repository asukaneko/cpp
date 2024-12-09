#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int n,m,st=1,cnt[2]={0,0},d[maxn],du[maxn][2];//cnt={出口,入口}
vector<int>g[maxn];
stack<int>s;
void dfs(int now){
    for(int i=d[now];i<g[now].size();i=d[now]){//字典序最小
        d[now]=i+1;
        dfs(g[now][i]);
    }
    s.push(now);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        du[x][1]++;//出度
        du[y][0]++;//入度
    }
    for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
    bool fg=1;
    for(int i=1;i<=n;i++){
        if(du[i][0]!=du[i][1])fg=0;
        if(du[i][0]-du[i][1]==1)cnt[0]++;
        if(du[i][1]-du[i][0]==1)cnt[1]++,st=i;
    }
    if(!fg&&!(cnt[0]==cnt[1]&&cnt[0]==1)){cout<<"No";return 0;}
    dfs(st);
    while(!s.empty())cout<<s.top()<<" ",s.pop();
}