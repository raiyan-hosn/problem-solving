#include<bits/stdc++.h>
using namespace std;
int low_bound(int arr[],int n,int x){
    int lo=0,hi=n;
    while(lo<hi){
        int md=(lo+hi)/2;
        if(x<=arr[md])hi=md;
        else lo=md+1;
    }
    return hi;
}
int upp_bound(int arr[],int n,int x){
    int lo=0,hi=n;
    while(lo<hi){
        int md=(lo+hi)/2;
        if(x<arr[md]){
            hi=md;
        }
        else{
           lo=md+1;
        }
      
    }
    return hi;
}
int main(){
    int arr[]={10,20,30,40,50,50,50,60,70,71,72,73,80};
    int n=sizeof(arr)/sizeof(int);

    int idx=upp_bound(arr,n,75);
    if(idx<n){
        printf("index= %d, value=%d\n",idx,arr[idx]);
    }else{
        printf("At the end\n");
    }
}