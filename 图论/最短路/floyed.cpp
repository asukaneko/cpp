#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
int d[maxn][maxn],n,m,q;
int main(){
    cin>>n>>m>>q;
    memset(d,0x3f,sizeof(d));//这里是为了让没有边的两点距离为无穷
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        d[x][y]=min(d[x][y],z);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d",d[x][y]);
    }
}