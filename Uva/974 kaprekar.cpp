#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll val(list<int>&lst)
{
    ll n=0;
    for(auto it=lst.begin();it!=lst.end();it++){
        n=n*10 + *it;
    }
    return n;
}
bool isKaprekar(int n)
{
   ll sqt=n*n;
   list<int>lst;
   while(sqt!=0){
        lst.push_front(sqt%10);
        sqt/=10;
        if(sqt==0)
            break;
        if(val(lst)==0)
            continue;
        if(sqt+val(lst)==n){
            return true;
        }
   }
   return false;
}
int main(void)
{

//    freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    vector<int>v;
    for(int i=2;i<=40000;i++){
        if(isKaprekar(i))
            v.push_back(i);
    }
    for(int t=1;t<=tc;t++){
        int l,r;
        scanf("%d %d",&l,&r);
        if(t!=1)
            printf("\n");
        printf("case #%d\n",t);
        bool hppn=false;
        auto it=lower_bound(v.begin(),v.end(),l);
        for(;it!=v.end();it++){
            if(*it>r)
                break;
            printf("%d\n",*it);
            hppn=true;
        }
        if(!hppn)
            printf("no kaprekar numbers\n");
    }
    return 0;
}
