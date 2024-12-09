#define gc getchar
#define ll long long
inline ll read(){
        ll a=0;int f=0;char p=gc();
        while(!isdigit(p)){f|=p=='-';p=gc();}
        while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48);p=gc();}
        return f?-a:a;
}