//https://www.luogu.com.cn/problem/T280776
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int d[maxn],n,m,k;
bool v[maxn];
vector<int>edge[maxn],val[maxn];
priority_queue<pair<int,int>>q;
void djs(int s){//以s为起点
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    d[s]=0;
    q.push(make_pair(0,s));
    while(q.size()){
        int x=q.top().second;q.pop();
        if(v[x])continue;
        v[x]=1;
        for(int i=0;i<edge[x].size();i++){
            int y=edge[x][i],z=val[x][i];
            if(d[y]>d[x]+z){
                d[y]=d[x]+z;
                q.push(make_pair(-d[y],y));
            }
        }
    }
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        edge[x].push_back(y);
        edge[y].push_back(x);
        val[x].push_back(z);
        val[y].push_back(z);
    }
    for(int i=1;i<=n;i++){
        djs(i);
        sort(d+1,d+n+1);
        for(int i=2;i<=k+1;i++)cout<<d[i]<<" ";
        cout<<endl;
    }
}