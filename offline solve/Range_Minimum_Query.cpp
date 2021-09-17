#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define left st,(st+en)/2,nd+nd
#define right (st+en)/2+1,en,nd+nd+1
int arr[MAX+5];
int tree[4* MAX+5];
void build(int st,int en,int nd){
    if(st==en){
        tree[nd]=arr[st];
        return;
    }

    build(left);
    build(right);
    tree[nd]=min(tree[nd+nd],tree[nd+nd+1]);
}
int query(int st,int en,int nd,int L,int R){
    if(L<=st&&en<=R){
        return tree[nd];
    }
    if(en<L||R<st){
        return INT_MAX;
    }

    return min( query(left,L,R), query(right,L,R));
}
void printTree(int n){
    for(int i=1;i<=n;i++){
        cout<<i<<" : "<<tree[i]<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(0,n-1,1);
    ///printTree(5);
    int q;
    cin>>q;
    while (q--)
    {
        int L,R;
        cin>>L>>R;
        cout<<query(0,n-1,1,L,R)<<endl;
    }
    
}