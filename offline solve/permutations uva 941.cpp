#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
ll fac(ll n)
{
    if(n<=1)
        return 1;
    return n*fac(n-1);
}
int main(void)
{
//    freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    int tc;
    cin>>tc;
    cin.ignore();
    while(tc--){
        ll n;
        string s;
        cin>>s>>n;
        vector<char> v;
        for(int i=0;i<s.length();i++)
            v.push_back(s[i]);
        sort(v.begin(),v.end());
        n=n%fac((int)v.size());
        while(v.size()!=1){
            ll f=fac((int)v.size()-1);
            ll idx=n/f;
            printf("%c",v[idx]);
            n-=(f*idx);
            v.erase(v.begin()+idx);
        }
        printf("%c\n",v[0]);
    }
    return 0;
}
