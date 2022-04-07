#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int>v(n);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        // v[i]=rand()%1000;
    }
    vector<int>lhs;
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            for(int c=0;c<n;c++){
               
                lhs.push_back((v[a]*v[b]+v[c]));    
            }
        }
    }
    map<int,pair<int,int>>mp;
    for(int d=0;d<n;d++){
        if(v[d]==0)continue;
        for(int e=0;e<n;e++){
            for(int f=0;f<n;f++){
                int val=v[d]*(v[e]+v[f]);
                mp[val]=make_pair(mp[val].first+1,v[d]);
            }
        }
    }

    int cnt=0;
    for(int i=0;i<lhs.size();i++){
       int val=lhs[i];
       if(mp.count(val)>0&& val%mp[val].second==0){
           cnt+=mp[val].first;
       }
    }
    printf("%d\n",cnt);
}
