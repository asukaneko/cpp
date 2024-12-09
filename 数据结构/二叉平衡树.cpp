#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
struct bst{
    int l,r;
    int val;
}a[maxn];
int tot,root,inf=1<<30;
int New(int val){
    a[++tot].val=val;
    return tot;
}
void build(){
    New(-inf),New(inf);
    root=1;a[1].r=2;
}
int Get(int p,int val){
    if(p==0)return 0;
    if(val==a[p].val) return p;
    return val<a[p].val?Get(a[p].l,val):Get(a[p].r,val);
}
void Insert(int &p,int val){
    if(p==0){
        p=New(val);
        return;
    }
    if(val==a[p].val)return;
    val<a[p].val?Insert(a[p].l, val):Insert(a[p].r,val);
}
int GetNext(int val){
    int ans=2;
    int p=root;
    while(p){
        if(val==a[p].val){
            if(a[p].r>0){
                p=a[p].r;
                while(a[p].l>0)p=a[p].l;
                ans=p;
            }
            break;
        }
        if(a[p].val>val&&a[p].val<a[ans].val)ans=p;
        p=val<a[p].val?a[p].l:a[p].r;
    }
    return ans;
}
