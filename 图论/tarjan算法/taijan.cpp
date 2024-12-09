#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int head[maxn],ver[maxn*2],Next[maxn*2];
int dfn[maxn],low[maxn],n,m,tot,num;
bool bridge[maxn*2];
inline void add(int x,int y){
    ver[++tot]=y,Next[tot]=head[x],head[x]=tot;
}
void tarjan(int x,int in_edge){
    dfn[x]=low[x]=++num;
    for(int i=head[x];i;i=Next[i]){
        int y=ver[i];
        if(!dfn[y]){
            tarjan(y,i);
            low[x]=min(low[x],low[y]);
            if(low[y]>dfn[x]){
                bridge[i]=bridge[i^1]=1;
            }
        }
        else if(i!=(in_edge^1))
            low[x]=min(low[x],dfn[y]);
    }
}
int main(){
    cin>>n>>m;
    tot=1;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i,0);
    }
    for(int i=2;i<tot;i+=2){
        if(bridge[i])printf("%d %d\n",ver[i^1],ver[i]);
    }
}