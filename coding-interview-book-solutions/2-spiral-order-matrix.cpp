#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int matrix[MAX][MAX];
void spiralOrder(int crrnt_i,int crrnt_j,int m,int n){
    if( crrnt_i>=(m+1)/2 || crrnt_j>=(n+1)/2){
        return;
    }
    for(int j=crrnt_j;j<n-crrnt_j;j++){
        printf("%d ",matrix[crrnt_i][j]);
    }
    for(int i=crrnt_i+1;i<m -crrnt_i;i++){
        printf("%d ",matrix[i][n-crrnt_j -1]);
    }
    for(int j= n -crrnt_j -2;j>=crrnt_j;j--){
        printf("%d ",matrix[m- crrnt_i-1][j]);
    }
    for(int i= m-crrnt_i-2;i>crrnt_i;i--){
        printf("%d ",matrix[i][crrnt_j]);
    }
    spiralOrder(crrnt_i+1,crrnt_j+1,m,n);
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