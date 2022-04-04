#include<bits/stdc++.h>
using namespace std;
int bpm(int b,int p,int m){
    if(p==0)return 1;
    if(p%2==0){
        int res=bpm(b,p/2,m);
        return (res*res)%m;
    }else{
        int res=bpm(b,p/2,m);
        return ((res*res)%m*(b%m))%m;
    }
}
int main()
{
    int b,p,m;
    while(scanf("%d %d %d",&b,&p,&m)!=EOF){
        printf("%d\n",bpm(b,p,m));
    }
}