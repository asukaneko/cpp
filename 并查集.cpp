#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5;
int n,m;
int f[maxn];
int find(int x){
    if(x==f[x])return x;
    return f[x]=find(f[x]);
}
void uni(int x,int y){
    x=find(x),y=find(y);
    f[y]=x;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)f[i]=i;
    while(m--){
        int x,y,opt;
        cin>>opt>>x>>y;
        if(opt==1)uni(x,y);
        else{
            x=find(x);
            y=find(y);
            if(x==y){
                cout<<"Y"<<endl;
                continue;
            }
            else cout<<"N"<<endl;
        }
    }

}
