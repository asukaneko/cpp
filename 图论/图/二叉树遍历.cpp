#include<bits/stdc++.h>
using namespace std;
#define lc(x) x*2
#define rc(x) x*2+1
void dfs(int node){
    if(node==0)return;
    printf("%d",node)//前序遍历
    dfs(lc(node));
    //printf("%d",node)中序
    dfs(rc(node));
    //printf("%d",node)后序
}