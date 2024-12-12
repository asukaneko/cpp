#include<stdio.h>
#include<string.h>
int n;
char a[201][1001];
int main(){
  while(scanf("%d",&n)!=EOF){
    for(int i=0;i<n;i++)scanf("%s",a[i]);
    for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
        if(strlen(a[i])>strlen(a[j])){
          char tmp[1001];
          strcpy(tmp,a[i]);
          strcpy(a[i],a[j]);
          strcpy(a[j],tmp);
        }
        else if(strlen(a[i])==strlen(a[j])&&strcmp(a[i],a[j])>0){
          char tmp[1001];
          strcpy(tmp,a[i]);
          strcpy(a[i],a[j]);
          strcpy(a[j],tmp);
        }
      }
    }
    for(int i=0;i<n;i++){
      printf("%s\n",a[i]);
    }
    
  }
}
/*
strcpy:字符串的赋值：strcpy(str,"123")，把123赋给str
strcmp:比较字符串的大小：strcmp(s1,s2)>0则s1>s2，=0则相等，<0则s1<s2
*/
