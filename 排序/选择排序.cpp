void cmp(int *a,int n){
    for(int i=1;i<n;i++){//数组1-n
        int min=i;
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[min])min=j;
        }
        int tmp=a[i];
        a[i]=a[min];
        a[min]=tmp;
    }
}