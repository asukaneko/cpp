#include<bits/stdc++.h>
using namespace std;
const int maxn=2e7;
int a[maxn],q[maxn],h,t,n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    h=t=1;
    for(int i=1;i<=n;i++){//最小值
        while(h<t&&q[h]<=i-m)h++;
        while(h<t&&a[i]<=a[q[t-1]])t--;
        q[t++]=i;//由于是t++，所以t指向队列的最后一个元素+1的位置
        if(i>=m)printf("%d ",a[q[h]]);//头值即为最值
    }
    putchar('\n');
    h=t=1;
    for(int i=1;i<=n;i++){//最大值
        while(h<t&&q[h]<=i-m)h++;
        while(h<t&&a[i]>=a[q[t-1]])t--;
        q[t++]=i;
        if(i>=m)printf("%d\n",a[q[h]]);
    }
}