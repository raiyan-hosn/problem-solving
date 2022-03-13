#include<bits/stdc++.h>
using namespace std;
int probability(int people, int days){
    double result=1;
    for(int i=1;i<people;i++){
        result*=(1.0-(1.0*i/days));
    }
    return (1-result)*100;
}
int main()
{
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n;
        scanf("%d",&n);
        
        int lo=2,hi=380;
        while(lo<hi){
            int mid=(lo+hi)/2;
            int p= probability(mid,n);
            if(p>=50){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        if(hi==1)hi++;
        printf("Case %d: %d\n",t,hi-1);
    }

}
