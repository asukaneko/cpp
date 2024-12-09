#include<bits/stdc++.h>
using namespace std;
int n,in[100010];
vector<int>edge[100010],val[100010];
vector<int> toposort(int n){
    vector<int>a;//a数组用于存放拓扑排序后的顺序,可以按照需求修改
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!in[i]){
            a.push_back(i);
            q.push(i);
        }

    }
    while(q.size()!=0){
        int u=q.front();q.pop();
        for(int i=0;i<edge[u].size();i++){
            int y=edge[u][i];
            if(!--in[y]){
                q.push(y);
                a.push_back(y);
            }
        }
    }
    vector<int>b;
    if(a.size()<n)return b;
    return a;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edge[a].push_back(b);
        val[a].push_back(c);
        in[b]++;
    }
    vector<int> ans=toposort(n);
    if(ans.size()==0)cout<<"None";
    for(auto i:ans)cout<<i<<endl;
}
