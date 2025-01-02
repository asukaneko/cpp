#include<stdio.h>
#include<string.h>
int max(int a,int b){
  return a>b?a:b;
}
char a[101],b[101],c[101];
int main(){
    while(scanf("%s%s",a,b)!=EOF){
        memset(c,'\0',sizeof(c));
        int lena=strlen(a),lenb=strlen(b);
        int i=lena-1,j=lenb-1;
        int k=max(i,j),t=0;
        c[k+1]='\0';
        while(i>=0&&j>=0){
            int tp=a[i]-'0'+(b[j]-'0')+t;
            if(tp<10)c[k]=tp+'0',t=0;
            else{c[k]=tp-10+'0';t=1;}
            i--,j--,k--;
        }
        while(i>=0){
            int tp=a[i]-'0'+t;
            if(tp<10)c[k]=tp+'0',t=0;
            else c[k]=tp-10+'0',t=1;
            i--,k--;
        }
        while(j>=0){
            int tp=b[j]-'0'+t;
            if(tp<10)c[k]=tp+'0',t=0;
            else c[k]=tp-10+'0',t=1;
            j--;k--;
        }
        if(t==1)printf("1");
        printf("%s\n",c);
    }
}
