#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,p;
int mul(int a,int b,int p){
    int ans=0;
    for(;b;b>>=1){
        if(b&1)ans=(ans+a)%p;
        a=a*2%p;
    }
    return ans;
}
signed main(){
    cin>>a>>b>>p;
    cout<<mul(a,b,p);
}
