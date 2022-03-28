#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=85;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            printf("i=%d\n",i);
            cnt++;
        }
    }
    printf("%d\n",cnt);
}