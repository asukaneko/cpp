#include<stdio.h>
#include<string.h>
int x,p,q;
int main(){
  while(scanf("%d<%d>%d",&x,&p,&q)!=EOF){
    int tp=x;
    int y=0,product=1;
	  while(x!=0){
		  y+=(x%10)*product;
		  x=x/10;
		  product=product*p;
	  }
    int a[100]; 
	  int count=0;
	  do{
		  a[count++]=y%q;
		  y=y/q;
	  }while(y!=0);
    printf("%d<%d>=",tp,p);
    for(int i=count-1;i>=0;i--){
		  printf("%d",a[i]);
	  }
    printf("<%d>\n",q);
  }
}
