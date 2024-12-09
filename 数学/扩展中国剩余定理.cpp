//题目链接：https://www.luogu.com.cn/problem/P4777
#include<bits/stdc++.h>
using namespace std;
typedef __int128 lll;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
ll n,p1,c1,p2,c2;
ll gi(){
	ll x=0; char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x;
}
ll Exgcd(ll a,ll b,ll &x0,ll &y0){
	if(!b){
		x0=1,y0=0;
		return a;
	}
	ll x1,y1,d=Exgcd(b,a%b,x1,y1);
	x0=y1;
	y0=x1-a/b*y1;
	return d;
}
ll Mul(ll a,ll b,ll p){ return ((ull)a*b-(ull)((ld)a/p*b)*p+p)%p; }// 防止溢出
ll Solve(ll a,ll b,ll c){
	ll x,y,d=Exgcd(a,b,x,y);
	return Mul(c/d,x,b/d);
}
ll Gcd(ll a,ll b){ return !b ?a :Gcd(b,a%b); }
int main(){
	n=gi();
	p1=gi(),c1=gi();
	for(int i=2;i<=n;i++){
		p2=gi(),c2=gi();
		ll k1=Solve(p1,p2,c2-c1),lcm=p1/Gcd(p1,p2)*p2;
		c1=(Mul(k1,p1,lcm)+c1)%lcm,p1=lcm;
	}
	printf("%lld\n",c1);
	return 0;
}