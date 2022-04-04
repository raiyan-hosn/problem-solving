#include<bits/stdc++.h>
using namespace std;
void prv(vector<int>v){
    for(int i=0;i<v.size();i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    scanf("%d",&n);
    vector<int>v(n);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    vector<int>lhs,rhs;//left hand side, righ hand side
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            for(int c=0;c<n;c++){
                for(int d=0;d<n;d++){
                    if(v[d]!=0){
                        lhs.push_back((v[a]*v[b]+v[c])/v[d]);
                    }
                }
            }
        }
    }
    for(int e=0;e<n;e++){
        for(int f=0;f<n;f++){
            rhs.push_back(v[e]+v[f]);
        }
    }
    sort(lhs.begin(),lhs.end());
    sort(rhs.begin(),rhs.end());

    // lhs.erase( unique(lhs.begin(),lhs.end()), lhs.end());
    // rhs.erase( unique(rhs.begin(),rhs.end()), rhs.end());
    int cnt=0;
    int i=0,j=0;
    prv(lhs);prv(rhs);
    while(i<lhs.size()&&j<rhs.size()){
        if(lhs[i]==rhs[j]){
            cnt++;
            i++;j++;
        }else if(lhs[i]<rhs[j]){
            i++;
        }else{
            j++;
        }
    }
    printf("%d\n",cnt);
}