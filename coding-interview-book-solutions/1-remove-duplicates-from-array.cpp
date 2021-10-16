#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int n){
    if(n==0)return 0;
    int num=0;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[num]){
            arr[++num]=arr[i];
        }
    }
    return num+1;
}
int main()
{
    int n=5;
    int arr[]={0,1,1,1,1};
    n=removeDuplicates(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}