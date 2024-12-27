#include<stdio.h>
#include<string.h>
#include<math.h>
char a[101],b[101],c[101];
int main(){
    while(scanf("%s%s",a,b)!=EOF){
        memset(c,'\0',sizeof(c));
        int lena=strlen(a),lenb=strlen(b);
        int i=lena-1,j=lenb-1;
        int k=fmax(i,j),t=0;
        c[k+1]='\0';
        while(i>=0&&j>=0){
            int tp=a[i]-'0'+(b[j]-'0')+t;
            if(tp<10)c[k]=tp+'0',t=0;
            else{c[k]=tp-10+'0';t=1;}
            i--,j--,k--;
        }
        while(i>=0){
            int tp=a[i]-'0'+t;
            if(tp<10)c[k]=tp+'0',t=0;
            else c[k]=tp-10+'0',t=1;
            i--,k--;
        }
        while(j>=0){
            int tp=a[j]-'0'+t;
            if(tp<10)c[k]=tp+'0',t=0;
            else c[k]=tp-10+'0',t=1;
            j--;k--;
        }
        if(t==1)printf("1");
        printf("%s\n",c);
    }
}
/*
#include <stdio.h>
#include <string.h>
int compare(char *a, char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    if (len_a > len_b) return 1;
    if (len_a < len_b) return -1;
    return strcmp(a, b);
}
void add(char *a, char *b, char *result) {
    int carry = 0;
    int len_a = strlen(a);
    int len_b = strlen(b);
    int i = len_a - 1, j = len_b - 1, k = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result[k++] = sum % 10 + '0';
        carry = sum / 10;
    }
    result[k] = '\0';
    int len = strlen(result);
    for (i = 0; i < len / 2; i++) {
        char temp = result[i];
        result[i] = result[len - i - 1];
        result[len - i - 1] = temp;
    }
}

int main() {
    char a[1051], b[1051], result[1052];
    while (scanf("%s %s", a, b) == 2) {
        add(a, b, result);
        printf("%s ", result);
    }
    return 0;
}
*/
