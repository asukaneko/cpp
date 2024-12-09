#include<stdio.h>
#define maxn 100
int max(int a,int b){
	return a>b?a:b;
}
int a[maxn][maxn],dp[maxn][maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			scanf("%d",&a[i][j]);
			//if(a[i][j]==-1)a[i][j]=-10000001;
			//dp[i][j]=a[i][j];
		}
		
	}
	for(int i=1;i<=n;i++)dp[1][i]=a[1][i];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(a[i][j]%2)dp[i][j]=max(dp[i-1][j]+a[i][j],dp[i][j-1]+a[i][j]);
			else dp[i][j]=dp[i-1][j]+a[i][j];		
		}
	}
	printf("%d",dp[n][1]);
}
