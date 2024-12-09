#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m,sumv[maxn],setv[maxn];
string s;
int x,y,v;
void push_up(int o,int L,int R){
    sumv[o]=sumv[o*2]|sumv[o*2+1];
    if(setv[o])sumv[o]=setv[o];
}

void build(int o,int L,int R){
    if(L==R){
        sumv[o]=setv[o]=1;
        return;
    }
    int m=(L+R)/2;
    build(o*2,L,m);
    build(o*2+1,m+1,R);
    push_up(o, L,R);
}
void pushdown(int o){
    if(setv[o]){
        setv[o*2]=setv[o*2+1]=setv[o];
        setv[o]=0;
    }
}
void update(int o,int L,int R){
    if(x<=L&&y>=R){
        setv[o]=1<<v-1;
        sumv[o]=setv[o];
        return;
    }
    pushdown(o);
    int m=(L+R)/2;
    if(x<=m)update(o*2,L,m);
    else push_up(o*2,L,m);
    if(y>m)update(o*2+1,m+1,R);
    else push_up(o*2+1,m+1,R);
    push_up(o, L, R);
}
int query(int o,int L,int R){
    if(setv[o]){
        return sumv[o];
    }
    if(x<=L&&y>=R)return sumv[o];
    int m=(L+R)/2;
    int ans=0;
    if(x<=m)ans=ans|query(o*2,L,m);
    if(y>m)ans=ans|query(o*2+1,m+1,R);
    return ans;
}
int main(){
    int n,T,m;
    scanf("%d%d%d",&n,&T,&m);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        scanf("%s",&s);
        scanf("%d%d",&x,&y);
        if(x>y)swap(x,y);
        if(s[0]=='C'){
            scanf("%d",&v);
            update(1,1,n);
        }
        else{
            int ans=0;
            int t=query(1,1,n);
            while(t){
                ans+=t%2;
                t/=2;
            }
            cout<<ans<<endl;
        }
    }
}
