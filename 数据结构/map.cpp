#include<iostream>
#include<cstdio>
#include<map>
#include<string.h>
#include <string>
using namespace std;
string s,x,y,lis[1000001];
map<string,string>m;
int n,tot;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s=="#define"){
            cin>>x>>y;
            m[x]=y;tot++;
            m[x+';']=y;
            continue;
        }
        if(s=="#undef"){
            cin>>x;
            map<string,string>::iterator it=m.find(x);
            m.erase(it);
            continue;
        }
        cout<<s<<" ";
        while(cin>>s&&s!="\n"){
            if(m.find(s)==m.end()){
                cout<<s<<" ";
                continue;
            }
            cout<<m[s]<<" ";
        }
        cout<<endl;
    }
}