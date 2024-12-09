#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
//#define int long long
struct Tree{
    int l,r;
    int sum,add;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define add(x) tree[x].add
}tree[maxn*4];
int a[maxn],op,x,y,k,n,m;
void build(int p,int l,int r){
    l(p)=l;r(p)=r;
    if(l==r){
        sum(p)=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    sum(p)=sum(p*2)+sum(p*2+1);
}  
void spread(int p){
    if(add(p)){
        sum(p*2)+=add(p)*(r(p*2)-l(p*2)+1);
        sum(p*2+1)+=add(p)*(r(p*2+1)-l(p*2+1)+1);
        add(p*2)+=add(p);
        add(p*2+1)+=add(p);
        add(p)=0;
    }
    
}
void change(int p,int l,int r,int d){
    if(l<=l(p)&&r>=r(p)){
        sum(p)+=(long long)d*(r(p)-l(p)+1);
        add(p)+=d;//因为这里sum已经加过了，所以add(p)应该在传送给子树后归零
        return;
    }
    spread(p);
    int mid=(l(p)+r(p))/2;
    if(l<=mid)change(p*2,l,r,d);
    if(r>mid)change(p*2+1,l,r,d);
    sum(p)=sum(p*2)+sum(p*2+1);
}
long long ask(int p,int l,int r){
    if(l<=l(p)&&r>=r(p))return sum(p);
    spread(p);
    int mid=(l(p)+r(p))/2;
    long long ans=0;
    if(l<=mid)ans+=ask(p*2,l,r);
    if(r>mid)ans+=ask(p*2+1,l,r);
    return ans;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,1,n);
    while(m--){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d%d",&x,&y,&k);
            change(1,x,y,k);
        }
        else{
            scanf("%d%d",&x,&y);
            printf("%lld\n",ask(1,x,y));
        }
    }
}