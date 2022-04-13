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

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n,x;
        scanf("%d %d",&n,&x);
        vector<int>v(n);
        for(int i=0;i<n;i++){
            scanf("%d",&v[i]);
        }
        int sum=0;
        int cnt=0;
        int crrn=0;
        for(int i=0;i<n;i++){
            if(sum+v[i]<x){
                sum+=v[i];
                crrn++;
            }else{
                cnt+=((crrn*(crrn+1))/2);
                if(v[i]<x){
                    sum=v[i];
                    crrn=1;
                }else{
                    crrn=sum=0;
                }
            }
        }
        if(crrn!=0){
            cnt+=((crrn*(crrn+1))/2);
        }
        printf("%d\n",cnt);
    }
}