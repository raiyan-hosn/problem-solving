#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n;
        scanf("%d",&n);
        vector<int>v(n);
        for(int i=0;i<n;i++){
            scanf("%d",&v[i]);
        }
        sort(v.begin(),v.end());
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum=v[i]+v[j];
                int idx=lower_bound(v.begin(),v.end(),sum)-v.begin();
                if(j<idx){
                    // printf("(%d,%d) idx=%d\n",i,j,idx);
                    cnt+=(idx-j-1);
                }
            }
        }
        printf("Case %d: %d\n",t,cnt);

    }
}