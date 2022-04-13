/**
 Is I simplify the problem,
 we have to count the number of sub-arrays of consicutive integers where their sum is less than X.

to do that,
we have to find the first sub-array of SUM<X
if the sum >= X then that is the end of the sub-array.
so within the sub-array all the sub-arrays(sub-arrays of the sub-array) are valid (sum<x)
and they can form n*(n+1)/2 sub-arrays where n is the lenght of the sub-array.

after that, we will find the second valid sub-array and so on.......
 **/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        ll n,x;
        scanf("%lld %lld",&n,&x);
        vector<ll>v(n);
        for(int i=0;i<n;i++){
            scanf("%lld",&v[i]);
        }
        ll sum=v[0];
        ll cnt=0;
        ll crrn=0;
        int i=0,j=0;
        for(;i<n&&j<n;){
            if(sum>=x){
            sum-=v[i++]; 
              
            }else{
                 j++;
                if(j>=i){
                    cnt+=(j-i);
                }
                if(j<n){
                    sum+=v[j];
                }
            }
        }
        
        printf("%lld\n",cnt);
    }
}