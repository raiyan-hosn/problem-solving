//alhamdulillah
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int f,r;
    while(scanf("%d",&f)&&f){
        scanf("%d",&r);
        vector<int>vf(f);
        vector<int>vr(r);
        for(int i=0;i<f;i++)
            scanf("%d",&vf[i]);
        for(int i=0;i<r;i++)
            scanf("%d",&vr[i]);
        vector<double>driveRatio;
        for(int i=0;i<r;i++){
            int m,n=vr[i];
            for(int j=0;j<f;j++){
                m=vf[j];
                driveRatio.push_back(1.0*n/m);
            }
        }
        sort(driveRatio.begin(),driveRatio.end());
        double mx=INT_MIN;
        
        for(int i=1;i<driveRatio.size();i++){
            mx=max(mx,driveRatio[i]/driveRatio[i-1]);
        }
        printf("%.2lf\n",mx);
    }
}