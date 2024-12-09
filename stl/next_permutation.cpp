#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[1000];
    for(int i=1;i<=10;i++)a[i]=i;
    while(next_permutation(a+1,a+11)){//可以输出全排列
        for(int i=1;i<=10;i++)cout<<a[i]<<" ";
        cout<<endl;
    }
}