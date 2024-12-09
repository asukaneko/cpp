#include <stdio.h>
#include <stdlib.h>
#define Maxn 50
int a[Maxn][Maxn];
typedef struct{
    int x,y,sum;
}Node;
Node queue[Maxn*Maxn];
int front=0,rear=0;
void push(int x,int y,int sum){
    queue[rear].x=x;
    queue[rear].y=y;
    queue[rear].sum=sum;
    rear++;
}
Node pop(){
    Node node=queue[front];
    front++;
    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    int** Map = (int**)malloc(n * sizeof(int*));
    for (int i = 1; i <=n; i++) {
        Map[i] = (int*)malloc((n - i) * sizeof(int));
        for (int j = 1; j <= n - i+1; j++) {
            scanf("%d", &Map[i][j]);
        }
    }
    push(n,1,a[n][1]);
    int ans=-1000;
    while (rear!=front) {
       Node now = pop();
       int x = now.x, y = now.y, sum = now.sum;
       if (x == 0) {
            if (sum > ans) ans = sum;
            continue;
        }
       if (a[x][y] % 2 != 0) { 
           if (x - 1 >= 0) { 
                push(x - 1, y, sum + a[x - 1][y]);
           }
           if (y + 1 <= n - x +1) {
                push(x, y + 1, sum + a[x][y + 1]);
           }
       } 
	   else { 
           if (x - 1 >= 0) { 
               push(x - 1, y, sum + a[x - 1][y]);
           }
       }
     }
     printf("%d",ans);
    return 0;
}
