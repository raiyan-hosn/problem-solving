#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mergeSort(int arr[],int st,int en){
    
    if(st+1>=en)return 0;
    int mid=(st+en)/2;
    
    ll sum = mergeSort(arr,st,mid) + mergeSort(arr,mid,en);
   
    for(int i=mid;i<en;i++){
        int idx=upper_bound(arr+st,arr+mid,arr[i])-arr;
        sum+=(mid-idx);
    }

    int i=st,j=mid,k=0;
    int temp[en-st];


    while(i<mid&&j<en){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    while(i<mid)temp[k++]=arr[i++];
    while(j<en)temp[k++]=arr[j++];

    for(i=0,j=st;i<k;i++,j++){
        arr[j]=temp[i];
    }
    return sum;
  
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        ll res= mergeSort(arr,0,n);
     
        printf("%lld\n",res);
    }
}