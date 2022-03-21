#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    double lo=0,hi=n;
    for(int i=0;i<100;i++){
        double md=(lo+hi)/2;
        if(abs(md*md)<1e-6)break;
        else if(md*md<n)lo=md;
        else hi=md;
    }
    printf("%.10f\n",hi);
}