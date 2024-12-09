#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>a;
    int n=100;
    for(int i=0;i<n;i++){
        a.push_back(i*i%100);
    }
    sort(a.begin(),a.end());
    int m=unique(a.begin(),a.end())-a.begin();//得出去重后的元素个数并放在0~m-1的空间中
    int b[100];
    for(int i=1;i<=n;i++)b[i]=i%20;
    sort(b+1,b+1+n);
    int k=unique(b+1,b+1+n)-(b+1);//把数组去重并把元素放在1-n中
    cout<<m<<" "<<k<<endl;
    for(int i=0;i<m;i++)cout<<a[i]<<endl;
    cout<<endl;
    for(int i=1;i<=k;i++)cout<<b[i]<<endl;
}