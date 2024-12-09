#include<bits/stdc++.h>
using namespace std;
bool v[10000000000];
void primes(int n){
    memset(v,0,sizeof(v));
    for(int i=2;i<=n;i++){
        if(v[i])continue;
        cout<<i<<endl;//i是质数
        for(int j=i;j<=n/i;j++)v[i*j]=1;
    }
}
int main(){
    int n;
    cin>>n;
    primes(n);
}