#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll numberOfWays(ll n,ll k){
    if(n<k)return 0;

    vector<bool>mark(k+1,true);
    ll ways=1;
    for(ll i=0;i<k;i++){
        ways*=( (n-i)*(n-i) );
        for(ll j=1;j<=k;j++){
            if(mark[j]&& ways%j==0){
                ways/=j;
                mark[j]=false;
            }
        }
    }
    return ways;
}
int main()
{
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        ll n,k;
        scanf("%lld %lld",&n,&k);
        ll ways=numberOfWays(n,k);
        printf("Case %d: %lld\n",t,ways);
    }
}