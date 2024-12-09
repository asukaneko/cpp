#include<bits/stdc++.h>
using namespace std;
struct rec {int x,y,z;}edge[500010];
int fa[100010],n,m,ans;
int get(int x){
    if(x==fa[x])return x;
    return fa[x]=get(fa[x]);
}
bool cmp(rec a,rec b){
    return a.z<b.z;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].z);
    }
    sort(edge+1,edge+m+1,cmp);
    //以边长从小到大排序，如果可以构成一个环，则跳过，如果不能，则加入
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int x=get(edge[i].x);
        int y=get(edge[i].y);
        if(x==y)continue;
        fa[x]=y;
        ans+=edge[i].z;
    }
    cout<<ans;
}