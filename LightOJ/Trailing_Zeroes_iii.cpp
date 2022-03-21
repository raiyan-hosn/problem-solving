#include<bits/stdc++.h>
using namespace std;
int numOfZerosInFact(int n){
    int cnt=0;
    for(int i=1;pow(5,i)<=n;i++){
        cnt+=(n/pow(5,i));
    }
    return cnt;
}
int main()
{
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int q;
        scanf("%d",&q);
        int lo=1,hi=INT_MAX;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(q<=numOfZerosInFact(mid)){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        printf("Case %d: ",t);
        if(q!=numOfZerosInFact(hi)){
            printf("impossible\n");
            // printf("q=%d , hi= %d\n",q,hi);
        }else{
            printf("%d\n",hi);
        }

    }
}