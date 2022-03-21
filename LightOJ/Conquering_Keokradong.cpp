#include<bits/stdc++.h>
using namespace std;
int n,k,arr[1003];
int numOfK(int maxWalk){
    int days=1,sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>maxWalk)return 10000007;
        if(sum+arr[i]<=maxWalk){
            sum+=arr[i];
        }else{
            sum=arr[i];
            days++;
        }
    }
    return days;
}
int main()
{
	// freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
       
        scanf("%d %d",&n,&k);
        k++;
        n++;
     
        int sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }
       
        int hi=sum;
        int lo=0;
     
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(numOfK(mid)<=k){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        printf("Case %d: %d\n",t,hi);

        sum=0;
        for(int i=0,j=0;i<n;i++){     
            if(sum+arr[i]<=hi&& n-i>=k-j){
                sum+=arr[i];
            }
            else{
                
                if(sum==0){
                    sum=arr[i];
                }
                printf("%d\n",sum);
                sum=arr[i];
                j++;
                
            }
            if(i+1==n){
                printf("%d\n",sum);
            }
            // printf("i=%d n=%d\n",i,n);
        }
    }
}
