//题目 https://www.luogu.com.cn/problem/UVA11992
#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+20;
const int INF=2e9;
int x,y,x2,y2,v,op,_sum,_min,_max;
class Tree{
    public:
    int lc(int x){return x*2;}
    int rc(int x){return x*2|1;};
    void pushup(int o,int L,int R){
        sumv[o]=sumv[lc(o)]+sumv[rc(o)];
        minv[o]=min(minv[lc(o)],minv[rc(o)]);
        maxv[o]=max(maxv[lc(o)],maxv[rc(o)]);
        if(setv[o]>=0){
            sumv[o]=setv[o]*(R-L+1);
            minv[o]=maxv[o]=setv[o];
        }
        if(addv[o]){
            sumv[o]+=addv[o]*(R-L+1);
            minv[o]+=addv[o];
            maxv[o]+=addv[o];
        }
    }
    void pushdown(int o){
        if(setv[o]>=0){
            setv[lc(o)]=setv[rc(o)]=setv[o];
            addv[lc(o)]=addv[rc(o)]=0;
            setv[o]=-1;
        }
        if(addv[o]){
            addv[lc(o)]+=addv[o];
            addv[rc(o)]+=addv[o];
            addv[o]=0;
        }
    }
    void update(int o,int L,int R){
        if(y<=L&&y2>=R){
            if(op==1){
                addv[o]+=v;
            }
            else{
                setv[o]=v;
                addv[o]=0;
            }
            pushup(o,L,R);
            return;
        }
        pushdown(o);
        int m=(L+R)/2;
        if(y<=m)update(lc(o),L,m);else pushup(lc(o),L,m);
        if(y2>m)update(rc(o),m+1,R);else pushup(rc(o),m+1,R);
        pushup(o,L,R);
    }
    void query(int o,int L,int R, int ADD){
        if(setv[o]>=0){
            int tmp=ADD+setv[o]+addv[o];
            _sum+=tmp*(min(y2,R)-max(y,L)+1);
            _min=min(_min,tmp);
            _max=max(_max,tmp);
            return;
        }
        if(y<=L&&R<=y2){
            _sum+=sumv[o]+ADD*(R-L+1);
            _min=min(_min,minv[o]+ADD);
            _max=max(_max,maxv[o]+ADD);
            return;
        }
        int m=(L+R)/2;
        if(y<=m)query(lc(o),L,m,ADD+addv[o]);
        if(y2>m)query(rc(o),m+1,R,ADD+addv[o]);
    }
    int maxv[maxn],minv[maxn],sumv[maxn],addv[maxn],setv[maxn];
};
Tree tree[30];
int main(){
    int r,c,m;
    while(scanf("%d%d%d",&r,&c,&m)!=EOF){
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=r;i++){
            memset(tree[i].setv,-1,sizeof(tree[i].setv));
            tree[i].setv[1]=0;
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&op);
            if(op==1||op==2){
                scanf("%d%d%d%d%d",&x,&y,&x2,&y2,&v);
                for(int j=x;j<=x2;j++){
                    tree[j].update(1, 1, c);
                }
            }
            else{
                scanf("%d%d%d%d",&x,&y,&x2,&y2);
                _sum=0;
                _min=INF;
                _max=-INF;
                for(int j=x;j<=x2;j++){
                    tree[j].query(1,1,c,0);
                }
                printf("%d %d %d\n",_sum,_min,_max);
            }
        }
    }
}