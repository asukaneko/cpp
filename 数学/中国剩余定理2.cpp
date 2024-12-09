//题目链接：https://www.luogu.com.cn/problem/P1495
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
#define ll long long
inline ll qmul(ll a, ll b)//快速乘法
{
    ll res=0;
    while(b>0)
	{
        if(b&1)res=(res+a);
        a=(a+a);
        b>>=1;
    }
    return res;
}
int a[15],p[15],n;
int crt(int a[],int p[],int n){
	int k=p[1],s=a[1];
	for(int i=2;i<=n;i++){
		while(k%a[i]!=p[i]) k+=s;
		s=qmul(s,a[i]);
	}
	return k;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i],&p[i]);
	}
	printf("%lld",crt(a,p,n));
	return 0;
}
