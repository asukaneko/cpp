#include<bits/stdc++.h>
using namespace std;
int d[100010],ans;
vector<int>edge[100010],val[100010];
bool v[100010];
void dp(int x){
    d[x]=1;
    for(int i=0;i<edge[x].size();i++){
        int y=edge[x][i],vl=val[x][i];
        if(v[y])continue;
        dp(y);
        ans=max(ans,d[x]+d[y]+vl);
        d[x]=max(d[x],d[y]+vl);
    }
}