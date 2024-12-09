#include<bits/stdc++.h>
using namespace std;
const int maxn=3010;
int a[maxn][maxn],d[maxn],n,m;
bool v[maxn];
void dijkstra(){//以1为起点
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    d[1]=0;
    for(int i=1;i<n;i++){//剩余的n-1个点
        int x=0;
        for(int j=1;j<=n;j++){
            if(!v[j]&&(x==0||d[j]<d[x]))x=j;
        }
        v[x]=1;
        for(int y=1;y<=n;y++)d[y]=min(d[y],d[x]+a[x][y]);
    }
}
int main(){
    
}