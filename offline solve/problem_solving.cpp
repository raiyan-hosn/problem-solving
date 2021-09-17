#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b){
    int x,y;
    x=stoi(a);
    y=stoi(b);
    return y-x==1;
}
void prnt(vector<string>&v){
    int mxmach=0;
    int n=v.size();
    int l=v[0].size();
    for(;mxmach<l;mxmach++){
        if(v[0][mxmach]!=v[n-1][mxmach])
            break;
    }

    cout<<v[0];
    if(n>1)cout<<"-";

//    printf("l=%d and mx=%d\n",l,mxmach);
    for(int i=mxmach;i<l;i++){
        cout<<v[n-1][i];
    }
    cout<<endl;
}
int main()
{
//    freopen("i.txt","r",stdin);
   int n;
   int tc=1;
   while(scanf("%d",&n)&&n!=0){
        vector<string>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<string>lst[n];
        int k=0;
        lst[0].push_back(v[0]);
        for(int i=1;i<n;i++){
            if(cmp(v[i-1],v[i])){
                lst[k].push_back(v[i]);
            }
            else{
                k++;
                lst[k].push_back(v[i]);
            }
        }

        printf("Case %d:\n",tc);
        for(int i=0;i<=k;i++){
            prnt(lst[i]);
        }
        printf("\n");
        tc++;
   }

