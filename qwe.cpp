#include<stdio.h>
#include<string.h>
int n,m;
int a[100][100],vis[100][100];
int mx[5]={0,1,0,-1,0};
int my[5]={0,0,1,0,-1};
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(vis,0,sizeof(vis));
		int i=1,j=1;
		int co=1;
		vis[i][j]=1;
		a[i][j]=1;
		while(co<=n*m-1){
		for(int k=1;k<=4;k++){
			while(i+mx[k]<=n&&i+mx[k]>=1&&j+my[k]<=m&&j+my[k]>=1&&!vis[i+mx[k]][j+my[k]]){
				i+=mx[k],j+=my[k];
				//printf("%d %d\n",i,j);
				vis[i][j]=1;
				a[i][j]=++co;
				
			}
		}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("%4d ",a[i][j]);
			}
			printf("\n");
		}
	}
}