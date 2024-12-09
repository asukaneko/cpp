//https://www.luogu.com.cn/problem/P2197
#include<bits/stdc++.h>
using namespace std;
int t,n,x,ans=0;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            ans^=x;
        }
        if(ans){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
        ans=0;
    }
}