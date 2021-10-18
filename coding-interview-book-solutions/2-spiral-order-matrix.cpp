#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int matrix[MAX][MAX];
void spiralOrder(int pi,int pj,int m,int n){
    if( pi>=(m+1)/2 || pj>=(n+1)/2){
        return;
    }
    for(int j=pj;j<n-pj;j++){
        printf("%d ",matrix[pi][j]);
    }
    for(int i=pi+1;i<m -pi;i++){
        printf("%d ",matrix[i][n-pj -1]);
    }
    for(int j= n -pj -2;j>=pj;j--){
        printf("%d ",matrix[m- pi-1][j]);
    }
    for(int i= m-pi-2;i>pi;i--){
        printf("%d ",matrix[i][pj]);
    }
    spiralOrder(pi+1,pj+1,m,n);
}

int main(void)
{
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    spiralOrder(0,0,m,n);

}