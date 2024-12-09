#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
vector<int>edge[maxn];
int d[maxn],c=0,n;
void dfs(int x,int fa){
    for(int y:edge[x]){
        if(y==fa)continue;
        d[y]=d[x]+1;
        if(d[y]>d[c])c=y;
        dfs(y,x);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1,0);//第一次搜索，从任意节点（1）开始
    d[c]=0;
    dfs(c,0);//第二次从最远的c开始搜索，得到的c即为答案
    cout<<d[c];
}