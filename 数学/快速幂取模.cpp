#include<bits/stdc++.h>
using namespace std;
int a,b,p;
#define int long long 
int power(int a,int b,int p){
    int ans=1%p;
    for(;b;b>>=1){
        if(b&1)ans=ans*a%p;
        a=a*a%p;
    }
    return ans;
}
signed main(){
    scanf("%d%d%d",&a,&b,&p);
    printf("%lld",power(a,b,p));
    
}