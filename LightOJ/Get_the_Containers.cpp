#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll necessaryContainers(vector<int>&v,ll maxCapacity){
    ll containters=0;
    ll sum=0;
    for(int i=0;i<v.size();i++){
        if(v[i]>maxCapacity)return INT_MAX;
        if(sum+v[i]<=maxCapacity){
            sum+=v[i];
        }else{
            sum=v[i];
            containters++;
        }
    }
    return ++containters;
}
int main()
{
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n,m;
        scanf("%d %d",&n,&m);
        vector<int>v(n);
        ll hi=0;
        for(int i=0;i<n;i++){
            scanf("%d",&v[i]);
            hi+=v[i];
        }
        ll lo=0;
        while(lo<hi){
            ll md=(lo+hi)/2;
            if(necessaryContainers(v,md)<=m){
                hi=md;
            }else{
                lo=md+1;
            }
        }
        printf("Case %d: %lld\n",t,hi);

    }
}