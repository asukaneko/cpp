inline int gcd(int a,int b) {    
    while(b^=a^=b^=a%=b);    
    return a;
}

inline int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}