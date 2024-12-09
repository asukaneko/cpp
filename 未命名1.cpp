#include<stdio.h>
int y,m,d;
int sum=0;
int main(){
	while(scanf("%d%d%d",&y,&m,&d)!=EOF){
		int fg=0;
		if(y%4==0||y%400==0)fg=1;
		for(int i=1;i<m;i++){
			if(i==2&&fg)sum+=29;
			else if(i==2&&!fg)sum+=28;
			else if(i==4||i==6||i==9||i==11)sum+=30;
			else sum+=31;
		}
		sum+=d;
		printf("%d\n",sum);
		sum=0;
	}
}