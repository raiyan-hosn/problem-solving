#include<bits/stdc++.h>
using namespace std;
bool dig[10];
bool ch(int n)
{
    while(n){
        if(dig[n%10]==1)
            return true;
        n/=10;
    }
    return false;
}
int main(void)
{
    int n;
    scanf("%d",&n);
    int t=n;
    while(t){
        dig[t%10]=1;
        t/=10;
    }
    int cnt=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(ch(i))
                cnt++;
            if(i!=n/i)
                if(ch(n/i))
                    cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
