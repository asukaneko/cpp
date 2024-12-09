#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+1;
int f[maxn][20],d[maxn],t,n,m,s,lg[maxn];
vector<int>edge[maxn];
queue<int>q;
inline void add(int x,int y){
    edge[x].push_back(y);
    edge[y].push_back(x);
}
void dfs(int now,int fa){
    f[now][0]=fa,d[now]=d[fa]+1;
    for(int i=1;i<=lg[d[now]];++i){
        f[now][i]=f[f[now][i-1]][i-1];
    }
    for(int i=0;i<edge[now].size();i++){
        int y=edge[now][i];
        if(y!=fa)dfs(y,now);
    }
}
int lca(int x,int y){
    if(d[x]<d[y])swap(x,y);
    while(d[x]>d[y]){
        x=f[x][lg[d[x]-d[y]]-1];
    }
    if(x==y)return x;
    for(int k=lg[d[x]]-1;k>=0;--k){
        if(f[x][k]!=f[y][k])
            x=f[x][k],y=f[y][k];
    }
    return f[x][0];
}
int main(){
    cin>>n>>m>>s;
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    for(int i=1;i<=n;++i)lg[i]=lg[i-1]+(1<<lg[i-1]==i);//预处理lg函数值
    dfs(s,0);
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        cout<<lca(x,y)<<endl;
    }
}