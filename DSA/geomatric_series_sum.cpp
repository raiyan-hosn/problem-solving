// find the sum of 1+x+x^2+.....+x^n mod 10^9+7 where 1<=x,n<=10^9
#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int _pow(int n, int p){
    if(p==0)return 1;
    if(p&1){
        // return ((_pow(n,p-1)%M)*n)%M;
        return ((_pow(n,p-1))*n);
    }else{
        int res=_pow(n,p/2);
        // return ((res%M)*(res%M))%M;
        return ((res)*(res));
    }
}
int geomatricSeriesSum(int x,int n){

    if(n==1)return 1+x;
    
    if(n%2==0){
        n--;
        return (((geomatricSeriesSum(x,n/2)%M)*((1+_pow(x,n/2+1)%M))%M)+ _pow(x,n+1))%M;
    }else{
        return ((geomatricSeriesSum(x,n/2)%M)*((1+_pow(x,n/2+1)%M))%M);
    }
}
int main()
{
    int x,n;
    while(scanf("%d %d",&x,&n)!=EOF){
        printf("%d\n",geomatricSeriesSum(x,n));
    }
}