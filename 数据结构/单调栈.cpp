//题目：https://www.luogu.com.cn/problem/P5788
#include <stack>
#include <iostream>
using namespace std;
const int maxn=3e6+1;
int n,a[maxn],ans[maxn];
stack<int> s;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=n;i>=1;i--){
        while(!s.empty()&&a[i]>=a[s.top()])s.pop();
        ans[i]=s.empty()?0:s.top();
        s.push(i);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}