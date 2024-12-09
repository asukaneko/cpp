#include<stdio.h>
#include<string.h>
int n,m,t;
int a[51][1001];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&n);
		getchar();
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				char tmp;
				scanf("%c",&tmp);
				switch(tmp){
					case 'A':a[i][j]=1;break;
					case 'C':a[i][j]=2;break;
					case 'G':a[i][j]=3;break;
					case 'T':a[i][j]=4;break;
				}
			}
			getchar();
		}
		int vis[5]={0};
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			for(int j=1;j<=m;j++){
				vis[a[j][i]]++;
			}
			int mx=-10,st=0;
			for(int i=1;i<=4;i++){
				if(vis[i]>mx){
					mx=vis[i];
					st=i;
				}
			}
			switch(st){
				case 1:printf("A");break;
				case 2:printf("C");break;
				case 3:printf("G");break;
				case 4:printf("T");break;
			}
			for(int j=1;j<=m;j++){
				if(a[j][i]!=st)ans++;
			}
		}
		printf("\n");
		printf("%d\n",ans);
			
	}
}