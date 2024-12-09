#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+1;
ll n,m,a[maxn],c[maxn];
ll lowbit(ll x){
	return x&(-x);
}
void add(int x,int v){
	for(int i=x;i<=n;i+=lowbit(i)){
		c[i]+=v;
	}
}
ll sum(int x){
	ll ans1=0;
	for(int i=x;i>=1;i-=lowbit(i)){
		ans1+=c[i];
	}
	return ans1;
}
ll sum(int x,int y){
	return sum(y)-sum(x-1);
}
void build(){
    for (int i=1; i<=n; i++)
        for (int j=i; j>=i-lowbit(i)+1; j--)
            c[i]+=a[j];
}

int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	build();
	for(int i=1;i<=m;i++){
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		switch(x){
			case 1:{
				add(y,k);
				break;
			}
			case 2:{
				printf("%lld\n",sum(y,k));
				break;
			}
		}
	}
}