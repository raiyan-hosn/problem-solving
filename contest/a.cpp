/**
 here we can simply sort the array and print the higest kth element.
 time complexity = O(Nlog2(N))

 I know another solution which is similar to quick sort
 and the complexity will be O(N)
 but do not enough time to implement that.
 * */

#include<bits/stdc++.h>
using namespace std;

int main()
{
   
 int n,k;
 scanf("%d %d",&n,&k);
 vector<int>v(n);
 for(int i=0;i<n;i++){
     scanf("%d",&v[i]);
 }
 sort(v.begin(),v.end());
 printf("%d\n",v[n-k]);
 
}