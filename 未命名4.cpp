#include<stdio.h>
#define maxn 100
int max(int a,int b){
	return a>b?a:b;
}
int a[maxn][maxn],dp[maxn][maxn];
int vis[maxn][maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==-1)a[i][j]=-10000000;
			dp[i][j]=a[i][j];
		}
		
	}
	dp[n][1]=a[n][1];
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=n-i+1;j++){
			if(j-1>=1&&a[i][j-1]%2&&!vis[i][j-1]){//jishu
				dp[i][j]=max(dp[i][j-1]+a[i][j],dp[i+1][j]+a[i][j]);
			}
			else {
				if(j<n-i+1&&!vis[i+1][j])dp[i][j]=max(dp[i][j],dp[i+1][j]+a[i][j]);
				else vis[i][j]=1;
			}
		}
	}
	int ans=-1000;
	for(int i=1;i<=n;i++)if(dp[1][i]>ans)ans=dp[1][i];
	printf("%d",ans);
}
