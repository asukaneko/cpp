#include<stdio.h>
int n,m;
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		int x=n/m,y=x*m+1;
		int st=0;
		for(int i=1;i<=m;i++)st+=2*i;
		st=st/m;
		for(int i=1;i<=x;i++){
			printf("%d ",st+(i-1)*2*m);
		}
		if(n%m==0)continue;
		int sum=0;
		for(int i=y;i<=n;i++)sum+=i*2;
		printf("%d\n",sum/(n-y+1));
	}
}