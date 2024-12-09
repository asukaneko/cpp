//速度略微低于线段树
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100010],sum[100010],add[100010],L[100010],R[100010],pos[100010];
int n,m,t;
void change(int l,int r,int d){
	int p=pos[l],q=pos[r];
	if(p==q){
		for(int i=l;i<=r;i++)a[i]+=d;
		sum[p]+=d*(r-l+1);
	} 
	else{
		for(int i=p+1;i<=q-1;i++)add[i]+=d;
		for(int i=l;i<=R[p];i++)a[i]+=d;
		sum[p]+=d*(R[p]-l+1);
		for(int i=L[q];i<=r;i++)a[i]+=d;
		sum[q]+=d*(r-L[q]+1);
	}
}
int ask(int l,int r){
	int p=pos[l],q=pos[r];
	int ans=0;
	if(q==p){
		for(int i=l;i<=r;i++)ans+=a[i];
		ans+=add[p]*(r-l+1);
		
	}
	else{
		for(int i=p+1;i<q;i++)ans+=sum[i]+add[i]*(R[i]-L[i]+1);
		for(int i=l;i<=R[p];i++)ans+=a[i];
		ans+=add[p]*(R[p]-l+1);
		for(int i=L[q];i<=r;i++)ans+=a[i];
		ans+=add[q]*(r-L[q]+1);
	}
	return ans;
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	t=sqrt(n);
	for(int i=1;i<=t;i++){
		L[i]=(i-1)*t+1;
		R[i]=i*t;
	}
	if(R[t]<n)t++,L[t]=R[t-1]+1,R[t]=n;
	for(int i=1;i<=t;i++){
		for(int j=L[i];j<=R[i];j++){
			pos[j]=i;
			sum[i]+=a[j];
		}
	}
	while(m--){
		int x,y,d,op;
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld%lld%lld",&x,&y,&d);
			change(x,y,d);
		}
		else{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",ask(x,y));
		}
	}
}