#include<bits/stdc++.h>
#include <cstddef>
using namespace std;
const int maxn=1e5;
vector<int>edge[maxn];
int size[maxn],weight[maxn],ct[2],n;//树的大小,重量,重心的节点
void getg(int x,int fa){
    size[x]=1;
    weight[x]=0;
    for(int y:edge[x]){
        if(y==fa)continue;
        getg(y,x);
        size[x]+=size[y];
        weight[x]=max(weight[x],size[y]);//weight[x]即为最大的子树数量
    }
    weight[x]=max(weight[x],n-size[x]);
    if(weight[x]<=n/2)ct[ct[0]!=0]=x;
}
