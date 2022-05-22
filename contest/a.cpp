#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    map<int,int>mf,mb;
    for(int i=0;i<n;i++){
        int f,b;
        scanf("%d %d",&f,&b);
        mb[f]=b;
        mf[b]=f;
    } 
    vector<int>v(n);
    int front=0;
    for(int i=1;i<n;i+=2){
        v[i]=mb[front];
        front=v[i];
    }
    int firstNumber;
    for(auto it=mb.begin();it!=mb.end();it++){
        if( mf[it->first]==0&& it->first!=v[1]){
            firstNumber=it->first;
        }
    }
    v[0]=firstNumber;
    for(int i=2;i<n;i+=2){
        v[i]=mb[v[i-2]];
    }
    for(int i=0;i<n;i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}