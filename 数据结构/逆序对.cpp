#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int a[maxn],b[maxn],cnt;
void merge(int l,int mid,int r){
    int i=l,j=mid+1;
    for(int k=l;k<=r;k++){
        if(j>r||i<=mid&&a[i]<=a[j])b[k]=a[i++];
        else b[k]=a[j++],cnt+=mid-i+1;
    }
    for(int k=l;k<=r;k++)a[k]=b[k];
}