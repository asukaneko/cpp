#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
    //lower_bound找到第一个大于等于x的元素的下标或指针
    //upper_bound找到第一个大于x的元素的下标或指针
    //--lower_bound取反，变成小于
    int a[1000],n=100;
    for(int i=1;i<=n;i++)a[i]=i;
    sort(a+1,a+1+n);//先要排序
    int x=10;//x为要查找的数
    int i=lower_bound(a+1,a+1+n,x)-a;
    int j=upper_bound(a+1,a+1+n,x)-a;
    vector<int>b;
    for(int i=1;i<=n;i++)b.push_back(i);
    sort(b.begin(),b.end());
    int y=*--upper_bound(b.begin(),b.end(),x);//查找小于等于x的最大整数
    int k=*--lower_bound(b.begin(),b.end(),x);//查找小于x的最大整数
    int p=*upper_bound(b.begin(),b.end(),x);
    int q=*lower_bound(b.begin(),b.end(),x);
    cout<<a[i]<<" "<<a[j]<<" "<<y<<" "<<k<<endl;
    cout<<p<<" "<<q;
}