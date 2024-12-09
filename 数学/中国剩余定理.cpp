//题目链接：https://www.luogu.com.cn/problem/P3868
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[110],b[110],k;
inline int read()
{
   int x=0,f=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){
       if(ch=='-')
           f=-1;
       ch=getchar();
   }
   while(ch>='0'&&ch<='9'){
       x=(x<<1)+(x<<3)+(ch^48);
       ch=getchar();
   }
   return x*f;
}
inline ll qmul(ll a, ll b, ll m)//快速乘法
{
    ll res=0;
    while(b>0)
	{
        if(b&1)res=(res+a)%m;
        a=(a+a)%m;
        b>>=1;
    }
    return res;
}
inline void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	int tmp=x;
	x=y,y=tmp-a/b*y;
	return;
}
ll Ch()
{
	ll ans=0,lcm=1;
	for(ll i=1;i<=k;i++)
		lcm*=b[i];
	ll x,y;
    for(ll i=1;i<=k;i++)
    {
        ll p=lcm/b[i];
        exgcd(p,b[i],x,y);
        x=(x%b[i]+b[i])%b[i];
        ans=(ans+qmul(qmul(p,x,lcm),a[i],lcm))%lcm;
    }
    return (ans+lcm)%lcm;
}
int main()
{
	cin>>k;
	for(int i=1;i<=k;i++)
		a[i]=read();
	for(int i=1;i<=k;i++)
		b[i]=read(),a[i]=(a[i]%b[i]+b[i])%b[i];
	cout<<Ch();
	return 0;
}