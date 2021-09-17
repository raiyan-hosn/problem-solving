#include<bits/stdc++.h>
using namespace std;
#define ll long long int
/// tutorial : https://www.youtube.com/watch?v=86CQq3pKSUw

ll kadane(int arr[],int n)
{
    ll max_current, max_global;
    max_current=max_global=arr[0];
    for(int i=1;i<n;i++){
        ll val=arr[i];
        max_current=max(val,max_current+val);
        if(max_current>max_global)
            max_global=max_current;
    }
    return max_global;
}
int main()
{
   int arr[]={-2,3,2,-1};
   printf("%lld\n",kadane(arr,sizeof(arr)/sizeof(int)));
}