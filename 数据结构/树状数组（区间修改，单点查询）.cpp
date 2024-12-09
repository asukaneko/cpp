#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+1;
ll n,m,a[maxn],c[maxn];
ll lowbit(ll x){
	return x&(-x);
}
#define gc getchar
inline ll read(){
        ll a=0;int f=0;char p=gc();
        while(!isdigit(p)){f|=p=='-';p=gc();}
        while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48);p=gc();}
        return f?-a:a;
}
inline void add(int x, ll num) {
    for(int i=x;i<=n;i+=lowbit(i)){
        c[x] += num;
    }
}
inline ll sum(int x){
	ll ans = 0;
    for(int i=x;i>=1;i-=lowbit(x)){
        ans += c[x];
    }
    return ans;
}

inline void build(){
    for (int i=1; i<=n; i++)
        for (int j=i; j>=i-lowbit(i)+1; j--)
            c[i]+=a[j];
}

int main(){
	n=read();m=read();
	ll now=0,last=0;
	for(int i=1;i<=n;i++){
		now=read();
		add(i, now - last);
        last = now;
	}
	//build();
	for(int i=1;i<=m;i++){
		int x,y,z,k;
		x=read();
		switch(x){
			case 1:{
				y=read(),z=read(),k=read();
				add(y, k);
                add(z + 1, -k);
				break;
			}
			case 2:{
				y=read();
				printf("%lld\n",sum(y));
				break;
			}
		}
	}
}



