#include<bits/stdc++.h>
using namespace std;
unsigned long long int sum;
struct rec
{
    int mx,mn;
};
rec cal(int ara[],int sz)
{
    rec s;
    s.mx=ara[0];
    s.mn=ara[0];
    for(int i=1;i<sz;i++){
        if(ara[i]>s.mx)
            s.mx=ara[i];
        if(ara[i]<s.mn)
            s.mn=ara[i];
    }
    return s;
}

int main(void)
{
    int n;
    scanf("%d",&n);
    vector<rec>v;
    for(int i=0;i<n;i++){
        int sz;
        scanf("%d",&sz);
        int ara[sz];
        bool hae=false;
        scanf("%d",&ara[0]);
        for(int j=1;j<sz;j++){
            scanf("%d",&ara[j]);
            if(ara[j]>ara[j-1])
                hae=true;
        }
        if(hae){
            sum+=(n-1)*2;
        }
        else{
            v.push_back(cal(ara,sz));
        }
    }
    vector<int>vmx,vmn;
//    printf("sum = %llu\n",sum);
    if(v.size()>0){
        for(int i=0;i<v.size();i++){
            vmx.push_back(v[i].mx);
            vmn.push_back(v[i].mn);
        }
        sort(vmx.begin(),vmx.end());
        sort(vmn.begin(),vmn.end());
        for(int i=0;i<vmx.size();i++){
            auto it=lower_bound(vmn.begin(),vmn.end(),vmx[i]);
            sum+=((it-vmn.begin()));

        }
        for(int i=0;i<vmn.size();i++){
            auto it=lower_bound(vmx.begin(),vmx.end(),vmn[i]);
            sum+=((it-vmx.begin()));

        }

    }
//    for(int i=0;i<v.size();i++){
//        if(v[i].mx>v[i].mn)
//            sum--;
//    }
    printf("%llu\n",sum);
    return 0;
}
